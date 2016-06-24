/*
 * Copyright (C) 2015, Nils Moehrle
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms
 * of the BSD 3-Clause license. See the LICENSE.txt file for details.
 */

#include "mesh.h"

CMVE_NAMESPACE_BEGIN

template <>
cacc::TringleMesh<cacc::HOST>::Ptr
convert(mve::TriangleMesh::ConstPtr mesh) {
    mve::TriangleMesh::FaceList const & faces = mesh->get_faces();
    mve::TriangleMesh::VertexList const & verts = mesh->get_vertices();

    uint num_faces = faces.size() / 3;
    uint num_verts = verts.size();
    cacc::TriangleMesh<cacc::HOST>::Ptr ret;
    ret = cacc::TriangleMesh<cacc::HOST>::create(num_faces, num_verts);

    cacc::TriangleMesh<cacc::HOST>::Data & data = ret->data_ref();
    for (uint i = 0; i < num_faces; ++i) {
        for (int j = 0; j < 3; ++j) {
            data.vid_face_ptr[j][i] = static_cast<uint>(faces[3 * i + j]);
        }
    }

    for (uint i = 0; i < num_verts; ++i) {
        data.verts_ptr[i] = cacc::Vec3f(*verts[i]);
    }
}

CMVE_NAMESPACE_END
