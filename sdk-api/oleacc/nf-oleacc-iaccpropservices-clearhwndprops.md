# IAccPropServices::ClearHwndProps

## Description

This method wraps [SetPropValue](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccpropservices-setpropvalue), [SetPropServer](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccpropservices-setpropserver), and [ClearProps](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccpropservices-clearprops), and provides a convenient entry point for callers who are annotating **HWND**-based accessible elements.

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

### `paProps` [in]

Type: **const MSAAPROPID***

Specifies an array of properties that is to be reset. These properties will revert to the default behavior that they displayed before they were annotated.

### `cProps` [in]

Type: **int**

Specifies the number of properties in the *paProps* array.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If successful, returns S_OK, even if the specified properties were never annotated on the accessible object; clearing already-cleared properties is considered a success.

Returns E_INVALIDARG if any of the properties in the *paProps* array are not supported.

May return other error codes under exceptional error conditions such as low memory.

For descriptions of return values, see the corresponding [SetPropValue](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccpropservices-setpropvalue), [SetPropServer](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccpropservices-setpropserver), or [ClearProps](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccpropservices-clearprops) method.

## Remarks

By using this method, the caller does not have to obtain an identity string; it can specify the *hwnd*, *idObject*, and *idChild* parameters directly.

Additionally, [SetHwndPropStr](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccpropservices-sethwndpropstr) takes a regular Unicode string as a parameter; the caller does not need to specially allocate a **BSTR**.

## See also

[ClearProps](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccpropservices-clearprops)

[IAccPropServices](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccpropservices)

[SetHwndProp](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccpropservices-sethwndprop)

[SetHwndPropServer](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccpropservices-sethwndpropserver)

[SetHwndPropStr](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccpropservices-sethwndpropstr)