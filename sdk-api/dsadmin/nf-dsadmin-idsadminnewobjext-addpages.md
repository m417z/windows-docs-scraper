# IDsAdminNewObjExt::AddPages

## Description

The **IDsAdminNewObjExt::AddPages** method is called to enable the object creation wizard extension to add the desired pages to the wizard.

## Parameters

### `lpfnAddPage` [in]

Pointer to a function that the object creation wizard extension calls to add a page to the wizard. This function takes the following format.

```cpp
BOOL fnAddPage(HPROPSHEETPAGE hPage, LPARAM lParam);
```

*hPage* contains the handle of the wizard page created by calling [CreatePropertySheetPage](https://learn.microsoft.com/windows/desktop/api/prsht/nf-prsht-createpropertysheetpagea).

*lParam* is the *lParam* value passed to **AddPages**.

### `lParam` [in]

Contains data that is private to the administrative snap-in. This value is passed as the second parameter to *lpfnAddPage*.

## Return value

If the method is successful,
**S_OK** is returned. If the method fails, an OLE-defined error code is returned.

## Remarks

For each page, the wizard extension adds to the wizard, the extension fills in a [PROPSHEETPAGE](https://learn.microsoft.com/windows/desktop/api/prsht/ns-prsht-propsheetpagea_v2) structure, calls the [CreatePropertySheetPage](https://learn.microsoft.com/windows/desktop/api/prsht/nf-prsht-createpropertysheetpagea) function to create the page handle and then calls the *lpfnAddPage* function with the page handle and *lParam*.

This method is identical in format and operation to the [IShellPropSheetExt::AddPages](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellpropsheetext-addpages) method.

## See also

[CreatePropertySheetPage](https://learn.microsoft.com/windows/desktop/api/prsht/nf-prsht-createpropertysheetpagea)

[IDsAdminNewObjExt](https://learn.microsoft.com/windows/desktop/api/dsadmin/nn-dsadmin-idsadminnewobjext)

[IShellPropSheetExt::AddPages](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellpropsheetext-addpages)

[PROPSHEETPAGE](https://learn.microsoft.com/windows/desktop/api/prsht/ns-prsht-propsheetpagea_v2)