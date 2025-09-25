# PFND3D12DDI_SET_PREDICATION callback function

## Description

The *pfnSetPredication* callback function denotes that subsequent video operations and resource manipulation commands are not actually performed if the resulting predicate data of the predicate is equal to the operation specified.

## Parameters

### `unnamedParam1`

*hCommandList*

A handle to the driver's data for the command list. The driver uses this region of memory to store internal data structures that are related to its command list.

### `unnamedParam2`

*hResource*

The handle of a resource.

### `unnamedParam3`

### `unnamedParam4`

*PredicationOp*

A predication operation. For more information, see the [D3D12DDI_PREDICATION_OP](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_predication_op) enumeration.

## See also

[D3D12DDI_PREDICATION_OP](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_predication_op)