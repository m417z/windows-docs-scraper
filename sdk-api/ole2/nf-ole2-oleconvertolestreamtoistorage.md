# OleConvertOLESTREAMToIStorage function

## Description

The
**OleConvertOLESTREAMToIStorage** function converts the specified object from the OLE 1 storage model to an OLE 2 structured storage object without specifying presentation data.

**Note** This is one of several compatibility functions.

## Parameters

### `lpolestream` [in]

A pointer to a stream that contains the persistent representation of the object in the OLE 1 storage format.

### `pstg` [out]

A pointer to the
[IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) interface on the OLE 2 structured storage object.

### `ptd` [in]

A pointer to the
[DVTARGETDEVICE](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-dvtargetdevice) structure that specifies the target device for which the OLE 1 object is rendered.

## Return value

This function supports the standard return value **E_INVALIDARG**, in addition to the following:

## Remarks

This function converts an OLE 1 object to an OLE 2 structured storage object. Use this function to update OLE 1 objects to OLE 2 objects when a new version of the object application supports OLE 2.

On entry, the *lpolestm* parameter should be created and positioned just as it would be for an
[OleLoadFromStream](https://learn.microsoft.com/windows/desktop/api/ole/nf-ole-oleloadfromstream) function call. On exit, the *lpolestm* parameter is positioned just as it would be on exit from an **OleLoadFromStream** function, and the *pstg* parameter contains the uncommitted persistent representation of the OLE 2 storage object.

For OLE 1 objects that use native data for their presentation, the
**OleConvertOLESTREAMToIStorage** function returns **CONVERT10_S_NO_PRESENTATION**. On receiving this return value, callers should call [IOleObject::Update](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-update) to get the presentation data so it can be written to storage.

Applications that do not use the OLE default caching resources, but use the conversion resources, can use an alternate function,
[OleConvertOLESTREAMToIStorageEx](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleconvertolestreamtoistorageex), which can specify the presentation data to convert. In the
**OleConvertOLESTREAMToIStorageEx** function, the presentation data read from the **OLESTREAM** structure is passed out and the newly created OLE 2 storage object does not contain a presentation stream.

The following procedure describes the conversion process using
**OleConvertOLESTREAMToIStorage**.

**Converting an OLE 1 object to an OLE 2 storage object**

1. Create a root
   [IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) object by calling the
   [StgCreateDocfile](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-stgcreatedocfile) function (..., &*pstg*).
2. Open the OLE 1 file (using [OpenFile](https://learn.microsoft.com/windows/desktop/direct3dtools/ipixengine-openfile-bstr-bstr-inewframescallback-ptr-ifileiocallback-ptr-lcid) or another OLE 1 technique).
3. Read from the file, using the OLE 1 procedure for reading files, until an OLE object is found.
4. Allocate an
   [IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) object from the root
   **IStorage** created in Step 1.

   ```cpp
   pstg->lpVtbl->CreateStorage(...&pStgChild);
   hRes = OleConvertIStorageToOLESTREAM(polestm, pStgChild);
   hRes = OleLoad(pStgChild, &IID_IOleObject, pClientSite, ppvObj);
   ```
5. Repeat Step 3 until the file is completely read.

## See also

[CoIsOle1Class](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-coisole1class)

[DVTARGETDEVICE](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-dvtargetdevice)

[OleConvertIStorageToOLESTREAM](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleconvertistoragetoolestream)

[OleConvertIStorageToOLESTREAMEx](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleconvertistoragetoolestreamex)

[OleConvertOLESTREAMToIStorageEx](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleconvertolestreamtoistorageex)

[STGMEDIUM](https://learn.microsoft.com/windows/win32/api/objidl/ns-objidl-ustgmedium-r1)

[TYMED](https://learn.microsoft.com/windows/desktop/api/objidl/ne-objidl-tymed)