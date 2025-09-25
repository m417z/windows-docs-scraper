# CertAddEncodedCertificateToSystemStoreA function

## Description

The **CertAddEncodedCertificateToSystemStore** function opens the specified system store and adds the encoded certificate to it.

## Parameters

### `szCertStoreName` [in]

A null-terminated string that contains the name of the system store for the encoded certificate.

### `pbCertEncoded` [in]

A pointer to a buffer that contains the encoded certificate to add.

### `cbCertEncoded` [in]

The size, in bytes, of the *pbCertEncoded* buffer.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. **CertAddEncodedCertificateToSystemStore** depends on the functions listed in the following remarks for error handling. Refer to those function topics for their respective error handling behaviors. For extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Internally, **CertAddEncodedCertificateToSystemStore** calls [CertOpenSystemStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certopensystemstorea) and [CertAddEncodedCertificateToStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddencodedcertificatetostore) with the following parameters.

| [CertOpenSystemStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certopensystemstorea) Parameter | Value |
| --- | --- |
| *szSubsystemProtocol* | *szCertStoreName* |

If **CertAddEncodedCertificateToSystemStore** obtains a handle to the specified system store, it calls [CertCloseStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certclosestore) to close the handle before it returns.

| [CertAddEncodedCertificateToStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddencodedcertificatetostore) Parameter | Value |
| --- | --- |
| *dwCertEncodingType* | **X509_ASN_ENCODING** |
| *dwAddDisposition* | **CERT_STORE_ADD_USE_EXISTING** |
| *ppCertContext* | **NULL** |

> [!NOTE]
> The wincrypt.h header defines CertAddEncodedCertificateToSystemStore as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).