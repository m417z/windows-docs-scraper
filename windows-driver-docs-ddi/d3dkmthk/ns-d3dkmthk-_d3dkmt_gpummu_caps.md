# D3DKMT_GPUMMU_CAPS structure

## Description

The **D3DKMT_GPUMMU_CAPS** structure describes the capabilities of the GPU MMU (memory management unit).

## Members

### `Flags`

Flags to indicate the type of capabilities.

### `Flags.ReadOnlyMemorySupported`

Indicates whether the GPU MMU supports read-only memory.

### `Flags.NoExecuteMemorySupported`

Indicates whether the GPU MMU supports marking memory as non-executable.

### `Flags.CacheCoherentMemorySupported`

Indicates whether the GPU MMU supports cache-coherent memory access.

### `Flags.Reserved`

Reserved for system use.

### `Flags.Value`

An alternative way to access the flags.

### `VirtualAddressBitCount`

The number of bits used for virtual addresses by the GPU MMU.

## See also

[**D3DKMTQueryAdapterInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtqueryadapterinfo)