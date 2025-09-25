# IWMWriterAdvanced::WriteStreamSample

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WriteStreamSample** method writes a stream sample directly into an ASF file, bypassing the normal compression procedures. Use this method when writing a compressed stream if you already have the compressed samples. The most common use of **WriteStreamSample** is in copying streams from one file to another.

## Parameters

### `wStreamNum` [in]

**WORD** containing the stream number. Stream numbers are in the range of 1 through 63.

### `cnsSampleTime` [in]

**QWORD** containing the sample time, in 100-nanosecond units.

### `msSampleSendTime` [in]

**DWORD** containing the sample send time, in milliseconds. This parameter is not used.

### `cnsSampleDuration` [in]

**QWORD** containing the sample duration, in 100-nanosecond units. This parameter is not used.

### `dwFlags` [in]

**DWORD** containing one or more of the following flags.

| Flag | Description |
| --- | --- |
| No flag set | None of the conditions for the other flags applies. For example, a [delta frame](https://learn.microsoft.com/windows/desktop/wmformat/wmformat-glossary) in most cases would not have any flags set for it. |
| WM_SF_CLEANPOINT | Indicates the sample is a key frame. Set this flag if and only if the compressed input sample is a key frame. |
| WM_SF_DISCONTINUITY | For audio inputs, this flag helps to deal with gaps that may appear between samples. You should set this flag for the first sample after a gap. |
| WM_SF_DATALOSS | This flag is not used by the writer object. |

### `pSample` [in]

Pointer to an [INSSBuffer](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsbuffer/nn-wmsbuffer-inssbuffer) interface representing the sample.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **NS_E_INVALID_STATE** | The writer cannot currently be run. |
| **NS_E_INVALID_DATA** | The sample is not valid. This can occur when an input script stream contains a script sample that is not valid. |

## Remarks

You must manually set the WM_SF_CLEANPOINT flag for every video key frame. If you do not specify the key frames, it will not be readable. The first video sample delivered by the reading object is the first sample marked as a clean point.

When reading a stream created using stream samples, the reader and synchronous reader objects set the WM_SF_DISCONTINUITY flag for the first sample in the stream.

Normally the application provides samples to an input file on the **IWMWriter** interface, and the samples are then compressed. However, the application can use this interface to put the samples directly into the file, without compressing or otherwise modifying them.

If the output stream has a time code data unit extension and there is no time code extension on the sample, this method will fail in order not to cause problems later when the file is indexed. All other data unit extensions are optional on the sample. That means that this method will succeed if a data unit extension has been specified for the stream but no actual data extension is present in the sample. **WriteStreamSample** will write zeros into the file for samples that do not have extensions specified on the sample.

You can use both [IWMWriter::WriteSample](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriter-writesample) and **WriteStreamSample** to write uncompressed samples and compressed samples to the same stream. However, problems can arise because the writer cannot accurately gauge the bit rate and buffer window usage for the stream samples. Some samples may be dropped as a result.

## See also

[INSSBuffer Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsbuffer/nn-wmsbuffer-inssbuffer)

[IWMWriterAdvanced Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmwriteradvanced)

[Writing Compressed Samples](https://learn.microsoft.com/windows/desktop/wmformat/writing-compressed-samples)