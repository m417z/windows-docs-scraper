# ITsSbProvider::GetResourcePluginStore

## Description

Retrieves an [ITsSbResourcePluginStore](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbresourcepluginstore) instance of the resource plug-in store.

Plug-ins can call this method if they have access to the [ITsSbProvider](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbprovider) and [ITsSbResourcePlugin](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbresourceplugin) objects that own the store. This method returns an instance of the resource plug-in store.

## Parameters

### `ppStore` [out]

A pointer to a pointer to an [ITsSbResourcePluginStore](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbresourcepluginstore) resource plug-in store object. When you have finished using the object, release it by calling the [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method.

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following list.

## See also

[ITsSbProvider](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbprovider)

[ITsSbResourcePlugin](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbresourceplugin)

[ITsSbResourcePluginStore](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbresourcepluginstore)