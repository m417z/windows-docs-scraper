## Description

The **PROPSHEETUI_GETICON_INFO** structure is used as an input parameter to an application's [PFNPROPSHEETUI](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/nc-compstui-pfnpropsheetui)-typed function, when the function is called with a reason value of PROPSHEETUI_REASON_GET_ICON.

## Members

### `cbSize`

CPSUI-supplied size, in bytes, of the **PROPSHEETUI_GETICON_INFO** structure.

### `Flags`

Reserved.

### `cxIcon`

CPSUI-supplied icon width, in pixels.

### `cyIcon`

CPSUI-supplied icon height, in pixels.

### `hIcon`

Receives an application-supplied icon handle. If the icon is not loaded, the member must be set to zero.