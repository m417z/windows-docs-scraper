# ITsSbResourcePluginStore::EnumerateTargets

## Description

Returns an array that contains the specified targets that are present in the resource plug-in store.

## Parameters

### `FarmName` [in]

The farm name.

### `EnvName` [in]

The environment name.

### `sortByFieldId` [in]

Specifies sort order.

### `sortyByPropName` [in]

The property name to sort by if *sortByFieldId* is set to **TS_SB_SORT_BY_PROP**.

### `pdwCount` [in, out]

The number of targets retrieved.

### `pVal` [out]

Pointer to the retrieved [ITsSbTarget](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbtarget) objects.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITsSbResourcePluginStore](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbresourcepluginstore)

[ITsSbResourcePluginStoreEx](https://learn.microsoft.com/windows/desktop/TermServ/itssbresourcepluginstoreex)

[ITsSbTarget](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbtarget)