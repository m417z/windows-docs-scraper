# RtwqCancelDeadline function

## Description

Cancels a deadline that was previously set with [RtwqSetDeadline](https://learn.microsoft.com/windows/desktop/api/rtworkq/nf-rtworkq-rtwqsetdeadline).

## Parameters

### `pRequest` [in]

Receives a handle to the request that can be used to cancel the request by calling **RtwqCancelDeadline**.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[RtwqSetDeadline](https://learn.microsoft.com/windows/desktop/api/rtworkq/nf-rtworkq-rtwqsetdeadline)