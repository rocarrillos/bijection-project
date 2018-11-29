#include "tutte.h"

void flatten(std::vector<Vector3f> model, std::vector<Vector2f> &mapping) {
    // Converts vertices from a 3D model to a 2D uniform mapping
    int i = model.size();
    Matrix4f tutte;
    Vector4f row0(1, -1/2, -1/3, -1/4);
    Vector4f row1(-1, 1, -1/3, -1/4);
    Vector4f row2(-1, -1/2, 1, -1/4);
    Vector4f row3(-1, -1/2, -1/3, 1);
    tutte.setRow(0, row0);
    tutte.setRow(1, row1);
    tutte.setRow(2, row2);
    tutte.setRow(3, row3);
    for (int iter = 0; iter < i; iter++) {
        Vector4f halfway(model[iter], 1);
        Vector4f t = tutte * halfway;
        mapping.push_back(t.xy());
    }
}