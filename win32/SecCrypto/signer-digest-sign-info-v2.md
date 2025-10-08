# SIGNER\_DIGEST\_SIGN\_INFO_V2 structure

The **SIGNER\_DIGEST\_SIGN\_INFO_V2** structure contains information about digest signing. It contains a pointer to a digest signing function implemented within the provided dll, specified by the dwDigestSignChoice.

> [!Note]
> This structure is not defined in any header file. To use this structure, you must define it yourself as shown in this topic.

## Members

**cbSize**

The size, in bytes, of the structure.

**pfnAuthenticodeDigestSign**

Pointer to the [**PFN_AUTHENTICODE_DIGEST_SIGN**](https://learn.microsoft.com/windows/win32/seccrypto/pfn-authenticode-digest-sign) callback function. Required if the caller of SignerSignEx3 specifies SPC_DIGEST_SIGN_FLAG in the dwFlags parameter.

**pfnAuthenticodeDigestSignEx**

Pointer to the [**PFN_AUTHENTICODE_DIGEST_SIGN_EX**](https://learn.microsoft.com/windows/win32/seccrypto/pfn-authenticode-digest-sign-ex) callback function. Required if the caller of SignerSignEx3 specifies SPC_DIGEST_SIGN_EX_FLAG in the dwFlags parameter.

**pMetadataBlob**

Optional pointer to [**CRYPT_DATA_BLOB**](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-crypt_integer_blob) specifying metadata.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------|
| Minimum supported client<br> | Windows 10 May 2020 Update \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2022 \[desktop apps only\]<br> |
| DLL | Mssign32.dll

  -->