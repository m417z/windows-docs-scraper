# ITsSbProvider::GetInstanceOfGlobalStore

## Description

Retrieves an [ITsSbGlobalStore](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbglobalstore) instance of the global store object.

Plug-ins can use this method to get an instance of the global store object. The global store object is designed for use by filter plug-ins that do not have access to the resource plug-in store.

## Parameters

### `ppGlobalStore` [out]

A pointer to a pointer to a global store object. When you have finished using the object, release it by calling the [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITsSbGlobalStore](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbglobalstore)

[ITsSbProvider](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbprovider)