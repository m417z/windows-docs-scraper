# IPackageDebugSettings::Resume

## Description

Resumes the processes of the package if they are currently suspended.

## Parameters

### `packageFullName` [in]

The package full name.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Each process receives the [Resuming](https://learn.microsoft.com/uwp/api/windows.applicationmodel.core.coreapplication.resuming) event, which is useful for stepping through your apps as they respond to this event.

## See also

[IPackageDebugSettings](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ipackagedebugsettings)

[Suspend](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ipackagedebugsettings-suspend)