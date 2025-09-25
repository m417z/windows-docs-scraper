# IDirectManipulationDragDropBehavior::SetConfiguration

## Description

Sets the configuration of the drag-drop interaction for the viewport this behavior is attached to.

## Parameters

### `configuration` [in]

Combination of values from [DIRECTMANIPULATION_DRAG_DROP_CONFIGURATION](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/ne-directmanipulation-directmanipulation_drag_drop_configuration).

For the configuration to be valid, *configuration* must contain exactly one of the following three values:

* **DIRECTMANIPULATION_DRAG_DROP_CONFIGURATION_SELECT_ONLY**
* **DIRECTMANIPULATION_DRAG_DROP_CONFIGURATION_SELECT_DRAG**
* **DIRECTMANIPULATION_DRAG_DROP_CONFIGURATION_HOLD_DRAG**

If **DIRECTMANIPULATION_DRAG_DROP_CONFIGURATION_SELECT_ONLY** or **DIRECTMANIPULATION_DRAG_DROP_CONFIGURATION_SELECT_DRAG** is specified, one of **DIRECTMANIPULATION_DRAG_DROP_CONFIGURATION_VERTICAL** or **DIRECTMANIPULATION_DRAG_DROP_CONFIGURATION_HORIZONTAL** is required.

If **DIRECTMANIPULATION_DRAG_DROP_CONFIGURATION_HOLD_DRAG** is specified, both **DIRECTMANIPULATION_DRAG_DROP_CONFIGURATION_VERTICAL** and **DIRECTMANIPULATION_DRAG_DROP_CONFIGURATION_HORIZONTAL** are required.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The configuration of the behavior can be set before or after it has been added to a viewport. If a configuration change is made while an interaction is occurring, the new configuration takes effect on the next interaction.

 

[IDirectManipulationViewport::ActivateConfiguration](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationviewport-activateconfiguration) should not be called prior to calling **IDirectManipulationDragDropBehavior::SetConfiguration**. This will result in unexpected behavior.

## See also

[IDirectManipulationDragDropBehavior](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationdragdropbehavior)

[IDirectManipulationViewport::ActivateConfiguration](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationviewport-activateconfiguration)