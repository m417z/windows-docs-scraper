# ID3D12DebugCommandList1::GetDebugParameter

## Description

Gets optional Command List Debug Layer settings.

## Parameters

### `Type`

Type: **[D3D12_DEBUG_COMMAND_LIST_PARAMETER_TYPE](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/ne-d3d12sdklayers-d3d12_debug_command_list_parameter_type)**

Specifies a [D3D12_DEBUG_COMMAND_LIST_PARAMETER_TYPE](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/ne-d3d12sdklayers-d3d12_debug_command_list_parameter_type) value that determines which debug parameter data to copy to the memory pointed to by *pData*.

### `pData` [out]

Type: **void***

Points to the memory that will be filled with a copy of the debug parameter data. The interpretation of this data depends on the [D3D12_DEBUG_COMMAND_LIST_PARAMETER_TYPE](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/ne-d3d12sdklayers-d3d12_debug_command_list_parameter_type) given in the *Type* parameter.

### `DataSize`

Type: **UINT**

Size in bytes of the memory buffer pointed to by *pData*.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns S_OK if successful, otherwise E_INVALIDARG.

## See also

[ID3D12DebugCommandList1](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/nn-d3d12sdklayers-id3d12debugcommandlist1)

[SetDebugParameter](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/nf-d3d12sdklayers-id3d12debugcommandlist1-setdebugparameter)