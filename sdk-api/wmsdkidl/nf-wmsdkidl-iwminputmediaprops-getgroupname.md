# IWMInputMediaProps::GetGroupName

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetGroupName** method is not implemented, and returns an empty string.

## Parameters

### `pwszName` [out]

Pointer to a wide-character **null**-terminated string containing the name. Pass **NULL** to retrieve the length required for the name.

### `pcchName` [in, out]

On input, a pointer to a variable containing the length of the *pwszName* array in wide characters (2 bytes). On output, if the method succeeds, the variable contains the length of the name, including the terminating **null** character.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The *pcchName* parameter is **NULL**. |
| **ASF_E_BUFFERTOOSMALL** | The *pwszName* parameter is not large enough. |

## See also

[IWMInputMediaProps Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwminputmediaprops)