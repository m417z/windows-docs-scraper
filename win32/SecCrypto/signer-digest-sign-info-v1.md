# SIGNER\_DIGEST\_SIGN\_INFO\_V1 structure

The **SIGNER\_DIGEST\_SIGN\_INFO\_V1** structure contains information about digest signing. It contains a pointer to a digest signing function implemented within the provided dll.

> [!Note]
> This structure is not defined in any header file. To use this structure, you must define it yourself as shown in this topic.

## Members

**cbSize**

The size, in bytes, of the structure.

**pMetadataBlob**

Optional pointer to [**CRYPT_DATA_BLOB**](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-crypt_integer_blob) specifying metadata.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------|
| Minimum supported client<br> | Windows 10 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2016 \[desktop apps only\] |
| DLL | Mssign32.dll

