#pragma once

#include "Resource.hpp"

class ResourceManager
{
private:
    Resource* managedResource;
    //test test
public:
    ResourceManager() : managedResource(new Resource) {}

    /*
    ResourceManager(Resource& resource) : managedResource(resource)
    {

        //.allocateResources();
    }
    */

    // konstruktor kopiujący
    ResourceManager(const ResourceManager& manager)
        : managedResource(new Resource(*manager.managedResource))
    {}

    // konstruktor przenoszący
    ResourceManager(ResourceManager&& manager) : managedResource(manager.managedResource)
    {
        manager.managedResource = nullptr;
    }

    ~ResourceManager()
    {
        delete managedResource;
        //.freeResources();
    }

    // Kopiujący operator przypisania
    ResourceManager& operator=(const ResourceManager& t)
    {
        // if (this != t)
        {
            delete (this->managedResource);
            (*this).managedResource = new Resource(*t.managedResource);
            return (*this);
        }
    }
;

    // Przenoszący operator przypisania
    ResourceManager& operator=(ResourceManager&& t)
    {
        // if (this != t)
        {
            delete (this->managedResource);
            (*this).managedResource = t.managedResource;
            t.managedResource        = nullptr;
            return (*this);
        }
    };

    double get()
    {
        return ((*managedResource).get());
    }
}
;







//#pragma once
//
//#include "Resource.hpp"
//
//class ResourceManager
//{
//private:
//    Resource& managedResource;
//
//public:
//    ResourceManager() : managedResource(*new Resource) {}
//
//    /*
//    ResourceManager(Resource& resource) : managedResource(resource)
//    {
//
//        //.allocateResources();
//    }
//    */
//
//    // konstruktor kopiujący
//    ResourceManager(const ResourceManager& manager)
//        : managedResource(*new Resource = manager.managedResource){}
//
//    // konstruktor przenoszący
//    ResourceManager(ResourceManager&& manager) : managedResource(manager.managedResource) {}
//
//    ~ResourceManager()
//    {
//        delete & managedResource;
//        //.freeResources();
//    }
//
//    // Kopiujący operator przypisania
//    ResourceManager& operator=(const ResourceManager& t)
//    {
//        managedResource = t.managedResource;
//        return (*this);
//    };
//    // Przenoszący operator przypisania
//    ResourceManager& operator=(ResourceManager&&);
//
//    double get() { return (managedResource.get()); }
//};
