# OleSaveToStream function

## Description

Saves an object with the [IPersistStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ipersiststream) interface on it to the specified stream.

## Parameters

### `pPStm` [in]

Pointer to the [IPersistStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ipersiststream) interface on the object to be saved to the stream. The *pPStm* parameter cannot be **NULL**.

### `pStm` [in]

 Pointer to the [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) interface on the stream in which the object is to be saved.

## Return value

This function returns S_OK on success. Other possible values include the following.

| Return code | Description |
| --- | --- |
| **STGMEDIUM_E_FULL** | The object could not be saved due to lack of disk space. |
| **OLE_E_BLANK** | The *pPStm* parameter is **NULL**. |

This function can also return any of the error values returned by the [WriteClassStm](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-writeclassstm) function or the [IPersistStream::Save](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersiststream-save) method.

## Remarks

This function simplifies saving an object that implements the [IPersistStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ipersiststream) interface to a stream. In this stream, the object's CLSID precedes its data. When the stream is retrieved, the CLSID permits the proper code to be associated with the data. The **OleSaveToStream** function does the following:

* Calls the [IPersist::GetClassID](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersist-getclassid) method to get the object's CLSID.
* Writes the CLSID to the stream with the [WriteClassStm](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-writeclassstm) function.
* Calls the [IPersistStream::Save](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersiststream-save) method with *fClearDirty* set to **TRUE**, which clears the dirty bit in the object.

The companion helper, [OleLoadFromStream](https://learn.microsoft.com/windows/desktop/api/ole/nf-ole-oleloadfromstream), loads objects saved in this way.

## See also

[IPersistStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ipersiststream)

[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)

[OleLoadFromStream](https://learn.microsoft.com/windows/desktop/api/ole/nf-ole-oleloadfromstream)