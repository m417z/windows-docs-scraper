# IXpsOMPageReference::IsPageLoaded

## Description

Gets the referenced page status, which indicates whether the page is loaded.

## Parameters

### `isPageLoaded` [out, retval]

A Boolean value that indicates the status of the page.

| Value | Meaning |
| --- | --- |
| **TRUE** | The page is loaded. |
| **FALSE** | The page is not loaded. |

## Return value

If the method succeeds, it returns S_OK; otherwise, it returns an **HRESULT** error code.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *isPageLoaded* is **NULL**. |

## See also

[IXpsOMPageReference](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompagereference)