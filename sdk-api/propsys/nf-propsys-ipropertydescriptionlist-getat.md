# IPropertyDescriptionList::GetAt

## Description

Gets the property description at the specified index in a property description list.

## Parameters

### `iElem` [in]

Type: **UINT**

The number of the property in the list string.

### `riid` [in]

Type: **REFIID**

A reference to the IID of the requested property description interface, typically IID_IPropertyDescription.

### `ppv` [out]

Type: **void****

When this method returns, contains the interface pointer requested in *riid*. Typically, this is [IPropertyDescription](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertydescription).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

It is recommended that you use the IID_PPV_ARGS macro, defined in objbase.h, to package the *riid* and *ppv* parameters. This macro provides the correct IID based on the interface pointed to by the value in *ppv*, eliminating the possibility of a coding error.