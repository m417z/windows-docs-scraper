# IPackageExecutionStateChangeNotification::OnStateChanged

## Description

Called when package state changes during Windows Store app debugging.

## Parameters

### `pszPackageFullName` [in]

The package full name.

### `pesNewState` [in]

The new state that the package changed to.

## Return value

Return **S_OK** when you implement the **OnStateChanged** method.

## See also

[IPackageExecutionStateChangeNotification](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ipackageexecutionstatechangenotification)

[RegisterForPackageStateChanges](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ipackagedebugsettings-registerforpackagestatechanges)