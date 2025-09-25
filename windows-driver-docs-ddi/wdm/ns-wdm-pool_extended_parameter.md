## Description

Specifies extended parameter information that the driver provides when calling [**ExAllocatePool3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepool3).

## Members

### `DUMMYSTRUCTNAME`

### `DUMMYSTRUCTNAME.Type`

A [**POOL_EXTENDED_PARAMETER_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-pool_extended_parameter_type) enumeration value that indicates the type of the parameter.

If this value is set to **PoolExtendedParameterPriority**, then the **Priority** member of this structure must be an [**EX_POOL_PRIORITY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-ex_pool_priority) value indicating the priority of the pool allocation. If there is not enough space for the specified priority the allocation fails.

### `DUMMYSTRUCTNAME.Optional`

If this field is set to 1, the extended parameter is optional. If **Type** is not a valid enumeration value, it is ignored. If **Type** is a valid enumeration, it may still be ignored, for example if it is incompatible with other specified flags.

If this field is set to 0, **Type** must be recognized by the pool allocator or the allocation fails.

### `DUMMYSTRUCTNAME.Reserved`

Reserved for future use.

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.Reserved2`

### `DUMMYUNIONNAME.Reserved3`

### `DUMMYUNIONNAME.Priority`

If **Type** is set to **PoolExtendedParameterPriority**, this field must contain a valid [**EX_POOL_PRIORITY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-ex_pool_priority) value.

### `DUMMYUNIONNAME.SecurePoolParams`

### `DUMMYUNIONNAME.PreferredNode`

If **Type** is set to **PoolExtendedParameterNumaNode** this field should contain a valid NUMA node index numbered 0 through N-1.
If the field also contains MM_ANY_NODE_OK, the call prefers the specified NUMA node but tries others if it is unavailable.
If MM_ANY_NODE_OK is not set, the call fails if the requested NUMA node cannot satisfy the allocation.
This parameter is valid only for allocations made with POOL_FLAG_NON_PAGED pool.

## Remarks

## See also

[**POOL_EXTENDED_PARAMETER_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-pool_extended_parameter_type)

[**ExAllocatePool3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepool3)