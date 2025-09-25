# WTSOpenServerA function

## Description

Opens a handle to the specified Remote Desktop Session Host (RD Session Host) server.

## Parameters

### `pServerName` [in]

Pointer to a null-terminated string specifying the NetBIOS name of the RD Session Host server.

## Return value

If the function succeeds, the return value is a handle to the specified server.

If the function fails, it returns a handle that is not valid. You can test the validity of the handle by using it in another function call.

## Remarks

When you have finished using the handle returned by
**WTSOpenServer**, release it by calling the [WTSCloseServer](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtscloseserver) function.

You do not need to open a handle for operations performed on the RD Session Host server on which your application is running. Use the constant **WTS_CURRENT_SERVER_HANDLE** instead.

> [!NOTE]
> The wtsapi32.h header defines WTSOpenServer as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[WTSCloseServer](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtscloseserver)