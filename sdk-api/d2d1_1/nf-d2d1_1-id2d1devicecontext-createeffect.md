# ID2D1DeviceContext::CreateEffect

## Description

Creates an effect for the specified class ID.

## Parameters

### `effectId`

Type: **REFCLSID**

The class ID of the effect to create. See [Built-in Effects](https://learn.microsoft.com/windows/desktop/Direct2D/built-in-effects) for a list of effect IDs.

### `effect` [out]

Type: **[ID2D1Effect](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1effect)****

When this method returns, contains the address of a pointer to a new effect.

## Return value

Type: **HRESULT**

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| HRESULT | Description |
| --- | --- |
| S_OK | No error occurred. |
| E_OUTOFMEMORY | Direct2D could not allocate sufficient memory to complete the call. |
| E_INVALIDARG | An invalid value was passed to the method. |
| D3DERR_OUTOFVIDEOMEMORY | Direct3D does not have enough display memory to perform the operation. |
| D2DERR_EFFECT_IS_NOT_REGISTERED | The specified effect is not registered by the system. |
| E_NOTFOUND | Other possible HRESULT for an effect not being registered (like D2DERR_EFFECT_IS_NOT_REGISTERED). |
| D2DERR_INSUFFICIENT_DEVICE_CAPABILITIES | The effect requires capabilities not supported by the D2D device. |

## Remarks

If the created effect is a custom effect that is implemented in a DLL, this doesn't increment the reference count for that DLL.
If the application deletes an effect while that effect is loaded, the resulting behavior is unpredictable.

## See also

[Effects](https://learn.microsoft.com/windows/desktop/Direct2D/effects-overview)

[ID2D1DeviceContext](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1devicecontext)

[ID2D1Effect](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1effect)

[ID2D1Factory1::RegisterEffect](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1factory1-registereffectfromstring)