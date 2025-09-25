# IWMReaderAllocatorEx::AllocateForStreamEx

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **AllocateForStreamEx** method allocates a user-created buffer for samples delivered to the [IWMReaderCallbackAdvanced::OnStreamSample](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreadercallbackadvanced-onstreamsample) method.

## Parameters

### `wStreamNum` [in]

**WORD** containing the stream number.

### `cbBuffer` [in]

Size of *ppBuffer*, in bytes.

### `ppBuffer` [out]

Pointer to a pointer to an **INSSBuffer** object.

### `dwFlags` [in]

**DWORD** containing the relevant flags.

| Flag | Description |
| --- | --- |
| WM_SFEX_NOTASYNCPOINT | This flag is the opposite of the WM_SF_CLEANPOINT flag used in other methods of this SDK. It indicates that the point is not a [key frame](https://learn.microsoft.com/windows/desktop/wmformat/wmformat-glossary), or is not a good point to go to during a seek. This inverse definition is used for compatibility with Direct Show. |
| WM_SFEX_DATALOSS | Some data has been lost between the previous sample and the sample with the flag set. |

### `cnsSampleTime` [in]

Specifies the sample time, in 100-nanosecond units.

### `cnsSampleDuration` [in]

Specifies the sample duration, in 100-nanosecond units.

### `pvContext` [in]

Generic pointer, for use by the application. This pointer is the context pointer given to the [IWMReader::Start](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreader-start) method.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an **HRESULT** error code.

## Remarks

This method differs from [IWMReaderCallbackAdvanced::AllocateForStream](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreadercallbackadvanced-allocateforstream) in that sample time and duration values can be passed.

When you allocate a sample in your implementation of this method, you should call [INSSBuffer::SetLength](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsbuffer/nf-wmsbuffer-inssbuffer-setlength) to set the length of the buffer to the length passed by the reader in the *cbBuffer* parameter. If you do not set the current length on the buffer, the reader may encounter an error.

## See also

[INSSBuffer Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsbuffer/nn-wmsbuffer-inssbuffer)

[IWMReaderAllocatorEx Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreaderallocatorex)

[IWMReaderCallbackAdvanced Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreadercallbackadvanced)