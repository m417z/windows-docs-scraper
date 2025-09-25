# IDirectManipulationViewport::AddConfiguration

## Description

Adds an interaction configuration for the viewport.

## Parameters

### `configuration` [in]

One of the values from [DIRECTMANIPULATION_CONFIGURATION](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/ne-directmanipulation-directmanipulation_configuration) that specifies the interaction configuration for the viewport.

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

An interaction configuration specifies how the manipulation engine responds to input and which manipulations are supported. Any number of possible configurations can be added to the viewport using **AddConfiguration** before processing input.

Configurations can be switched by the application at runtime using [ActivateConfiguration](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationviewport-activateconfiguration).

When a configuration is no longer required (and is not currently active), it can be removed using [RemoveConfiguration](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationviewport-removeconfiguration).

If a configuration has not been added using **AddConfiguration**, it can be automatically added and then activated by calling [ActivateConfiguration](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationviewport-activateconfiguration).

**Note** If input processing is occurring, this call will fail.

This method fails if a [drag and drop](https://learn.microsoft.com/previous-versions/windows/desktop/directmanipulation/direct-manipulation-guids) behavior has been specified.

A [drag and drop](https://learn.microsoft.com/previous-versions/windows/desktop/directmanipulation/direct-manipulation-guids) behavior object cannot be attached after successfully calling this method.

You cannot add another [drag and drop](https://learn.microsoft.com/previous-versions/windows/desktop/directmanipulation/direct-manipulation-guids) behavior after an existing one has already been added.

This method is designed to allow an application to switch pre-added configurations, as a configuration cannot be changed while a manipulation is occurring. Under most circumstances it is better to update the configuration using [ActivateConfiguration](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationviewport-activateconfiguration).

## See also

[IDirectManipulationViewport](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationviewport)