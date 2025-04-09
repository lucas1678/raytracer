First ray tracer which I will be building from scratch. 
After building, you can run (on Windows) like .\raytracer.exe >> name_of_your_image.ppm

## Drawing Process  (camera window confined in XY axis for now)
1. Generate list of ray directions
2. For each ray in this list, extend the ray in that direction and check for intersection with a plane


For the intersection of a ray with a disk, we can first check if the ray, at any point, lies in the plane of the disk.
If so, then we can check if its distance from the center of the disk is equal to or less than the disk's radius!