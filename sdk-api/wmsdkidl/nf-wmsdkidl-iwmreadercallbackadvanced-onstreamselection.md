# IWMReaderCallbackAdvanced::OnStreamSelection

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **OnStreamSelection** method notifies the application of stream changes made due to bandwidth restrictions. To have this method called, call [IWMReaderAdvanced::SetReceiveSelectionCallbacks](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreaderadvanced-setreceiveselectioncallbacks).

## Parameters

### `wStreamCount` [in]

**WORD** containing the number of entries in the *pStreamNumbers* array.

### `pStreamNumbers` [in]

Pointer to an array of stream numbers.

### `pSelections` [in]

Pointer to an array of members of the [WMT_STREAM_SELECTION](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/ne-wmsdkidl-wmt_stream_selection) enumeration type. Each element in this array corresponds to the stream number contained in the corresponding element of the array pointed to by *pStreamNumbers*.

### `pvContext` [in]

Generic pointer, for use by the application. This pointer is the context pointer given to the [IWMReader::Start](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreader-start) method.

## Return value

To use this method, you must implement it in your application. You can return whatever **HRESULT** error codes are appropriate to your implementation. For more information about the **HRESULT** error codes included for use by the Windows Media Format SDK, see [Error Codes](https://learn.microsoft.com/windows/desktop/wmformat/error-codes).

## Remarks

Stream numbers are in the range of 1 through 63.

The application can also get callbacks when stream changes due to bandwidth restrictions occur.

## See also

[IWMReaderCallbackAdvanced Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreadercallbackadvanced)