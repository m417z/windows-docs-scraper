# UCM_PD_REQUEST_DATA_OBJECT_INIT_ULONG function

## Description

Initializes a [UCM_PD_REQUEST_DATA_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtypes/ns-ucmtypes-_ucm_pd_request_data_object) structure by interpreting Request Data Object values and sets each field correctly.

## Parameters

### `Rdo`

A pointer to a [**UCM_PD_REQUEST_DATA_OBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtypes/ns-ucmtypes-_ucm_pd_request_data_object) structure.

### `UlongInLittleEndian` [in]

The ULONG value to set in the **Ul** member of [UCM_PD_REQUEST_DATA_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtypes/ns-ucmtypes-_ucm_pd_request_data_object).

## Remarks

For information about Request Data Objects, see the Power Delivery specification. There are different types of Request Data Objects and the type depends on the Power Data Object that is specified in the **ObjectPosition** member of [UCM_PD_REQUEST_DATA_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtypes/ns-ucmtypes-_ucm_pd_request_data_object). The source buffer is little-endian format. The client driver can call the [**memcpy**](https://learn.microsoft.com/cpp/c-runtime-library/reference/memcpy-wmemcpy) function to get the Request Data Objects from the hardware into an array of **UCM_PD_REQUEST_DATA_OBJECT** structures.

## See also

[UCM_PD_REQUEST_DATA_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtypes/ns-ucmtypes-_ucm_pd_request_data_object)