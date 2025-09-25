# GET_RAWINPUT_CODE_WPARAM macro

## Syntax

```cpp
WPARAM GET_RAWINPUT_CODE_WPARAM(
    WPARAM wParam
);
```

## Description

Retrieves the input code from *wParam* in [WM_INPUT](https://learn.microsoft.com/windows/desktop/inputdev/wm-input) message.

## Parameters

### `wParam`

*wParam* from [WM_INPUT](https://learn.microsoft.com/windows/desktop/inputdev/wm-input) message.

## Return value

Input code value. Can be one of the following:

| Value | Meaning |
| -------------------- | --------------------------------------------------------------- |
| **RIM\_INPUT** 0 | Input occurred while the application was in the foreground. |
| **RIM\_INPUTSINK** 1 | Input occurred while the application was not in the foreground. |

## See also

**Conceptual**

[RAWINPUT](https://learn.microsoft.com/windows/win32/api/winuser/ns-winuser-rawinput)

[Raw Input](https://learn.microsoft.com/windows/desktop/inputdev/raw-input)

**Reference**

[WM_INPUT](https://learn.microsoft.com/windows/desktop/inputdev/wm-input)