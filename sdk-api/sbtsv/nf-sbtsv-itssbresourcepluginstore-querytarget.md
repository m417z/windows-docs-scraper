# ITsSbResourcePluginStore::QueryTarget

## Description

Returns the target that has the specified target name and farm name.

## Parameters

### `TargetName` [in]

The target name.

### `FarmName` [in]

The farm name. If this parameter is **NULL**, the method returns the first target it finds.

### `ppTarget` [out]

A pointer to a pointer to an [ITsSbTarget](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbtarget) target object. When you have finished using the object, release it by calling the [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

A resource plug-in store can use this method to retrieve the target that has the specified target name and farm name. Unlike the global store, the resource plug-in store does not copy the target object retrieved because the resource plug-in owns the target object. Accordingly, if you modify the [ITsSbTarget](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbtarget) object that is returned by this method, you are modifying the target object in the resource plug-in store.

## See also

[ITsSbResourcePluginStore](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbresourcepluginstore)

[ITsSbResourcePluginStoreEx](https://learn.microsoft.com/windows/desktop/TermServ/itssbresourcepluginstoreex)

[ITsSbTarget](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbtarget)