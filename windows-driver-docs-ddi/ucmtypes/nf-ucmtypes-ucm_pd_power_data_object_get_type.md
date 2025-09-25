# UCM_PD_POWER_DATA_OBJECT_GET_TYPE function

## Description

Retrieves the type of Power Data Object from the [UCM_PD_POWER_DATA_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtypes/ns-ucmtypes-_ucm_pd_power_data_object) structure.

## Parameters

### `Pdo` [in]

A pointer to a [UCM_PD_POWER_DATA_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtypes/ns-ucmtypes-_ucm_pd_power_data_object) structure that contains the type of Power Data Object.

## Return value

Returns the **Common.Type** member of the [UCM_PD_POWER_DATA_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtypes/ns-ucmtypes-_ucm_pd_power_data_object) structure.

## Remarks

For information about the Power Data Object including the types of object, see Power Delivery specification. The Type member of [UCM_PD_POWER_DATA_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtypes/ns-ucmtypes-_ucm_pd_power_data_object) indicates the type of Power Data Object.

## See also

[UCM_PD_POWER_DATA_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtypes/ns-ucmtypes-_ucm_pd_power_data_object)