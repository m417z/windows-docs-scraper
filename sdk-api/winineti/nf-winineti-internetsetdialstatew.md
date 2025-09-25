# InternetSetDialStateW function

## Description

Not supported.

This function is obsolete. Do not use.

## Parameters

### `lpszConnectoid`

Unused.

### `dwState`

Unused.

### `dwReserved`

Unused.

## Return value

This function does not return a value.

## Remarks

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

> [!NOTE]
> The winineti.h header defines InternetSetDialState as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).