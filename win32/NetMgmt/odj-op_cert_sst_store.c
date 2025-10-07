typedef struct _OP_CERT_SST_STORE
{
    ULONG                       StoreLocation;
    [string] wchar_t            *pStoreName;
    ULONG                       cbSst;
    [size_is(cbSst)]    PBYTE   pSst;
} OP_CERT_SST_STORE, *POP_CERT_SST_STORE;