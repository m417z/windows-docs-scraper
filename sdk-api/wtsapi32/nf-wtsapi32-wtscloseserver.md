# WTSCloseServer function

## Description

Closes an open handle to a Remote Desktop Session Host (RD Session Host) server.

## Parameters

### `hServer` [in]

A handle to an RD Session Host server opened by a call to the
[WTSOpenServer](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsopenservera) or [WTSOpenServerEx](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsopenserverexa) function.

Do not pass **WTS_CURRENT_SERVER_HANDLE** for this parameter.

## Remarks

Call the **WTSCloseServer** function as part of your program's clean-up routine to
close all the server handles opened by calls to the [WTSOpenServer](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsopenservera) or [WTSOpenServerEx](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsopenserverexa) function.

After the handle has been closed, it cannot be used with any other WTS APIs.

## See also

[WTSOpenServer](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsopenservera)