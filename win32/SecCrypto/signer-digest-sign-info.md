# SIGNER\_DIGEST\_SIGN\_INFO structure

The **SIGNER\_DIGEST\_SIGN\_INFO** structure contains information about digest signing. It contains a pointer to a digest signing function implemented within the provided dll, specified by the dwDigestSignChoice.

> [!Note]
> This structure is not defined in any header file. To use this structure, you must define it yourself as shown in this topic.

## Members

**cbSize**

The size, in bytes, of the structure.

**dwDigestSignChoice**

Specifies which digest sign implementation to use.

| Value | Meaning |
|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **DIGEST\_SIGN**

1 (0x1) | Use the DIGEST_SIGN implementation.\ | | **DIGEST\_SIGN\_WITHFILEHANDLE**

2 (0x2) | Use the DIGEST_SIGN_WITHFILEHANDLE implementation. \ | | **DIGEST\_SIGN\_EX**

3 (0x3) | Use the DIGEST_SIGN_EX implementation.\ | | **DIGEST\_SIGN\_EX\_WITHFILEHANDLE**

4 (0x4) |Use the DIGEST_SIGN_EX_WITHFILEHANDLE implementation.\ |

**pfnAuthenticodeDigestSign**

Pointer to the [**PFN_AUTHENTICODE_DIGEST_SIGN**](https://learn.microsoft.com/windows/win32/seccrypto/pfn-authenticode-digest-sign) callback function. Required if dwDigestSignChoice==DIGEST_SIGN.

**pfnAuthenticodeDigestSignWithFileHandle**

Pointer to the [**PFN_AUTHENTICODE_DIGEST_SIGN_WITHFILEHANDLE**](https://learn.microsoft.com/windows/win32/seccrypto/pfn-authenticode-digest-sign-withfilehandle) callback function. Required if dwDigestSignChoice==DIGEST_SIGN_WITHFILEHANDLE.

**pfnAuthenticodeDigestSignEx**

Pointer to the [**PFN_AUTHENTICODE_DIGEST_SIGN_EX**](https://learn.microsoft.com/windows/win32/seccrypto/pfn-authenticode-digest-sign-ex) callback function. Required if dwDigestSignChoice==DIGEST_SIGN_EX.

**pfnAuthenticodeDigestSignExWithFileHandle**

Pointer to the [**PFN_AUTHENTICODE_DIGEST_SIGN_EX_WITHFILEHANDLE**](https://learn.microsoft.com/windows/win32/seccrypto/pfn-authenticode-digest-sign-ex-withfilehandle) callback function. Required if dwDigestSignChoice==DIGEST_SIGN_EX_WITHFILEHANDLE.

**pMetadataBlob**

Optional pointer to [**CRYPT_DATA_BLOB**](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-crypt_integer_blob) specifying metadata.

**dwReserved**

Reserved. This value must be zero (0).

**dwReserved2**

Reserved. This value must be zero (0).

**dwReserved3**

Reserved. This value must be zero (0).

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------|
| Minimum supported client<br> | Windows 11 \[desktop apps only\]<br> |
| DLL<br> | Mssign32.dll <br> |