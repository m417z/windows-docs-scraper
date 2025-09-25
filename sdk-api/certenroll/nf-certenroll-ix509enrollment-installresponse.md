# IX509Enrollment::InstallResponse

## Description

The **InstallResponse** method installs a certificate chain on the end-entity computer. The byte array that contains the response is encoded by using [Distinguished Encoding Rules](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DER) as defined by the [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) standard. You must specify the DER-encoded byte array in a string that is either a pure binary sequence or is Unicode encoded. This method is web enabled.

## Parameters

### `Restrictions` [in]

An [InstallResponseRestrictionFlags](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-installresponserestrictionflags) enumeration value that specifies the type of certificates that can be installed. This can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| ****AllowNone**** | Do not install untrusted certificates or certificates for which there is no corresponding request. |
| ****AllowNoOutstandingRequest**** | Create the [private key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) from the certificate response rather than from the dummy certificate. This makes the dummy certificate optional. If this value is not set, the dummy certificate must exist, and the private key is extracted from it. |
| ****AllowUntrustedCertificate**** | Install untrusted end entity and [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) certificates. Certification authority certificates include root and subordinate CA certificates. End entity certificates are installed to the personal store, and CA certificates are installed to the certification authority store. |
| ****AllowUntrustedRoot**** | Perform the same action as the **AllowUntrustedCertificate** flag but also installs the certificate even if the certificate chain cannot be built because the root is not trusted.<br><br>**Note** On Windows Vista, the behavior of this flag is the same as that defined for the **AllowUntrustedCertificate** flag. Beginning with Windows Vista with SP1, you can install a certificate that chains up to an untrusted root. |

### `strResponse` [in]

A **BSTR** variable that contains the DER-encoded response.

### `Encoding` [in]

An [EncodingType](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-encodingtype) enumeration value that specifies the type of encoding applied to the string that contains the DER-encoded response.

### `strPassword` [in, optional]

An optional password for the certificate installation. This can be **NULL** or an empty string to indicate that no password is used. If there is a password, clear it from memory when you have finished using it by calling the [SecureZeroMemory](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa366877(v=vs.85)) function. For more information about protecting the password, see [Handling Passwords](https://learn.microsoft.com/windows/desktop/SecBP/handling-passwords).

Beginning with Windows 8 and Windows Server 2012, a **NULL** or empty password may mean that the PFX packet was created in the [PFXExportCertStoreEx](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-pfxexportcertstoreex) function by using the **PKCS12_PROTECT_TO_DOMAIN_SIDS** flag. If so, the PFX was encrypted to an Active Directory group. For more information, see **PFXExportCertStoreEx** and [PFXImportCertStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-pfximportcertstore).

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | This method was called from the web and either **AllowNoOutstandingRequest** or **AllowUntrustedCertificate** was specified in the *Restrictions* parameter. |
| **HRESULT_FROM_WIN32(ERROR_ARITHMETIC_OVERFLOW** | The length of the string that contains the password exceeds 64 kilobytes. |
| **OLE_E_BLANK** | The enrollment object has not been initialized. |

## Remarks

The **InstallResponse** method:

1. Retrieves the dummy certificate from the external store.
2. Retrieves the certificate contained in the response and installs it on the computer.
3. Copies properties from the dummy certificate in the external store onto the newly installed certificate in the personal store.

Before calling the **InstallResponse** method, you must initialize the [IX509Enrollment](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollment) object by calling one of the following methods.

* [Initialize](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollment-initialize)
* [InitializeFromRequest](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollment-initializefromrequest)
* [InitializeFromTemplateName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollment-initializefromtemplatename)

If you call this method from the web, you can specify only **AllowNone** or **AllowUntrustedRoot** in the *Restrictions* parameter. If you specify **AllowNoOutstandingRequest** or **AllowUntrustedCertificate**, the method returns an **E_ACCESSDENIED** error.

## See also

[IX509Enrollment](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollment)