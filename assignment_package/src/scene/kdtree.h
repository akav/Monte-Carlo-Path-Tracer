#pragma once
#include "geometry/primitive.h"
#include <QTime>
#include "scene/photons.h"

// Forward declarations of structs used by our kd tree
// They are defined in the .cpp file
struct KdNode;
class Scene;
class Photon;

class KdTree
{
public:
    KdTree(const Scene &scene, std::vector<std::vector<Photon*>*> &indirectMap, std::vector<std::vector<Photon*>*> &causticMap);

    void constructHelper( glm::vec3 bv_min, glm::vec3 bv_max,
                          KdTree* parent_node, int& depth,
                          int &count);

    //members
    int maxPhotonsInNode;
    KdNode* root;
};
