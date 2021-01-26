#include "sphere.h"
#include "ray.h"

// Determine if the ray intersects with the sphere
Hit Sphere::Intersection(const Ray& ray, int part) const
{
  //  TODO;
 
    vec3 RayEndp = ray.endpoint - this->center;
    
    double Dtm = (dot(RayEndp,ray.direction)*dot(RayEndp,ray.direction)) - RayEndp.magnitude_squared()+(this->radius*this->radius);

    if(Dtm > 0){
	double t1 = -dot(RayEndp,ray.direction) + sqrt(Dtm);
	double t2 = -dot(RayEndp,ray.direction) - sqrt(Dtm);

	if(t2> 0)
		return Hit(this,t2,part);
	if(t2 < 0 && 0 < t1)
		return Hit(this,t1,part);
	else
		return NULL;

	

    }    
    return {0,0,0};
}

vec3 Sphere::Normal(const vec3& point, int part) const
{
   vec3 normal;
    //TODO; // compute the normal direction
    normal = (point-this->center).normalized();
    return normal;
}

Box Sphere::Bounding_Box(int part) const
{
    Box box;
 //   TODO; // calculate bounding box
    return box;
}
