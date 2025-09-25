# IWMReaderCallbackAdvanced::OnOutputPropsChanged

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **OnOutputPropsChanged** method indicates that the media properties for the specified output have changed. This change occurs as a result of a call to the [IWMReader::SetOutputProps](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreader-setoutputprops) method.

## Parameters

### `dwOutputNum` [in]

**DWORD** containing the output number.

### `pMediaType` [in]

Pointer to a [WM_MEDIA_TYPE](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsdkidl/ns-wmsdkidl-wm_media_type) structure.

### `pvContext` [in]

Generic pointer, for use by the application. This pointer is the context pointer given to the **IWMReader::Start** method.

## Return value

To use this method, you must implement it in your application. You can return whatever **HRESULT** error codes are appropriate to your implementation. For more information about the **HRESULT** error codes included for use by the Windows Media Format SDK, see [Error Codes](https://learn.microsoft.com/windows/desktop/wmformat/error-codes).

## Remarks

This method is called by the reader if the caller gets an asynchronous result from the **SetOutputProps** method call. The next sample received for this output has these properties. After a call to **SetOutputProps** and before **OnOutputPropsChanged** is called, the contents of the media type are undefined.

## See also

[IWMReaderCallbackAdvanced Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreadercallbackadvanced)