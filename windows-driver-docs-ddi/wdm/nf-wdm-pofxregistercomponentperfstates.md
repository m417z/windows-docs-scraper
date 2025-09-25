# PoFxRegisterComponentPerfStates function

## Description

The **PoFxRegisterComponentPerfStates** routine registers a device component for performance state management by the power management framework (PoFx).

## Parameters

### `Handle` [in]

A handle that represents the registration of the device with PoFx. The device driver previously received this handle from the [PoFxRegisterDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxregisterdevice) routine.

### `Component` [in]

The index that identifies the component whose performance states will be managed. This parameter is an index into the **Components** array in the [PO_FX_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_po_fx_device_v1) structure that the device driver used to register the device with PoFx. If the **Components** array contains N elements, component indexes range from 0 to N–1.

### `Flags` [in]

The flags that modify the behavior of the performance state registration. Set this member to zero or to one of the following flag **PO_FX_FLAG_PERF_*XXX*** bits:

| Value | Meaning |
| --- | --- |
| **PO_FX_FLAG_PERF_PEP_OPTIONAL**<br><br>0x1 | Indicates that the driver can change performance states without assistance from the platform extension plug-in (PEP), or that the driver is registering performance states with PoFx for logging purposes only. If this flag is set, the **PoFxRegisterComponentPerfStates** call will still succeeded if the PEP does not support performance states for the component. |
| **PO_FX_FLAG_PERF_QUERY_ON_F0**<br><br>0x2 | For some devices, the PEP may need to a place a performance state set for a component into a certain performance state (known as a *nominal performance state*) when it idles the component. Drivers set this flag if the component contains nominal performance states, in which case PoFx will query the PEP to determine the current performance state when the component transitions to F0. |
| **PO_FX_FLAG_PERF_QUERY_ON_ALL_IDLE_STATES**<br><br>0x4 | For some devices, the PEP may need to a place a performance state set for a component into a certain performance state (known as a *nominal performance state*) when it transitions the component between idle states. Drivers set this flag if this component contains nominal performance states, in which case PoFx will query the PEP to determine the current performance state when the component transitions between idle states. |

### `ComponentPerfStateCallback` [in]

A pointer to a [ComponentPerfStateCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_component_perf_state_callback) routine. This routine is called when PoFx has completed logging and notifying the PEP about a performance state transition that is initiated by the driver’s call to [PoFxIssueComponentPerfStateChange](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxissuecomponentperfstatechange) or [PoFxIssueComponentPerfStateChangeMultiple](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxissuecomponentperfstatechangemultiple). This callback may be the same for all components and all devices; PoFx provides the device handle and component index in each completion call.

### `InputStateInfo` [in]

If the driver provides performance state info, this parameter contains a pointer to a driver allocated [PO_FX_COMPONENT_PERF_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_po_fx_component_perf_info) structure that provides performance state information to PoFx. If the driver requires performance state information from the PEP, this parameter must be set to NULL.

### `OutputStateInfo` [out]

If the driver requires performance state information from the PEP, after a successful registration this parameter contains a pointer to a [PO_FX_COMPONENT_PERF_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_po_fx_component_perf_info) structure that provides performance state information defined by the PEP. If the driver provides performance state info, this parameter must be set to NULL.

The memory allocated for this parameter is managed by PoFx, and the driver should not free this memory when the device is removed. The lifetime of this memory is guaranteed to exceed the lifetime of the PoFx component that contains these performance state sets.

## Return value

**PoFxRegisterComponentPerfStates** returns **STATUS_SUCCESS** if PoFx accepts the device's registration of performance states. If any of the necessary information is not provided or incorrect, registration will fail with a return code other than **STATUS_SUCCESS**. Possible error return values include the following status codes.

| Return code | Description |
| --- | --- |
| ****STATUS_NOT_IMPLEMENTED**** | The *Flags* parameter does not include the **PO_FX_FLAG_PERF_PEP_OPTIONAL** flag and the PEP is not able to provide performance state management for this device. |
| ****STATUS_INVALID_PARAMETER**** | Both *InputStateInfo* and *OutputStateInfo* are NULL or both of these parameters are not NULL, or there are no performance state sets in the [PO_FX_COMPONENT_PERF_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_po_fx_component_perf_info) structure that was assigned to the *InputStateInfo* parameter. |

## Remarks

Note that PoFx performs a deep-copy of the device's structures into its memory.

Either the driver or the platform extension plug-in (PEP) may provide information about the performance states supported by each component:

* If the driver provides performance state information, the driver must set the *InputStateInfo* parameter to a pointer to a [PO_FX_COMPONENT_PERF_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_po_fx_component_perf_info) structure that contains the performance state information. Otherwise, the driver must set this parameter to NULL.
* If the PEP provides performance state information, the driver must set the *OutputStateInfo* parameter to a valid pointer to a [PO_FX_COMPONENT_PERF_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_po_fx_component_perf_info) structure that receives the performance state information. Otherwise, the driver must set this parameter to NULL.

If the PEP does not support performance states, the driver may register for performance state support with PoFx for logging purposes only.

If the driver registers for performance state support for logging purposes only, or if the driver can function correctly with or without PEP support for performance state management, the driver must set the **PO_FX_FLAG_PERF_PEP_OPTIONAL** flag in the *Flags* parameter. If the flag is set, the registration call will succeed even if the PEP does not provide support for performance states.

If the driver requires the PEP to provide performance state information, the driver cannot set the **PO_FX_FLAG_PERF_PEP_OPTIONAL** flag in the *Flags* parameter.

## See also

[ComponentPerfStateCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_component_perf_state_callback)

[Device Performance State Management](https://learn.microsoft.com/windows-hardware/drivers/kernel/component-level-performance-management)

[PO_FX_COMPONENT_PERF_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_po_fx_component_perf_info)

[PoFxRegisterDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxregisterdevice)