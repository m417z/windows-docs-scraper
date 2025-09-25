# IPropertyPage::Help

## Description

Invokes the property page help in response to an end-user request.

## Parameters

### `pszHelpDir` [in]

A pointer to the string under the **HelpDir** key in the property page's CLSID information in the registry. If **HelpDir** does not exist, this will be the path found in the **[InprocServer32](https://learn.microsoft.com/windows/desktop/com/inprocserver32)** entry minus the server file name. (Note that **[LocalServer32](https://learn.microsoft.com/windows/desktop/com/localserver32)** is not checked, because local property pages are not supported).

## Return value

This method can return the standard return values E_OUTOFMEMORY and E_UNEXPECTED, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The page displayed its own help. |
| **E_NOTIMPL** | Help is either not provided or is provided only through the information is [PROPPAGEINFO](https://learn.microsoft.com/windows/desktop/api/ocidl/ns-ocidl-proppageinfo). |

## Remarks

### Notes to Callers

Calls to this method must occur between calls to [IPropertyPage::Activate](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ipropertypage-activate) and [IPropertyPage::Deactivate](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ipropertypage-deactivate).

### Notes to Implementers

If the page fails this method (such as E_NOTIMPL), then the frame will attempt to use the **pszHelpFile** and **dwHelpContext** members of the [PROPPAGEINFO](https://learn.microsoft.com/windows/desktop/api/ocidl/ns-ocidl-proppageinfo) structure obtained through [IPropertyPage::GetPageInfo](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ipropertypage-getpageinfo). Therefore, the page should either implement **IPropertyPage::Help** or return help information through **IPropertyPage::GetPageInfo**.

## See also

[IPropertyPage](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ipropertypage)

[PROPPAGEINFO](https://learn.microsoft.com/windows/desktop/api/ocidl/ns-ocidl-proppageinfo)