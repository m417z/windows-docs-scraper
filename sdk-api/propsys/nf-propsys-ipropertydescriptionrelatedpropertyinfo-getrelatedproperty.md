# IPropertyDescriptionRelatedPropertyInfo::GetRelatedProperty

## Description

Retrieves an [IPropertyDescription](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertydescription) object that represents the related property.

## Parameters

### `pszRelationshipName` [in]

Type: **LPCWSTR**

A pointer to a string that contains the relationship of the property to get.

### `riid` [in]

Type: **REFIID**

A reference to the IID of the interface to retrieve through the *ppv* parameter, typically IID_IPropertyDescription.

### `ppv` [out]

Type: **void****

Receives the interface pointer requested in the parameter. This is typically [IPropertyDescription](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertydescription).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

We recommend that you use the [IID_PPV_ARGS](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-iid_ppv_args) macro, defined in Objbase.h, to package the *riid* and *ppv* parameters. This macro provides the correct IID based on the interface pointed to by the value in *ppv*, which eliminates the possibility of a coding error in *riid* that could lead to unexpected results.

## See also

[IPropertyDescriptionRelatedPropertyInfo](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertydescriptionrelatedpropertyinfo)

[Property Description Schema](https://learn.microsoft.com/windows/desktop/properties/propdesc-schema-entry)