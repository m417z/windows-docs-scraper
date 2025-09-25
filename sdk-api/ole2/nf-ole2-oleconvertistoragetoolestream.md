# OleConvertIStorageToOLESTREAM function

## Description

The
**OleConvertIStorageToOLESTREAM** function converts the specified storage object from OLE 2 structured storage to the OLE 1 storage object model but does not include the presentation data. This is one of several compatibility functions.

## Parameters

### `pstg` [in]

Pointer to the
[IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) interface on the storage object to be converted to an OLE 1 storage.

### `lpolestream` [out]

Pointer to an OLE 1 stream structure where the persistent representation of the object is saved using the OLE 1 storage model.

## Return value

This function supports the standard return value E_INVALIDARG, in addition to the following:

## Remarks

This function converts an OLE 2 storage object to OLE 1 format. The **OLESTREAM** structure code implemented for OLE 1 must be available.

On entry, the stream to which *lpolestm* points should be created and positioned just as it would be for an
[OleSaveToStream](https://learn.microsoft.com/windows/desktop/api/ole/nf-ole-olesavetostream) call. On exit, the stream contains the persistent representation of the object using OLE 1 storage.

**Note** Paintbrush objects are dealt with differently from other objects because their native data is in device-independent bitmap (DIB) format. When Paintbrush objects are converted using
**OleConvertIStorageToOLESTREAM**, no presentation data is added to the **OLESTREAM** structure. To include presentation data, use the
[OleConvertIStorageToOLESTREAMEx](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleconvertistoragetoolestreamex) function instead.

## See also

[CoIsOle1Class](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-coisole1class)

[OleConvertIStorageToOLESTREAMEx](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleconvertistoragetoolestreamex)

[OleConvertOLESTREAMToIStorage](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleconvertolestreamtoistorage)

[OleConvertOLESTREAMToIStorageEx](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleconvertolestreamtoistorageex)