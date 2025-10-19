# IX509Enrollment2::InstallResponse2

## Description

The **InstallResponse2** method installs a certificate chain on the end-entity computer. The byte array that contains the response is encoded by using [Distinguished Encoding Rules](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DER) as defined by the [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) standard. You must specify the DER-encoded byte array in a string that is either a pure binary sequence or is Unicode encoded. This method is web enabled.

## Parameters

### `Restrictions` [in]

An [InstallResponseRestrictionFlags](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-installresponserestrictionflags) enumeration value that specifies the type of certificates that can be installed. This can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **AllowNone** | Do not install untrusted certificates or certificates for which there is no corresponding request. |
| **AllowNoOutstandingRequest** | Create the [private key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) from the certificate response rather than from the dummy certificate. This makes the dummy certificate optional. If this value is not set, the dummy certificate must exist, and the private key is extracted from it. |
| **AllowUntrustedCertificate** | Install untrusted end entity and [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) certificates. Certification authority certificates include root and subordinate CA certificates. End entity certificates are installed to the personal store, and CA certificates are installed to the certification authority store. |
| **AllowUntrustedRoot** | Perform the same action as the **AllowUntrustedCertificate** flag but also installs the certificate even if the certificate chain cannot be built because the root is not trusted.<br><br>**Note** On Windows Vista, the behavior of this flag is the same as that defined for the **AllowUntrustedCertificate** flag. You can install an untrusted root beginning with Windows Vista with SP1. |

### `strResponse` [in]

A **BSTR** variable that contains the DER-encoded response.

### `Encoding` [in]

An [EncodingType](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-encodingtype) enumeration value that specifies the type of encoding applied to the string that contains the DER-encoded response.

### `strPassword` [in, optional]

An optional password for the certificate installation. This can be **NULL** to indicate that no password is used. When you have finished using the password, clear it from memory by calling the [SecureZeroMemory](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa366877(v=vs.85)) function. For more information about protecting the password, see [Handling Passwords](https://learn.microsoft.com/windows/desktop/SecBP/handling-passwords).

### `strEnrollmentPolicyServerUrl` [in]

A **BSTR** that contains the URL of the certificate enrollment policy (CEP) server.

### `strEnrollmentPolicyServerID` [in]

A **BSTR** that contains an identifier for the CEP server.

### `EnrollmentPolicyServerFlags` [in]

A [PolicyServerUrlFlags](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-policyserverurlflags) enumeration value. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **PsfLocationGroupPolicy** | The CEP server URL is specified in group policy by an administrator. |
| **PsfLocationRegistry** | The CEP server URL is specified in the registry. |
| **PsfUseClientId** | Specifies that certificate enrollments and renewals include client specific data in a **ClientId** attribute. Examples include the name of the cryptographic service provider, the Windows version number, the user name, the computer DNS name, and the domain controller DNS name. This flag can be set by group policy.<br><br>This flag has been included to address privacy concerns that can arise during enrollment to servers that are managed by administrators other than those who manage the forest in which the user resides. By not setting this flag, you can prevent sending personal information to non-local administrators. |
| **PsfAutoEnrollmentEnabled** | Automatic certificate enrollment is enabled. |
| **PsfAllowUnTrustedCA** | Specifies that the certificate of the issuing CA need not be trusted by the client to install a certificate signed by the CA. |

### `authFlags` [in]

An [X509EnrollmentAuthFlags](https://learn.microsoft.com/windows/desktop/api/certcli/ne-certcli-x509enrollmentauthflags) enumeration value that specifies the client authentication type. For Windows 7, only **X509AuthCertificate** can be chosen from the following values.

| Value | Meaning |
| --- | --- |
| **X509AuthAnonymous** | Anonymous authentication. |
| **X509AuthKerberos** | Kerberos authentication. |
| **X509AuthUsername** | Clear text user name and password authentication.<br><br>**Note** The user name and password are encrypted before transmission and are stored securely in the credential vault on the CEP server. |
| **X509AuthCertificate** | Client authentication certificate installed on the local computer and used by the server to verify the identity of the client. |

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | This method was called from the web and either **AllowNoOutstandingRequest** or **AllowUntrustedCertificate** was specified in the *Restrictions* parameter. |
| **HRESULT_FROM_WIN32(ERROR_ARITHMETIC_OVERFLOW** | The length of the string that contains the password exceeds 64 kilobytes. |
| **OLE_E_BLANK** | The enrollment object has not been initialized. |

## Remarks

The **InstallResponse2** method:

1. Retrieves the dummy certificate from the external store.
2. Retrieves the certificate contained in the response and installs it on the computer.
3. Copies properties from the dummy certificate in the external store onto the newly installed certificate in the personal store.

Before calling the **InstallResponse2** method, you must initialize the [IX509Enrollment](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollment) object by calling one of the following methods.

* [Initialize](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollment-initialize)
* [InitializeFromRequest](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollment-initializefromrequest)
* [InitializeFromTemplate](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollment2-initializefromtemplate)
* [InitializeFromTemplateName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollment-initializefromtemplatename)

If you call this method from the web, you can specify only **AllowNone** or **AllowUntrustedRoot** in the *Restrictions* parameter. If you specify **AllowNoOutstandingRequest** or **AllowUntrustedCertificate**, the method returns an **E_ACCESSDENIED** error.

The last four parameters (*strEnrollmentPolicyServerUrl*, *strEnrollmentPolicyServerID*, *EnrollmentPolicyServerFlags*, and *authFlags*) are not included in the [InstallResponse](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollment-installresponse) method. They enable you to add a property value to the installed certificate in much the same way as the [ICertPropertyEnrollmentPolicyServer](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertpropertyenrollmentpolicyserver) interface does.

## See also

[IX509Enrollment2](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollment2)