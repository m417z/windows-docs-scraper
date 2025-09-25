# OleConvertIStorageToOLESTREAMEx function

## Description

The
**OleConvertIStorageToOLESTREAMEx** function converts the specified storage object from OLE 2 structured storage to the OLE 1 storage object model, including the presentation data. This is one of several functions included in Structured Storage to ensure compatibility between OLE1 and OLE2.

## Parameters

### `pstg` [in]

Pointer to the
[IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) interface on the storage object to be converted to an OLE 1 storage.

### `cfFormat` [in]

Format of the presentation data. May be **NULL**, in which case the *lWidth*, *lHeight*, *dwSize*, and *pmedium* parameters are ignored.

### `lWidth` [in]

Width of the object presentation data in HIMETRIC units.

### `lHeight` [in]

Height of the object presentation data in HIMETRIC units.

### `dwSize` [in]

Size of the data, in bytes, to be converted.

### `pmedium` [in]

Pointer to the
[STGMEDIUM](https://learn.microsoft.com/windows/win32/api/objidl/ns-objidl-ustgmedium-r1) structure for the serialized data to be converted.

### `polestm` [out]

Pointer to a stream where the persistent representation of the object is saved using the OLE 1 storage model.

## Return value

This function supports the standard return value E_INVALIDARG, in addition to the following:

## Remarks

The
**OleConvertIStorageToOLESTREAMEx** function converts an OLE 2 storage object to OLE 1 format. It differs from the
[OleConvertIStorageToOLESTREAM](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleconvertistoragetoolestream) function in that the
**OleConvertIStorageToOLESTREAMEx** function also passes the presentation data to the OLE 1 storage object, whereas the
**OleConvertIStorageToOLESTREAM** function does not.

Because
**OleConvertIStorageToOLESTREAMEx** can specify which presentation data to convert, it can be used by applications that do not use OLE default caching resources but do use OLE's conversion resources.

The value of the **tymed** member of
[STGMEDIUM](https://learn.microsoft.com/windows/win32/api/objidl/ns-objidl-ustgmedium-r1) must be either TYMED_HGLOBAL or TYMED_ISTREAM; refer to the
[TYMED](https://learn.microsoft.com/windows/desktop/api/objidl/ne-objidl-tymed) enumeration for more information. The medium is not released by the
**OleConvertIStorageToOLESTREAMEx** function.

## See also

[CoIsOle1Class](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-coisole1class)

[OleConvertIStorageToOLESTREAM](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleconvertistoragetoolestream)

[OleConvertOLESTREAMToIStorage](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleconvertolestreamtoistorage)

[OleConvertOLESTREAMToIStorageEx](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleconvertolestreamtoistorageex)

[STGMEDIUM](https://learn.microsoft.com/windows/win32/api/objidl/ns-objidl-ustgmedium-r1)

[TYMED](https://learn.microsoft.com/windows/desktop/api/objidl/ne-objidl-tymed)