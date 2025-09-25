# InitCommonControlsEx function

## Description

Ensures that the common control DLL (Comctl32.dll) is loaded, and registers specific common control classes from the DLL. An application must call this function before creating a common control.

## Parameters

### `picce` [in]

Type: **const LPINITCOMMONCONTROLSEX**

A pointer to an [INITCOMMONCONTROLSEX](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-initcommoncontrolsex) structure that contains information specifying which control classes will be registered.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns **TRUE** if successful, or **FALSE** otherwise.

## Remarks

The effect of each call to **InitCommonControlsEx** is cumulative. For example, if **InitCommonControlsEx** is called with the [ICC_UPDOWN_CLASS](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-initcommoncontrolsex) flag, then is later called with the [ICC_HOTKEY_CLASS](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-initcommoncontrolsex) flag, the result is that both the up-down and hot key common control classes are registered and available to the application.