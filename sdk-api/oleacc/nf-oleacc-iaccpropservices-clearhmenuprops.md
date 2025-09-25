# IAccPropServices::ClearHmenuProps

## Description

This method wraps [ClearProps](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccpropservices-clearprops), and provides a convenient entry point for callers who are annotating **HMENU**-based accessible elements.

## Parameters

### `hmenu` [in]

Type: **[HMENU](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Identifies the **HMENU**-based accessible element to be annotated.

### `idChild` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies the child ID of the accessible element.

### `paProps` [in]

Type: **const MSAAPROPID***

Specifies an array of properties to be reset. These properties will revert to the default behavior that they displayed before they were annotated.

### `cProps` [in]

Type: **int**

Specifies the number of properties in the *paProps* array.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If successful, returns S_OK, even if the specified properties were never annotated on the accessible object; clearing already-cleared properties is considered a success.

Returns E_INVALIDARG if any of the properties in the *paProps* array are not supported.

May return other error codes under exceptional error conditions such as low memory.

For descriptions of other parameters and return values, see the [ClearProps](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccpropservices-clearprops) method.

## Remarks

By using this method, the caller does not have to obtain an identity string; it can specify the *hmenu* and *idChild* parameters directly.

## See also

[ClearProps](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccpropservices-clearprops)

[IAccPropServices](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccpropservices)

[SetHmenuProp](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccpropservices-sethmenuprop)

[SetHmenuPropServer](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccpropservices-sethmenupropserver)

[SetHmenuPropStr](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccpropservices-sethmenupropstr)