# PROPPAGEINFO structure

## Description

Contains parameters used to describe a property page to a property frame. A property page fills a caller-provided structure in the [IPropertyPage::GetPageInfo](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ipropertypage-getpageinfo) method.

## Members

### `cb`

The size of the structure, in bytes.

### `pszTitle`

Pointer to an [OLESTR](https://learn.microsoft.com/windows/desktop/api/wtypesbase/nf-wtypesbase-olestr) that contains the string that appears in the tab for this page. The string must be allocated with [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc). The caller of [IPropertyPage::GetPageInfo](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ipropertypage-getpageinfo) is responsible for freeing the memory with [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

### `size`

Required dimensions of the page's dialog box, in pixels.

### `pszDocString`

Pointer to a text string describing the page, which can be displayed in the property sheet dialog box (current frame implementation doesn't use this field). The text must be allocated with [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc). The caller of [IPropertyPage::GetPageInfo](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ipropertypage-getpageinfo) is responsible for freeing the memory with [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

### `pszHelpFile`

Pointer to an [OLESTR](https://learn.microsoft.com/windows/desktop/api/wtypesbase/nf-wtypesbase-olestr) that contains the simple name of the help file that describes this property page used instead of implementing [IPropertyPage::Help](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ipropertypage-help). When the user presses Help, the Help method is normally called. If that method fails, the frame will open the help system with this help file (prefixed with the value of the HelpDir key in the property page's registry entries under its CLSID) and will instruct the help system to display the context described by the **dwHelpContext** field. The path must be allocated with [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc). The caller of [IPropertyPage::GetPageInfo](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ipropertypage-getpageinfo) is responsible for freeing the memory with [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

### `dwHelpContext`

Context identifier for the help topic within **pszHelpFile** that describes this page.

## Remarks

The **pszTitle**, **pszDocString**, and the **pszHelpFile** members specified in this structure should contain text sensitive to the locale obtained through [IPropertyPageSite::GetLocaleID](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ipropertypagesite-getlocaleid).

## See also

[IPropertyPage::GetPageInfo](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ipropertypage-getpageinfo)

[IPropertyPageSite::GetLocaleID](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ipropertypagesite-getlocaleid)

[OLESTR](https://learn.microsoft.com/windows/desktop/api/wtypesbase/nf-wtypesbase-olestr)