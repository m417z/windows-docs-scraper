# TYMED enumeration

## Description

Indicates the type of storage medium being used in a data transfer. They are used in the [STGMEDIUM](https://learn.microsoft.com/windows/win32/api/objidl/ns-objidl-ustgmedium-r1) or [FORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-formatetc) structures.

## Constants

### `TYMED_HGLOBAL:1`

The storage medium is a global memory handle (**HGLOBAL**). Allocate the global handle with the GMEM_MOVEABLE flag. If the **punkForRelease** member of [STGMEDIUM](https://learn.microsoft.com/windows/win32/api/objidl/ns-objidl-ustgmedium-r1) is **NULL**, the destination process should use [GlobalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalfree) to release the memory.

### `TYMED_FILE:2`

The storage medium is a disk file identified by a path. If the [STGMEDIUM](https://learn.microsoft.com/windows/win32/api/objidl/ns-objidl-ustgmedium-r1) **punkForRelease** member is **NULL**, the destination process should use [OpenFile](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-openfile) to delete the file.

### `TYMED_ISTREAM:4`

The storage medium is a stream object identified by an [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) pointer. Use [ISequentialStream::Read](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-isequentialstream-read) to read the data. If the [STGMEDIUM](https://learn.microsoft.com/windows/win32/api/objidl/ns-objidl-ustgmedium-r1) **punkForRelease** member is not **NULL**, the destination process should use [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) to release the stream component.

### `TYMED_ISTORAGE:8`

The storage medium is a storage component identified by an [IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) pointer. The data is in the streams and storages contained by this **IStorage** instance. If the [STGMEDIUM](https://learn.microsoft.com/windows/win32/api/objidl/ns-objidl-ustgmedium-r1) **punkForRelease** member is not **NULL**, the destination process should use [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) to release the storage component.

### `TYMED_GDI:16`

The storage medium is a GDI component (**HBITMAP**). If the [STGMEDIUM](https://learn.microsoft.com/windows/win32/api/objidl/ns-objidl-ustgmedium-r1) **punkForRelease** member is **NULL**, the destination process should use [DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject) to delete the bitmap.

### `TYMED_MFPICT:32`

The storage medium is a metafile (**METAFILEPICT**). Use the GDI functions to access the metafile's data. If the [STGMEDIUM](https://learn.microsoft.com/windows/win32/api/objidl/ns-objidl-ustgmedium-r1) **punkForRelease** member is **NULL**, the destination process should use [DeleteMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deletemetafile) to delete the bitmap.

### `TYMED_ENHMF:64`

The storage medium is an enhanced metafile (**HENHMETAFILE**). If the [STGMEDIUM](https://learn.microsoft.com/windows/win32/api/objidl/ns-objidl-ustgmedium-r1) **punkForRelease** member is **NULL**, the destination process should use [DeleteEnhMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteenhmetafile) to delete the bitmap.

### `TYMED_NULL:0`

No data is being passed.

## Remarks

During data transfer operations, a storage medium is specified. This medium must be released after the data transfer operation. The provider of the medium indicates its choice of ownership scenarios in the value it provides in the [STGMEDIUM](https://learn.microsoft.com/windows/win32/api/objidl/ns-objidl-ustgmedium-r1) structure. A **NULL** value for the **pUnkForRelease** member indicates that the receiving body of code owns and can free the medium. A non-**NULL** pointer specifies that [ReleaseStgMedium](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-releasestgmedium) can always be called to free the medium.

## See also

[FORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-formatetc)

[IAdviseSink](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iadvisesink)

[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject)

[IOleCache](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iolecache)

[ReleaseStgMedium](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-releasestgmedium)

[STGMEDIUM](https://learn.microsoft.com/windows/win32/api/objidl/ns-objidl-ustgmedium-r1)