# MFRemovePeriodicCallback function

## Description

Cancels a callback function that was set by the [MFAddPeriodicCallback](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfaddperiodiccallback) function.

## Parameters

### `dwKey` [in]

Key that identifies the callback. This value is retrieved by the [MFAddPeriodicCallback](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfaddperiodiccallback) function.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The function succeeded. |

## Remarks

The callback is dispatched on another thread, and this function does not attempt to synchronize with the callback thread. Therefore, it is possible for the callback to be invoked after this function returns.

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)

[Work Queues](https://learn.microsoft.com/windows/desktop/medfound/work-queues)