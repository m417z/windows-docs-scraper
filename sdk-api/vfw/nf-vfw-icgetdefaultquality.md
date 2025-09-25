# ICGetDefaultQuality macro

## Syntax

```cpp
DWORD ICGetDefaultQuality(
     hic,
     wParam
);
```

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns ICERR_OK if the driver supports this message or ICERR_UNSUPPORTED otherwise.

## Description

The **ICGetDefaultQuality** macro queries a video compression driver to provide its default quality setting. You can use this macro or explicitly call the [ICM_GETDEFAULTQUALITY](https://learn.microsoft.com/windows/desktop/Multimedia/icm-getdefaultquality) message.

## Parameters

### `hic`

Handle to a compressor.

#### - wParam

Address to contain the default quality value. Quality values range from 0 to 10,000.

## Remarks

The **ICGetDefaultQuality** macro returns the default quality value.

## See also

[Video Compression Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-macros)

[Video Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-manager)