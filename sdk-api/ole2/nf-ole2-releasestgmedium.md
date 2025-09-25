# ReleaseStgMedium function

## Description

Frees the specified storage medium.

## Parameters

### `LPSTGMEDIUM` [in]

Pointer to the storage medium that is to be freed.

## Remarks

The **ReleaseStgMedium** function calls the appropriate method or function to release the specified storage medium. Use this function during data transfer operations where storage medium structures are parameters, such as [IDataObject::GetData](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-getdata) or [IDataObject::SetData](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-setdata). In addition to identifying the type of the storage medium, this structure specifies the appropriate [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method for releasing the storage medium when it is no longer needed.

It is common to pass a [STGMEDIUM](https://learn.microsoft.com/windows/win32/api/objidl/ns-objidl-ustgmedium-r1) from one body of code to another, such as in [IDataObject::GetData](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-getdata), in which the one called can allocate a medium and return it to the caller. **ReleaseStgMedium** permits flexibility in whether the receiving body of code owns the medium, or whether the original provider of the medium still owns it, in which case the receiving code needs to inform the provider that it can free the medium.

When the original provider of the medium is responsible for freeing the medium, the provider calls **ReleaseStgMedium**, specifying the medium and the appropriate [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) pointer as the **punkForRelease** structure member. Depending on the type of storage medium being freed, one of the following actions is taken, followed by a call to the [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method on the specified **IUnknown** pointer.

| Medium | ReleaseStgMedium Action |
| --- | --- |
| TYMED_HGLOBAL | None. |
| TYMED_GDI | None. |
| TYMED_ENHMF | None. |
| TYMED_MFPICT | None. |
| TYMED_FILE | Frees the file name string using standard memory management mechanisms. |
| TYMED_ISTREAM | Calls [IStream::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release). |
| TYMED_ISTORAGE | Calls [IStorage::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release). |

The provider indicates that the receiver of the medium is responsible for freeing the medium by specifying **NULL** for the **punkForRelease** structure member. Then the receiver calls **ReleaseStgMedium**, which makes a call as described in the following table depending on the type of storage medium being freed.

| Medium | ReleaseStgMedium Action |
| --- | --- |
| TYMED_HGLOBAL | Calls the [GlobalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalfree) function on the handle. |
| TYMED_GDI | Calls the [DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject) function on the handle. |
| TYMED_ENHMF | Deletes the enhanced metafile. |
| TYMED_MFPICT | The hMF that it contains is deleted with the [DeleteMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deletemetafile) function; then the handle itself is passed to [GlobalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalfree). |
| TYMED_FILE | Frees the disk file by deleting it. Frees the file name string by using the standard memory management mechanisms. |
| TYMED_ISTREAM | Calls [IStream::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release). |
| TYMED_ISTORAGE | Calls [IStorage::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release). |

In either case, after the call to **ReleaseStgMedium**, the specified storage medium is invalid and can no longer be used.

## See also

[STGMEDIUM](https://learn.microsoft.com/windows/win32/api/objidl/ns-objidl-ustgmedium-r1)