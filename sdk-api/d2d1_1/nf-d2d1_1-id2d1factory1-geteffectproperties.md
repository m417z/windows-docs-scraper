# ID2D1Factory1::GetEffectProperties

## Description

Retrieves the properties of an effect.

## Parameters

### `effectId` [in]

Type: **REFCLSID**

The ID of the effect to retrieve properties from.

### `properties` [out]

Type: **[ID2D1Properties](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1properties)****

When this method returns, contains the address of a pointer to the property interface that can be used to query the metadata of the effect.

## Return value

Type: **HRESULT**

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| HRESULT | Description |
| --- | --- |
| S_OK | No error occurred. |
| D2DERR_EFFECT_IS_NOT_REGISTERED | The requested effect could not be found. |
| E_OUTOFMEMORY | Direct2D could not allocate sufficient memory to complete the call. |

## Remarks

The returned effect properties will have all the mutable properties for the effect set to a default of **NULL**, or an empty value.

* Value types will be zero-filled.
* Blob and string types will be zero-length.
* Array types will have length 1 and the element of the array will conform to the previous rules.

This method cannot be used to return the properties for any effect not visible to [ID2D1DeviceContext::CreateEffect](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-createeffect).

## See also

[ID2D1Factory1](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1factory1)

[ID2D1Factory1::GetRegisteredEffects](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1factory1-getregisteredeffects)

[ID2D1Factory1::RegisterEffect](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1factory1-registereffectfromstring)