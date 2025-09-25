# IForegroundTransfer::AllowForegroundTransfer

## Description

Yields the foreground window to the COM server process.

## Parameters

### `lpvReserved` [in]

This parameter is reserved and must be **NULL**.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_INVALIDARG** | The *lpvReserved* parameter is not **NULL**, or this interface is on a proxy that does not support foreground control. |

## See also

[CoAllowSetForegroundWindow](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-coallowsetforegroundwindow)

[IForegroundTransfer](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iforegroundtransfer)