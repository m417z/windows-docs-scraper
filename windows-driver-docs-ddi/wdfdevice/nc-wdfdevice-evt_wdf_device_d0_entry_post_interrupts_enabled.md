# EVT_WDF_DEVICE_D0_ENTRY_POST_INTERRUPTS_ENABLED callback function

## Description

[Applies to KMDF and UMDF]

A driver's *EvtDeviceD0EntryPostInterruptsEnabled* event callback function performs device-specific operations that are required after the driver has enabled the device's hardware interrupts.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `PreviousState` [in]

A [WDF_POWER_DEVICE_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_power_device_state)-typed enumerator that identifies the previous device power state.

## Return value

If the *EvtDeviceD0EntryPostInterruptsEnabled* callback function encounters no errors, it must return STATUS_SUCCESS or another status value for which [NT_SUCCESS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values)(*status*) equals **TRUE**. Otherwise, it must return a status value for which NT_SUCCESS(*status*) equals **FALSE**.

For more information about this callback function's return values, see [Reporting Device Failures](https://learn.microsoft.com/windows-hardware/drivers/wdf/reporting-device-failures).

## Remarks

To register an *EvtDeviceD0EntryPostInterruptsEnabled* callback function, a driver must call [WdfDeviceInitSetPnpPowerEventCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetpnppowereventcallbacks).

The *EvtDeviceD0EntryPostInterruptsEnabled* callback function is called at IRQL = PASSIVE_LEVEL, after the driver's [EvtInterruptEnable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_enable) callback function returns. A driver can provide this function if it must perform device-specific operations after it has enabled an interrupt, if those operations should not be performed at IRQL = DIRQL in the *EvtInterruptEnable* callback function. You should not make this callback function [pageable](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-pageable-code-in-a-kmdf-driver).

For more information about when the framework calls this callback function, see [PnP and Power Management Scenarios](https://learn.microsoft.com/windows-hardware/drivers/wdf/pnp-and-power-management-scenarios).

For more information about handling interrupts, see [Handling Hardware Interrupts](https://learn.microsoft.com/windows-hardware/drivers/wdf/handling-hardware-interrupts).

## See also

[EvtDeviceD0ExitPreInterruptsDisabled](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_d0_exit_pre_interrupts_disabled)