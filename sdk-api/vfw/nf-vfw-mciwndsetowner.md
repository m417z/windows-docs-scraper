# MCIWndSetOwner macro

## Syntax

```cpp
LONG MCIWndSetOwner(
     hwnd,
     hwndP
);
```

## Return value

Type: **LONG**

Returns zero.

## Description

The **MCIWndSetOwner** macro sets the window to receive notification messages associated with the MCIWnd window. You can use this macro or explicitly send the [MCIWNDM_SETOWNER](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-setowner) message.

## Parameters

### `hwnd`

Handle of the MCIWnd window.

### `hwndP`

Handle of the window to receive the notification messages.