# IWMReaderAdvanced::SetAllocateForStream

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetAllocateForStream** method specifies whether the reader uses [IWMReaderCallbackAdvanced::AllocateForStream](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreadercallbackadvanced-allocateforstream) to allocate buffers for stream samples.

## Parameters

### `wStreamNum` [in]

**WORD** containing the stream number. Stream numbers are in the range of 1 through 63.

### `fAllocate` [in]

Boolean value that is True if the reader uses **IWMReaderCallbackAdvanced** to allocate streams.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an **HRESULT** error code.

## Remarks

If the application's callback implements the [IWMReaderAllocatorEx](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreaderallocatorex) interface, the [AllocateForStreamEx](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreaderallocatorex-allocateforstreamex) method is called instead of **AllocateForStream**.

## See also

[IWMReaderAdvanced Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreaderadvanced)

[IWMReaderAdvanced::GetAllocateForStream](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreaderadvanced-getallocateforstream)

[IWMReaderAllocatorEx::AllocateForStreamEx](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreaderallocatorex-allocateforstreamex)