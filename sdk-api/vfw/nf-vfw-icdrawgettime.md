# ICDrawGetTime macro

## Syntax

```cpp
DWORD ICDrawGetTime(
     hic,
     lplTime
);
```

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns ICERR_OK if successful or an error otherwise.

## Description

The **ICDrawGetTime** macro requests a rendering driver that controls the timing of drawing frames to return the current value of its internal clock. You can use this macro or explicitly call the [ICM_DRAW_GETTIME](https://learn.microsoft.com/windows/desktop/Multimedia/icm-draw-gettime) message.

## Parameters

### `hic`

Handle to a driver.

### `lplTime`

Address to contain the current time. The return value should be specified in samples.

## Remarks

This message is generally supported by hardware that performs its own asynchronous decompression, timing, and drawing. The message can also be sent if the hardware is being used as the synchronization master.

## See also

[Video Compression Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-macros)

[Video Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-manager)