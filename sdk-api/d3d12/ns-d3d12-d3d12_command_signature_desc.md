# D3D12_COMMAND_SIGNATURE_DESC structure

## Description

Describes the arguments (parameters) of a command signature.

## Members

### `ByteStride`

Specifies the size of each command in the drawing buffer, in bytes.

### `NumArgumentDescs`

Specifies the number of arguments in the command signature.

### `pArgumentDescs`

An array of [D3D12_INDIRECT_ARGUMENT_DESC](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_indirect_argument_desc) structures,
containing details of the arguments, including whether the argument is a vertex buffer, constant, constant buffer view, shader resource view, or unordered access view.

### `NodeMask`

For single GPU operation, set this to zero. If there are multiple GPU nodes, set bits to identify the nodes (the device's physical adapters) for which the command signature is to apply.
Each bit in the mask corresponds to a single node.
Refer to [Multi-adapter systems](https://learn.microsoft.com/windows/win32/direct3d12/multi-engine).

## Remarks

Use this structure by [CreateCommandSignature](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device-createcommandsignature).

## See also

[Core Structures](https://learn.microsoft.com/windows/win32/direct3d12/direct3d-12-structures)