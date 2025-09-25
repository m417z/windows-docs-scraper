# IWMReaderAdvanced::SetAllocateForOutput

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetAllocateForOutput** method specifies whether the reader allocates its own buffers for output samples or gets buffers from your application.

## Parameters

### `dwOutputNum` [in]

**DWORD** containing the output number.

### `fAllocate` [in]

Boolean value that is True if the reader gets buffers from your application.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an **HRESULT** error code.

## Remarks

You can allocate your own buffers for file reading to reduce the overhead required by the reader object to allocate a new buffer for every sample. The reader object will make calls to the **IWMReaderCallbackAdvanced::AllocateForOutput** method.

If the application's callback implements the [IWMReaderAllocatorEx](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreaderallocatorex) interface, the [AllocateForOutputEx](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreaderallocatorex-allocateforoutputex) method is called instead of **AllocateForOutput**.

## See also

[IWMReaderAdvanced Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreaderadvanced)

[IWMReaderAdvanced::GetAllocateForOutput](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreaderadvanced-getallocateforoutput)