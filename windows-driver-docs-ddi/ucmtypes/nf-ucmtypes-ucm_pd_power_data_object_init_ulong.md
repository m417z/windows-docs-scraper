# UCM_PD_POWER_DATA_OBJECT_INIT_ULONG function

## Description

Initializes a [UCM_PD_POWER_DATA_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtypes/ns-ucmtypes-_ucm_pd_power_data_object) structure by interpreting Power Data Object values and sets each field correctly.

## Parameters

### `Pdo` [out]

A pointer to a [UCM_PD_POWER_DATA_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtypes/ns-ucmtypes-_ucm_pd_power_data_object) structure.

### `UlongInLittleEndian` [in]

The ULONG value to set in the **Ul** member of [UCM_PD_POWER_DATA_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtypes/ns-ucmtypes-_ucm_pd_power_data_object).

## Remarks

A Power Data Object, as defined by the Power Delivery specification, is a 32-bit value. The hardware is expected to retrieve the Power Data Objects as 32-bit values. This utility function initializes a [UCM_PD_POWER_DATA_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtypes/ns-ucmtypes-_ucm_pd_power_data_object) structure by interpreting those values and setting each field correctly.

The 4 byte value is expected to be in little-endian format.
The structure is 4 bytes and the client driver can memcopy the Power Data Objects from the hardware into an array of [UCM_PD_POWER_DATA_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtypes/ns-ucmtypes-_ucm_pd_power_data_object) structures.

## See also

[UCM_PD_POWER_DATA_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtypes/ns-ucmtypes-_ucm_pd_power_data_object)