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


class Model3D : public Qt3DCore::QEntity
{
    Q_OBJECT
public:
    explicit Model3D(Qt3DCore::QEntity *parent = nullptr);
};

#endif // MODEL3D_HH
