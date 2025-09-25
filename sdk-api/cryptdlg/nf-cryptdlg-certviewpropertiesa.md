# CertViewPropertiesA function

## Description

[The **CertViewProperties** function is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use the [CryptUIDlgViewContext](https://learn.microsoft.com/windows/desktop/api/cryptuiapi/nf-cryptuiapi-cryptuidlgviewcontext) function.]

The **CertViewProperties** function displays the properties for a certificate in a user interface (UI) dialog box. This function has no associated import library. You must use the [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to CryptDlg.dll.

**Note** This function has no associated import library. You must use the [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to CryptDlg.dll.

## Parameters

### `pCertViewInfo` [in]

A pointer to a [CERT_VIEWPROPERTIES_STRUCT](https://learn.microsoft.com/windows/desktop/api/cryptdlg/ns-cryptdlg-cert_viewproperties_struct_a) structure that contains the information about the certificate to view.

## Return value

The return value is **TRUE** if the function is successful; **FALSE** if the function fails.

## Remarks

> [!NOTE]
> The cryptdlg.h header defines CertViewProperties as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).