/*
 * Copyright (C) 2015, Nils Moehrle
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms
 * of the BSD 3-Clause license. See the LICENSE.txt file for details.
 */

#ifndef CMVE_MESH_HEADER
#define CMVE_MESH_HEADER

#include <memory>

#include "mve/mesh.h"
#include "cacc/mesh.h"

#include "defines.h"

CMVE_NAMESPACE_BEGIN

cacc::TringleMesh<cacc::HOST>::Ptr
convert(mve::TriangleMesh::ConstPtr mesh);

CMVE_NAMESPACE_END

#endif /* CMVE_MESH_HEADER */
