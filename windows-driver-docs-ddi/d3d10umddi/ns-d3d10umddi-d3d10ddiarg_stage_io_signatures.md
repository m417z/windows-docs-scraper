# D3D10DDIARG_STAGE_IO_SIGNATURES structure

## Description

The D3D10DDIARG_STAGE_IO_SIGNATURES structure describes an I/O signature.

## Members

### `pInputSignature` [in]

An array of [D3D10DDIARG_SIGNATURE_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_signature_entry) structures for the input part of a signature.

### `NumInputSignatureEntries` [in]

The number of entries in the array that the **pInputSignature** member specifies.

### `pOutputSignature` [in]

An array of [D3D10DDIARG_SIGNATURE_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_signature_entry) structures for the output part of a signature.

### `NumOutputSignatureEntries` [in]

The number of entries in the array that the **pOutputSignature** member specifies.

## Remarks

A signature is basically the union of all registers that are input and output by any shader that shares the signature. Therefore, a signature might be a superset of what a given shader might actually input or output.

Hardware should determine that the upstream stage in the pipeline might provide some or all of the data in the signature that is laid out as the **pInputSignature** and **NumInputSignatureEntries** members specify. Similarly, hardware should determine that the downstream stage in the pipeline might consume some or all of the data in the signature that is laid out as the **pOutputSignature** and **NumOutputSignatureEntries** members specify.

To comply with the requirement for the event input and output registers to be reordered during shader compilation, the full signature is passed to the driver. Such reordering might depend on the driver being able to determine all of the registers in the signature, as well as which registers have system names (for example, names that the **SystemValue** member of the [D3D10DDIARG_SIGNATURE_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_signature_entry) structure specifies). Such reordering might also depend on the driver being able to determine registers that are not present in the current shader.

The declarations within the shader code itself also show which registers are actually used by a particular shader. These registers are possibly a subset of the input and output parts of the signature. If some hardware is not required to reorder input and output registers at compile time, the driver for that hardware can completely ignore the full signature that the D3D10DDIARG_STAGE_IO_SIGNATURES structure provides. The reference rasterizer, for example, does not require the information that the D3D10DDIARG_STAGE_IO_SIGNATURES structure provides.

## See also

[D3D10DDIARG_SIGNATURE_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_signature_entry)