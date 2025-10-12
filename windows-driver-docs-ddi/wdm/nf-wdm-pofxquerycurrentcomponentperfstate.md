# PoFxQueryCurrentComponentPerfState function

## Description

The **PoFxQueryCurrentComponentPerfState** routine retrieves the active performance state in a component's performance state set.

## Parameters

### `Handle` [in]

A handle that represents the registration of the device with power management framework (PoFx). The device driver previously received this handle from the [PoFxRegisterDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxregisterdevice) routine.

### `Flags` [in]

Set to 0. Currently, no flags are defined for this routine.

### `Component` [in]

The index that identifies the component whose performance state is being retrieved. This parameter is an index into the **Components** array in the [PO_FX_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_po_fx_device_v1) structure that the device driver used to register the device with PoFx. If the **Components** array contains N elements, component indexes range from 0 to N–1.

### `SetIndex` [in]

The index that identifies the performance state set whose performance is being queried. This parameter is an index into the **PerfStateSets** array in the [PO_FX_COMPONENT_PERF_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_po_fx_component_perf_info) structure that the device driver used to register the component performance states with PoFx. If the **PerfStateSets** array contains N elements, performance state set indexes range from 0 to N–1.

### `CurrentPerf` [in]

A pointer to variable in which the current performance state for the specified performance state set is returned. For more information about the value that is returned, see Remarks.

## Return value

**PoFxQueryCurrentComponentPerfState** returns **STATUS_SUCCESS** if the requested operation succeeds. Possible error return values include the following status codes.

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | The caller supplied an invalid index for the component or component state set. |

## Remarks

A driver can call the **PoFxQueryCurrentComponentPerfState** routine to retrieve the current performance state of a given performance state set for a component. If the call succeeds, the *CurrentPerf* parameter is overwritten with a pointer to a value that specifies the current performance state of the set. This value may be one of the following, depending on the contents of the [PO_FX_COMPONENT_PERF_SET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_po_fx_component_perf_set) structure that the driver passed to the [PoFxRegisterComponentPerfStates](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxregistercomponentperfstates) routine:

* For a performance state set that represents a continuous distribution of performance states, this is a value between the **Minimum** and **Maximum** members of the [PO_FX_COMPONENT_PERF_SET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_po_fx_component_perf_set) structure.
* For a performance state set that represents a discrete number of performance states, this value is an index into the **States** member of the [PO_FX_COMPONENT_PERF_SET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_po_fx_component_perf_set) structure .

This call always executes synchronously.

## See also

[Device Performance State Management](https://learn.microsoft.com/windows-hardware/drivers/kernel/component-level-performance-management)

[PO_FX_COMPONENT_PERF_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_po_fx_component_perf_info)

[PO_FX_COMPONENT_PERF_SET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_po_fx_component_perf_set)

[PoFxRegisterComponentPerfStates](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxregistercomponentperfstates)