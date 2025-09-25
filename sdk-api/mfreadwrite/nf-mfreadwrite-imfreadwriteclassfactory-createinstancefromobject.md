# IMFReadWriteClassFactory::CreateInstanceFromObject

## Description

Creates an instance of the sink writer or source reader, given an **IUnknown** pointer.

## Parameters

### `clsid` [in]

The CLSID of the object to create.

| Value | Meaning |
| --- | --- |
| ****CLSID_MFSinkWriter**** | Create the sink writer. The *ppvObject* parameter receives an [IMFSinkWriter](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nn-mfreadwrite-imfsinkwriter) interface pointer. |
| ****CLSID_MFSourceReader**** | Create the source reader. The *ppvObject* parameter receives an [IMFSourceReader](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nn-mfreadwrite-imfsourcereader) interface pointer. |

### `punkObject` [in]

A pointer to the **IUnknown** interface of an object that is used to initialize the source reader or sink writer. The method queries this pointer for one of the following interfaces.

| Value | Meaning |
| --- | --- |
| **[IMFByteStream](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfbytestream)** | Pointer to a byte stream. <br><br>If *clsid* is **CLSID_MFSinkWriter**, the sink writer writes data to this byte stream.<br><br>If *clsid* is **CLSID_MFSourceReader**, this byte stream provides the source data for the source reader. |
| **[IMFMediaSink](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediasink)** | Pointer to a media sink. Applies only when *clsid* is **CLSID_MFSinkWriter**. |
| **[IMFMediaSource](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediasource)** | Pointer to a media source. Applies only when *clsid* is **CLSID_MFSourceReader**. |

### `pAttributes` [in]

A pointer to the [IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes) interface. You can use this parameter to configure the sink writer or source reader. For more information, see the following topics:

* [Sink Writer Attributes](https://learn.microsoft.com/windows/desktop/medfound/sink-writer-attributes)
* [Source Reader Attributes](https://learn.microsoft.com/windows/desktop/medfound/source-reader-attributes)

This parameter can be **NULL**.

### `riid` [in]

The IID of the requested interface.

### `ppvObject` [out]

Receives a pointer to the requested interface. The caller must release the interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This interface is available on Windows Vista if Platform Update Supplement for Windows Vista is installed.

## See also

[IMFReadWriteClassFactory](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nn-mfreadwrite-imfreadwriteclassfactory)