# ReadClassStg function

## Description

The **ReadClassStg** function
reads the CLSID previously written to a storage object with the
[WriteClassStg](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-writeclassstg) function.

## Parameters

### `pStg` [in]

Pointer to the
[IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) interface on the storage object containing the CLSID to be retrieved.

### `pclsid` [out]

Pointer to where the CLSID is written. May return CLSID_NULL.

## Return value

This function supports the standard return value E_OUTOFMEMORY, in addition to the following:

This function also returns any of the error values returned by the
[IStorage::Stat](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-stat) method.

## Remarks

**ReadClassStg** is a helper function that calls the [IStorage::Stat](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-stat) method and retrieves the CLSID previously written to the storage object with a call to
[WriteClassStg](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-writeclassstg) from the
[STATSTG](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-statstg) structure.

## See also

[IStorage::Stat](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-stat)

[OleLoad](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleload)

[STATSTG](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-statstg)

[WriteClassStg](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-writeclassstg)