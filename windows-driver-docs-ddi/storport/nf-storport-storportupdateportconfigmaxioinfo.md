## Description

A miniport calls **StorPortUpdatePortConfigMaxIOInfo** to update the maximum IOs and maximum IOs per LUN supported by an adapter.

## Parameters

### `HwDeviceExtension`

[in] A pointer to miniport's device extension.

### `MaxIoCount`

[in] Maximum number of outstanding I/O operations supported by the adapter.

### `MaxIosPerLun`

[in] Maximum number of outstanding I/O operations per LUN supported by the adapter.

## Return value

**StorPortUpdatePortConfigMaxIOInfo** returns STOR_STATUS_SUCCESS upon success. Otherwise, it returns one of the following values:

| Value | Description |
| ----- | ----------- |
| STOR_STATUS_NOT_IMPLEMENTED | The function was called on an OS version that doesn't support it. |
| STOR_STATUS_INVALID_PARAMETER | There is an invalid parameter. |
| STOR_STATUS_INVALID_DEVICE_REQUEST | The function was called outside of [**HwInitialize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_initialize)/[**HwPassiveInitRoutine**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_passive_initialize_routine). |

## Remarks

**StorPortUpdatePortConfigMaxIOInfo** is valid only within a [**HwInitialize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_initialize)/[**HwPassiveInitRoutine**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_passive_initialize_routine) callback and has effect only during adapter initialization.

## See also

[**HwInitialize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_initialize)

[**HwPassiveInitRoutine**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_passive_initialize_routine)

[**PORT_CONFIGURATION_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_port_configuration_information)

[**StorPortUpdateAdapterMaxIO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportupdateadaptermaxio)