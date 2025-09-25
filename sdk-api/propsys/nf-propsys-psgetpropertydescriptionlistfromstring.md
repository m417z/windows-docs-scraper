# PSGetPropertyDescriptionListFromString function

## Description

Gets an instance of a property description list interface for a specified property list.

## Parameters

### `pszPropList` [in]

Type: **LPCWSTR**

Pointer to a null-terminated, Unicode string that identifies the property list. See [IPropertySystem::GetPropertyDescriptionListFromString](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-ipropertysystem-getpropertydescriptionlistfromstring) for more information about the format of this parameter.

### `riid` [in]

Type: **REFIID**

Reference to the interface ID of the requested interface.

### `ppv` [out]

Type: **void****

When this function returns, contains the interface pointer requested in *riid*. This is typically [IPropertyDescriptionList](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertydescriptionlist).

## Return value

Type: **PSSTDAPI**

Returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The interface was obtained. |
| **E_INVALIDARG** | The *ppv* parameter is **NULL**. |

## Remarks

This function calls the property subsystem implementation of [IPropertySystem::GetPropertyDescriptionListFromString](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-ipropertysystem-getpropertydescriptionlistfromstring) to obtain a collection of properties provided as a semicolon-delimited property list string.

We recommend that you use the **IID_PPV_ARGS** macro, defined in Objbase.h, to package the *riid* and *ppv* parameters. This macro provides the correct IID based on the interface pointed to by the value in *ppv*, which eliminates the possibility of a coding error.

For more information about property schemas, see [Property Schemas](https://learn.microsoft.com/windows/desktop/properties/building-property-handlers-property-schemas).

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [PSGetPropertyDescriptionListFromString](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-psgetpropertydescriptionlistfromstring).

```cpp
IPropertyDescriptionList *pList;

HRESULT hr = PSGetPropertyDescriptionListFromString(L"prop:System.Title;System.Size",
                                                    IID_PPV_ARGS(&pList));

if (SUCCEEDED(hr))
{
    // pList is now valid.

    pList->Release();
}
```