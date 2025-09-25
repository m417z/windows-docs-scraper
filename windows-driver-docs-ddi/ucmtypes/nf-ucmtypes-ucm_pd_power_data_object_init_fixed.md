# UCM_PD_POWER_DATA_OBJECT_INIT_FIXED function

## Description

Initializes a to the [UCM_PD_POWER_DATA_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtypes/ns-ucmtypes-_ucm_pd_power_data_object) for a Fixed Supply type Power Data Object.

## Parameters

### `Pdo` [out]

A pointer to a [UCM_PD_POWER_DATA_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtypes/ns-ucmtypes-_ucm_pd_power_data_object) structure in which the **FixedSupplyPdo.FixedSupply** member is set to **UcmPdPdoTypeFixedSupply**.

## Remarks

For different types of Power Data Objects, see the power delivery specification.

This function initializes the structure and sets Power Data Object as a Fixed Supply type. The client driver must set the remaining members with values relevant to the specific object type.

## See also

[UCM_PD_POWER_DATA_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtypes/ns-ucmtypes-_ucm_pd_power_data_object)