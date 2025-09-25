# D3D12DDI_LOCAL_ROOT_SIGNATURE_0054 structure

## Description

Describes a local root signature.

## Members

### `hLocalRootSignature`

A handle to the local root signature.

## Remarks

For ray tracing shaders, bindings can be defined by one or both of the following root signatures:

* A local root signature, whose arguments come from shader tables, enabling each shader to have unique arguments.
* A root signature whose arguments are shared across all raytracing shaders and compute PSOs on CommandLists, set via [SetRootSignature](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_set_root_signature).

Each ray tracing shader used together can use different local root signatures but must use the same root signature.

## See also