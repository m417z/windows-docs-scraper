# IPackageDebugSettings::DisableDebugging

## Description

Disables debug mode for the processes of the specified package.

## Parameters

### `packageFullName` [in]

The package full name.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method has no effect if the [EnableDebugging](https://learn.microsoft.com/previous-versions/hh438395(v=vs.85)) method was not previously called for this package.

## See also

[EnableDebugging](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ipackagedebugsettings-enabledebugging)

[IPackageDebugSettings](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ipackagedebugsettings)