# MCIWndEnd macro

## Syntax

```cpp
LONG MCIWndEnd(
     hwnd
);
```

## Return value

Type: **LONG**

Returns zero if successful or an error otherwise.

## Description

The **MCIWndEnd** macro moves the current position to the end of the content. You can use this macro or explicitly send the [MCI_SEEK](https://learn.microsoft.com/windows/desktop/Multimedia/mci-seek) message.

## Parameters

### `hwnd`

Handle of the MCIWnd window.

## See also

[MCI_SEEK](https://learn.microsoft.com/windows/desktop/Multimedia/mci-seek)