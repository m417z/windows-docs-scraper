# ImmRequestMessageW function

## Description

Generates a [WM_IME_REQUEST](https://learn.microsoft.com/windows/desktop/Intl/wm-ime-request) message.

## Parameters

### `HIMC` [in]

Handle to the target input context.

### `WPARAM` [in]

Value of the *wParam* parameter for the [WM_IME_REQUEST](https://learn.microsoft.com/windows/desktop/Intl/wm-ime-request) message.

### `LPARAM` [in]

Value of the *lParam* parameter for the [WM_IME_REQUEST](https://learn.microsoft.com/windows/desktop/Intl/wm-ime-request) message.

## Return value

Returns an operation-specific value if successful, or 0 otherwise.

## Remarks

IME must use this function instead of sending the [WM_IME_REQUEST](https://learn.microsoft.com/windows/desktop/Intl/wm-ime-request) message to the application in a call to [SendMessage](https://learn.microsoft.com/previous-versions/windows/desktop/oe/oe-ihttpmailtransport-sendmessage).

> [!NOTE]
> The immdev.h header defines ImmRequestMessage as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Input Method Manager](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager)

[Input Method Manager Functions](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager-functions)

[WM_IME_REQUEST](https://learn.microsoft.com/windows/desktop/Intl/wm-ime-request)