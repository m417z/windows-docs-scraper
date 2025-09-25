# PDXGK_INITIAL_COMPONENT_STATE callback function

## Description

The **PDXGK_INITIAL_COMPONENT_STATE** callback function is implemented by the client driver to initialize the component state.

## Parameters

### `GraphicsDeviceHandle`

A handle to the graphics device.

### `PrivateHandle`

An opaque handle provided in any callbacks. This handle must be globally unique, therefore, a pointer to the calling driver’s PDO or FDO should be used.

### `ComponentIndex`

The index of the component. Generally, this will be the index used by the graphics adapter. The exception is for linked display adapter (LDA) scenarios, where the HIWORD of the **ComponentIndex** indicates the adapter index, as is done when the graphics driver is called by the graphics kernel for F-state changes in LDA scenarios.

### `IsBlockingType`

Set TRUE if the component is "blocking"; for example, the graphics driver has reported the component as [**ActiveInD3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_power_component_flags) = 0. Otherwise, set FALSE.

### `InitialFState`

The F-state of a component represented by **ComponentIndex** at the time of the call. If an F-state transition is currently in progress, a [**PDXGK_FSTATE_NOTIFICATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nc-d3dkmthk-pdxgk_fstate_notification) completion notification callback with ```PreNotification=FALSE``` will follow some time later when the transition completes. Depending on the timing, a ```PreNotification=TRUE``` callback might occur. If it does occur, it will precede the completion notification callback.

### `ComponentGuid`

A GUID value which is the component GUID as reported by the graphics driver for this component during its [**DXGKQAITYPE_POWERCOMPONENTINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_queryadapterinfotype) response.

### `PowerComponentMappingFlag`

The HIWORD indicates if this is a custom driver defined value (0 = no, 1 = yes). If 0 (no), then the low word represents a [**DXGKMT_POWER_SHARED_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ne-d3dkmthk-_dxgkmt_power_shared_type) enum value. These values are set by the graphics driver during its [**DXGKQAITYPE_POWERCOMPONENTINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_queryadapterinfotype) response, using the **DXGK_POWER_COMPONENT_SHARED_DESC** type added to [**DXGK_POWER_COMPONENT_MAPPING**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_power_component_mapping).

## Remarks

Upon shared power registration ([**IoCallDriver**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocalldriver) call), if **PDXGK_INITIAL_COMPONENT_STATE** was provided, it is called once for each shared power component that the graphics driver has reported. The behavior of this callback is such that:

* These calls are re-entrant calls, occurring prior to **IoCallDriver** returning
* These calls occur at [DISPATCH_LEVEL, which requires driver code and data to be memory-resident](https://learn.microsoft.com/windows-hardware/drivers/kernel/when-should-code-and-data-be-pageable-)
* As these callbacks occur prior to **IoCallDriver** returning, [**DXGK_GRAPHICSPOWER_REGISTER_OUTPUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_dxgk_graphicspower_register_output) would not have been filled in yet
* If any F-state transitions are currently in progress, a post-notification [**PDXGK_FSTATE_NOTIFICATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nc-d3dkmthk-pdxgk_fstate_notification) will alert the driver of the final state. Such calls will be guaranteed to occur after the InitialComponentStateCb calls. However, it is possible that such callbacks could occur prior to **IoCallDriver** returning if synchronization is required. A spin lock should be around **IoCallDriver** and the **PDXGK_FSTATE_NOTIFICATION** handler.

## See also

[**DXGK_GRAPHICSPOWER_REGISTER_OUTPUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_dxgk_graphicspower_register_output)

[**DXGK_POWER_COMPONENT_MAPPING**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_power_component_mapping)

[**DXGK_QUERYADAPTERINFOTYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_queryadapterinfotype)

[**DXGKMT_POWER_SHARED_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ne-d3dkmthk-_dxgkmt_power_shared_type)

[**PDXGK_FSTATE_NOTIFICATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nc-d3dkmthk-pdxgk_fstate_notification)