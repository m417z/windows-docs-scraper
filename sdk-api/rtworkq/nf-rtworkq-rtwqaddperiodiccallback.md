# RtwqAddPeriodicCallback function

## Description

Sets a callback function to be called at a fixed interval.

## Parameters

### `Callback` [in]

Pointer to the callback function.

### `context`

Pointer to a caller-provided object that implements [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown), or **NULL**. This parameter is passed to the callback function.

### `key` [out, optional]

Receives a key that can be used to cancel the callback. To cancel the callback, call [RtwqRemovePeriodicCallback](https://learn.microsoft.com/windows/desktop/api/rtworkq/nf-rtworkq-rtwqremoveperiodiccallback) and pass this key as the *dwKey* parameter.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.