# EnrollmentEnrollStatus enumeration

## Description

The **EnrollmentEnrollStatus** enumeration type specifies the enrollment status of a [certificate request](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly). This enumeration is used by the [Status](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollmentstatus-get_status) property on the [IX509EnrollmentStatus](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollmentstatus) interface.

## Constants

### `Enrolled:0x1`

The enrollment succeeded, and the certificate has been issued.

### `EnrollPended:0x2`

The request has been submitted and the enrollment is pending, or the request has been issued out of band.

### `EnrollUIDeferredEnrollmentRequired:0x4`

Enrollment must be deferred.

### `EnrollError:0x10`

An error occurred.

### `EnrollUnknown:0x20`

The enrollment status is unknown.

### `EnrollSkipped:0x40`

The status information has been skipped. This can occur if a [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) is not valid or has not been selected for monitoring.

### `EnrollDenied:0x100`

Enrollment has been denied.

## See also

[CertEnroll Enumerations](https://learn.microsoft.com/windows/desktop/SecCertEnroll/certenroll-enumerations)

[CertEnroll Interfaces](https://learn.microsoft.com/windows/desktop/SecCertEnroll/certenroll-interfaces)

[EnrollmentSelectionStatus](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-enrollmentselectionstatus)

[IX509EnrollmentStatus](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollmentstatus)