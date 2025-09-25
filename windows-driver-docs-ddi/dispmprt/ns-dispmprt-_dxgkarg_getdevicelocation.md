# _DXGKARG_GETDEVICELOCATION structure

## Description

Arguments used to get the location of a Virtual Function on the PCI bus relative to the root partition.

## Members

### `VirtualFunctionIndex`

Zero-based offset of the Virtual Function from the first VF exposed by this Physical Function.

### `SegmentNumber`

To be filled in with the segment number of this function.

### `BusNumber`

To be filled in with the bus number of this function.

### `FunctionNumber`

To be filled in with the function number of this function.

## Remarks

## See also