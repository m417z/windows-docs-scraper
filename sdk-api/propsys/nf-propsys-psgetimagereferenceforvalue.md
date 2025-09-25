# PSGetImageReferenceForValue function

## Description

Gets an instance of a property description interface for a specified property.

## Parameters

### `propkey` [in]

Type: **REFPROPERTYKEY**

A reference to a [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey) structure that specifies the property.

### `propvar` [in]

Type: **REFIID**

A reference to the IID of the interface to retrieve through *ppv*.

### `ppszImageRes` [out]

Type: **void****

When this function returns successfully, contains the interface pointer requested in *riid*.

## Return value

Type: **HRESULT**

Returns **S_OK** if successful, or an error value otherwise, including the following:

| Return code | Description |
| --- | --- |
| **TYPE_E_ELEMENTNOTFOUND** |  |

## Remarks

We recommend that you use the [IID_PPV_ARGS](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-iid_ppv_args) macro, defined in Objbase.h, to package the *riid* and *ppv* parameters. This macro provides the correct IID based on the interface pointed to by the value in *ppv*, which eliminates the possibility of a coding error in *riid* that could lead to unexpected results.