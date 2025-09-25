# IPackageDebugSettings::UnregisterForPackageStateChanges

## Description

Stops receiving package state-change notifications associated with a previous call to [RegisterForPackageStateChanges](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ipackagedebugsettings-registerforpackagestatechanges).

## Parameters

### `dwCookie` [in]

The notification to cancel. This identifier is returned by a previous call to the [RegisterForPackageStateChanges](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ipackagedebugsettings-registerforpackagestatechanges) method.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Call the **UnregisterForPackageStateChanges** to stop receiving package state-change notifications associated with a previous call to the [RegisterForPackageStateChanges](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ipackagedebugsettings-registerforpackagestatechanges) method.

## See also

[IPackageDebugSettings](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ipackagedebugsettings)

[RegisterForPackageStateChanges](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ipackagedebugsettings-registerforpackagestatechanges)