# ICertPropertyEnrollment::get_FriendlyName

## Description

The **FriendlyName** property retrieves the display name of the certificate.

This property is read-only.

## Parameters

## Remarks

Set the **FriendlyName** property by calling the [Initialize](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icertpropertyenrollment-initialize) method. The display name is specified during the enrollment process. For more information, see the [CertificateFriendlyName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollment-get_certificatefriendlyname) property on the [IX509Enrollment](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollment) interface.

You can also call the following properties to retrieve the other values specified during initialization:

* [CADnsName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icertpropertyenrollment-get_cadnsname)
* [CAName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icertpropertyenrollment-get_caname)
* [RequestId](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icertpropertyenrollment-get_requestid)

## See also

[ICertProperty](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertproperty)

[ICertPropertyEnrollment](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertpropertyenrollment)