# ICertPropertyEnrollment::get_CAName

## Description

The **CAName** property retrieves the common name (CN) of the certification authority (CA).

This property is read-only.

## Parameters

## Remarks

Set the **CAName** property by calling the [Initialize](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icertpropertyenrollment-initialize) method. The common name is returned to the client during the enrollment process and is part of the certification authority configuration string. For more information, see the [CAConfigString](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollment-get_caconfigstring) property on the [IX509Enrollment](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollment) interface.

You can also call the following properties to retrieve the other values specified during initialization:

* [CADnsName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icertpropertyenrollment-get_cadnsname)
* [FriendlyName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icertpropertyenrollment-get_friendlyname)
* [RequestId](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icertpropertyenrollment-get_requestid)

## See also

[ICertProperty](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertproperty)

[ICertPropertyEnrollment](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertpropertyenrollment)