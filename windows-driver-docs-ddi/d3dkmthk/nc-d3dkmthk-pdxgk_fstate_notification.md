# PDXGK_FSTATE_NOTIFICATION callback function

## Description

Implemented by the client driver to issue a state notification.

## Parameters

### `GraphicsDeviceHandle`

An opaque handle which should be provided when making callbacks to the graphics device.

### `ComponentIndex`

The index of the component. Generally, this will be the index used by the graphics adapter. The exception is for LDA scenarios, where the HIWORD of the ComponentIndex indicates the adapter index, as is done when the graphics driver is called by graphics kernel for F-state changes in LDA scenarios.

### `NewFState`

The F-state to transition to.

### `PreNotification`

Indicates that a notification should be provided.

### `PrivateHandle`

An opaque handle which will be provided in any callbacks. This handle must be globally unique, therefore, a pointer to the calling driver's PDO or FDO should be used.

## Prototype

```cpp
//Declaration

PDXGK_FSTATE_NOTIFICATION PdxgkFstateNotification;

// Definition

VOID PdxgkFstateNotification
(
  PVOID GraphicsDeviceHandle
  ULONG ComponentIndex
  UINT NewFState
  BOOLEAN PreNotification
  PVOID PrivateHandle
)
{...}

```

## Remarks

All callbacks made from Dxgkrnl to this callback may be called at up to DISPATCH_LEVEL (e.g., the non-graphics driver should not block on any of these notifications). Callbacks will only be made for [DXGK_POWER_COMPONENT_SHARED](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_power_component_type) type power components.

Pre-notifications will be provided prior to transitioning F-states. Completion notification callbacks (PreNotification==FALSE) are issued as part of the graphics driver's [DxgkCbCompleteFStateTransition](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_completefstatetransition) callback. That is, all shared power components will be notified of the F-state transition completion prior to DxgkCbCompleteFStateTransition returning.

## See also