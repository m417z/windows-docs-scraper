# IX509Enrollment2::get_RequestIdString

## Description

The **RequestIdString** property retrieves a string that contains a unique identifier for the certificate request sent to the certification enrollment server (CES).

This property is read-only.

## Parameters

## Remarks

The value of the **RequestIdString** property is set during the enrollment process. It can be used during subsequent communication between the client and the CES. For example, if a CES marks a request as pending when initially submitted, the client can use the request ID string when it again contacts the CES and attempts to retrieve the certificate response.

## See also

[IX509Enrollment2](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollment2)