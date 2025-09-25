# IAccPropServices::SetHwndPropStr

## Description

This method wraps [SetPropValue](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccpropservices-setpropvalue), providing a more convenient entry point for callers who are annotating **HWND**-based accessible elements.

## Parameters

### `hwnd` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Identifies the accessible element that is to be annotated. This replaces the identity string.

### `idObject` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Identifies the accessible element that is to be annotated. This replaces the identity string.

### `idChild` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Identifies the accessible element that is to be annotated. This replaces the identity string.

### `idProp` [in]

Type: **MSAAPROPID**

Specifies which property of that element is to be annotated.

### `str` [in]

Type: **[LPCWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies a new value for that property.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If successful, returns S_OK.

May return other error codes under exceptional error conditions such as low memory.

## Remarks

By using this method, the caller does not have to obtain an identity string; it can specify the *hwnd*, *idObject*, and *idChild* parameters directly.

## See also

[ClearHwndProps](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccpropservices-clearhwndprops)

[IAccPropServices](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccpropservices)

[SetHwndProp](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccpropservices-sethwndprop)

[SetHwndPropServer](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccpropservices-sethwndpropserver)

[SetPropValue](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccpropservices-setpropvalue)