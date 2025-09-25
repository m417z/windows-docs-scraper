# IWMReaderAdvanced::GetAllocateForOutput

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetAllocateForOutput** method ascertains whether the reader is configured to use the [IWMReaderCallbackAdvanced](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreadercallbackadvanced) interface to allocate samples delivered by the [IWMReaderCallback::OnSample](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreadercallback-onsample) callback.

## Parameters

### `dwOutputNum` [in]

**DWORD** containing the identifying number of the output media stream.

### `pfAllocate` [out]

Pointer to a Boolean value that is set to True if the reader uses **IWMReaderCallbackAdvanced** to allocate samples.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an **HRESULT** error code.

## See also

[IWMReaderAdvanced Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreaderadvanced)

[IWMReaderAdvanced::SetAllocateForOutput](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreaderadvanced-setallocateforoutput)