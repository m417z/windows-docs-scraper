# PDXGK_SET_SHARED_POWER_COMPONENT_STATE callback function

## Description

A callback to indicate whether the specified power component is active.

## Parameters

### `DeviceHandle`

An opaque handle which should be provided when making callbacks to the graphics device.

### `PrivateHandle`

An opaque handle which will be provided in any callbacks. This handle must be globally unique, therefore, a pointer to the calling driver’s PDO or FDO should be used.

### `ComponentIndex`

The index of the component. Generally, this will be the index used by the graphics adapter. The exception is for LDA scenarios, where the HIWORD of the ComponentIndex indicates the adapter index, as is done when the graphics driver is called by graphics kernel for F-state changes in LDA scenarios.

### `Active`

Specifies whether the shared power component state is active.

## Return value

Return STATUS_SUCCESS if the call succeeds.