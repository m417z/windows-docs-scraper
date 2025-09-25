# PropVariantToWinRTPropertyValue function

## Description

Extracts data from a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure into a Windows Runtime property value. Note that in some cases more than one [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) type maps to a single Windows Runtime property type.

## Parameters

### `propvar` [in]

Reference to a source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

### `riid` [in]

A reference to the IID of the interface to retrieve through *ppv*, typically IID_IPropertyValue (defined in Windows.Foundation.h).

### `ppv` [out]

When this method returns successfully, contains the interface pointer requested in *riid*. This is typically an [IPropertyValue](https://learn.microsoft.com/uwp/api/Windows.Foundation.IPropertyValue) pointer. If the call fails, this value is **NULL**.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

We recommend that you use the [IID_PPV_ARGS](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-iid_ppv_args) macro, defined in Objbase.h, to package the *riid* and *ppv* parameters. This macro provides the correct IID based on the interface pointed to by the value in *ppv*, which eliminates the possibility of a coding error in *riid* that could lead to unexpected results.

## See also

[PropertyValue class](https://learn.microsoft.com/uwp/api/Windows.Foundation.PropertyValue)