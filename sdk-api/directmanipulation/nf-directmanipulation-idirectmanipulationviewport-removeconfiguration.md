# IDirectManipulationViewport::RemoveConfiguration

## Description

Removes an interaction configuration for the viewport.

## Parameters

### `configuration` [in]

One of the values from [DIRECTMANIPULATION_CONFIGURATION](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/ne-directmanipulation-directmanipulation_configuration) that specifies the interaction configuration for the viewport.

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method removes a possible configuration that was added by using [AddConfiguration](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationviewport-addconfiguration). This method can be called only if the configuration is not active.

An interaction configuration specifies how the manipulation engine responds to input and which gestures are supported. Any number of configurations can be added to the viewport using [AddConfiguration](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationviewport-addconfiguration). Configurations can be switched by the application at runtime using [ActivateConfiguration](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationviewport-activateconfiguration). When a configuration is no longer required (and is not currently active), it can be removed using **RemoveConfiguration**.

#### Examples

The following example shows how to use this method.

```
HRESULT hr = pRegion->RemoveConfiguration(
    DIRECTMANIPULATION_CONFIGURATION_INTERACTION |
    DIRECTMANIPULATION_CONFIGURATION_TRANSLATION_X);

```

## See also

[IDirectManipulationViewport](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationviewport)