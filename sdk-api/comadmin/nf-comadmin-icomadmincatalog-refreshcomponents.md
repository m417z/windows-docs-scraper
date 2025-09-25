# ICOMAdminCatalog::RefreshComponents

## Description

Updates component registration information from the registry.

You generally should not use **RefreshComponents**. The recommended way to update components in COM+ applications is to remove and reinstall the components using [ICOMAdminCatalog::InstallComponent](https://learn.microsoft.com/windows/desktop/api/comadmin/nf-comadmin-icomadmincatalog-installcomponent) so that complete registration information is updated in the registry database.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## Remarks

The **RefreshComponents** method is called from within the Microsoft Visual Basic 6.0 development environment when you use the **Auto-refresh** or **Refresh all** components now features from the **Component Services** submenu of the **Add-Ins** menu.

To find mismatches, **RefreshComponents** compares CLSIDs and ProgIDs between the COM+ class registration database (RegDB) and the registry. This method updates components only when there is both a mismatch between CLSIDs and a match between corresponding ProgIDs.

Only CLSID information is updated to RegDB. No interface or method information is updated. Components that are refreshed using **RefreshComponents** cannot be configured or secured at the interface or method levels within COM+ applications.

## See also

[ICOMAdminCatalog](https://learn.microsoft.com/windows/desktop/api/comadmin/nn-comadmin-icomadmincatalog)