# ODJ_PROVISION_DATA structure

Specifies the outermost serialization structure used by the offline domain join apis.

## Members

### ulVersion

This must be set to 1.

### ulcBlobs

This must be set to the number of elements in the pBlobs array.

### pBlobs

Points to an array of ODJ_BLOB structures.

## See also

[**Offline Domain Join IDL Definitions**](https://learn.microsoft.com/windows/win32/netmgmt/odj-idl)

[**ODJ\_BLOB**](https://learn.microsoft.com/windows/win32/netmgmt/odj-odj_blob)