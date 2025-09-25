# EnrollmentSelectionStatus enumeration

## Description

The **EnrollmentSelectionStatus** enumeration type specifies whether the enrollment status of an object will be monitored during the enrollment process. Cryptographic providers, individual enrollment objects in a collection, and [certification authorities](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) are often monitored and their status displayed in a user interface. A value of this enumeration can be specified or retrieved by using the [Selected](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollmentstatus-get_selected) property on the [IX509EnrollmentStatus](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollmentstatus) interface. An **IX509EnrollmentStatus** object can be retrieved from the [IX509Enrollment](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollment) and [ICspStatus](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspstatus) objects.

## Constants

### `SelectedNo:0`

The enrollment status is not monitored.

### `SelectedYes:1`

The enrollment status is monitored.

## See also

[CertEnroll Enumerations](https://learn.microsoft.com/windows/desktop/SecCertEnroll/certenroll-enumerations)

[CertEnroll Interfaces](https://learn.microsoft.com/windows/desktop/SecCertEnroll/certenroll-interfaces)

[IX509EnrollmentStatus](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollmentstatus)