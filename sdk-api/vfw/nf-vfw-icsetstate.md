# ICSetState macro

## Syntax

```cpp
DWORD ICSetState(
     hic,
     pv,
     cb
);
```

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns the number of bytes used by the compressor if successful or zero otherwise.

## Description

The **ICSetState** macro notifies a video compression driver to set the state of the compressor. You can use this macro or explicitly call the [ICM_SETSTATE](https://learn.microsoft.com/windows/desktop/Multimedia/icm-setstate) message.

## Parameters

### `hic`

Handle of the compressor.

### `pv`

Pointer to a block of memory containing configuration data. You can specify **NULL** for this parameter to reset the compressor to its default state.

### `cb`

Size, in bytes, of the block of memory.

## Remarks

The information used by this message is private and specific to a given compressor. Client applications should use this message only to restore information previously obtained with the [ICGetState](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-icgetstate) and [ICConfigure](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-icconfigure) macros and should use the **ICConfigure** macro to adjust the configuration of a video compression driver.

## See also

[Video Compression Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-macros)

[Video Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-manager)