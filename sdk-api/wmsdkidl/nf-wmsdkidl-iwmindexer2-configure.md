# IWMIndexer2::Configure

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **Configure** method changes the internal settings of the indexer object. You can use **Configure** to activate frame-based indexing or SMPTE time code indexing. **Configure** does not create an index, it just configures the indexer object. After you have changed the desired settings, you must call [IWMIndexer::StartIndexing](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmindexer-startindexing) to create the index.

## Parameters

### `wStreamNum` [in]

**WORD** containing the stream number for which an index is to be made. If you pass 0, all streams will be indexed.

### `nIndexerType` [in]

A variable containing one member of the [WMT_INDEXER_TYPE](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsdkidl/ne-wmsdkidl-wmt_indexer_type) enumeration type.

### `pvInterval` [in]

This void pointer must point to a **DWORD** containing the desired indexing interval. Intervals for temporal indexing are in milliseconds. Frame-based index intervals are specified in frames.

If you pass **NULL**, **Configure** will use the default value. For temporal indexes, the default value is 3000 milliseconds, for frame-based indexes it is 10 frames.

### `pvIndexType` [in]

This void pointer must point to a **WORD** value containing one member of the [WMT_INDEX_TYPE](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsdkidl/ne-wmsdkidl-wmt_index_type) enumeration type. If you pass **NULL**, **Configure** will use the default value.

The default value is WMT_IT_NEAREST_CLEAN_POINT. Using another index type degrades seeking performance.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_OUTOFMEMORY** | The method is unable to add the stream number to its internal list. |

## Remarks

You can call **Configure** as many times as needed to configure multiple streams in a file. You must make all desired calls to **Configure** before you start indexing. If you configure and index a file that already has an index, the existing index will be deleted.

If you configure the indexer to build a frame-based index, it will also create a temporal index. This is required for synchronizing audio and video.

## See also

[IWMIndexer2 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmindexer2)