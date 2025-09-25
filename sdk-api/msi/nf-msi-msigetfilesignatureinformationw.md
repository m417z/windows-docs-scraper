# MsiGetFileSignatureInformationW function

## Description

The
**MsiGetFileSignatureInformation** function takes the path to a file that has been digitally signed and returns the file's signer certificate and hash.
**MsiGetFileSignatureInformation** may be called to obtain the signer certificate and hash needed to populate the
[MsiDigitalCertificate](https://learn.microsoft.com/windows/desktop/Msi/msidigitalcertificate-table), [MsiPatchCertificate](https://learn.microsoft.com/windows/desktop/Msi/msipatchcertificate-table), and
[MsiDigitalSignature](https://learn.microsoft.com/windows/desktop/Msi/msidigitalsignature-table) tables.

**Windows Installer 3.0 and later:** Beginning with Windows Installer 3.0, the Windows Installer can verify the digital signatures of patches (.msp files) by using the [MsiPatchCertificate](https://learn.microsoft.com/windows/desktop/Msi/msipatchcertificate-table) and [MsiDigitalCertificate](https://learn.microsoft.com/windows/desktop/Msi/msidigitalcertificate-table) tables. For more information see [Guidelines for Authoring Secure Installations](https://learn.microsoft.com/windows/desktop/Msi/guidelines-for-authoring-secure-installations) and [User Account Control (UAC) Patching](https://learn.microsoft.com/windows/desktop/Msi/user-account-control--uac--patching).

**Windows Installer 2.0:** Digital signatures of patches is not supported. Windows Installer 2.0 uses digital signatures as a means to detect corrupted resources, and can only verify the digital signatures of external cabinets, and only by the use of the [MsiDigitalSignature](https://learn.microsoft.com/windows/desktop/Msi/msidigitalsignature-table) and [MsiDigitalCertificate](https://learn.microsoft.com/windows/desktop/Msi/msidigitalcertificate-table) tables.

## Parameters

### `szSignedObjectPath` [in]

Pointer to a null-terminated string specifying the full path to the file that contains the digital signature.

### `dwFlags` [in]

Special error case flags.

| Flag | Meaning |
| --- | --- |
| **MSI_INVALID_HASH_IS_FATAL**<br><br>0x1 | Without this flag set, and when requesting only the certificate context, an invalid hash in the digital signature does not cause **MsiGetFileSignatureInformation** to return a fatal error. <br><br>To return a fatal error for an invalid hash, set the MSI_INVALID_HASH_IS_FATAL flag. |

### `ppcCertContext` [out]

Returned signer certificate context

### `pbHashData` [out]

Returned hash buffer. This parameter can be **NULL** if the hash data is not being requested.

### `pcbHashData` [in, out]

Pointer to a variable that specifies the size, in bytes, of the buffer pointed to by the *pbHashData* parameter. This parameter cannot be **NULL** if *pbHashData* is non-**NULL**. If ERROR_MORE_DATA is returned, *pbHashData* gives the size of the buffer required to hold the hash data. If ERROR_SUCCESS is returned, it gives the number of bytes written to the hash buffer. The *pcbHashData* parameter is ignored if *pbHashData* is **NULL**.

## Return value

| Value | Meaning |
| --- | --- |
| **ERROR_SUCCESS/S_OK** | Successful completion. |
| **ERROR_INVALID_PARAMETER** | Invalid parameter was specified. |
| **ERROR_FUNCTION_FAILED** | [WinVerifyTrust](https://learn.microsoft.com/windows/desktop/api/wintrust/nf-wintrust-winverifytrust) is not available on the system. **MsiGetFileSignatureInformation** requires the presence of the Wintrust.dll file on the system. |
| **ERROR_MORE_DATA** | A buffer is too small to hold the requested data. If ERROR_MORE_DATA is returned, *pcbHashData* gives the size of the buffer required to hold the hash data. |
| **TRUST_E_NOSIGNATURE** | File is not signed |
| **TRUST_E_BAD_DIGEST** | The file's current hash is invalid according to the hash stored in the file's digital signature. |
| **CERT_E_REVOKED** | The file's signer certificate has been revoked. The file's digital signature is compromised. |
| **TRUST_E_SUBJECT_NOT_TRUSTED** | The subject failed the specified verification action. Most trust providers return a more detailed error code that describes the reason for the failure. |
| **TRUST_E_PROVIDER_UNKNOWN** | The trust provider is not recognized on this system. |
| **TRUST_E_ACTION_UNKNOWN** | The trust provider does not support the specified action. |
| **TRUST_E_SUBJECT_FORM_UNKNOWN** | The trust provider does not support the form specified for the subject. |

**MsiGetFileSignatureInformation** also returns all the Win32 error values mapped to their equivalent **HRESULT** data type by
**HRESULT_FROM_WIN32**.

## Remarks

When requesting only the certificate context, an invalid hash in the digital signature does not cause
**MsiGetFileSignatureInformation** to return a fatal error. To return a fatal error for an invalid hash, set the MSI_INVALID_HASH_IS_FATAL flag in the *dwFlags* parameter.

The certificate context and hash information is extracted from the file by a call to [WinVerifyTrust](https://learn.microsoft.com/windows/desktop/api/wintrust/nf-wintrust-winverifytrust). The *ppcCertContext* parameter is a duplicate of the signer certificate context from the signature. It is the responsibility of the caller to call *CertFreeCertificateContext* to free the certificate context when finished.

Note that
**MsiGetFileSignatureInformation** requires the presence of the Wintrust.dll file on the system.

> [!NOTE]
> The msi.h header defines MsiGetFileSignatureInformation as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Digital Signatures and Windows Installer](https://learn.microsoft.com/windows/desktop/Msi/digital-signatures-and-windows-installer)

[MsiDigitalCertificate table](https://learn.microsoft.com/windows/desktop/Msi/msidigitalcertificate-table)

[MsiDigitalSignature table](https://learn.microsoft.com/windows/desktop/Msi/msidigitalsignature-table)