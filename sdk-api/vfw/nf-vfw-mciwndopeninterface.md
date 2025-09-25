# MCIWndOpenInterface macro

## Syntax

```cpp
LONG MCIWndOpenInterface(
     hwnd,
     pUnk
);
```

## Return value

Type: **LONG**

Returns zero if successful or an error otherwise.

## Description

The **MCIWndOpenInterface** macro attaches the data stream or file associated with the specified interface to an MCIWnd window. You can use this macro or explicitly send the [MCIWNDM_OPENINTERFACE](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-openinterface) message.

## Parameters

### `hwnd`

Handle of the MCIWnd window.

### `pUnk`

Pointer to an IAVI interface that points to a file or a data stream in a file.