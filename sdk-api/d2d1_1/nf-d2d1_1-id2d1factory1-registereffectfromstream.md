# ID2D1Factory1::RegisterEffectFromStream

## Description

Registers an effect within the factory instance with the property XML specified as a stream.

## Parameters

### `classId` [in]

Type: **REFCLSID**

The identifier of the effect to be registered.

### `propertyXml` [in]

Type: **IStream**

A list of the effect properties, types, and metadata.

### `bindings` [in, optional]

Type: **const [D2D1_PROPERTY_BINDING](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/ns-d2d1effectauthor-d2d1_property_binding)***

An array of properties and methods.

This binds a property by name to a particular method implemented by the effect author to handle the property.
The name must be found in the corresponding *propertyXml*.

### `bindingsCount`

Type: **[UINT32](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_uint32_description)**

The number of bindings in the binding array.

### `effectFactory`

Type: **[PD2D1_EFFECT_FACTORY](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nc-d2d1_1-pd2d1_effect_factory)**

The static factory that is used to create the corresponding effect.

## Return value

Type: **HRESULT**

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| HRESULT | Description |
| --- | --- |
| S_OK | No error occurred. |
| E_OUTOFMEMORY | Direct2D could not allocate sufficient memory to complete the call. |
| E_INVALIDARG | An invalid parameter was passed to the returning function. |

## Remarks

Direct2D effects must define their properties at registration time via registration XML. An effect declares several required system properties,
and can also declare custom properties. See [Custom effects](https://learn.microsoft.com/windows/desktop/Direct2D/custom-effects)
for more information about formatting the *propertyXml* parameter.

[RegisterEffect](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1factory1-registereffectfromstring) is both atomic and reference counted. To unregister an effect,
call [UnregisterEffect](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1factory1-unregistereffect) with the *classId* of the effect.

**Important** [RegisterEffect](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1factory1-registereffectfromstring) does not hold a reference to the DLL or executable file in which
the effect is contained. The application must independently make sure that the lifetime of the DLL or executable file completely contains all instances of each registered and created effect.

Aside from the [built-in effects](https://learn.microsoft.com/windows/desktop/Direct2D/built-in-effects) that are globally registered, this API registers effects only for this factory, derived device,
and device context interfaces.

## See also

[ID2D1Factory1](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1factory1)

[ID2D1Factory1::UnregisterEffect](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1factory1-unregistereffect)