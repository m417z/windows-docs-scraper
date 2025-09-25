# WdfInterruptReportInactive function

## Description

[Applies to KMDF only]

The **WdfInterruptReportInactive** method informs the system that the interrupt is no longer active and the driver is not expecting interrupt requests on the associated lines.

## Parameters

### `Interrupt` [in]

A handle to a framework interrupt object.

## Remarks

Only drivers that implement functional state power management call **WdfInterruptReportInactive**.

When a driver calls **WdfInterruptReportInactive**, the power management framework (PoFx) can then perform related power management tasks.

Typically, a driver calls **WdfInterruptReportInactive** from either its [ComponentIdleConditionCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_component_idle_condition_callback) routine, or from [ComponentIdleStateCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_component_idle_state_callback) when *State* is greater than zero (indicating a low-power Fx state).

If your driver calls this method on an operating system earlier than Windows 8, [the framework's verifier](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-kmdf-verifier) reports an error.

#### Examples

The following example shows how a driver might call **WdfInterruptReportInactive** from the [ComponentIdleStateCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_component_idle_state_callback) routine of a KMDF driver. The driver registers a single component by calling [WdfDeviceWdmAssignPowerFrameworkSettings](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicewdmassignpowerframeworksettings).

```cpp
VOID
MyComponentIdleStateCallback(
    _In_ PVOID Context,
    _In_ ULONG Component,
    _In_ ULONG State
    )
{
    PFDO_DEVICE_DATA deviceData;
    PFDO_INTERRUPT_CONTEXT interruptContext;

    deviceData = FdoGetData((WDFDEVICE)Context);
    interruptContext = InterruptGetData(deviceData->Interrupt);

    switch (State) {
        case 0:
             …
            break;

        //
        // PoFx may make us go to any of the F-states directly, hence we execute
        // F0Exit code for all of the Fx states. Note that transition to any Fx
        // state happens from F0 (and not another Fx state).
        //
        default:
            //
            // Disable interrupt generation at hardware if needed.
            //
            WdfInterruptAcquireLock(deviceData->Interrupt);
            DisableInterruptInHardware();
            WdfInterruptReleaseLock(deviceData->Interrupt);

            //
            // Report that interrupt is now inactive.
            //
            WdfInterruptReportInactive(deviceData->Interrupt);

            interruptContext->ReportedInactive = TRUE;

        break;

    …

}

```

## See also

[WdfInterruptReportActive](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdfinterruptreportactive)