# IPackageDebugSettings::Suspend

## Description

Suspends the processes of the package if they are currently running.

## Parameters

### `packageFullName` [in]

The package full name.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The system has successfully started suspending the package. |
| *A failing HRESULT value* | No process in the package is currently running, or another error occurred. |

## Remarks

Each process receives the [Suspending](https://learn.microsoft.com/uwp/api/windows.applicationmodel.core.coreapplication.suspending) event, which is useful for stepping through your apps as they respond to this event.

## See also

[IPackageDebugSettings](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ipackagedebugsettings)

[Resume](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ipackagedebugsettings-resume)