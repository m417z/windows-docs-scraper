# _DXGK_VIRTUALGPUPROFILE structure

## Description

Information about a virtual GPU profile.

## Members

### `Capability`

The array of capability values, which include Memory, Encode, Decode and Compute. A minimum, maximum and optimal values are specified for each capability. When the vGPU is running, each capability cannot be lower than MinValue and more than MaxValue. The driver could assign the current capability value based in the physical GPU load.

## Remarks

## See also