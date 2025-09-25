# IGraphicsEffectD2D1Interop::GetNamedPropertyMapping (windows.graphics.effects.interop.h)

## Description

Retrieves the mapping for an effect property.

## Parameters

### `name`

Type: **LPCWSTR**

Name of the property.

### `index` [out]

Type: **UINT***

When this method returns, this parameter will contain the index of the property.

### `mapping` [out]

Type: **[GRAPHICS_EFFECT_PROPERTY_MAPPING](https://learn.microsoft.com/windows/desktop/api/windows.graphics.effects.interop/ne-windows-graphics-effects-interop-graphics_effect_property_mapping)***

Indicates how a strongly-typed effect property maps to an underlying Direct2D effect property.

## Return value

Type: **HRESULT**

This method returns an HRESULT success or error code.

## See also

[IGraphicsEffectD2D1Interop](https://learn.microsoft.com/windows/desktop/api/windows.graphics.effects.interop/nn-windows-graphics-effects-interop-igraphicseffectd2d1interop)