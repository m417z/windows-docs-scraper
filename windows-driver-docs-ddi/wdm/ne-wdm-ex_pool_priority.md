## Description

Specifies the priority of a pool memory allocation request.

## Constants

### `LowPoolPriority`

This setting indicates that it is acceptable to the driver for the mapping request to fail if the system is low on resources. For example, this could be for a non-critical network connection where the driver can handle the failure case when system resources are close to being depleted.

### `LowPoolPrioritySpecialPoolOverrun`

### `LowPoolPrioritySpecialPoolUnderrun`

### `NormalPoolPriority`

Indicates that it is acceptable to the driver for the mapping request to fail if the system is very low on resources. For example, this could be for a non-critical local filesystem request.

### `NormalPoolPrioritySpecialPoolOverrun`

### `NormalPoolPrioritySpecialPoolUnderrun`

### `HighPoolPriority`

Should be used when it is unacceptable to the driver for the mapping request to fail unless the system is out of resources. An example of this would be the paging file path in a driver.

### `HighPoolPrioritySpecialPoolOverrun`

### `HighPoolPrioritySpecialPoolUnderrun`

## Syntax

```cpp
typedef _Enum_is_bitflag_ enum _EX_POOL_PRIORITY {
    LowPoolPriority,
    LowPoolPrioritySpecialPoolOverrun = 8,
    LowPoolPrioritySpecialPoolUnderrun = 9,
    NormalPoolPriority = 16,
    NormalPoolPrioritySpecialPoolOverrun = 24,
    NormalPoolPrioritySpecialPoolUnderrun = 25,
    HighPoolPriority = 32,
    HighPoolPrioritySpecialPoolOverrun = 40,
    HighPoolPrioritySpecialPoolUnderrun = 41
} EX_POOL_PRIORITY;
```

## Remarks

The **SpecialPool** settings can be used to bound the allocation at a page beginning or end.Use this option only on systems being debugged as the memory cost is expensive.

## See also

[**ExAllocatePoolPriorityZero**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolpriorityzero)