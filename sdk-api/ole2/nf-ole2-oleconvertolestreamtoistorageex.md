# OleConvertOLESTREAMToIStorageEx function

## Description

The
**OleConvertOLESTREAMToIStorageEx** function converts the specified object from the OLE 1 storage model to an OLE 2 structured storage object including presentation data. This is one of several compatibility functions.

## Parameters

### `polestm` [in]

Pointer to the stream that contains the persistent representation of the object in the OLE 1 storage format.

### `pstg` [out]

Pointer to the OLE 2 structured storage object.

### `pcfFormat` [out]

Pointer to where the format of the presentation data is returned. May be **NULL**, indicating the absence of presentation data.

### `plwWidth` [out]

Pointer to where the width value (in HIMETRIC) of the presentation data is returned.

### `plHeight` [out]

Pointer to where the height value (in HIMETRIC) of the presentation data is returned.

### `pdwSize` [out]

Pointer to where the size in bytes of the converted data is returned.

### `pmedium` [out]

Pointer to where the
[STGMEDIUM](https://learn.microsoft.com/windows/win32/api/objidl/ns-objidl-ustgmedium-r1) structure for the converted serialized data is returned.

## Return value

This function returns HRESULT.

## Remarks

This function converts an OLE 1 object to an OLE 2 structured storage object. You can use this function to update OLE 1 objects to OLE 2 objects when a new version of the object application supports OLE 2.

This function differs from the
[OleConvertOLESTREAMToIStorage](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleconvertolestreamtoistorage) function in that the presentation data read from the **OLESTREAM** structure is passed out and the newly created OLE 2 storage object does not contain a presentation stream.

Since this function can specify which presentation data to convert, it can be used by applications that do not use OLE's default caching resources but do use the conversion resources.

The **tymed** member of
[STGMEDIUM](https://learn.microsoft.com/windows/win32/api/objidl/ns-objidl-ustgmedium-r1) can only be TYMED_NULL or TYMED_ISTREAM. If it is TYMED_NULL, the data will be returned in a global handle through the **hGlobal** member of **STGMEDIUM**, otherwise data will be written into the **pstm** member of this structure.

## See also

[CoIsOle1Class](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-coisole1class)

[OleConvertIStorageToOLESTREAM](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleconvertistoragetoolestream)

[OleConvertIStorageToOLESTREAMEx](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleconvertistoragetoolestreamex)

[OleConvertOLESTREAMToIStorage](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleconvertolestreamtoistorage)

[STGMEDIUM](https://learn.microsoft.com/windows/win32/api/objidl/ns-objidl-ustgmedium-r1)

[TYMED](https://learn.microsoft.com/windows/desktop/api/objidl/ne-objidl-tymed)