#ifndef MODEL3D_HH
#define MODEL3D_HH

#include <Qt3DCore/QEntity>
#include <Qt3DExtras/QCuboidMesh>
#include <Qt3DExtras/QPhongMaterial>
#include <Qt3DExtras/Qt3DWindow>
#include <Qt3DExtras/QForwardRenderer>
#include <Qt3DExtras/QOrbitCameraController>
#include <Qt3DRender/QCamera>
#include <Qt3DCore/QEntity>
#include <Qt3DRender/QPointLight>
#include <Qt3DRender/QMesh>
#include <Qt3DExtras/QPhongMaterial>


/**
 * @file model3d.hh
 * @brief Definition of the Model3D class
 *
 * This file contains the class definition.
 */

/**
 * @brief The Model3D class represents a 3D model in a Qt3D scene
 */
class Model3D : public Qt3DCore::QEntity
{
    Q_OBJECT
public:
    /**
     * @brief Constructor for Model3D class
     * @param parent Pointer to parent entity, default is nullptr
     */
    explicit Model3D(Qt3DCore::QEntity *parent = nullptr);
};

#endif // MODEL3D_HH
