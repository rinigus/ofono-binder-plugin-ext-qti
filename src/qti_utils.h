#ifndef QTI_UTILS_H

#include <gbinder.h>

extern gsize qti_binder_read_parcelable_size(GBinderReader *reader);

extern void qti_binder_skip_parcelable_end(GBinderReader *reader,
                                           gsize parcel_size,
                                           gsize initial_size);

#endif
