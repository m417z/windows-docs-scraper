# IWMIndexer::StartIndexing

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **StartIndexing** method initiates indexing. If you configure the indexer using the [IWMIndexer2::Configure](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmindexer2-configure) method, **StartIndexing** creates an index based upon your configuration. When you use **StartIndexing** without first calling **Configure**, the indexer creates a default temporal index.

## Parameters

### `pwszURL` [in]

Pointer to a wide-character **null**-terminated string containing the URL or file name.

### `pCallback` [in]

Pointer to an [IWMStatusCallback](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmstatuscallback) interface.

### `pvContext` [in]

Generic pointer, for use by the application.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The parameter *pwszURL* or *pCallback* is **NULL**. |
| **NS_E_BUSY** | The method cannot start indexing in the current state. |

## Remarks

**StartIndexing** is an asynchronous call; it returns almost immediately and the application must wait for appropriate **OnStatus** calls to be sent to the callback function.

If you call **StartIndexing** for a file that is already indexed, the old index is discarded.

When the indexer successfully indexes a file, it will set some of the reserved attribute values as described in the following table.

| Index type | Attributes set |
| --- | --- |
| WMT_IT_PRESENTATION_TIME | g_wszWMSeekable<br><br>g_wszWMStridable, if a video stream is present. |
| WMT_IT_FRAME_NUMBERS | g_wszWMNumberOfFrames<br><br>g_wszWMSeekable<br><br>g_wszWMStridable |

## See also

[IWMIndexer Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmindexer)

[IWMStatusCallback::OnStatus](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmstatuscallback-onstatus)