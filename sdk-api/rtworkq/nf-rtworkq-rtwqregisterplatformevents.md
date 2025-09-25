# RtwqRegisterPlatformEvents function

## Description

Enables an app to listen to the [RtwqStartup](https://learn.microsoft.com/windows/desktop/api/rtworkq/nf-rtworkq-rtwqstartup) and [RtwqShutdown](https://learn.microsoft.com/windows/desktop/api/rtworkq/nf-rtworkq-rtwqshutdown) functions.

## Parameters

### `platformEvents` [in]

Pointer to the [IRtwqPlatformEvents](https://learn.microsoft.com/windows/desktop/api/rtworkq/nn-rtworkq-irtwqplatformevents) object which provides the events.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.