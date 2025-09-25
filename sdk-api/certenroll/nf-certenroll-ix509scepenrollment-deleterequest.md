# IX509SCEPEnrollment::DeleteRequest

## Description

Delete any certificates or keys created for the request.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

You must set the [TransactionId](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509scepenrollment-get_transactionid) property and call the [InitializeForPending](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509scepenrollment-initializeforpending) method before calling this method.

## See also

[IX509SCEPEnrollment](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509scepenrollment)