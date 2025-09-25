## Description

**IDDCX_SYSTEM_BUFFER_INFO** holds the resulting buffer-specific information after a buffer release and acquire operation.

## Members

### `Size`

Size of this structure, in bytes.

### `Pitch`

The pitch (also called stride) of the surface, in number of bytes.

### `Height`

The height of the surface, in number of pixels.

### `Width`

The width of the surface, in number of pixels.

### `Format`

A [**DXGI_FORMAT**](https://learn.microsoft.com/windows/win32/api/dxgiformat/ne-dxgiformat-dxgi_format) structure that identifies the format of the surface pixel.

### `pBuffer`

Pointer in system memory to the surface buffer. **pBuffer** must be at least 16-byte aligned.

## Remarks

## See also

[**IDARG_OUT_RELEASEANDACQUIRESYSTEMBUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_out_releaseandacquiresystembuffer)

[**IddCxSwapChainReleaseAndAcquireSystemBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_out_releaseandacquiresystembuffer)