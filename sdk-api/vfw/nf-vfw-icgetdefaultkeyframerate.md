# ICGetDefaultKeyFrameRate macro

## Syntax

```cpp
DWORD ICGetDefaultKeyFrameRate(
     hic,
     wParam
);
```

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns ICERR_OK if the driver supports this message or ICERR_UNSUPPORTED otherwise.

## Description

The **ICGetDefaultKeyFrameRate** macro queries a video compression driver for its default (or preferred) key-frame spacing. You can use this macro or explicitly call the [ICM_GETDEFAULTKEYFRAMERATE](https://learn.microsoft.com/windows/desktop/Multimedia/icm-getdefaultkeyframerate) message.

## Parameters

### `hic`

Handle to a compressor.

#### - wParam

Address to contain the preferred key-frame spacing.

## Remarks

The **ICGetDefaultKeyFrameRate** macro returns the default key frame rate.

## See also

[Video Compression Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-macros)

[Video Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-manager)