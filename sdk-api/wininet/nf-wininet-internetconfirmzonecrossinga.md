# InternetConfirmZoneCrossingA function

## Description

Checks for changes between secure and nonsecure URLs. Always inform the user when a change occurs in security between two URLs. Typically, an application should allow the user to acknowledge the change through interaction with a dialog box.

## Parameters

### `hWnd` [in]

Handle to the parent window for any required dialog box.

### `szUrlPrev` [in]

Pointer to a null-terminated string that specifies the URL that was viewed before the current request was made.

### `szUrlNew` [in]

Pointer to a null-terminated string that specifies the new URL that the user has requested to view.

### `bPost` [in]

Not implemented.

## Return value

Returns one of the following values.

| Return code | Description |
| --- | --- |
| **ERROR_SUCCESS** | The user confirmed that it was okay to continue, or there was no user input required. |
| **ERROR_CANCELLED** | The user canceled the request. |
| **ERROR_NOT_ENOUGH_MEMORY** | There is not enough memory to carry out the request. |

## Remarks

 Always inform the user when a change in security level occurs, or you risk subjecting the user to involuntary information disclosure.

Like all other aspects of the WinINet API, this function cannot be safely called from within DllMain or the constructors and destructors of global objects.

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

> [!NOTE]
> The wininet.h header defines InternetConfirmZoneCrossing as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Enabling Internet Functionality](https://learn.microsoft.com/windows/desktop/WinInet/enabling-internet-functionality)

[WinINet Functions](https://learn.microsoft.com/windows/desktop/WinInet/wininet-functions)