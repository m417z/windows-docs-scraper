# IMFReadWriteClassFactory::CreateInstanceFromURL

## Description

Creates an instance of the sink writer or source reader, given a URL.

## Parameters

### `clsid` [in]

The CLSID of the object to create.

| Value | Meaning |
| --- | --- |
| ****CLSID_MFSinkWriter**** | Create the sink writer. The *ppvObject* parameter receives an [IMFSinkWriter](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nn-mfreadwrite-imfsinkwriter) interface pointer. |
| ****CLSID_MFSourceReader**** | Create the source reader. The *ppvObject* parameter receives an [IMFSourceReader](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nn-mfreadwrite-imfsourcereader) interface pointer. |

### `pwszURL` [in]

A null-terminated string that contains a URL. If *clsid* is CLSID_**MFSinkWriter**, the URL specifies the name of the output file. The sink writer creates a new file with this name. If *clsid* is **CLSID_MFSourceReader**, the URL specifies the input file for the source reader.

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