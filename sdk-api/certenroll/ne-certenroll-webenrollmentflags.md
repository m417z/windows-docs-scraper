# WebEnrollmentFlags enumeration

## Description

The **WebEnrollmentFlags** enumeration specifies web enrollment behavior. It is used by the [Enroll](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollmenthelper-enroll) method on the [IX509EnrollmentHelper](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollmenthelper) interface.

## Constants

### `EnrollPrompt:0x1`

If this flag is set and no authentication credential is available for the certificate enrollment server, the certificate service prompts for a credential. If there is no authentication credential and this flag is not set, the [Enroll](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollmenthelper-enroll) method fails.

## See also

[Enroll](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollmenthelper-enroll)

[IX509EnrollmentHelper](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollmenthelper)