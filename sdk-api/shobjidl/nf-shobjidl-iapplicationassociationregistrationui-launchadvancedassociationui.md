# IApplicationAssociationRegistrationUI::LaunchAdvancedAssociationUI

## Description

Launches an advanced association dialog box through which the user can customize the associations for the application specified in *pszAppRegName*.

## Parameters

### `pszAppRegistryName` [in]

Type: **LPCWSTR**

A pointer to a null-terminated Unicode string that specifies the registered name of the application. This value is only valid if it matches one of the application strings registered under **HKCU\Software\RegisteredApplications** or under **HKLM\Software\RegisteredApplications**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Starting in Windows 10, this does not launch the association dialog box. It displays a dialog to the user informing them that they can change the default programs used to open file extensions in their **Settings**

## See also

[Default Programs](https://learn.microsoft.com/windows/desktop/shell/default-programs)

[IApplicationAssociationRegistrationUI](https://learn.microsoft.com/windows/desktop/api/shobjidl/nn-shobjidl-iapplicationassociationregistrationui)