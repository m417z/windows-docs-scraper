# ID3D12DebugCommandList1::SetDebugParameter

## Description

Modifies optional Debug Layer settings of a command list.

## Parameters

### `Type`

Type: **[D3D12_DEBUG_COMMAND_LIST_PARAMETER_TYPE](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/ne-d3d12sdklayers-d3d12_debug_command_list_parameter_type)**

Specifies a [D3D12_DEBUG_COMMAND_LIST_PARAMETER_TYPE](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/ne-d3d12sdklayers-d3d12_debug_command_list_parameter_type) value that indicates which debug parameter data to set.

### `pData` [in]

Type: **const void***

Pointer to debug parameter data to set. The interpretation of this data depends on the [D3D12_DEBUG_COMMAND_LIST_PARAMETER_TYPE](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/ne-d3d12sdklayers-d3d12_debug_command_list_parameter_type) given in the *Type* parameter.

### `DataSize`

Type: **UINT**

Specifies the size in bytes of the debug parameter *pData*.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the [Direct3D 12 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d12/d3d12-graphics-reference-returnvalues).

## Remarks

Certain debug behaviors of D3D12 Debug Layer can be modified by setting debug parameters. These can be used to toggle extra validation or expose experimental debug features.

**ID3D12DebugCommandList1::SetDebugParameter** only impacts debug settings for the associated command list. For device-wide debug parameters see the [ID3D12DebugDevice1::SetDebugParameter](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/nf-d3d12sdklayers-id3d12debugdevice1-setdebugparameter) method.

Resetting a command list restores the debug parameters to the default values. This is because a command list reset is treated as equivalent to creating a new command list.

## See also

[GetDebugParameter](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/nf-d3d12sdklayers-id3d12debugcommandlist1-getdebugparameter)

[ID3D12DebugCommandList1](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/nn-d3d12sdklayers-id3d12debugcommandlist1)