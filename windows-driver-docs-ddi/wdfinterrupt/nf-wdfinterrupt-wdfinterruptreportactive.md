# WdfInterruptReportActive function

## Description

[Applies to KMDF only]

The **WdfInterruptReportActive** informs the system that the interrupt is active and the driver is ready to process interrupt requests on the associated lines.

## Parameters

### `Interrupt` [in]

A handle to a framework interrupt object.

## Remarks

Only drivers that implement functional state power management call **WdfInterruptReportActive**.

A driver does not need to call **WdfInterruptReportActive** immediately after creating an interrupt. The driver should only call **WdfInterruptReportActive** after having previously called [WdfInterruptReportInactive](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdfinterruptreportinactive).

Typically, a driver calls **WdfInterruptReportActive** from either its [ComponentActiveConditionCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_component_active_condition_callback) routine, or from [ComponentIdleStateCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_component_idle_state_callback) when *State* is 0 (indicating the fully on F0 state).

If your driver calls this method on an operating system earlier than Windows 8, [the framework's verifier](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-kmdf-verifier) reports an error.

For more information, see [Supporting Functional Power States](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-functional-power-states).

#### Examples

The following example shows how a driver might call **WdfInterruptReportActive** from the [ComponentIdleStateCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_component_idle_state_callback) routine of a KMDF driver. The driver registers a single component by calling [WdfDeviceWdmAssignPowerFrameworkSettings](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicewdmassignpowerframeworksettings).

```cpp
VOID
MyComponentIdleStateCallback(
    _In_ PVOID Context,
    _In_ ULONG Component,
    _In_ ULONG State
    )
{
    PFDO_DEVICE_DATA deviceData;
    PINTERRUPT_CONTEXT interruptContext;

    deviceData = FdoGetData((WDFDEVICE)Context);
    interruptContext = InterruptGetData(deviceData->Interrupt);

    switch (State) {
        case 0:
            if (interruptContext->ReportedInactive) {

                //
                // the interrupt was reported inactive earlier. We need to report active now.
                //
                WdfInterruptReportActive(deviceData->Interrupt);
                interruptContext->ReportedInactive = FALSE;

                //
                // Enable interrupt generation at hardware.
                //
                WdfInterruptAcquireLock(deviceData->Interrupt);
                EnableInterruptInHardware();
                WdfInterruptReleaseLock(deviceData->Interrupt);

            }

        break;

    …

}

```

## See also

[WdfInterruptReportInactive](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdfinterruptreportinactive)