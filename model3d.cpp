#include "model3d.hh"


Model3D::Model3D(Qt3DCore::QEntity *parent)
    : Qt3DCore::QEntity(parent)
{

    Qt3DRender::QMesh *mesh = new Qt3DRender::QMesh();
    mesh->setSource(QUrl(QStringLiteral("file:///C:/Users/ADMIN/Documents/qt_projekts/WSD-main/robot.obj"))); // Adjust the path as needed
    //C:\Users\ADMIN\Documents\qt_projekts\WSD-main


    Qt3DExtras::QPhongMaterial *material = new Qt3DExtras::QPhongMaterial();
    material->setDiffuse(QColor(QRgb(0xbeb32b)));
    material->setSpecular(QColor(QRgb(0xffffff)));
    material->setShininess(50.0f);


    addComponent(mesh);
    addComponent(material);
}
