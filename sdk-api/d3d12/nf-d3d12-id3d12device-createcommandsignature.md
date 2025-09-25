# ID3D12Device::CreateCommandSignature

## Description

This method creates a command signature.

## Parameters

### `pDesc` [in]

Type: **const [D3D12_COMMAND_SIGNATURE_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_command_signature_desc)***

Describes the command signature to be created with the [D3D12_COMMAND_SIGNATURE_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_command_signature_desc) structure.

### `pRootSignature` [in, optional]

Type: **[ID3D12RootSignature](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12rootsignature)***

Specifies the [ID3D12RootSignature](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12rootsignature) that the command signature applies to.

The root signature is required if any of the commands in the signature will update bindings on the pipeline. If the only command present is a draw or dispatch, the root signature parameter can be set to NULL.

### `riid`

Type: **REFIID**

The globally unique identifier (**GUID**) for the command signature interface ([ID3D12CommandSignature](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12commandsignature)).
The **REFIID**, or **GUID**, of the interface to the command signature can be obtained by using the __uuidof() macro.
For example, __uuidof(**ID3D12CommandSignature**) will get the **GUID** of the interface to a command signature.

### `ppvCommandSignature` [out, optional]

Type: **void****

Specifies a pointer, that on successful completion of the method will point to the created command signature ([ID3D12CommandSignature](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12commandsignature)).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the [Direct3D 12 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d12/d3d12-graphics-reference-returnvalues).

## See also

[ID3D12Device](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12device)