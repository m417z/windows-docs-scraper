# ICConfigure macro

## Syntax

```cpp
DWORD ICConfigure(
     hic,
     hwnd
);
```

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns ICERR_OK if the driver supports this macro or ICERR_UNSUPPORTED otherwise.

## Description

The **ICConfigure** macro notifies a video compression driver to display its configuration dialog box. You can use this macro or explicitly send the [ICM_CONFIGURE](https://learn.microsoft.com/windows/desktop/Multimedia/icm-configure) message.

## Parameters

### `hic`

Handle of the compressor.

### `hwnd`

Handle of the parent window of the displayed dialog box.

## Remarks

The [ICM_CONFIGURE](https://learn.microsoft.com/windows/desktop/Multimedia/icm-configure) message is different from the [DRV_CONFIGURE](https://learn.microsoft.com/windows/desktop/Multimedia/drv-configure) message used for hardware configuration. The dialog box for this message should let the user set and edit the internal state referenced by the [ICGetState](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-icgetstate) and [ICSetState](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-icsetstate) macros. For example, this dialog box can let the user change parameters affecting the quality level and other similar compression options.

## See also

[Video Compression Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-macros)

[Video Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-manager)