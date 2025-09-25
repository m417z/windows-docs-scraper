# OleSave function

## Description

Saves an object opened in transacted mode into the specified storage object.

## Parameters

### `pPS` [in]

Pointer to the [IPersistStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ipersiststorage) interface on the object to be saved.

### `pStg` [in]

Pointer to the [IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) interface on the destination storage object to which the object indicated in *pPS* is to be saved.

### `fSameAsLoad` [in]

**TRUE** indicates that *pStg* is the same storage object from which the object was loaded or created; **FALSE** indicates that *pStg* was loaded or created from a different storage object.

## Return value

This function returns S_OK on success. Other possible values include the following.

| Return code | Description |
| --- | --- |
| **STGMEDIUM_E_FULL** | The object could not be saved due to lack of disk space.<br><br>This function can also return any of the error values returned by the [IPersistStorage::Save](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersiststorage-save) method. |

## Remarks

The **OleSave** helper function handles the common situation in which an object is open in transacted mode and is then to be saved into the specified storage object which uses the OLE-provided compound file implementation. Transacted mode means that changes to the object are buffered until either of the [IStorage::Commit](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-commit) or [IStorage::Revert](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-revert) is called. Callers can handle other situations by calling the [IPersistStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ipersiststorage) and [IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) interfaces directly.

**OleSave** does the following:

* Calls the [IPersist::GetClassID](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersist-getclassid) method to get the CLSID of the object.
* Writes the CLSID to the storage object using the [WriteClassStg](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-writeclassstg) function.
* Calls the [IPersistStorage::Save](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersiststorage-save) method to save the object.
* If there were no errors on the save; calls the [IStorage::Commit](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-commit) method to commit the changes.

**Note** Static objects are saved into a stream called CONTENTS. Static metafile objects get saved in "placeable metafile format" and static DIB data gets saved in "DIB file format." These formats are defined to be the OLE standards for metafile and DIB. All data transferred using an [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) interface or a file (that is, via [IDataObject::GetDataHere](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-getdatahere)) must be in these formats. Also, all objects whose default file format is a metafile or DIB must write their data into a CONTENTS stream using these standard formats.

## See also

[IPersistStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ipersiststorage)

[IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage)