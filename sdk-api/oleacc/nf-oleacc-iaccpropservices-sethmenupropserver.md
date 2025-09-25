# IAccPropServices::SetHmenuPropServer

## Description

This method wraps [SetPropServer](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccpropservices-setpropserver), providing a convenient entry point for callers who are annotating **HMENU**-based accessible elements.

## Parameters

### `hmenu` [in]

Type: **[HMENU](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Identifies the **HMENU**-accessible element to be annotated.

### `idChild` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Identifies the accessible element that is to be annotated. This replaces the identity string.

### `paProps` [in]

Type: **const MSAAPROPID***

Specifies an array of properties that is to be handled by the specified callback object.

### `cProps` [in]

Type: **int**

Specifies the number of properties in the *paProps* array.

### `pServer` [in]

Type: **IAccPropServer***

Specifies the callback object, which will be invoked when a client requests one of the overridden properties.

### `annoScope` [in]

Type: **AnnoScope**

May be ANNO_THIS, indicating that the annotation affects the indicated accessible element only; or ANNO_CONTAINER, indicating that it applies to the element and its immediate element children.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If successful, returns S_OK.

Returns E_INVALIDARG if any of the properties in the *paProps* array are not supported properties, if the identity string is not valid, or if *annoScope* is not one of ANNO_THIS or ANNO_CONTAINER.

May return other error codes under exceptional error conditions such as low memory.

## Remarks

By using this method, the caller does not have to obtain an identity string; it can specify the *hmenu* and *idChild* parameters directly.

## See also

[ClearHmenuProps](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccpropservices-clearhmenuprops)

[IAccPropServices](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccpropservices)

[SetHmenuProp](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccpropservices-sethmenuprop)

[SetHmenuPropStr](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccpropservices-sethmenupropstr)

[SetPropServer](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccpropservices-setpropserver)