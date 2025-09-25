# CoIsOle1Class function

## Description

Determines whether the specified CLSID represents an OLE 1 object.

## Parameters

### `rclsid` [in]

The CLSID to be checked.

## Return value

If the CLSID refers to an OLE 1 object, the return value is **TRUE**; otherwise, it is **FALSE**.

## Remarks

The **CoIsOle1Class** function determines whether an object class is from OLE 1. You can use it to prevent linking to embedded OLE 1 objects within a container, which OLE 1 objects do not support. After a container has determined that copied data represents an embedded object, the container code can call **CoIsOle1Class** to determine whether the embedded object is an OLE 1 object. If **CoIsOle1Class** returns **TRUE**, the container does not offer CF_LINKSOURCE as one of its clipboard formats. This is one of several OLE compatibility functions. The following compatibility functions, listed below, can be used to convert the storage formats of objects between OLE 1 and OLE.

* [OleConvertIStorageToOLESTREAM](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleconvertistoragetoolestream)
* [OleConvertIStorageToOLESTREAMEx](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleconvertistoragetoolestreamex)
* [OleConvertOLESTREAMToIStorage](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleconvertolestreamtoistorage)
* [OleConvertOLESTREAMToIStorageEx](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleconvertolestreamtoistorageex)