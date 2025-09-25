# IWMReaderAdvanced4::GetURL

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetURL** method retrieves the URL of the file being read. This URL might be different from the URL that was passed to [IWMReader::Open](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreader-open), because the reader might have been redirected.

## Parameters

### `pwszURL`

[ out ] Pointer to a wide-character **null**-terminated string containing the URL of the file.

### `pcchURL` [in]

[ in, out ] Pointer to a variable containing the number of wide characters in *pwszURL*.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | **NULL** pointer argument. |

## Remarks

Call this method twice. The first time, pass **NULL** as the value for *pwszURL*. The method returns the size of the string in the *pcchURL* parameter. Allocate the required amount of memory for the string and call the method again. This time, pass a pointer to the allocated buffer in the *pwszURL* parameter.

## See also

[IWMReaderAdvanced4 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreaderadvanced4)