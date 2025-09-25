# ITsSbResourcePluginStore::EnumerateFarms

## Description

Enumerates all the farms that have been added to the resource plug-in store.

## Parameters

### `pdwCount` [out]

The number of farms retrieved.

### `pVal` [out]

An array of farm names. The *pdwCount* parameter contains the number of elements in this array. When you have finished using the array, free the allocated memory by calling the [SafeArrayDestroy](https://learn.microsoft.com/windows/desktop/api/oleauto/nf-oleauto-safearraydestroy) function.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITsSbResourcePluginStore](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbresourcepluginstore)

[ITsSbResourcePluginStoreEx](https://learn.microsoft.com/windows/desktop/TermServ/itssbresourcepluginstoreex)