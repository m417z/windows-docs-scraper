# IApplicationActivationManager::ActivateForFile

## Description

Activates the specified Windows Store app for the file contract (Windows.File).

## Parameters

### `appUserModelId` [in]

The application user model ID of the Windows Store app.

### `itemArray` [in]

A pointer to an array of Shell items, each representing a file. This value is converted to a [VectorView](https://learn.microsoft.com/cpp/cppcx/platform-collections-vectorview-class?view=vs-2019&preserve-view=true) of [StorageItem](https://learn.microsoft.com/uwp/api/windows.storage.istorageitem) objects that is passed to the app through [FileActivatedEventArgs](https://learn.microsoft.com/uwp/api/windows.applicationmodel.activation.fileactivatedeventargs).

### `verb` [in]

The verb being applied to the file or files specified by *itemArray*.

### `processId` [out]

A pointer to a value that, when this method returns successfully, receives the process ID of the app instance that fulfills this contract.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IApplicationActivationManager](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iapplicationactivationmanager)