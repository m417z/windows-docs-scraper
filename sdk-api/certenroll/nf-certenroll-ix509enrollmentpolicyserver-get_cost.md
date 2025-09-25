# IX509EnrollmentPolicyServer::get_Cost

## Description

The **Cost** property specifies and retrieves an arbitrary cost for contacting the certificate enrollment policy server.

This property is read/write.

## Parameters

## Remarks

If multiple CEP servers have the same ID value (specified when the [Initialize](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollmentpolicyserver-initialize) method is called), the server with the lowest cost is contacted first.

## See also

[IX509EnrollmentPolicyServer](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollmentpolicyserver)