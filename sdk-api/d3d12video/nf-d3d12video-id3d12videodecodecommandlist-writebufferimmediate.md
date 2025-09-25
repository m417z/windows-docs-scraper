# ID3D12VideoDecodeCommandList::WriteBufferImmediate

## Description

Writes a number of 32-bit immediate values to the specified buffer locations directly from the command stream.

## Parameters

### `Count`

The number of elements in the *pParams* and *pModes* arrays.

### `pParams`

The address of an array of [D3D12_WRITEBUFFERIMMEDIATE_PARAMETER](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_writebufferimmediate_parameter) structures of size *Count*.

### `pModes`

The address of an array of [D3D12_WRITEBUFFERIMMEDIATE_MODE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_writebufferimmediate_mode) structures of size *Count*. The default value is **null**. Passing **null** causes the system to write all immediate values using **D3D12_WRITEBUFFERIMMEDIATE_MODE_DEFAULT**.

## Remarks

The capability for this feature is specified with [D3D12_FEATURE_DATA_D3D12_OPTIONS3::WriteBufferImmediateSupportFlags](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_feature_data_d3d12_options3)

## See also