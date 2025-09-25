# MCIWndOpen macro

## Syntax

```cpp
LONG MCIWndOpen(
     hwnd,
     sz,
     f
);
```

## Return value

Type: **LONG**

Returns zero if successful or an error otherwise.

## Description

The **MCIWndOpen** macro opens an MCI device and associates it with an MCIWnd window. For MCI devices that use data files, this macro can also open a specified data file, name a new file to be created, or display a dialog box to let the user select a file to open. You can use this macro or explicitly send the [MCIWNDM_OPEN](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-open) message.

## Parameters

### `hwnd`

Handle of the MCIWnd window.

### `sz`

Pointer to a null-terminated string identifying the filename or MCI Device Names to open. Specify −1 for this parameter to display the Open dialog box.

### `f`

Flags associated with the device or file to open. The MCIWNDOPENF_NEW flag specifies a new file is to be created with the name specified in szFile.