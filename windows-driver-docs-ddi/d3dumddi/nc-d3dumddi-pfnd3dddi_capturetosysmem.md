# PFND3DDDI_CAPTURETOSYSMEM callback function

## Description

The **CaptureToSysMem** function copies the contents of a capture buffer to a destination surface.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

pData [in]

A pointer to a [D3DDDIARG_CAPTURETOSYSMEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_capturetosysmem) structure that describes the parameters of the bit-block transfer (bitblt).

## Return value

**CaptureToSysMem** returns one of the following values:

| **Return code** | **Description** |
|:--|:--|
| **S_OK** | All resources for the bitblt are in GPU-accessible memory. |
| **E_OUTOFMEMORY** | [CaptureToSysMem]() could not allocate the required memory for it to complete. |

## Remarks

The **CaptureToSysMem** function is similar to the [Blt](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_blt) function except that **CaptureToSysMem** supports copying only from a capture buffer.

## See also

[D3DDDIARG_CAPTURETOSYSMEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_capturetosysmem)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)