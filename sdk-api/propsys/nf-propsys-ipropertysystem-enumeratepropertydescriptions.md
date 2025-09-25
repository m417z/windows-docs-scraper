# IPropertySystem::EnumeratePropertyDescriptions

## Description

Gets an instance of the subsystem object that implements [IPropertyDescriptionList](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertydescriptionlist), to obtain either the entire or a partial list of property descriptions in the system.

## Parameters

### `filterOn` [in]

Type: **[PROPDESC_ENUMFILTER](https://learn.microsoft.com/windows/desktop/api/propsys/ne-propsys-propdesc_enumfilter)**

The list to return. See [PROPDESC_ENUMFILTER](https://learn.microsoft.com/windows/desktop/api/propsys/ne-propsys-propdesc_enumfilter). Valid values for this method are 0 through 4.

### `riid` [in]

Type: **REFIID**

A reference to the desired IID.

### `ppv` [out]

Type: **void****

The address of an [IPropertyDescriptionList](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertydescriptionlist) interface pointer.

## Return value

Type: **HRESULT**

Returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | Indicates interface is obtained. |
| **E_INVALIDARG** | Indicates *ppv* is **NULL**. |

## Remarks

This method is not implemented where BUILDING_DOWNLEVEL_LIB is defined.

It is recommended that you use the IID_PPV_ARGS macro, defined in objbase.h, to package the *riid* and *ppv* parameters. This macro provides the correct IID based on the interface pointed to by the value in *ppv*, eliminating the possibility of a coding error.

## See also

[IPropertySystem](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertysystem)