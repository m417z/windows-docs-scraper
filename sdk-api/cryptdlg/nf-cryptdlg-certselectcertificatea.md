# CertSelectCertificateA function

## Description

The **CertSelectCertificate** function presents a dialog box that allows the user to select certificates from a set of certificates that match the given criteria.

**Note** This function has no associated import library. You must use the [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to CryptDlg.dll.

## Parameters

### `pCertSelectInfo` [in, out]

A pointer to a [CERT_SELECT_STRUCT](https://learn.microsoft.com/windows/win32/api/cryptdlg/ns-cryptdlg-cert_select_struct_a) structure that contains criteria that control the displayed certificates for selection and receives the selected certificate.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. For extended error information, call the
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## See also

[CERT_SELECT_STRUCT](https://learn.microsoft.com/windows/win32/api/cryptdlg/ns-cryptdlg-cert_select_struct_a)

## Remarks

> [!NOTE]
> The cryptdlg.h header defines CertSelectCertificate as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).