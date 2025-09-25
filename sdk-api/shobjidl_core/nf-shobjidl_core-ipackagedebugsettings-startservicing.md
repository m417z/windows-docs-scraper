# IPackageDebugSettings::StartServicing

## Description

Suspends and terminates the non-background portion of the apps associated with the specified package and cancels the background tasks associated with the package.

## Parameters

### `packageFullName` [in]

The package full name.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Use the **StartServicing** method to simulate what happens when a package is updated to a newer version. New background task activations are buffered (delayed) until you call the [StopServicing](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ipackagedebugsettings-stopservicing) method.

## See also

[IPackageDebugSettings](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ipackagedebugsettings)

[StopServicing](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ipackagedebugsettings-stopservicing)