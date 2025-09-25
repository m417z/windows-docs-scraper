# IWMWriter::AllocateSample

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **AllocateSample** method allocates a buffer that can be used to provide samples to the writer.

## Parameters

### `dwSampleSize` [in]

**DWORD** containing the sample size, in bytes.

### `ppSample` [out]

Pointer to a pointer to an [INSSBuffer](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsbuffer/nn-wmsbuffer-inssbuffer) interface to an object containing the sample.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **NS_E_INVALID_REQUEST** | The writer is not currently running. |

## Remarks

You must use a new buffer for each sample passed to the writer object; reusing a buffer after passing it to call [IWMWriter::WriteSample](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriter-writesample) will cause errors because the writer object does not immediately release its references to the buffer object. You can release the interfaces of the buffer object safely any time after the **WriteSample** call returns.

## See also

[IWMWriter Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmwriter)

[To Write Samples](https://learn.microsoft.com/windows/desktop/wmformat/to-write-samples)