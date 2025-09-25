# IStreamBufferSink::CreateRecorder

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies only to Windows XP Service Pack 1 or later.

The **CreateRecorder** method creates a new Recording object. Recording objects are used to create permanent files from the stream buffer.

## Parameters

### `pszFilename` [in]

Pointer to a null-terminated wide-character string that contains the file name for the recording.

### `dwRecordType` [in]

Indicates the type of recording to create, either a reference recording or a content recording. Specify one of the following values.

| Value | Description |
| --- | --- |
| RECORDING_TYPE_REFERENCE | Reference recording. A reference recording is created from temporary backing files that have already been recorded. It uses a stub file to reference the existing files. Because a reference recording refers to existing content, the start time can be in the past. |
| RECORDING_TYPE_CONTENT | Content recording. A content recording saves content into a new file. Because the content must be new, the start time cannot be in the past. |

### `pRecordingIUnknown` [out]

Address of a variable that receives a pointer to the [Recording](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/recording-object) object's **IUnknown** interface.

## Return value

Returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The Stream Buffer Sink filter's profile must be locked, either explicitly or implicitly, before you call this method. For more information, see [IStreamBufferSink::LockProfile](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nf-sbe-istreambuffersink-lockprofile).

The returned **IUnknown** interface has an outstanding reference count. The caller must release the interface.

## See also

[Creating Stream Buffer Recordings](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/creating-stream-buffer-recordings)

[IStreamBufferSink Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nn-sbe-istreambuffersink)