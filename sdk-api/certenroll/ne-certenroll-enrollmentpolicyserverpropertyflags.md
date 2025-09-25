# EnrollmentPolicyServerPropertyFlags enumeration

## Description

The **EnrollmentPolicyServerPropertyFlags** enumeration specifies the default policy server. It is used by the [Initialize](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icertpropertyenrollmentpolicyserver-initialize) method on the [ICertPropertyEnrollmentPolicyServer](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertpropertyenrollmentpolicyserver) interface.

## Constants

### `DefaultNone:0`

No default policy server URL has been specified.

### `DefaultPolicyServer:0x1`

The policy server URL returned by [GetPolicyServerUrl](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icertpropertyenrollmentpolicyserver-getpolicyserverurl) is the default value when an URL has not been specified.

## See also

[ICertPropertyEnrollmentPolicyServer](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertpropertyenrollmentpolicyserver)

[Initialize](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icertpropertyenrollmentpolicyserver-initialize)