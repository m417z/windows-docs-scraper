# IPropertyPage::GetPageInfo

## Description

Retrieves information about the property page.

## Parameters

### `pPageInfo` [out]

A pointer to the caller-allocated [PROPPAGEINFO](https://learn.microsoft.com/windows/desktop/api/ocidl/ns-ocidl-proppageinfo) structure in which the property page stores its page information. All allocations stored in this structure become the responsibility of the caller.

## Return value

This method can return the standard return values E_OUTOFMEMORY and E_UNEXPECTED, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The structure was successfully filled. |
| **E_POINTER** | The address in *pPageInfo* is not valid. For example, it may be **NULL**. |

## Remarks

### Notes to Implementers

E_NOTIMPL is not a valid return value.

## See also

[IPropertyPage](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ipropertypage)