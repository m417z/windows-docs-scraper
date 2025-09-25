# PFND3D12DDI_CREATEDEVICE_0003 callback function

## Description

The PFND3D12DDI_CREATEDEVICE_0003 function creates a graphics context that is referenced in subsequent calls.

## Parameters

### `unnamedParam1`

A handle to the graphics adapter object that was created with the [PFND3D12DDI_OPENADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_openadapter) function.

### `unnamedParam2`

A pointer to a [D3D12DDIARG_CREATEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_createdevice_0003) structure.

## Return value

PFND3D12DDI_CREATEDEVICE_0003 returns one of the following values:

| **Return code** | **Description** |
|:--|:--|
| **S_OK** | The graphics context was successfully created. |
| **DXGI_STATUS_NO_REDIRECTION** | The graphics context was successfully created. However, the DirectX Graphics Infrastructure (DXGI) should not use the shared resource presentation path to effect communication with the Desktop Windows Manager (DWM). For more information about the DXGI DDI, see [Supporting the DXGI DDI](https://learn.microsoft.com/windows-hardware/drivers/display/supporting-the-dxgi-ddi) . |
| **E_OUTOFMEMORY** | PFND3D12DDI_CREATEDEVICE_0003 could not allocate the memory that was required for it to complete. |