# IMFTimer::CancelTimer

## Description

Cancels a timer that was set using the [IMFTimer::SetTimer](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imftimer-settimer) method.

## Parameters

### `punkKey` [in]

Pointer to the **IUnknown** interface that was returned in the *ppunkKey* parameter of the [SetTimer](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imftimer-settimer) method.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

Because the timer is dispatched asynchronously, the application's timer callback might get invoked even if this method succeeds.

## See also

[IMFTimer](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftimer)