# ICQueryAbout macro

## Syntax

```cpp
DWORD ICQueryAbout(
     hic
);
```

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns ICERR_OK if the driver supports this message or ICERR_UNSUPPORTED otherwise.

## Description

The **ICQueryAbout** macro queries a video compression driver to determine if it has an About dialog box. You can use this macro or explicitly call the [ICM_ABOUT](https://learn.microsoft.com/windows/desktop/Multimedia/icm-about) message.

## Parameters

### `hic`

Handle of the compressor.

## See also

[Video Compression Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-macros)

[Video Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-manager)