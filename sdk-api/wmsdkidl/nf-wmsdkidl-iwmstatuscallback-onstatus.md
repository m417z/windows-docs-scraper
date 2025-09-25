# IWMStatusCallback::OnStatus

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **OnStatus** method is called when status information must be communicated to the application.

## Parameters

### `Status` [in]

One member of the [WMT_STATUS](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/ne-wmsdkidl-wmt_status) enumeration type. For a description of possible **WMT_STATUS** values, see the tables in the Remarks section.

### `hr` [in]

**HRESULT** error code. If this indicates failure, you should not process the status as normal, as some error has occurred. Use `if (FAILED(hr))` to check for a failed value. See the topic [Error Codes](https://learn.microsoft.com/windows/desktop/wmformat/error-codes) for a list of possible results.

### `dwType` [in]

Member of the [WMT_ATTR_DATATYPE](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/ne-wmsdkidl-wmt_attr_datatype) enumeration type. This value specifies the type of data in the buffer at *pValue*.

### `pValue` [in]

Pointer to a byte array containing the value. The contents of this array depend on the value of *Status* and the value of *dwType*.

### `pvContext` [in]

Generic pointer provided by the application, for its own use. This pointer matches the context pointer given to the [IWMReader::Open](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreader-open), [IWMIndexer::StartIndexing](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmindexer-startindexing), and other methods. The SDK makes no assumptions about the use of this pointer; it is simply provided by the application and passed back to the application when a callback is made.

## Return value

This method is implemented by the application. It should always return S_OK.

## Remarks

The contents of *pParam* depend on those of *Status*.

The following **WMT_STATUS** values can be passed to this method by the reader.

| Member | Description |
| --- | --- |
| WMT_ACQUIRE_LICENSE | The license acquisition process is complete. If the license acquisition is unsuccessful, an error is returned in the *hr* parameter. If the license acquisition is successful, S_OK is returned in the *hr* parameter, and a [WM_GET_LICENSE_DATA](https://learn.microsoft.com/windows/desktop/wmformat/wm-get-license-data) data structure is returned in the *pvalue* parameter. |
| WMT_BUFFERING_START | The reader has started buffering data. |
| WMT_BUFFERING_STOP | The reader has stopped buffering data. |
| WMT_CLOSED | The reader has closed the file. |
| WMT_CONNECTING | The reader is connecting to a server. |
| WMT_END_OF_FILE | The reader has reached the end of the file. |
| WMT_END_OF_SEGMENT | When the **Start** method is called with a duration argument, WMT_END_OF_SEGMENT is returned when playback has been completed after the specified period. The argument is a **QWORD** indicating duration of playback in 100-nanosecond units. |
| WMT_END_OF_STREAMING | The file has finished streaming. |
| WMT_EOF | The reader has reached the end of the file. |
| WMT_ERROR | An error occurred in reading the file. |
| WMT_INDIVIDUALIZE | The individualization process is in progress or has completed. This event is sent repeatedly during the individualization process. *pvalue* contains a [WM_INDIVIDUALIZE_STATUS](https://learn.microsoft.com/windows/desktop/wmformat/wm-individualize-status) structure that contains status information about the progress of the download. |
| WMT_LOCATING | The reader is locating a server. |
| WMT_MISSING_CODEC | The reader does not have the appropriate codec to decompress this file. |
| WMT_NEEDS_INDIVIDUALIZATION | The client needs a security update. |
| WMT_NEW_METADATA | The metadata has changed for the current source. |
| WMT_NEW_SOURCEFLAGS | There has been a change to the settings for the current source. |
| WMT_NO_RIGHTS | The reader has tried to play back DRM version 1 content and the computer does not have an appropriate license to play it. |
| WMT_NO_RIGHTS_EX | The reader has tried to play back DRM version 7 content and the computer does not have an appropriate license to play it. |
| WMT_OPENED | The file has been opened for reading. |
| WMT_SAVEAS_START | Starting to save the file to disk. |
| WMT_SAVEAS_STOP | Stopped saving the file to disk. |
| WMT_SOURCE_SWITCH | There has been a change in source file or stream. |
| WMT_STARTED | The reader has started reading the file. The *pValue* parameter points to a **QWORD** that indicates the starting timestamp. If it is -1 the starting timestamp is 0. When the value is any other negative number, it should be converted to a positive to give the starting timestamp. |
| WMT_STOPPED | The reader has stopped reading the file. |
| WMT_TIMER | A timer event has occurred. |

The following **WMT_STATUS** values can be passed to the callback by the writer file sink.

| Member | Description |
| --- | --- |
| WMT_ERROR | An error occurred in writing the file. |
| WMT_OPENED | The file has been opened for writing. |
| WMT_STARTED | The writer has started writing the file. The *pValue* parameter points to a **QWORD** that indicates the starting timestamp. If it is -1 the starting timestamp is 0. When the value is any other negative number, it should be converted to a positive to give the starting timestamp. |
| WMT_STOPPED | The writer has stopped writing the file. |
| WMT_CLOSED | The writer has closed the file. |

The following **WMT_STATUS** enumeration values can be passed to the callback by the writer network sink.

| Member | Description |
| --- | --- |
| WMT_CLIENT_CONNECT | A client has connected to the broadcast. The *dwType* parameter is WMT_TYPE_BINARY, and the *pValue* parameter points to a [WM_CLIENT_PROPERTIES](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsdkidl/ns-wmsdkidl-wm_client_properties) structure. |
| WMT_CLIENT_DISCONNECT | A client has disconnected from the broadcast. The *dwType* parameter is WMT_TYPE_BINARY, and the *pValue* parameter points to a **WM_CLIENT_PROPERTIES** structure. |

The following **WMT_STATUS** enumeration values can be passed to the callback by the indexer.

| Member | Description |
| --- | --- |
| WMT_ERROR | An error occurred in reading the file. |
| WMT_OPENED | The file has been opened for indexing. |
| WMT_STARTED | The indexer has started indexing the file. The *pValue* parameter points to a **QWORD** that indicates the starting timestamp. If it is -1 the starting timestamp is 0. When the value is any other negative number, it should be converted to a positive to give the starting timestamp. |
| WMT_STOPPED | The indexer has stopped indexing the file. |
| WMT_CLOSED | The indexer has closed the file. |
| WMT_INDEX_PROGRESS | Indicates the progress of the current indexing operation. The argument is a **DWORD** that indicates percentage completed, ranging from 0 to 100. |

The following **WMT_STATUS** enumeration values can be passed to the callback by the backup restorer.

| Member | Description |
| --- | --- |
| WMT_BACKUPRESTORE_BEGIN | Sent when backing up or restoring licenses to indicate the process has started. |
| WMT_BACKUPRESTORE_END | Sent when backing up or restoring licenses to indicate the process has completed successfully. |
| WMT_BACKUPRESTORE_CONNECTING | Sent only when restoring licenses, to indicate the clients credentials are being validated. |
| WMT_BACKUPRESTORE_DISCONNECTING | Sent only when restoring licenses to indicate the clients credentials were validated successfully. |
| WMT_ERROR_WITHURL | Sent only when restoring licenses to indicate the client does not have the rights to do this. |
| WMT_RESTRICTED_LICENSE | Sent only when backing up licenses to indicate the licenses are restricted and cannot be backed up. |

## See also

[IWMStatusCallback Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmstatuscallback)

[WMT_STATUS](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/ne-wmsdkidl-wmt_status)