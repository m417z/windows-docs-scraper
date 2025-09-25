# IWMOutputMediaProps::GetStreamGroupName

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetStreamGroupName** method is not implemented in this release, and returns the empty string.

## Parameters

### `pwszName` [out]

Pointer to a wide-character **null**-terminated string containing the name. Pass **NULL** to retrieve the length of the name.

### `pcchName` [in, out]

On input, a pointer to a variable containing the length of the *pwszName* array in wide characters (2 bytes). On output, and if the method succeeds, the variable contains the length of the name, including the terminating **null** character.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The *pcchName* parameter is **NULL**. |
| **ASF_E_BUFFERTOOSMALL** | The buffer pointed to by the *pwszName* parameter is not large enough. |

## Remarks

You should make two calls to **GetStreamGroupName**. On the first call, pass **NULL** as *pwszName*. On return, the value pointed to by *pcchName* is set to the number of wide characters, including the terminating **null** character, required to hold the stream group name. Then you can allocate the required amount of memory for the string and pass a pointer to it as *pwszName* on the second call.

## See also

[IWMOutputMediaProps Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmoutputmediaprops)