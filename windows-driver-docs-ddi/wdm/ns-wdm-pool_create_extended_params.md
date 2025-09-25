## Description

Defines the **POOL_CREATE_EXTENDED_PARAMS** structure.

## Members

### `Version`

ULONG that specifies the version of this structure. Set to **POOL_CREATE_PARAMS_VERSION** (currently 1). Any other value causes **ExCreatePool** to fail with **STATUS_INVALID_PARAMETER**. Future versions may extend this structure; drivers must always initialize this field explicitly.

### `ParameterCount`

Number of elements in the array pointed to by **Parameters**. Must be 0 if no extended parameters are supplied.

### `Parameters`

Pointer to an array of [**POOL_CREATE_EXTENDED_PARAMETER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-pool_create_extended_parameter) entries that provide additional creation parameters. Must be NULL when **ParameterCount** is 0. Each entry's **Type** field identifies the parameter kind. Currently the only valid type is **PoolCreateExtendedParameterName**, which supplies the pool's Unicode name in the **PoolName** member. The name must be unique within the creating driver context and follow any internal naming constraints. Unsupported or duplicate parameter types are rejected.

## Remarks

Use this structure to pass optional (or required) extended creation data to [**ExCreatePool**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-excreatepool) via its **Params** argument.

Paged and nonpaged private pools must specify exactly one name parameter. Secure pools must not specify a name parameter.

If **ParameterCount** is non-zero, **Parameters** must point to a valid, readable array of that many entries.

Parameter types not recognized by the kernel or appearing more than once cause **ExCreatePool** to return **STATUS_INVALID_PARAMETER_3**.

The structure is versioned to allow forward compatibility; drivers should not assume additional fields remain zero across future releases—always check the version before interpreting unrecognized extensions (if reading a buffer originated elsewhere).

## See also

[**ExCreatePool**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-excreatepool)

[**ExDestroyPool**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exdestroypool)