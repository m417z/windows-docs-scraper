# IAccPropServices::SetHmenuProp

## Description

This method wraps [SetPropValue](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccpropservices-setpropvalue), providing a convenient entry point for callers who are annotating **HMENU**-based accessible elements. If the new value is a string, you can use [IAccPropServices::SetHmenuPropStr](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccpropservices-sethmenupropstr) instead.

## Parameters

### `hmenu` [in]

Type: **[HMENU](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Identifies the **HMENU**-based accessible element to be annotated.

### `idChild` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies the child ID of the accessible element.

### `idProp` [in]

Type: **MSAAPROPID**

Specifies which property of the accessible element is to be annotated.

### `var` [in]

Type: **VARIANT**

Specifies a new value for the *idProp* property.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If successful, returns S_OK.

May return other error codes under exceptional error conditions such as low memory.

## See also

[ClearHmenuProps](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccpropservices-clearhmenuprops)

[IAccPropServices](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccpropservices)

[SetHmenuPropServer](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccpropservices-sethmenupropserver)

[SetHmenuPropStr](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccpropservices-sethmenupropstr)

[SetPropValue](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccpropservices-setpropvalue)