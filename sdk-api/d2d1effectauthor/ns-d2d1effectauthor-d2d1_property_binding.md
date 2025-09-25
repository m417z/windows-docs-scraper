# D2D1_PROPERTY_BINDING structure

## Description

Defines a property binding to a pair of functions which get and set the corresponding property.

## Members

### `propertyName`

 The name of the property.

### `setFunction`

 The function that will receive the data to set.

### `getFunction`

The function that will be asked to write the output data.

## Remarks

The **propertyName** is used to cross-correlate the property binding with the registration XML. The **propertyName** must be present in the XML call or the registration will fail.

All properties must be bound.

## See also

[ID2D1EffectImpl](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1effectimpl)

[ID2D1Factory::RegisterEffect](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1factory1-registereffectfromstring)