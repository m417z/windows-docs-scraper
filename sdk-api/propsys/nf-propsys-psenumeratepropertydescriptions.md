# PSEnumeratePropertyDescriptions function

## Description

A wrapper API that calls the schema subsystem's [IPropertySystem::EnumeratePropertyDescriptions](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-ipropertysystem-enumeratepropertydescriptions). This function retrieves an instance of the subsystem object that implements [IPropertyDescriptionList](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertydescriptionlist), to obtain either the entire list or a partial list of property descriptions in the system.

## Parameters

### `filterOn` [in]

Type: **[PROPDESC_ENUMFILTER](https://learn.microsoft.com/windows/desktop/api/propsys/ne-propsys-propdesc_enumfilter)**

The list to return. [PROPDESC_ENUMFILTER](https://learn.microsoft.com/windows/desktop/api/propsys/ne-propsys-propdesc_enumfilter) shows the valid values for this method.

### `riid` [in]

Type: **REFIID**

Reference to the interface ID of the requested interface.

### `ppv` [out]

Type: **void****

The address of an [IPropertyDescriptionList](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertydescriptionlist) interface pointer.

## Return value

Type: **PSSTDAPI**

Returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | Indicates an interface is obtained. |
| **E_INVALIDARG** | Indicates that *ppv* is **NULL**. |

## Remarks

We recommend that you use the IID_PPV_ARGS macro, defined in objbase.h, to package the *riid* and *ppv* parameters. This macro provides the correct IID based on the interface pointed to by the value in *ppv*, eliminating the possibility of a coding error.