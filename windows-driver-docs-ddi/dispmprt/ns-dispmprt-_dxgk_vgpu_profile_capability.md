# _DXGK_VGPU_PROFILE_CAPABILITY structure

## Description

Contains information about the virtual GPU profile capability.

## Members

### `TotalValue`

Total amount in this partition configuration.

### `AvailableValue`

Currently available amount in this partition configuration. This value changes as vGPUs start and stop running

### `MinPartitionValue`

Minimum value for each partition in this partition configuration.

### `MaxPartitionValue`

Maximum value for each partition in this partition configuration.

### `OptimalPartitionValue`

Optimal value for each partition in this partition configuration.

The meaning of the capability values depend on the capability type.
For memory it is the number of bytes. For compute it is the number of gigaflops of 16fp instructions.
For video Encode/Decode it is roughly in blocks of 540p capability. 1 is 540p60, 2 is 720p60, 4 is 1080p60, 4Kp60 is 16, etc.

## Remarks

## See also