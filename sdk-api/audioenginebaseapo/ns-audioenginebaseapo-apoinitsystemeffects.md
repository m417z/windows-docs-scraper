# APOInitSystemEffects structure

## Description

The APOInitSystemEffects structure gets passed to the system effects APO for
initialization.

## Members

### `APOInit`

An [APOInitBaseStruct](https://learn.microsoft.com/windows/desktop/api/audioenginebaseapo/ns-audioenginebaseapo-apoinitbasestruct) structure.

### `pAPOEndpointProperties`

A pointer to an [IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore) object.

### `pAPOSystemEffectsProperties`

A pointer to an [IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore) object.

### `pReserved`

Reserved for future use.

### `pDeviceCollection`

A pointer to an IMMDeviceCollection object.

## See also

[APOInitBaseStruct](https://learn.microsoft.com/windows/desktop/api/audioenginebaseapo/ns-audioenginebaseapo-apoinitbasestruct)

[APOInitSystemEffects2](https://learn.microsoft.com/windows/desktop/api/audioenginebaseapo/ns-audioenginebaseapo-apoinitsystemeffects2)

[IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore)