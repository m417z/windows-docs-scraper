# MFAddPeriodicCallback function

## Description

Sets a callback function to be called at a fixed interval.

## Parameters

### `Callback` [in]

Pointer to the callback function, of type [MFPERIODICCALLBACK](https://learn.microsoft.com/windows/desktop/api/mfapi/nc-mfapi-mfperiodiccallback).

### `pContext` [in]

Pointer to a caller-provided object that implements **IUnknown**, or **NULL**. This parameter is passed to the callback function.

### `pdwKey` [out]

Receives a key that can be used to cancel the callback. To cancel the callback, call [MFRemovePeriodicCallback](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfremoveperiodiccallback) and pass this key as the *dwKey* parameter.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The function succeeded. |

## Remarks

To get the timer interval for the periodic callback, call [MFGetTimerPeriodicity](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfgettimerperiodicity).

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)

[Work Queues](https://learn.microsoft.com/windows/desktop/medfound/work-queues)