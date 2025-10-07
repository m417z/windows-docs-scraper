# OP_PACKAGE structure

Contains a structure that contains a serialized OP_PACKAGE_COLLECTION.

## Members

### EncryptionType

Reserved for future use and MUST be set to GUID_NULL.

### EncryptionContext

Reserved for future use and MUST be set to all zeros.

### WrappedPartCollection

An OP_BLOB structure that contains a serialized OP_PACKAGE_COLLECTION structure.

### cbDecryptedPartCollection

Reserved for future use and MUST be set to zero.

### Extension

Reserved for future use and MUST be set to all zeros.

## See also

[**Offline Domain Join IDL Definitions**](https://learn.microsoft.com/windows/win32/netmgmt/odj-idl)

[**OP\_BLOB**](https://learn.microsoft.com/windows/win32/netmgmt/odj-op_blob)

[**OP\_PACKAGE\_COLLECTION**](https://learn.microsoft.com/windows/win32/netmgmt/odj-op_package_collection)