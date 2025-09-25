# _D3DKMT_CREATEDCFROMMEMORY structure

## Description

The D3DKMT_CREATEDCFROMMEMORY structure describes parameters for creating the display context.

## Members

### `pMemory` [in]

A pointer to a block of memory for the display context.

### `Format` [in]

A [D3DDDIFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddiformat)-typed value that indicates the pixel format for the memory block that **pMemory** points to.

### `Width` [in]

The width, in pixels, of the memory block that **pMemory** points to.

### `Height` [in]

The height, in pixels, of the memory block that **pMemory** points to.

### `Pitch` [in]

The pitch, in bytes, of the memory block that **pMemory** points to--that is, the distance in bytes to the start of the next line.

### `hDeviceDc` [in]

A handle to the display context for the device.

### `pColorTable` [in]

An array of 2, 4, 16, or 256 PALETTEENTRY structures that are used to initialize the colors for the memory block that **pMemory** points to. For more information about PALETTEENTRY, see the Microsoft Window SDK documentation.

### `hDc` [out]

A handle to the display context. The OpenGL runtime generates a handle and passes it back to the driver.

### `hBitmap` [out]

A handle to a bitmap that is related to the display context. The OpenGL runtime generates a handle and passes it back to the driver.

## See also

[D3DDDIFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddiformat)

[D3DKMTCreateDCFromMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreatedcfrommemory)