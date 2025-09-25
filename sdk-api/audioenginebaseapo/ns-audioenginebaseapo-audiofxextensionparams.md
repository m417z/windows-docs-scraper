# AudioFXExtensionParams structure

## Description

The AudioFXExtensionParams structure is passed to the system effects ControlPanel
Extension PropertyPage via [IShellPropSheetExt::AddPages](https://learn.microsoft.com/previous-versions/bb416595(v=msdn.10)).

## Members

### `AddPageParam`

Parameters for the Property Page extension.

### `pwstrEndpointID`

The ID for the audio endpoint.

### `pFxProperties`

An [IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore) object.

## See also

[IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore)

[IShellPropSheetExt::AddPages](https://learn.microsoft.com/previous-versions/bb416595(v=msdn.10))