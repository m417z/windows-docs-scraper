## Description

The **POOL_CREATE_EXTENDED_PARAMETER_TYPE** enumeration identifies the kind of data present in a [**POOL_CREATE_EXTENDED_PARAMETER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-pool_create_extended_parameter) entry.

## Constants

### `PoolCreateExtendedParameterInvalidType`

Using this value in a parameter causes [**ExCreatePool**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-excreatepool) to fail with **STATUS_INVALID_PARAMETER_3**.

### `PoolCreateExtendedParameterName`

Specifies that the parameter supplies a pool name through the **PoolName** member of the union in **POOL_CREATE_EXTENDED_PARAMETER**. Required for paged and nonpaged private pools. Not permitted for secure pools.

## Remarks

Future versions of Windows may introduce additional parameter types. Drivers constructing a parameters array must not include duplicate types.

## See also

[**ExCreatePool**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-excreatepool)

[**POOL_CREATE_EXTENDED_PARAMETER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-pool_create_extended_parameter)

[**POOL_CREATE_EXTENDED_PARAMS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-pool_create_extended_params)