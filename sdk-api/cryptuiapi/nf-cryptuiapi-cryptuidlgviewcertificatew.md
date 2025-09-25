# CryptUIDlgViewCertificateW function

## Description

The **CryptUIDlgViewCertificate** function presents a dialog box that displays a specified certificate.

## Parameters

### `pCertViewInfo` [in]

A pointer to a [CRYPTUI_VIEWCERTIFICATE_STRUCT](https://learn.microsoft.com/windows/win32/api/cryptuiapi/ns-cryptuiapi-cryptui_viewcertificate_structa) structure that contains information about the certificate to view.

### `pfPropertiesChanged` [out]

Indicates whether any certificate properties were modified by the caller.

## Return value

If the function succeeds, the return value is nonzero (**TRUE**).

If the function fails, the return value is zero (**FALSE**). For extended error information, call the
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## See also

[CRYPTUI_VIEWCERTIFICATE_STRUCT](https://learn.microsoft.com/windows/win32/api/cryptuiapi/ns-cryptuiapi-cryptui_viewcertificate_structa)

## Remarks

> [!NOTE]
> The cryptuiapi.h header defines CryptUIDlgViewCertificate as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).