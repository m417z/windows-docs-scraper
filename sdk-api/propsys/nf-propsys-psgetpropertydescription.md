# PSGetPropertyDescription function

## Description

Gets an instance of a property description interface for a property specified by a [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey) structure.

## Parameters

### `propkey` [in]

Type: **REFPROPERTYKEY**

Reference to a [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey).

### `riid` [in]

Type: **REFIID**

Reference to the interface ID of the requested interface.

### `ppv` [out]

Type: **void****

When this function returns, contains the interface pointer requested in *riid*. This is typically [IPropertyDescription](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertydescription), [IPropertyDescriptionAliasInfo](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertydescriptionaliasinfo), or [IPropertyDescriptionSearchInfo](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertydescriptionsearchinfo).

## Return value

Type: **PSSTDAPI**

Returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The interface was obtained. |
| **E_INVALIDARG** | The *ppv* parameter is **NULL**. |
| **TYPE_E_ELEMENTNOTFOUND** | The [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey) does not exist in the schema subsystem cache. |

## Remarks

We recommend that you use the **IID_PPV_ARGS** macro, defined in Objbase.h, to package the *riid* and *ppv* parameters. This macro provides the correct IID based on the interface pointed to by the value in *ppv*, which eliminates the possibility of a coding error.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [PSGetPropertyDescription](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-psgetpropertydescription) to get the property description for the ratings property.

```cpp
IPropertyDescription *pPropDesc;

HRESULT hr = PSGetPropertyDescription(PKEY_Ratings, IID_PPV_ARGS(&pPropDesc));

if (SUCCEEDED(hr))
{
    // pPropDesc is now valid.

    pPropDesc->Release();
}
```

## See also

[PSGetPropertyDescriptionByName](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-psgetpropertydescriptionbyname)

[PSGetPropertySystem](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-psgetpropertysystem)