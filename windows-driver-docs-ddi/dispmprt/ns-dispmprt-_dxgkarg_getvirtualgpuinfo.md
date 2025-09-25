# _DXGKARG_GETVIRTUALGPUINFO structure

## Description

Arguments used to get virtual GPU info.

## Members

### `PartitionId`

An index (from 0 to maximum supported vGPU minus one) for the vGPU partition.

### `Capability`

The array of capability values, which include Memory, Encode, Decode and Compute. A minimum, maximum and optimal values are specified for each capability. When the vGPU is running, each capability cannot be lower than MinValue and more than MaxValue. The driver could assign the current capability value based in the physical GPU load.

## Remarks

## See also