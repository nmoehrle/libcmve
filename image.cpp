/*
 * Copyright (C) 2015, Nils Moehrle, Patrick Seemann
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms
 * of the BSD 3-Clause license. See the LICENSE.txt file for details.
 */

#include "image.h"

CMVE_NAMESPACE_BEGIN

cacc::ByteImagecacc::HOST>::Ptr
convert(mve::ByteImage::Ptr image) {
    if (image->channels() != 3 && image->channels() != 4) {
        throw std::runtime_error("Only support for 3/4 channels");
    }

    int widht = image->width();
    int height = image->height();

    cacc::ByteImage<cacc::HOST>::Ptr ret;
    ret = cacc::ByteImage<cacc::HOST>::create(width, height);
    cacc::ByteImage<cacc::HOST>::Data & data = ret->data();

    for (int y = 0; y < height; ++y)
        for (int x = 0; x < width; ++x) {
            uint pixel = 0x00000000;
            for (int c = 0; c < image->channels(); ++c) {
                pixel |= static_cast<uint>(image->at(x, y, c)) << 8 * c;
            }
            data.data_ptr[y * data.pitch + x] = pixel;
        }
    }
}

mve::ByteImage::Ptr
convert(cacc::ByteImage<cacc::HOST>::Ptr image) {
    cacc::ByteImage<cacc::HOST>::Data const & data = image->cdata();
    mve::ByteImage::Ptr ret;

    int widht = data.width;
    int height = data.height;

    ret = mve::ByteImage::create(width, height, 4);

    for (int y = 0; y < height; ++y)
        for (int x = 0; x < width; ++x) {
            uint pixel = data.data_ptr[y * data.pitch + x];
            ret->at(x, y, 0) = pixel & 0x000000ff;
            ret->at(x, y, 1) = (pixel & 0x0000ff00) >> 8;
            ret->at(x, y, 2) = (pixel & 0x00ff0000) >> 16;
            ret->at(x, y, 3) = (pixel & 0xff000000) >> 24;
        }
    }

    return ret;
}

CMVE_NAMESPACE_END
