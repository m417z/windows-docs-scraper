# RtwqLockPlatform function

## Description

Adds a reference to indicate to the platform that there are still pending asynchronous items. Blocks the [RtwqShutdown](https://learn.microsoft.com/windows/desktop/api/rtworkq/nf-rtworkq-rtwqshutdown) function if there are active asynchronous items.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.