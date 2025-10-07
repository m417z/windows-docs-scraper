typedef struct _ODJ_BLOB
{
    ULONG ulODJFormat;
    ULONG cbBlob;
    [size_is(cbBlob)] PBYTE pBlob;
} ODJ_BLOB, *PODJ_BLOB;