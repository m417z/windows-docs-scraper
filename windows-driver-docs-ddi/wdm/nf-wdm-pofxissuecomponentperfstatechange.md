# PoFxIssueComponentPerfStateChange function

## Description

The **PoFxIssueComponentPerfStateChange** routine submits a request to place a device component in a
particular performance state.

## Parameters

### `Handle` [in]

A handle that represents the registration of the device with PoFx. The device driver previously received this handle from the [PoFxRegisterDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxregisterdevice) routine.

### `Flags` [in]

The flags that modify the behavior of the performance state change operation. Set this member to zero or to one of the following flag **PO_FX_FLAG_*XXX*** bits:

These two flag bits are mutually exclusive. For more information, see Remarks.

| Value | Meaning |
| --- | --- |
| **PO_FX_FLAG_BLOCKING**<br><br>0x1 | Make the condition change synchronous. If this flag is set, the routine that requests the condition change does not return control to the calling driver until the component hardware completes the transition to the new condition. This flag can be used only if the caller is running at IRQL < DISPATCH_LEVEL. |
| **PO_FX_FLAG_ASYNC_ONLY**<br><br>0x2 | Make the condition change fully asynchronous. If this flag is set, the calling driver's callback routine is called from a thread other than the thread in which the routine that requests the condition change is called. Thus, the routine that requests the condition change always returns asynchronously without waiting for the callback to complete. |

### `Component` [in]

The index that identifies the component. This parameter is an index into the **Components** array in the [PO_FX_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_po_fx_device_v1) structure that the device driver used to register the device with PoFx. If the **Components** array contains N elements, component indexes range from 0 to N–1.

### `PerfChange` [in]

A pointer to a [PO_FX_PERF_STATE_CHANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_po_fx_perf_state_change) structure that represents the new performance state of the component.

### `Context` [in]

A pointer to the context for the [ComponentPerfStateCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_component_perf_state_callback) callback routine. This parameter is optional. It is provided so that a driver or device context can be passed to the callback routine. If this parameter is not used, it must be set to NULL.

## Remarks

When a driver calls **PoFxIssueComponentPerfStateChange**, the power management framework (PoFx) requests the platform extension plug-in (PEP) to place
the component's performance state set in the specified performance state. This routine may be used with both discrete and range-based types of performance state sets. For more information about discrete and range-based performance state sets, see [PO_FX_PERF_STATE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_po_fx_perf_state_type).

If *Flags* = **PO_FX_FLAG_BLOCKING**, the **PoFxIssueComponentPerfStateChange** call is synchronous. In this case, **PoFxIssueComponentPerfStateChange** waits to return until the component completes the performance state transition. The driver's [ComponentPerfStateCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_component_perf_state_callback) routine is called to inform the driver that the component's performance state change is complete. This callback occurs in the same thread as the call to **PoFxIssueComponentPerfStateChange**, and **PoFxIssueComponentPerfStateChange** returns only after the *ComponentPerfStateCallback* callback returns.

If *Flags* = **PO_FX_FLAG_ASYNC_ONLY**, the **PoFxIssueComponentPerfStateChange** call is asynchronous. In this case, **PoFxIssueComponentPerfStateChange** schedules the [ComponentPerfStateCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_component_perf_state_callback) routine to occur in another thread, and then returns without waiting for the callback to occur. The callback can occur before or after **PoFxIssueComponentPerfStateChange** returns. The driver should rely on the *ComponentPerfStateCallback* routine to determine when the component completes the transition to the new performance state.

The driver can set *Flags* = 0 to indicate that it does not care whether the **PoFxIssueComponentPerfStateChange** call is synchronous or asynchronous. In this case, PoFx decides the synchronicity of the call based on whether the PEP uses a synchronous or asynchronous request to issue the performance state change to the component.

If *Flags* = **PO_FX_FLAG_ASYNC_ONLY** or no flags are passed, this routine requires an IRQL of <= DISPATCH_LEVEL. If *Flags* = **PO_FX_FLAG_BLOCKING**, this routine requires an IRQL of <= APC_LEVEL.

This function will always result in a call to the [ComponentPerfStateCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_component_perf_state_callback) routine regardless of the synchronicity of the call. Because the PEP may choose to deny the request to change the performance state, the driver must wait until receiving the callback before committing the performance state to hardware.

Only a single call of the **PoFxIssueComponentPerfStateChange** routine is allowed at a time per component, regardless of whether the call is synchronous or asynchronous. After issuing a performance state change request, the driver must wait until the [ComponentPerfStateCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_component_perf_state_callback) is received before calling this routine again, even if the request involves a different performance state set. If this routine is called again before waiting until the *ComponentPerfStateCallback* is received, a bugcheck will occur.

## See also

[ComponentPerfStateCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_component_perf_state_callback)

[Device Performance State Management](https://learn.microsoft.com/windows-hardware/drivers/kernel/component-level-performance-management)

[PO_FX_PERF_STATE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_po_fx_perf_state_type)

[PoFxIssueComponentPerfStateChangeMultiple](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxissuecomponentperfstatechangemultiple)

[PoFxRegisterComponentPerfStates](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxregistercomponentperfstates)