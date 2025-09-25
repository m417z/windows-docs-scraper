# IApplicationActivationManager::ActivateForProtocol

## Description

Activates the specified Windows Store app for the protocol contract (Windows.Protocol).

## Parameters

### `appUserModelId` [in]

The application user model ID of the Windows Store app.

### `itemArray` [in]

A pointer to an array of a single Shell item. The first item in the array is converted into a Uri object that is passed to the app through [ProtocolActivatedEventArgs](https://learn.microsoft.com/uwp/api/windows.applicationmodel.activation.protocolactivatedeventargs). Any items in the array except for the first element are ignored.

### `processId` [out]

A pointer to a value that, when this method returns successfully, receives the process ID of the app instance that fulfills this contract.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IApplicationActivationManager](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iapplicationactivationmanager)