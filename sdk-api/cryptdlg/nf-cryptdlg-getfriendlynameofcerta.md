# GetFriendlyNameOfCertA function

## Description

[The **GetFriendlyNameOfCert** function is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use the [CertGetNameString](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetnamestringa) function with the CERT_NAME_FRIENDLY_DISPLAY_TYPE flag.]

The **GetFriendlyNameOfCert** function retrieves the display name for a certificate.

**Note** This function has no associated import library. You must use the [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to CryptDlg.dll.

## Parameters

### `pccert` [in]

A pointer to the certificate context whose display name is being retrieved.

### `pch` [out]

A pointer to a character string that receives the display name for the certificate.

### `cch` [in]

Number of characters allocated for *pchBuffer*, including the terminating **NULL** character.

## Return value

The return value is the number of characters, including the terminating **NULL** character, in the returned display name.

## Remarks

> [!NOTE]
> The cryptdlg.h header defines GetFriendlyNameOfCert as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).