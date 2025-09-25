# ICertPropertyEnrollment::get_RequestId

## Description

The **RequestId** property retrieves a unique certificate request identifier.

This property is read-only.

## Parameters

## Remarks

Set the **RequestId** property by calling the [Initialize](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icertpropertyenrollment-initialize) method. The request ID is created during the enrollment process. For more information, see the [RequestId](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollment-get_requestid) property on the [IX509Enrollment](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollment) interface.

The ID can be used during subsequent communication between the client and the CA. For example, if a CA marks a request as pending when initially submitted, the client can use the request ID and the configuration string when it again contacts the CA and attempts to retrieve the certificate response.

You can also call the following properties to retrieve the other values specified during initialization:

* [CADnsName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icertpropertyenrollment-get_cadnsname)
* [CAName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icertpropertyenrollment-get_caname)
* [FriendlyName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icertpropertyenrollment-get_friendlyname)

## See also

[ICertProperty](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertproperty)

[ICertPropertyEnrollment](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertpropertyenrollment)