# ICAbout macro

## Syntax

```cpp
DWORD ICAbout(
     hic,
     hwnd
);
```

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns ICERR_OK if the driver supports this message or ICERR_UNSUPPORTED otherwise.

## Description

The **ICAbout** macro notifies a video compression driver to display its About dialog box. You can use this macro or explicitly call the [ICM_ABOUT](https://learn.microsoft.com/windows/desktop/Multimedia/icm-about) message.

## Parameters

### `hic`

Handle of the compressor.

### `hwnd`

Handle of the parent window of the displayed dialog box.

You can also determine if a driver has an About dialog box by specifying -1 in this parameter, as in the [ICQueryAbout](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-icqueryabout) macro. The driver returns ICERR_OK if it has an About dialog box or ICERR_UNSUPPORTED otherwise.

## See also

[Video Compression Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-macros)

[Video Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-manager)