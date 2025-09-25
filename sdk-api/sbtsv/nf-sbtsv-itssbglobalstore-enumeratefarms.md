# ITsSbGlobalStore::EnumerateFarms

## Description

Enumerates all the farms that have been added by the specified resource
plug-in.

## Parameters

### `ProviderName` [in]

The provider name of the resource plug-in.

### `pdwCount` [out]

The count of farms retrieved.

### `pVal` [out]

A pointer to an array of farm names. The number of elements in this array is specified by the *pdwCount* parameter. When you have finished using the array, free the allocated memory by calling the [SafeArrayDestroy](https://learn.microsoft.com/windows/desktop/api/oleauto/nf-oleauto-safearraydestroy) function.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITsSbGlobalStore](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbglobalstore)