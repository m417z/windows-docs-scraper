# IX509SCEPEnrollment::CreateRetrievePendingMessage

## Description

Create a message for certificate polling (manual enrollment).

## Parameters

### `Encoding` [in]

### `pValue` [out, retval]

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

You must call the [InitializeForPending](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509scepenrollment-initializeforpending) method before calling this method.

## See also

[IX509SCEPEnrollment](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509scepenrollment)