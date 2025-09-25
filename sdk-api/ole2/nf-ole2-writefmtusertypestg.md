# WriteFmtUserTypeStg function

## Description

The **WriteFmtUserTypeStg** function writes a clipboard format and user type to the storage object.

## Parameters

### `pstg` [in]

[IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) pointer to the storage object where the information is to be written.

### `cf` [in]

Specifies the clipboard format that describes the structure of the native area of the storage object. The format tag includes the policy for the names of streams and substorages within this storage object and the rules for interpreting data within those streams.

### `lpszUserType` [in]

Pointer to a null-terminated Unicode string that specifies the object's current user type. The user type value, itself, cannot be **NULL**. This is the type returned by the
[IOleObject::GetUserType](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-getusertype) method. If this function is transported to a remote machine where the object class does not exist, this persistently stored user type can be shown to the user in dialog boxes.

## Return value

This function returns HRESULT.

## Remarks

The
**WriteFmtUserTypeStg** function must be called in an object's implementation of the
[IPersistStorage::Save](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersiststorage-save) method. It must also be called by document-level objects that use structured storage for their persistent representation in their save sequence.

To read the information saved, applications call the
[ReadFmtUserTypeStg](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-readfmtusertypestg) function.

## See also

[IPersistStorage::Save](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersiststorage-save)

[ReadFmtUserTypeStg](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-readfmtusertypestg)