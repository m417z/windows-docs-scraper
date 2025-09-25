# MFGetTimerPeriodicity function

## Description

Retrieves the timer interval for the [MFAddPeriodicCallback](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfaddperiodiccallback) function.

## Parameters

### `Periodicity` [out]

Receives the timer interval, in milliseconds.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The function succeeded. |

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)

[Work Queues](https://learn.microsoft.com/windows/desktop/medfound/work-queues)