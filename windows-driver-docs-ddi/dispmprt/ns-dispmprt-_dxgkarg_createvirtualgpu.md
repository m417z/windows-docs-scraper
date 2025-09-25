# _DXGKARG_CREATEVIRTUALGPU structure

## Description

Arguments used to create a virtual GPU.

## Members

### `PartitionId`

An index (from 0 to maximum supported vGPU minus one) for the vGPU partition.

### `Profile`

Describes the desired vGPU capabilities.

### `UserModeVirtualDeviceProvider`

The class Id for the user mode emulation DLL. This value can be set to zero if the driver does not need device emulation. The Id is used by the OS to instantiate the user mode DLL.

### `VirtualGpuLuid`

LUID, which uniquely identifies the virtual GPU. This LUID will be passed to the user mode emulation DLL.

### `NumMemorySegments`

The number of valid entries in the *SegmentInfo* array.

### `SegmentInfo`

First *NumMemorySegment* entries describe information about local memory segments, which are needed in the vGPU.

### `NumEngines`

The number of valid elements in the EngineInfo array. This is deprecated and should be zero.

### `EngineInfo`

Specifies physical engines, which should be used when creating a vGPU with the given profile. This is deprecated and should be zero.

## Remarks

## See also