# ICertPropertyEnrollment::Initialize

## Description

The **Initialize** method initializes the property from the certificate request ID, the certification authority (CA) configuration string, and an optional certificate display name.

## Parameters

### `RequestId` [in]

A **LONG** variable that contains the certificate request ID. A request ID is created by the enrollment process. You can retrieve this value by calling the [RequestId](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollment-get_requestid) property on the [IX509Enrollment](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollment) interface.

### `strCADnsName` [in]

A **BSTR** variable that contains the Domain Name System (DNS) name of the CA. This is the first name in the *CADnsName\CAName* CA configuration string. The configuration string is typically set during the enrollment process. The DNS name can be retrieved by calling the [CAConfigString](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollment-get_caconfigstring) property and separating the string into its constituent parts.

### `strCAName` [in]

A **BSTR** variable that contains the subject common name (CN) of the CA. This is the second name in the *CADnsName\CAName* CA configuration string. The configuration string is typically set during the enrollment process. The CN name can be retrieved by calling the [CAConfigString](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollment-get_caconfigstring) property and separating the string into its constituent parts.

### `strFriendlyName` [in, optional]

A **BSTR** variable that contains an optional display name for the certificate. The default value is **NULL**. This value is typically set during the enrollment process. You can retrieve it by calling the [CertificateFriendlyName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollment-get_certificatefriendlyname) property.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code/value | Description |
| --- | --- |
| **HRESULT_FROM_WIN32(ERROR_ALREADY_INITIALIZED)** | The object is already initialized. |

## Remarks

The values that you can use to initialize the [ICertPropertyEnrollment](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertpropertyenrollment) object are set during the certificate enrollment process when the client calls the [Enroll](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollment-enroll) method on the [IX509Enrollment](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollment) object. That is, to retrieve a request ID, call the [RequestId](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollment-get_requestid) property on the **IX509Enrollment** object. To retrieve a certificate display name, call the [CertificateFriendlyName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollment-get_certificatefriendlyname) property. To retrieve a distinguished name and common name, call the [CAConfigString](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollment-get_caconfigstring) property and separate the configuration string into its constituent parts.

Call the [SetValueOnCertificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icertproperty-setvalueoncertificate) method to associate the property with a certificate. You can also call the following properties to retrieve the values specified during initialization:

* [CADnsName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icertpropertyenrollment-get_cadnsname)
* [CAName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icertpropertyenrollment-get_caname)
* [FriendlyName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icertpropertyenrollment-get_friendlyname)
* [RequestId](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icertpropertyenrollment-get_requestid)

## See also

[ICertProperty](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertproperty)

[ICertPropertyEnrollment](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertpropertyenrollment)