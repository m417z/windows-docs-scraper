# SHGetPropertyStoreForWindow function

## Description

Retrieves an object that represents a specific window's collection of properties, which allows those properties to be queried or set.

## Parameters

### `hwnd` [in]

Type: **HWND**

A handle to the window whose properties are being retrieved.

### `riid` [in]

Type: **REFIID**

A reference to the IID of the property store object to retrieve through *ppv*. This is typically IID_IPropertyStore.

### `ppv` [out]

Type: **void****

When this function returns, contains the interface pointer requested in *riid*. This is typically [IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore).

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

An application can use this function to obtain access to a window's property store so that it can set an explicit Application User Model ID (AppUserModelID) in the [System.AppUserModel.ID](https://learn.microsoft.com/windows/desktop/properties/props-system-appusermodel-id) property.

A window's properties must be removed before the window is closed. If this is not done, the resources used by those properties are not returned to the system. A property is removed by setting it to the [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) type VT_EMPTY.

When a call is made to [IPropertyStore::SetValue](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-ipropertystore-setvalue) on the object retrieved through *ppv*, the properties and values are immediately stored on the window. Therefore, no call to [IPropertyStore::Commit](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-ipropertystore-commit) is needed. No error occurs if it is called, but it has no effect.

An application sets AppUserModelIDs on individual windows to control the application's taskbar grouping and Jump List contents. For instance, a suite application might want to provide a different taskbar button for each of its subfeatures, with the windows relating to that subfeature grouped under that button. Without window-level AppUserModelIDs, those windows would all be grouped together under the main process.

Applications should also use this property store to set these relaunch properties so that the system can return the application to that state.

* [System.AppUserModel.RelaunchCommand](https://learn.microsoft.com/windows/desktop/properties/props-system-appusermodel-relaunchcommand)
* [System.AppUserModel.RelaunchDisplayNameResource](https://learn.microsoft.com/windows/desktop/properties/props-system-appusermodel-relaunchdisplaynameresource)
* [System.AppUserModel.RelaunchIconResource](https://learn.microsoft.com/windows/desktop/properties/props-system-appusermodel-relaunchiconresource)

## See also

[Application User Model IDs (AppUserModelIDs)](https://learn.microsoft.com/windows/desktop/shell/appids)