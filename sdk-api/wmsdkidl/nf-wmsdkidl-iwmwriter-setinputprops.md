# IWMWriter::SetInputProps

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetInputProps** method specifies the media properties of an input stream.

## Parameters

### `dwInputNum` [in]

**DWORD** containing the input number.

### `pInput` [in]

Pointer to an [IWMInputMediaProps](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwminputmediaprops) interface. See Remarks.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | *dwInputNum* is greater than the highest index number. |
| **E_OUTOFMEMORY** | There is not enough available memory. |
| **E_UNEXPECTED** | The method failed for an unspecified reason. |

## Remarks

Manipulating the **IWMInputMediaProps** object has no effect on the writer until the application calls this method to configure the input.

Specify **NULL** for *pInput* if the input contains compressed samples that will be written directly to the new stream (using [IWMWriterAdvanced::WriteStreamSample](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriteradvanced-writestreamsample)) without being recompressed.

## See also

[Assigning Input Formats](https://learn.microsoft.com/windows/desktop/wmformat/assigning-input-formats)

[IWMWriter Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmwriter)

[IWMWriter::GetInputCount](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriter-getinputcount)

[IWMWriter::GetInputProps](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriter-getinputprops)