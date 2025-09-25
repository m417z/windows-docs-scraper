# RtwqRemovePeriodicCallback function

## Description

Cancels a callback function that was set by the [RtwqAddPeriodicCallback](https://learn.microsoft.com/windows/desktop/api/rtworkq/nf-rtworkq-rtwqaddperiodiccallback) function.

## Parameters

### `dwKey` [in]

Key that identifies the callback. This value is retrieved by the [RtwqAddPeriodicCallback](https://learn.microsoft.com/windows/desktop/api/rtworkq/nf-rtworkq-rtwqaddperiodiccallback) function.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.