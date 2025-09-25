## Description

Queries reflection metadata about available meta commands.

## Parameters

### `pNumMetaCommands`

Type: [in, out] **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

A pointer to a [UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types) containing the number of meta commands to query for. This field determines the size of the *pDescs* array, unless *pDescs* is **nullptr**.

### `pDescs`

Type: [out, optional] **[D3D12_META_COMMAND_DESC](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_meta_command_desc)\***

An optional pointer to an array of [D3D12_META_COMMAND_DESC](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_meta_command_desc) containing the descriptions of the available meta commands. Pass `nullptr` to have the number of available meta commands returned in *pNumMetaCommands*.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an [HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes) error code.

## See also

[ID3D12Device5](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12device5)