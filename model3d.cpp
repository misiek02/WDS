#include "model3d.hh"


Model3D::Model3D(Qt3DCore::QEntity *parent)
    : Qt3DCore::QEntity(parent)
{
    // Load your 3D model file (e.g., "your_model.obj")
    Qt3DRender::QMesh *mesh = new Qt3DRender::QMesh();
    mesh->setSource(QUrl(QStringLiteral("file:///C:/Users/ADMIN/Documents/qt_projekts/WSD-main/robot.obj"))); // Adjust the path as needed
    //C:\Users\ADMIN\Documents\qt_projekts\WSD-main

    // Create a material for your model
    Qt3DExtras::QPhongMaterial *material = new Qt3DExtras::QPhongMaterial();
    material->setDiffuse(QColor(QRgb(0xbeb32b))); // Set diffuse color
    material->setSpecular(QColor(QRgb(0xffffff))); // Set specular color
    material->setShininess(50.0f); // Set shininess

    // Add components to the entity
    addComponent(mesh);
    addComponent(material);
}
