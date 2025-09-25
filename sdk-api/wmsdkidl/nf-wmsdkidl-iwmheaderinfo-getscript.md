# IWMHeaderInfo::GetScript

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetScript** method returns the type and command strings, and the presentation time, of a script.

## Parameters

### `wIndex` [in]

**WORD** that contains the index.

### `pwszType` [out]

Pointer to a wide-character **null**-terminated string buffer into which the type is copied.

### `pcchTypeLen` [in, out]

On input, a pointer to a variable that contains the length of the *pwszType* array in wide characters (2 bytes). On output, if the method succeeds, the variable contains the actual length of the string loaded into *pwszType*.This includes the terminating **null** character. To retrieve the length of the type, you must set this to zero and set *pwszType* to **NULL**.

### `pwszCommand` [out]

Pointer to a wide-character **null**-terminated string buffer into which the command is copied.

### `pcchCommandLen` [in, out]

On input, a pointer to a variable that contains the length of the *pwszCommand* array in wide characters (2 bytes). On output, if the method succeeds, the variable contains the actual length of the command string. This includes the terminating **null** character. To retrieve the length of the command, you must set this to zero and set *pwszCommand* to **NULL**.

### `pcnsScriptTime` [out]

Pointer to a **QWORD** that specifies the presentation time of this script command in 100-nanosecond increments.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **ASF_E_BUFFERTOOSMALL** | The size specified by *pcchCommandLen* or *pcchTypeLen* is not large enough to receive the value. |
| **ASF_E_NOTFOUND** | A script command that matches was not found. |
| **NS_E_INVALID_STATE** | The object is not in a configurable state. |
| **E_INVALIDARG** | A pointer is **NULL** where a value is required. |
| **E_POINTER** | A pointer variable does not contain a valid pointer. |
| **E_UNEXPECTED** | The method failed for an unspecified reason. |

## Remarks

You should make two calls to **GetScript** for each script you want to retrieve. On the first call, pass **NULL** for *pwszType* and *pwszCommand*. On return, the values that are pointed to by *pcchTypeLen* and *pcchCommandLen* are set to the number of wide characters. These include the terminating **null** character, which is required to hold the script type in *pcchTypeLen* and the command in *pcchCommandLen*. You can then create buffers of the appropriate size to receive *pwszType* and *pwszCommand* and pass pointers to them on the second call.

## See also

[IWMHeaderInfo Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmheaderinfo)

[IWMHeaderInfo2](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmheaderinfo2)

[IWMHeaderInfo3](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmheaderinfo3)

[IWMHeaderInfo::AddScript](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmheaderinfo-addscript)

[IWMHeaderInfo::GetScriptCount](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmheaderinfo-getscriptcount)

[IWMHeaderInfo::RemoveScript](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmheaderinfo-removescript)