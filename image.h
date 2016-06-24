/*
 * Copyright (C) 2015, Nils Moehrle
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms
 * of the BSD 3-Clause license. See the LICENSE.txt file for details.
 */

#ifndef CMVE_IMAGE_HEADER
#define CMVE_IMAGE_HEADER

#include <memory>

#include "mve/image.h"
#include "cacc/image.h"

#include "defines.h"

CMVE_NAMESPACE_BEGIN

cacc::ByteImage<cacc::HOST>::Ptr
convert(mve::ByteImage::Ptr image);

mve::ByteImage::Ptr
convert(ByteImage<cacc::HOST>::Ptr image);

CMVE_NAMESPACE_END

#endif /* CMVE_IMAGE_HEADER */
