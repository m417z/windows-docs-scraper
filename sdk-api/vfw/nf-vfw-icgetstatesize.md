# ICGetStateSize macro

## Syntax

```cpp
DWORD ICGetStateSize(
     hic
);
```

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns the amount of memory, in bytes, required by the state information.

## Description

The **ICGetStateSize** macro queries a video compression driver to determine the amount of memory required to retrieve the configuration information. You can use this macro or explicitly call the [ICM_GETSTATE](https://learn.microsoft.com/windows/desktop/Multimedia/icm-getstate) message.

## Parameters

### `hic`

Handle of the compressor.

## Remarks

The structure used to represent configuration information is driver specific and is defined by the driver.

Use **ICGetStateSize** before calling the [ICGetState](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-icgetstate) macro to determine the size of buffer to allocate for the call.

## See also

[Video Compression Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-macros)

[Video Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-manager)