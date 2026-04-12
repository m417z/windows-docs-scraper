# EVT_IDD_CX_MONITOR_I2C_TRANSMIT_AND_RECEIVE callback function

## Description

**EVT_IDD_CX_MONITOR_I2C_TRANSMIT_AND_RECEIVE** is called by the OS to return data received from an I2C device in a monitor.

## Parameters

### `MonitorObject` [in]

The OS context handle for this monitor returned by the [**IddCxMonitorCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorcreate) call.

### `pInArgs` [in]

Input arguments of the function.

### Return value

(NTSTATUS) If the operation is successful, the callback function must return STATUS_SUCCESS, or another status value for which NT_SUCCESS(status) equals TRUE. Otherwise, an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) error code.

### Remarks

IddCx 1.11 drivers that support I2C must supply this DDI as well as the existing [**EVT_IDD_CX_MONITOR_I2C_TRANSMIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nc-iddcx-evt_idd_cx_monitor_i2c_transmit) and [**EVT_IDD_CX_MONITOR_I2C_RECEIVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nc-iddcx-evt_idd_cx_monitor_i2c_receive).

The new **EVT_IDD_CX_MONITOR_I2C_TRANSMIT_AND_RECEIVE** DDI allows a driver to complete an I2C operation in the context of one call as opposed to the old DDIs where the driver would have to hold on to the received data until the OS called **EVT_IDD_CX_MONITOR_I2C_RECEIVE**.

> [!NOTE]
> It's possible an OS that supports IddCx 1.11 doesn't support this functionality. In this case, it's safe for the driver to expose the new function, but the OS doesn't use it.

> [!NOTE]
> IddCx 1.11 drivers that support I2C must also expose the existing **EVT_IDD_CX_MONITOR_I2C_TRANSMIT** and EVT_IDD_CX_MONITOR_I2C_RECEIVE DDs.

## See also

[**IDARG_IN_I2C_TRANSMIT_AND_RECEIVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_i2c_transmit_and_receive)

[IddCx versions](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx-versions)