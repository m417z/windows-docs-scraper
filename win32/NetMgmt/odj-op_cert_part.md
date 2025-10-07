# OP_CERT_PART structure

Contains serialized PFX and certificate stores.

## Members

### cPfxStores

Contains the number of elements in pPfxStores.

### pPfxStores

Contains an array of OP_CERT_PFX_STORE structures.

### cSstStores

Contains the number of elements in pSstStores.

### pSstStores

Contains an array of OP_CERT_SST_STORE structures.

### Extension

Reserved for future use and must contain all zeros.

## See also

[**Offline Domain Join IDL Definitions**](https://learn.microsoft.com/windows/win32/netmgmt/odj-idl)

[**OP\_CERT\_PFX\_STORE**](https://learn.microsoft.com/windows/win32/netmgmt/odj-op_cert_pfx_store)

[**OP\_CERT\_SST\_STORE**](https://learn.microsoft.com/windows/win32/netmgmt/odj-op_cert_sst_store)

[**OP\_BLOB**](https://learn.microsoft.com/windows/win32/netmgmt/odj-op_blob)