# WriteClassStg function

## Description

The **WriteClassStg** function stores the specified class identifier (CLSID) in a storage object.

## Parameters

### `pStg` [in]

[IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) pointer to the storage object that gets a new CLSID.

### `rclsid` [in]

Pointer to the CLSID to be stored with the object.

## Return value

This function returns HRESULT.

## Remarks

The
**WriteClassStg** function writes a CLSID to the specified storage object so that it can be read by the
[ReadClassStg](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-readclassstg) function. Container applications typically call this function before calling the
[IPersistStorage::Save](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersiststorage-save) method.

## See also

[OleSave](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olesave)

[ReadClassStg](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-readclassstg)