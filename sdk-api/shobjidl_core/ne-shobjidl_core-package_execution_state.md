# PACKAGE_EXECUTION_STATE enumeration

## Description

Represents the state of a Windows app package.

## Constants

### `PES_UNKNOWN:0`

The package is in an unknown state.

### `PES_RUNNING:1`

The package is running.

### `PES_SUSPENDING:2`

The package is being suspended.

### `PES_SUSPENDED:3`

The package is suspended.

### `PES_TERMINATED:4`

The package was terminated.

## See also

[IPackageIPackageDebugSettings::GetPackageExecutionState](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ipackagedebugsettings-getpackageexecutionstate)

[IPackageExecutionStateChangeNotification::OnStateChanged](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ipackageexecutionstatechangenotification-onstatechanged)