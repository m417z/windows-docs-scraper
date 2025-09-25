# IX509Enrollment::get_RequestId

## Description

The **RequestId** property retrieves a unique identifier for the certificate request sent to the certification authority by the [Enroll](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollment-enroll) method.

This property is read-only.

## Parameters

## Remarks

The value of the **RequestId** property is set during the enrollment process. It can be used during subsequent communication between the client and the CA. For example, if a CA marks a request as pending when initially submitted, the client can use the request ID and the configuration string when it again contacts the CA and attempts to retrieve the certificate response. To retrieve the configuration string, call the [CAConfigString](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollment-get_caconfigstring) property.

## See also

[IX509Enrollment](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollment)