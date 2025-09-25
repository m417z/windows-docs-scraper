## Description

The **POOL_CREATE_EXTENDED_PARAMETER** structure is used within the **Parameters** array of [**POOL_CREATE_EXTENDED_PARAMS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-pool_create_extended_params) when calling [**ExCreatePool**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-excreatepool).

## Members

### `Type`

Specifies the parameter type. Must be a value from [**POOL_CREATE_EXTENDED_PARAMETER_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-pool_create_extended_parameter_type).

### `DUMMYUNIONNAME`

Anonymous union that contains the data for the parameter. Interpret the active member based on **Type**.

### `DUMMYUNIONNAME.PoolName`

Valid only when **Type** == **PoolCreateExtendedParameterName**. A UNICODE_STRING specifying the name of the pool being created. Required (and must be non-empty) for paged and nonpaged private pools; must be omitted for secure pools. The string buffer must remain valid for the duration of the **ExCreatePool** call. The name is not case-sensitive for uniqueness checks.

## Remarks

Only one parameter with **Type** == **PoolCreateExtendedParameterName** may be supplied in a single **Parameters** array.

Paged and nonpaged private pools must include exactly one name parameter.

Secure pools must not include a name parameter.

The structure does not own the underlying string buffer; the caller is responsible for allocation and freeing after the call returns.

## See also

[**ExCreatePool**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-excreatepool)

[**POOL_CREATE_EXTENDED_PARAMS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-pool_create_extended_params)

[**POOL_CREATE_EXTENDED_PARAMETER_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-pool_create_extended_parameter_type)