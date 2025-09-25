# IWMWriter::WriteSample

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WriteSample** method passes in uncompressed data to be compressed and appended to the file that is being created.

## Parameters

### `dwInputNum` [in]

**DWORD** containing the input number.

### `cnsSampleTime` [in]

**QWORD** containing the sample time, in 100-nanosecond units.

### `dwFlags` [in]

**DWORD** containing one or more of the following flags.

| Flag | Description |
| --- | --- |
| No flag set | None of the conditions for the other flags applies. For example, a [delta frame](https://learn.microsoft.com/windows/desktop/wmformat/wmformat-glossary) in most cases would not have any flags set for it. |
| WM_SF_CLEANPOINT | Forces the sample to be written as a key frame. Setting this flag for audio inputs will have no effect, as all audio samples are cleanpoints. |
| WM_SF_DISCONTINUITY | For audio inputs, this flag helps to deal with gaps that may appear between samples. You should set this flag for the first sample after a gap. |
| WM_SF_DATALOSS | This flag is not used by the writer object. |

### `pSample` [in]

Pointer to an [INSSBuffer](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsbuffer/nn-wmsbuffer-inssbuffer) interface representing a sample.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The *dwInputNum* value is greater than the highest index number. |
| **E_UNEXPECTED** | The method failed for an unspecified reason. |
| **NS_E_INVALID_STATE** | The writer is not running. |
| **NS_E_INVALID_DATA** | The sample is not valid. This can occur when an input script stream contains a script sample that is not valid. |
| **NS_E_INVALID_NUM_PASSES** | The wrong number of preprocessing passes was used for the stream's output type.<br><br>Typically, this error will be returned if the stream configuration requires a preprocessing pass and a sample is passed without first configuring preprocessing. You can check for this error to determine whether a stream requires a preprocessing pass. Preprocessing passes are required only for bit-rate-based VBR. |
| **NS_E_LATE_OPERATION** | The writer has received samples whose presentation times differ by an amount greater than the maximum synchronization tolerance. You can set the synchronization tolerance by calling [IWMWriterAdvanced::SetSyncTolerance](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriteradvanced-setsynctolerance).<br><br>This error can occur when there is more than one stream, and the application sends samples for one stream at a faster rate than the other stream. At some point, the second stream will lag too far behind the first, and the writer will return this error code. |
| **NS_E_TOO_MUCH_DATA** | Samples from a real-time source are arriving faster than expected. This error is returned only if [IWMWriterAdvanced::SetLiveSource](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriteradvanced-setlivesource) has been called to indicate a live source. |

## Remarks

If the output stream has a time code data unit extension and there is no time code extension on the sample, this method will fail in order not to cause problems later when the file is indexed. All other data unit extensions are optional on the sample. That means that this method will succeed if a data unit extension has been specified for the stream but no actual data extension is present in the sample. **WriteSample** will write zeros into the file for samples that do not have extensions specified on the sample.

## See also

[IWMWriter Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmwriter)

[To Write Samples](https://learn.microsoft.com/windows/desktop/wmformat/to-write-samples)