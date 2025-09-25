# ICGetState macro

## Syntax

```cpp
DWORD ICGetState(
     hic,
     pv,
     cb
);
```

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

If _pv_ is **NULL**, returns the amount of memory, in bytes, required for configuration information.If _pv_ is not **NULL**, returns ICERR_OK if successful or an error otherwise.

## Description

The **ICGetState** macro queries a video compression driver to return its current configuration in a block of memory. You can use this macro or explicitly call the [ICM_GETSTATE](https://learn.microsoft.com/windows/desktop/Multimedia/icm-getstate) message.

## Parameters

### `hic`

Handle of the compressor.

### `pv`

Pointer to a block of memory to contain the current configuration information. You can specify **NULL** for this parameter to determine the amount of memory required for the configuration information, as in [ICGetStateSize](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-icgetstatesize).

### `cb`

Size, in bytes, of the block of memory.

## Remarks

The [ICGetStateSize](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-icgetstatesize) macro returns the number of bytes used by the state data.

The structure used to represent configuration information is driver specific and is defined by the driver.

Use [ICGetStateSize](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-icgetstatesize) before calling the **ICGetState** macro to determine the size of buffer to allocate for the call.

## See also

[Video Compression Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-macros)

[Video Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-manager)