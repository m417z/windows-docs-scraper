# uSTGMEDIUM structure

## Description

Represents a generalized global memory handle used for data transfer operations by the [IAdviseSink](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iadvisesink), [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject), and [IOleCache](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iolecache) interfaces.

## Members

### `tymed`

The type of storage medium. The marshaling and unmarshaling routines use this value to determine which union member was used. This value must be one of the elements of the [TYMED](https://learn.microsoft.com/windows/desktop/api/objidl/ne-objidl-tymed) enumeration.

### `DUMMYUNIONNAME`

Handle, string, or interface pointer that the receiving process can use to access the data being transferred. If tymed is TYMED_NULL, the union member is undefined; otherwise, it is one of the following values.

### `DUMMYUNIONNAME.hBitmap`

Bitmap handle. The tymed member is TYMED_GDI.

### `DUMMYUNIONNAME.hMetaFilePict`

Metafile handle. The tymed member is TYMED_MFPICT.

### `DUMMYUNIONNAME.hEnhMetaFile`

Enhanced metafile handle. The tymed member is TYMED_ENHMF.

### `DUMMYUNIONNAME.hGlobal`

Global memory handle. The tymed member is TYMED_HGLOBAL.

### `DUMMYUNIONNAME.lpszFileName`

Pointer to the path of a disk file that contains the data. The tymed member is TYMED_FILE.

### `DUMMYUNIONNAME.pstm`

Pointer to an [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) interface. The tymed member is TYMED_ISTREAM.

### `DUMMYUNIONNAME.pstg`

Pointer to an [IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) interface. The tymed member is TYMED_ISTORAGE.

### `pUnkForRelease`

Pointer to an interface instance that allows the sending process to control the way the storage is released when the receiving process calls the [ReleaseStgMedium](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-releasestgmedium) function. If *pUnkForRelease* is **NULL**, **ReleaseStgMedium** uses default procedures to release the storage; otherwise, **ReleaseStgMedium** uses the specified IUnknown interface.

## See also

[FORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-formatetc)

[IAdviseSink](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iadvisesink)

[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject)

[IOleCache](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iolecache)

[ReleaseStgMedium](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-releasestgmedium)