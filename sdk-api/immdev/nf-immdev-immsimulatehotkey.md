# ImmSimulateHotKey function

## Description

Simulates the specified IME hot key, causing the same response as if the user presses the hot key in the specified window.

## Parameters

### `HWND` [in]

Handle to the window.

### `DWORD` [in]

Identifier of the IME hot key. For more information, see [IME Hot Key Identifiers](https://learn.microsoft.com/windows/desktop/Intl/ime-hot-key-identifiers).

## Return value

Returns a nonzero value if successful, or 0 otherwise.

## See also

[Input Method Manager](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager)

[Input Method Manager Functions](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager-functions)