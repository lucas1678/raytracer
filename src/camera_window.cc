#include "camera_window.hh"

void CameraWindow::draw() const {
    // ~~~~~~ generate rays which will hit screen! ~~~~~~~~~~~~~~
    int num_of_generated_rays = m_Window_height * m_Window_width;
    std::vector<vec3> generated_rays(num_of_generated_rays);  // check if using a vector to store these is a good idea for efficiency!

    //  RIGHT NOW I'M ASSUMING RESOLUTION OF WINDOW IS 1:1 AS IN, 1600X900 SIZE SCREEN WILL HAVE 1600 BY 900 PIXELS
    float grid_spacing = 1.0;

    //  ALSO FIXED CAMERA WINDOW TO ALIGN WITH WITH X-AXIS (so we only draw on x-y plane)
    for(int i=0; i<m_Window_width; i++){
        for(int j=0; j<m_Window_height; j++){
            //  this trick can be ROW-MAJOR (how we should be implementing it) or COLUMN-MAJOR! Different on whether (1,0) or (0,1) get mapped to 1
            int ray_index = j*m_Window_width + i;  //  math trick to extract 1D index out of 2D nested for loop (i,j)
            vec3 ray{m_Window_pos.x() + grid_spacing/2 + i*grid_spacing, 
                     m_Window_pos.y() - grid_spacing/2 - j*grid_spacing, 
                     m_Window_pos.z()};
            generated_rays[ray_index] = ray;
        }
    }


    //  ~~~~~~~  check what these generated rays collide with, and convert them to the appropriate pixel/color

    


                   



}

void CameraWindow::draw(std::vector<Pixel> pixel_list) const {
    std::cout << "P3\n" << m_Window_width << ' ' << m_Window_height << "\n255\n";
    for(const auto& pixel : pixel_list){
        std::cout << pixel << '\n';
    }
    std::cout << std::flush;
}