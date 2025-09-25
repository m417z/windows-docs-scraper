# IDirectManipulationViewport::ActivateConfiguration

## Description

Sets the configuration for input interaction.

## Parameters

### `configuration` [in]

One or more values from [DIRECTMANIPULATION_CONFIGURATION](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/ne-directmanipulation-directmanipulation_configuration) that specify the interaction configuration for the viewport.

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

An interaction configuration specifies how the manipulation engine responds to input and which manipulations are supported. Any number of possible configurations can be added to the viewport using [AddConfiguration](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationviewport-addconfiguration) before processing input.

Configurations can be switched by the application at runtime using **ActivateConfiguration**.

When a configuration is no longer required (and is not currently active), it can be removed using [RemoveConfiguration](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationviewport-removeconfiguration).

If a configuration has not been added using [AddConfiguration](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationviewport-addconfiguration), it can be automatically added and then activated by calling **ActivateConfiguration**.

**Note** If input processing is occurring, this call will fail.

This method fails if a [drag and drop](https://learn.microsoft.com/previous-versions/windows/desktop/directmanipulation/direct-manipulation-guids) behavior has been specified.

A [drag and drop](https://learn.microsoft.com/previous-versions/windows/desktop/directmanipulation/direct-manipulation-guids) behavior object cannot be attached after successfully calling this method.

#### Examples

The following example shows how to configure a viewport for horizontal panning.

```
HRESULT hr = pViewport>ActivateConfiguration(
    DIRECTMANIPULATION_CONFIGURATION_INTERACTION |
    DIRECTMANIPULATION_CONFIGURATION_TRANSLATION_X);
```

## See also

[IDirectManipulationViewport](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationviewport)