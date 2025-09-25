# ID2D1EffectContext::CreateEffect

## Description

Creates a Direct2D effect for the specified class ID.
This is the same as [ID2D1DeviceContext::CreateEffect](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-createeffect) so custom effects can create other effects and wrap them in a transform.

## Parameters

### `effectId`

Type: **REFCLSID**

The built-in or registered effect ID to create the effect. See [Built-in Effects](https://learn.microsoft.com/windows/desktop/Direct2D/built-in-effects) for a list of effect IDs.

### `effect` [out]

Type: **[ID2D1Effect](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1effect)****

When this method returns, contains the address of a pointer to the effect.

## Return value

Type: **HRESULT**

The method returns an HRESULT. Possible values include, but are not limited to, those in the following table.

| HRESULT | Description |
| --- | --- |
| S_OK | No error occurred. |
| E_OUTOFMEMORY | Direct2D could not allocate sufficient memory to complete the call. |
| E_INVALIDARG | An invalid value was passed to the method. |
| D3DERR_OUTOFVIDEOMEMORY | Direct3D does not have enough display memory to perform the operation. |
| D2DERR_EFFECT_IS_NOT_REGISTERED | The specified effect is not registered by the system. |

## Remarks

The created effect does not reference count the DLL from which the effect was created. If the caller unregisters an effect while this effect is loaded, the resulting behavior is unpredictable.

## See also

[D2D1_BLEND_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/ns-d2d1effectauthor-d2d1_blend_description)

[Effects](https://learn.microsoft.com/windows/desktop/Direct2D/effects-overview)

[ID2D1BlendTransform](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1blendtransform)

[ID2D1EffectContext](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1effectcontext)