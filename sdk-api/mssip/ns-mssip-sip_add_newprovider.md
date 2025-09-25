# SIP_ADD_NEWPROVIDER structure

## Description

The **SIP_ADD_NEWPROVIDER** structure defines a [subject interface package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SIP). This structure is used by the [CryptSIPAddProvider](https://learn.microsoft.com/windows/desktop/api/mssip/nf-mssip-cryptsipaddprovider) function.

## Members

### `cbStruct`

The size, in bytes, of this structure. Set this value to `sizeof(SIP_ADD_NEWPROVIDER)`.

### `pgSubject`

Pointer to the GUID that identifies the SIP.

### `pwszDLLFileName`

Pointer to a null-terminated string that contains the name of the DLL file.

### `pwszMagicNumber`

This member is not used.

### `pwszIsFunctionName`

Pointer to a null-terminated string that contains the name of the function that determines whether the file contents are supported by this SIP. This member can be **NULL**. The signature for this function pointer is described in [pfnIsFileSupported](https://learn.microsoft.com/windows/desktop/api/mssip/nc-mssip-pfnisfilesupported).

### `pwszGetFuncName`

Pointer to a null-terminated string that contains the name of the function that retrieves the signed data. The signature for this function pointer is described in [CryptSIPGetSignedDataMsg](https://learn.microsoft.com/windows/desktop/api/mssip/nf-mssip-cryptsipgetsigneddatamsg).

### `pwszPutFuncName`

Pointer to a null-terminated string that contains the name of the function that stores the [Authenticode](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) signature in the target file. The signature for this function pointer is described in [CryptSIPPutSignedDataMsg](https://learn.microsoft.com/windows/desktop/api/mssip/nf-mssip-cryptsipputsigneddatamsg).

### `pwszCreateFuncName`

Pointer to a null-terminated string that contains the name of the function that creates the hash. The signature for this function pointer is described in [CryptSIPCreateIndirectData](https://learn.microsoft.com/windows/desktop/api/mssip/nf-mssip-cryptsipcreateindirectdata).

### `pwszVerifyFuncName`

Pointer to a null-terminated string that contains the name of the function that verifies the hash. The signature for this function pointer is described in [CryptSIPVerifyIndirectData](https://learn.microsoft.com/windows/desktop/api/mssip/nf-mssip-cryptsipverifyindirectdata).

### `pwszRemoveFuncName`

Pointer to a null-terminated string that contains the name of the function that removes the signed data. The signature for this function pointer is described in [CryptSIPRemoveSignedDataMsg](https://learn.microsoft.com/windows/desktop/api/mssip/nf-mssip-cryptsipremovesigneddatamsg).

### `pwszIsFunctionNameFmt2`

Pointer to a null-terminated string that contains the name of the function that determines whether the file name extension is supported by this SIP. This member can be **NULL**. The signature for this function pointer is described in [pfnIsFileSupportedName](https://learn.microsoft.com/windows/desktop/api/mssip/nc-mssip-pfnisfilesupportedname).

### `pwszGetCapFuncName`

Pointer to a null-terminated string that contains the name of the function that determines the capabilities of the SIP. If this parameter is set to **NULL**, multiple signatures are not available for this SIP. The signature for this function pointer is described in [pCryptSIPGetCaps](https://learn.microsoft.com/windows/desktop/api/mssip/nc-mssip-pcryptsipgetcaps).

**Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This member is not available.

## See also

[CryptSIPAddProvider](https://learn.microsoft.com/windows/desktop/api/mssip/nf-mssip-cryptsipaddprovider)