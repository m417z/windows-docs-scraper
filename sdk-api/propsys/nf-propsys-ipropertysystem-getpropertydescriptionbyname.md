# IPropertySystem::GetPropertyDescriptionByName

## Description

Gets an instance of the subsystem object that implements [IPropertyDescription](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertydescription), to obtain the property description for a given canonical name.

## Parameters

### `pszCanonicalName` [in]

Type: **LPCWSTR**

A pointer to a string that identifies the property.

### `riid` [in]

Type: **REFIID**

A reference to the desired IID.

### `ppv` [out]

Type: **void****

The address of an [IPropertyDescription](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertydescription) interface pointer.

## Return value

Type: **PSSTDAPI**

Returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | Indicates that the interface is obtained. |
| **E_INVALIDARG** | Indicates *pszCanonicalName* is **NULL**. |
| **TYPE_E_ELEMENTNOTFOUND** | Indicates that the canonical name does not exist in the schema subsystem cache. |

## Remarks

It is recommended that you use the IID_PPV_ARGS macro, defined in objbase.h, to package the *riid* and *ppv* parameters. This macro provides the correct IID based on the interface pointed to by the value in *ppv*, eliminating the possibility of a coding error.

## See also

[IPropertySystem](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertysystem)