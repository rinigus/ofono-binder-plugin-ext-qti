#include "qti_utils.h"

gsize
qti_binder_read_parcelable_size(
    GBinderReader* reader)
{
    /* Read a single AIDL parcelable header and return inner data size */
    guint32 non_null = 0, payload_size = 0;
    if (gbinder_reader_read_uint32(reader, &non_null) && non_null &&
        gbinder_reader_read_uint32(reader, &payload_size) &&
        payload_size >= sizeof(payload_size)) {

        return payload_size - sizeof(payload_size);
    }
    return 0;
}

void
qti_binder_skip_parcelable_end(
    GBinderReader* reader,
    gsize parcel_size,
    gsize initial_size)
{
    gsize data_read;
    data_read = gbinder_reader_bytes_read(reader) - initial_size;
    while (data_read < parcel_size) {
        gbinder_reader_read_uint32(reader, NULL);
        data_read += sizeof(guint32);
    }
}

