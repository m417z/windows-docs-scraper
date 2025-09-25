# WTSOpenServerExW function

## Description

Opens a handle to the specified Remote Desktop Session Host (RD Session Host) server or Remote Desktop Virtualization Host (RD Virtualization Host) server.

## Parameters

### `pServerName` [in]

A pointer to a null-terminated string that contains the NetBIOS name of the server.

## Return value

If the function succeeds, the return value is a handle to the specified server.

If the function fails, it returns an invalid handle. You can test the validity of the handle by using it in another function call.

## Remarks

If the server specified by the *pServerName* parameter is an RD Session Host server, the behavior of this function is identical to that of the [WTSOpenServer](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsopenservera) function.

To work with sessions running on virtual machines on the RD Virtualization Host server on which the calling application is running, specify **WTS_CURRENT_SERVER_NAME** for the *pServerName* parameter.

When you have finished using the handle returned by this function, release it by calling the [WTSCloseServer](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtscloseserver) function.

> [!NOTE]
> The wtsapi32.h header defines WTSOpenServerEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[WTSCloseServer](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtscloseserver)

[WTSOpenServer](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsopenservera)