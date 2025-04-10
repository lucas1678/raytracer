#include "camera_window.hh"

void CameraWindow::draw(const Scene& scene) const {
    // ~~~~~~ generate rays which will hit screen! ~~~~~~~~~~~~~~
    int num_of_generated_rays = m_Window_height * m_Window_width;
    std::vector<vec3> generated_rays(num_of_generated_rays);  // check if using a vector to store these is a good idea for efficiency!

    //  GRID SPACING OF 0.01 WILL MAKE 900X1600 SCREEN BE OF SIZE 9 X 16
    float grid_spacing = 0.01;

    //  ALSO FIXED CAMERA WINDOW TO ALIGN WITH WITH X-AXIS (so we only draw on x-y plane)
    for(int i=0; i<m_Window_width; i++){
        for(int j=0; j<m_Window_height; j++){
            //  this trick can be ROW-MAJOR (how we should be implementing it) or COLUMN-MAJOR! Different on whether (1,0) or (0,1) get mapped to 1
            int ray_index = j*m_Window_width + i;  //  math trick to extract 1D index out of 2D nested for loop (i,j)
            vec3 ray{m_Window_pos.x() + grid_spacing/2 + i*grid_spacing, 
                     m_Window_pos.y() - grid_spacing/2 - j*grid_spacing, 
                     m_Window_pos.z()};
            ray.normalize();
            generated_rays[ray_index] = ray;
        }
    }

    //  ~~~~~~~  check what these generated rays collide with, and convert them to the appropriate pixel/color
    std::vector<Color> color_list(num_of_generated_rays, scene.getBackgroundColour());

    for(size_t idx=0; idx<num_of_generated_rays; idx++){
        const Ray& ray = generated_rays[idx];
        float closest_t = std::numeric_limits<float>::max();  // maximum value represented by a float (nothing can be higher than this!)
        Object *closest_object{nullptr};

        for(Object *object : scene.getObjectList()){
            float t_hit;
            if(object->hasCollisionWith(ray, t_hit) && t_hit < closest_t){
                closest_t = t_hit;
                closest_object = object;
            }
        }

        if(closest_object != nullptr){
            vec3 hitPoint = ray*closest_t;
            //  for now implemention lambertian (diffuse) reflection directly here.
            //  later, I can have a class such a PhysicsModel which includes all functionality for such things
            vec3 normalAtHitPoint = closest_object->getNormalAt(hitPoint);
            float intensity = ray.dot(normalAtHitPoint);
            if(intensity < 0) intensity *= -1;  //instead of this, need to do std::max(0, dot_prod) to avoid light rays coming from behind to trigger!

            Color ambient_color = Color(0,0,10); // blue ambient color...
            color_list[idx] = intensity*(closest_object->getColor()) + ambient_color;
        }
    }

    //  Draw to cout based on color_list
    std::cout << "P3\n" << m_Window_width << ' ' << m_Window_height << "\n255\n";
    for(const auto& pixel : color_list){
        std::cout << pixel << '\n';
    }
    std::cout << std::flush;
}

void CameraWindow::draw(std::vector<Pixel> pixel_list) const {
    std::cout << "P3\n" << m_Window_width << ' ' << m_Window_height << "\n255\n";
    for(const auto& pixel : pixel_list){
        std::cout << pixel << '\n';
    }
    std::cout << std::flush;
}