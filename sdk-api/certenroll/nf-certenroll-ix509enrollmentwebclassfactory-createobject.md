# IX509EnrollmentWebClassFactory::CreateObject

## Description

The **CreateObject** method can be used to create an object in the user context on a webpage.

## Parameters

### `strProgID` [in]

A **BSTR** variable that contains the Prog ID. The following table shows the strings you can use for each object that can be created by using this method.

| Object | Prog ID string |
| --- | --- |
| **[ICertProperties](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertproperties)** | "X509Enrollment.CCertProperties" |
| **[ICertPropertyDescription](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertpropertydescription)** | "X509Enrollment.CCertPropertyDescription" |
| **[ICertPropertyFriendlyName](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertpropertyfriendlyname)** | "X509Enrollment.CCertPropertyFriendlyName" |
| **[ICspInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspinformation)** | "X509Enrollment.CCspInformation" |
| **[ICspInformations](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspinformations)** | "X509Enrollment.CCspInformations" |
| **[ICspStatus](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspstatus)** | "X509Enrollment.CCspStatus" |
| **[IObjectId](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-iobjectid)** | "X509Enrollment.CObjectId" |
| **[IObjectIds](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-iobjectids)** | "X509Enrollment.CObjectIds" |
| **[ISignerCertificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-isignercertificate)** | "X509Enrollment.CSignerCertificate" |
| **[IX500DistinguishedName](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix500distinguishedname)** | "X509Enrollment.CX500DistinguishedName" |
| **[IX509CertificateRequestCmc](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestcmc)** | "X509Enrollment.CX509CertificateRequestCmc" |
| **[IX509CertificateRequestPkcs10](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestpkcs10)** | "X509Enrollment.CX509CertificateRequestPkcs10" |
| **[IX509CertificateRequestPkcs7](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestpkcs7)** | "X509Enrollment.CX509CertificateRequestPkcs7" |
| **[IX509Enrollment](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollment)** | "X509Enrollment.CX509Enrollment" |
| **[IX509EnrollmentHelper](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollmenthelper)** | "X509Enrollment.CX509EnrollmentHelper" |
| **[IX509Extension](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509extension)** | "X509Enrollment.CX509Extension" |
| **[IX509ExtensionEnhancedKeyUsage](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509extensionenhancedkeyusage)** | "X509Enrollment.CX509ExtensionEnhancedKeyUsage" |
| **[IX509ExtensionKeyUsage](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509extensionkeyusage)** | "X509Enrollment.CX509ExtensionKeyUsage" |
| **[IX509Extensions](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509extensions)** | "X509Enrollment.CX509Extensions" |
| **[IX509ExtensionTemplate](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509extensiontemplate)** | "X509Enrollment.CX509ExtensionTemplate" |
| **[IX509ExtensionTemplateName](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509extensiontemplatename)** | "X509Enrollment.CX509ExtensionTemplateName" |
| **[IX509PrivateKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509privatekey)** | "X509Enrollment.CX509PrivateKey" |

### `ppIUnknown` [out]

Address of a variable that receives a pointer to an **IUnknown** interface that represents the created object.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code | Description |
| --- | --- |
| **E_NOINTERFACE** | The Prog ID specified represents an object that cannot be created by using this method. |

## See also

[IX509EnrollmentWebClassFactory](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollmentwebclassfactory)