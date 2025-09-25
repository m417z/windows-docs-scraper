# RtwqUnregisterPlatformEvents function

## Description

Unregisters a listener event from the callback platform.

## Parameters

### `platformEvents`

Pointer to the [IRtwqPlatformEvents](https://learn.microsoft.com/windows/desktop/api/rtworkq/nn-rtworkq-irtwqplatformevents) object which provides the events.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The app should use the same pointer that was passed to [RtwqRegisterPlatformEvents](https://learn.microsoft.com/windows/win32/api/rtworkq/nf-rtworkq-rtwqregisterplatformevents).