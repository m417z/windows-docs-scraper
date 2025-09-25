# IPackageDebugSettings::EnableDebugging

## Description

Enables debug mode for the processes of the specified package.

## Parameters

### `packageFullName` [in]

The package full name.

### `debuggerCommandLine` [in]

The command line to use to launch processes from this package. This parameter is optional.

### `environment` [in]

Any environment strings to pass to processes. This parameter is optional.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Enabling debug mode has the following effects:

* Optionally enables debugger attach on activation.
* Disables activation timeouts.
* Disables automatic process suspension.
* Disables automatic process termination.
* Disables automatic process resumption.

To restore normal operation, call the [DisableDebugging](https://learn.microsoft.com/previous-versions/hh438394(v=vs.85)) method.

## See also

[DisableDebugging](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ipackagedebugsettings-disabledebugging)

[IPackageDebugSettings](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ipackagedebugsettings)