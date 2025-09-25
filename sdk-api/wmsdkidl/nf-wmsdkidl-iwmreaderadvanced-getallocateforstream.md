# IWMReaderAdvanced::GetAllocateForStream

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetAllocateForStream** method ascertains whether the reader is configured to use [IWMReaderCallbackAdvanced](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreadercallbackadvanced) to allocate stream samples delivered by the [IWMReaderCallbackAdvanced::OnStreamSample](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreadercallbackadvanced-onstreamsample) callback.

## Parameters

### `dwSreamNum` [in]

**WORD** containing the stream number.

### `pfAllocate` [out]

Pointer to a Boolean value that is set to True if the reader uses **IWMReaderCallbackAdvanced** to allocate samples.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an **HRESULT** error code.

## Remarks

Stream numbers are in the range of 1 through 63.

## See also

[IWMReaderAdvanced Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreaderadvanced)

[IWMReaderAdvanced::SetAllocateForStream](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreaderadvanced-setallocateforstream)