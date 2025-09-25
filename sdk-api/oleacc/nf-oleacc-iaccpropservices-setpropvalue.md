# IAccPropServices::SetPropValue

## Description

Use **SetPropValue** to identify the accessible element to be annotated, specify the property to be annotated, and provide a new value for that property.

If server developers know the **HWND** of the accessible element they want to annotate, they can use one of the following methods:

* [IAccPropServices::SetHwndPropStr](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccpropservices-sethwndpropstr),
* [IAccPropServices::SetHwndProp](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccpropservices-sethwndprop), or
* [IAccPropServices::SetHwndPropServer](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccpropservices-sethwndpropserver)

## Parameters

### `pIDString` [in]

Type: **const [BYTE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Identifies the accessible element that is to be annotated.

### `dwIDStringLen` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies the length of the string identified by the *pIDString* parameter.

### `idProp` [in]

Type: **MSAAPROPID**

Specifies the property of the accessible element to be annotated.

### `var` [in]

Type: **VARIANT**

Specifies a new value for the property.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If successful, returns S_OK.

Returns E_INVALIDARG if *idProp* is not a supported property, if *var* is not a supported type for that property, or if the identity string is not valid.

May return other error codes under exceptional error conditions such as low memory.

## Remarks

See the support section for a list of supported properties and their expected types. Note that currently some properties are supported only when a callback is used and cannot be specified directly using this method.