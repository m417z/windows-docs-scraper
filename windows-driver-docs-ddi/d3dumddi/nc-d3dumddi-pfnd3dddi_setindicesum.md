# PFND3DDDI_SETINDICESUM callback function

## Description

The *SetIndicesUM* function sets the current index buffer to the given user memory buffer.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*IndexSize* [in]

The size, in bytes, of the indices that are contained in the index buffer. The value of this parameter is 2 if the indices are 16-bit quantities or 4 if the indices are 32-bit quantities.

### `unnamedParam3`

*pUMBuffer* [in]

A pointer to the user-memory buffer that supplies the indices for the index buffer.

## Return value

*SetIndicesUM* returns S_OK or an appropriate error result if the index buffer is not successfully set to the given user memory buffer.

## See also

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)