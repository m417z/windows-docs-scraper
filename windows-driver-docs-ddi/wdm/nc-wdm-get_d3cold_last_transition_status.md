# GET_D3COLD_LAST_TRANSITION_STATUS callback function

## Description

The *GetLastTransitionStatus* routine enables the driver for a device to query whether the most recent transition to the D3hot substate was followed by a transition to the D3cold substate.

## Parameters

### `Context` [in, optional]

A pointer to interface-specific context information. The caller sets this parameter to the value of the **Context** member of the [D3COLD_SUPPORT_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_d3cold_support_interface) structure for the interface.

### `LastTransitionStatus` [out]

A pointer to a variable into which the routine writes one of the following [D3COLD_LAST_TRANSITION_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_d3cold_last_transition_status) enumeration values:

* **LastDStateTransitionStatusUnknown**
* **LastDStateTransitionD3hot**
* **LastDStateTransitionD3cold**

The **LastDStateTransitionD3cold** value indicates that the most recent transition to D3hot was followed by a transition to D3cold. For more information, see Remarks.

## Remarks

This routine tries to get the information needed to answer the caller's query from the parent bus driver and platform firmware. If this information is not available, the routine writes the value **LastDStateTransitionStatusUnknown** to the location pointed to by *the LastTransitionStatus* parameter.

For more information, see [D3COLD_LAST_TRANSITION_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_d3cold_last_transition_status).

## See also

[D3COLD_LAST_TRANSITION_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_d3cold_last_transition_status)

[D3COLD_SUPPORT_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_d3cold_support_interface)