# IWMReaderCallbackAdvanced::AllocateForStream

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **AllocateForStream** method allocates user-created buffers for stream samples delivered to [IWMReaderCallbackAdvanced::OnStreamSample](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreadercallbackadvanced-onstreamsample). For more information about allocating your own buffers, see [User Allocated Sample Support](https://learn.microsoft.com/windows/desktop/wmformat/user-allocated-sample-support).

## Parameters

### `wStreamNum` [in]

**WORD** containing the stream number.

### `cbBuffer` [in]

Size of the buffer, in bytes.

### `ppBuffer` [out]

If the method succeeds, returns a pointer to a pointer to an [INSSBuffer](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsbuffer/nn-wmsbuffer-inssbuffer) interface.

### `pvContext` [in]

Generic pointer, for use by the application. This pointer is the context pointer given to the [IWMReader::Start](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreader-start) method.

## Return value

To use this method, you must implement it in your application. You can return whatever **HRESULT** error codes are appropriate to your implementation. For more information about the **HRESULT** error codes included for use by the Windows Media Format SDK, see [Error Codes](https://learn.microsoft.com/windows/desktop/wmformat/error-codes).

## Remarks

Stream numbers are in the range of 1 through 63.

An extended version of this method called [AllocateForStreamEx](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreaderallocatorex-allocateforstreamex) exists in the [IWMReaderAllocatorEx](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreaderallocatorex) interface.

When allocating buffers, you can use whatever logic suits your application. Typically, applications initialize a pool of buffers for the file or a pool of buffers for each stream or output. When the application is done with a sample, the buffer is put back into the pool for use.

You can determine the size needed to hold the largest sample of a stream by calling [IWMReaderAdvanced::GetMaxStreamSampleSize](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreaderadvanced-getmaxstreamsamplesize). This is the size you should make the samples in the pool used for the output.

When you allocate a sample in your implementation of this method, you should call [INSSBuffer::SetLength](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsbuffer/nf-wmsbuffer-inssbuffer-setlength) to set the length of the buffer to the length passed by the reader in the *cbBuffer* parameter. If you do not set the current length on the buffer, the reader may encounter an error.

## See also

[IWMReaderCallbackAdvanced Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreadercallbackadvanced)