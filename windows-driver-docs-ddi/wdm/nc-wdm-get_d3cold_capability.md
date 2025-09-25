# GET_D3COLD_CAPABILITY callback function

## Description

The **GET_D3COLD_CAPABILITY** callback routine is used for two different functions in the [**D3COLD_SUPPORT_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_d3cold_support_interface):

- **GetD3ColdCapability** - Reports whether this device is capable of entering the D3cold device power state.
- **GetBusDriverD3ColdSupport** - Reports whether the underlying bus driver and ACPI system firmware support D3cold for this device.

## Parameters

### `Context` [in, optional]

A pointer to interface-specific context information. The caller sets this parameter to the value of the **Context** member of the [**D3COLD_SUPPORT_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_d3cold_support_interface) structure for the interface.

### `D3ColdSupported` [out]

A pointer to a BOOLEAN variable to which the routine writes a value to indicate the D3cold support status. The meaning of this value depends on which function is being called:

- **GetD3ColdCapability**: If TRUE, the device is capable of entering D3cold. If FALSE, the device isn't capable of entering D3cold.
- **GetBusDriverD3ColdSupport**: If TRUE, the bus driver supports D3cold. If FALSE, the bus driver doesn't support D3cold.

If the call fails, the routine returns an error status code and doesn't write anything to this variable.

## Return value

The **GET_D3COLD_CAPABILITY** routine returns STATUS_SUCCESS if it is successful. Otherwise, it returns an appropriate error status code.

## Remarks

This callback function type is used for two different routines in the [**D3COLD_SUPPORT_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_d3cold_support_interface):

- **GetD3ColdCapability** - Reports whether this device is capable of entering the D3cold device power state.
- **GetBusDriverD3ColdSupport** - Reports whether the underlying bus driver and ACPI system firmware support D3cold for this device.

### GetBusDriverD3ColdSupport Usage

The driver for the device calls the version of this routine that is implemented by the [Windows ACPI driver](https://learn.microsoft.com/windows-hardware/drivers/kernel/acpi-driver), Acpi.sys. This routine checks the parent bus driver for the device to determine whether this bus driver supports the D3cold power state.

For example, starting with Windows 8, Microsoft supplies an inbox USB 3.0 eXtensible Host Controller Interface (xHCI) driver that supports D3cold. Some third-party hardware vendors supply Windows drivers for their xHCI controllers, but these drivers might not support D3cold. The driver for a USB 3.0 device can call the *GetBusDriverD3ColdSupport* routine to determine whether the parent xHCI controller driver supports D3cold.

A bus driver supports D3cold if all of the following are true:

- The bus driver implements the GUID_D3COLD_SUPPORT_INTERFACE driver interface.
- The bus driver implements the *GetBusDriverD3ColdSupport* routine in this interface.
- The output value from the *GetBusDriverD3ColdSupport* routine indicates that the bus driver supports D3cold.

The driver for a device can call the [**GetIdleWakeInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-get_idle_wake_info) routine to determine whether the underlying bus drivers and ACPI system firmware support D3cold for the device. If this call fails and returns an error status code, the device driver can call the *GetBusDriverD3ColdSupport* routine to determine whether the failure is caused by lack of D3cold support by the parent bus driver.

A device on a bus can make a transition to the D3cold substate only if the bus driver supports this transition. If the bus driver doesn't support D3cold, the device never enters D3cold, even if the function driver for the device calls the [**SetD3ColdSupport**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-set_d3cold_support) routine to enable the transition to D3cold. In this case, *SetD3ColdSupport* calls have no effect, but are harmless.

For this reason, most device drivers never need to call the *GetBusDriverD3ColdSupport* routine.

## See also

[**D3COLD_SUPPORT_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_d3cold_support_interface)

[**GetIdleWakeInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-get_idle_wake_info)

[**SetD3ColdSupport**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-set_d3cold_support)