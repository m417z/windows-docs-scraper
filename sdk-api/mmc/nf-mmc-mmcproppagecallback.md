# MMCPropPageCallback function

## Description

The
**MMCPropPageCallback** function is only required by Microsoft Foundation Classes (MFC)-based snap-ins. The function sets the correct module state during page creation.

## Parameters

### `vpsp`

A pointer to the Microsoft Windows
[PROPSHEETPAGE](https://learn.microsoft.com/windows/desktop/api/prsht/ns-prsht-propsheetpagea_v2) structure. Be aware that by default, MFC installs its own callback in the **pfnCallback** member of the structure.

## Return value

This callback function can return one of these values.

## Remarks

This function should not be called by snap-ins that statically link MFC libraries. A call to this function by such a snap-in will not link correctly.

For each page derived from **CPropertyPage**, call
**MMCPropPageCallback** with a pointer to the page's callback, following these guidelines:

* All pages for a particular property sheet must use the same callback pointer.
* If you replace MFC's callback with your own, your callback must call MFC's callback.
* You must call this function with each **CPropertyPage** derived class.

MFC must have the correct module state set from exported functions or COM interfaces. This includes calls made from the operating system to the module. For exported functions or COM interfaces, this is done by adding the AFX_MANAGE_STATE macro at the beginning of all the exported functions in snap-in DLLs that dynamically link to MFC. This is done by adding the following line of code to the beginning of functions exported from the snap-in:

```vb
AFX_MANAGE_STATE(AfxGetStaticModuleState( ))
```

For an operating system call, MFC does this automatically. Because MMC's property sheet is not an MFC **CPropertySheet**, the operating system call due to the callback is in the wrong module state. As a result, you need to make sure that the module state is correctly set during the page creation. This is the purpose of
**MMCPropPageCallback**. After the module state has been set, the only AFX_MANAGE_STATE calls that need to be made are those exposed by the COM interfaces implemented by the snap-in (for example
[IExtendPropertySheet2::CreatePropertyPages](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa814847(v=vs.85))). To determine whether the application has the correct module state, look at **CWinApp** and note the application name.

## See also

[PROPSHEETPAGE](https://learn.microsoft.com/windows/desktop/api/prsht/ns-prsht-propsheetpagea_v3)