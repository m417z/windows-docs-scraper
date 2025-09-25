# IPackageDebugSettings::StartSessionRedirection

## Description

Causes background tasks for the specified package to activate in the specified user session.

## Parameters

### `packageFullName` [in]

The package full name.

### `sessionId` [in]

The identifier of the session which background tasks are redirected to.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IPackageDebugSettings](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ipackagedebugsettings)

[StopSessionRedirection](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ipackagedebugsettings-stopsessionredirection)