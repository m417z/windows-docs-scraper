# IMFSinkWriter::WriteSample

## Description

Delivers a sample to the sink writer.

## Parameters

### `dwStreamIndex` [in]

The zero-based index of the stream for this sample.

### `pSample` [in]

A pointer to the [IMFSample](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfsample) interface of the sample.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| ****S_OK**** | The method succeeded. |
| ****MF_E_INVALIDREQUEST**** | The request is invalid. |

## Remarks

You must call [IMFSinkWriter::BeginWriting](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nf-mfreadwrite-imfsinkwriter-beginwriting) before calling this method. Otherwise, the method returns **MF_E_INVALIDREQUEST**.

By default, the sink writer limits the rate of incoming data by blocking the calling thread inside the **WriteSample** method. This prevents the application from delivering samples too quickly. To disable this behavior, set the [MF_SINK_WRITER_DISABLE_THROTTLING](https://learn.microsoft.com/windows/desktop/medfound/mf-sink-writer-disable-throttling) attribute when you create the sink writer.

This interface is available on Windows Vista if Platform Update Supplement for Windows Vista is installed.

## See also

[IMFSinkWriter](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nn-mfreadwrite-imfsinkwriter)

[Sink Writer](https://learn.microsoft.com/windows/desktop/medfound/sink-writer)