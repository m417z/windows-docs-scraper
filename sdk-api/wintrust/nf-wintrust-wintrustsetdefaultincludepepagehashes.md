# WintrustSetDefaultIncludePEPageHashes function

## Description

The **WintrustSetDefaultIncludePEPageHashes** function sets the default setting that determines whether page hashes are included when creating subject interface package (SIP) indirect data for PE files.

This setting is only used if neither the **SPC_EXC_PE_PAGE_HASHES_FLAG** or the **SPC_INC_PE_PAGE_HASHES_FLAG** flag is specified in the *dwFlags* parameter of the [SignerSignEx](https://learn.microsoft.com/windows/desktop/SecCrypto/signersignex) function.

 This function has no associated import library. You must use the [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Wintrust.dll.

## Parameters

### `fIncludePEPageHashes` [in]

Determines whether page hashes are included when creating SIP indirect data for PE files. If this parameter is nonzero, page hashes are included. If this parameter is zero, page hashes are not included. The value is zero by default.

## Remarks

This setting applies to each instance of Wintrust.dll.

## See also

[SignerSignEx](https://learn.microsoft.com/windows/desktop/SecCrypto/signersignex)