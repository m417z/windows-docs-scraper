# D3D12DDI_RENDER_PASS_ENDING_ACCESS_SUSPEND_LOCAL_READ_PARAMETERS structure

## Description

Specifies the kernel size of the read, or how many surrounding pixels are needed.

> [!NOTE]
> The parameters here must match those on the [D3D12DDI_RENDER_PASS_BEGINNING_ACCESS_RESUME_LOCAL_READ_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_render_pass_beginning_access_resume_local_read_parameters) structure.

## Members

### `AdditionalWidth`

The width in pixels. '0' means no pixels on either side, '1' pixel means one pixel on each side, for a total of three pixels of width.

### `AdditionalHeight`

The height in pixels.

## Remarks

## See also