# IX509SCEPEnrollment::ProcessResponseMessage

## Description

Process a response message and return the disposition of the message.

## Parameters

### `strResponse` [in]

### `Encoding` [in]

### `pDisposition` [out, retval]

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

You must call the [Initialize](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509scepenrollment-initialize) and [CreateRequestMessage](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509scepenrollment-createrequestmessage) methods or the [InitializeForPending](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509scepenrollment-initializeforpending) method before calling this method.

## See also

[IX509SCEPEnrollment](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509scepenrollment)