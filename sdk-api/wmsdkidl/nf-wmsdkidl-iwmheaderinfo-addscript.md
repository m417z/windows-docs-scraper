# IWMHeaderInfo::AddScript

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **AddScript** method adds a script, consisting of type and command strings, and a specific time, to the header section of the ASF file.

## Parameters

### `pwszType` [in]

Pointer to a wide-character null-terminated string containing the type. Script types are limited to 1024 wide characters.

### `pwszCommand` [in]

Pointer to a wide-character null-terminated string containing the command. Script commands are limited to 10240 wide characters.

### `cnsScriptTime` [in]

The script time in 100-nanosecond increments.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **NS_E_INVALID_STATE** | The object is not in a configurable state. |
| **E_INVALIDARG** | No value was supplied in *pwszType* or *pwszCommand*. |
| **E_POINTER** | A pointer parameter does not contain a valid pointer. |
| **E_UNEXPECTED** | The method failed for an unspecified reason. |

## Remarks

Before **BeginWriting** has been called, the writer only supports **AddScript**. The reader does not support **AddScript**, and always returns E_NOTIMPL.

You should not add a large number of script commands to the file header if the file is intended for streaming. Some protocols impose limits on the size of a header. Limits differ by protocol, but if your script commands total tens of kilobytes, you should create a script stream instead.

When using DRM to encrypt a file, no script command can have a presentation time of 0.

## See also

[IWMHeaderInfo Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmheaderinfo)

[IWMHeaderInfo2](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmheaderinfo2)

[IWMHeaderInfo3](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmheaderinfo3)

[IWMHeaderInfo::GetScript](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmheaderinfo-getscript)

[IWMHeaderInfo::RemoveScript](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmheaderinfo-removescript)

[Using Script Commands](https://learn.microsoft.com/windows/desktop/wmformat/using-script-commands)