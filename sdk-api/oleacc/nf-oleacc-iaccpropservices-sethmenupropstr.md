# IAccPropServices::SetHmenuPropStr

## Description

This method wraps [SetPropValue](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccpropservices-setpropvalue), providing a more convenient entry point for callers who are annotating **HMENU**-based accessible elements.

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

### `str` [in]

Type: **[LPCWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies a new value for the *idProp* property.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If successful, returns S_OK.

May return other error codes under exceptional error conditions such as low memory.

## Remarks

By using this method, the caller does not have to obtain an identity string; it can specify the *hmenu*, *idObject*, and *idChild* parameters directly.

## See also

[ClearHmenuProps](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccpropservices-clearhmenuprops)

[IAccPropServices](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccpropservices)

[SetHmenuProp](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccpropservices-sethmenuprop)

[SetHmenuPropServer](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccpropservices-sethmenupropserver)

[SetPropValue](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccpropservices-setpropvalue)