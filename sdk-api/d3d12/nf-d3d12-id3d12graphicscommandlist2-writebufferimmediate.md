# ID3D12GraphicsCommandList2::WriteBufferImmediate

## Description

Writes a number of 32-bit immediate values to the specified buffer locations directly from the command stream.

## Parameters

### `Count`

The number of [D3D12_WRITEBUFFERIMMEDIATE_PARAMETER](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_writebufferimmediate_parameter) structures that are pointed to by *pParams* and *pModes*.

### `pParams` [in]

The address of an array containing a number of [D3D12_WRITEBUFFERIMMEDIATE_PARAMETER](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_writebufferimmediate_parameter) structures equal to *Count*.

### `pModes` [in, optional]

The address of an array containing a number of [D3D12_WRITEBUFFERIMMEDIATE_MODE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_writebufferimmediate_mode) structures equal to *Count*. The default value is **null**; passing **null** causes the system to write all immediate values using **D3D12_WRITEBUFFERIMMEDIATE_MODE_DEFAULT**.

## Remarks

**WriteBufferImmediate** performs *Count* number of 32-bit writes: one for each value and destination specified in *pParams*.

The receiving buffer (resource) must be in the **D3D12_RESOURCE_STATE_COPY_DEST** state to be a valid destination for **WriteBufferImmediate**.

## See also

[ID3D12GraphicsCommandList2](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12graphicscommandlist2)