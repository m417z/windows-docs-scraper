# IWMMetadataEditor2::OpenEx

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **OpenEx** method opens a file for use by the metadata editor object. **OpenEx** opens ASF files and MP3 files, though the metadata editor has limited capabilities when working with MP3 files.

## Parameters

### `pwszFilename` [in]

Pointer to a wide-character null-terminated string containing the file name.

### `dwDesiredAccess` [in]

**DWORD** containing the desired access type. This can be set to GENERIC_READ or GENERIC_WRITE. For read/write access, pass both values combined with a bitwise **OR**. When using GENERIC_READ, you must also pass a valid sharing mode as *dwShareMode*. Failure to do so will result in an error.

### `dwShareMode` [in]

**DWORD** containing the sharing mode. This can be one of the values in the following table or a combination of the two using a bitwise **OR**. A value of zero indicates no sharing. Sharing is not supported when requesting read/write access. If you request read/write access and pass any value other than zero for the share mode, an error is returned.

| Value | Description |
| --- | --- |
| FILE_SHARE_READ | Subsequent open operations on the file will succeed only if read access is requested. |
| FILE_SHARE_DELETE | (NTFS only) Subsequent open operations on the file will succeed only if it is being deleted. |

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | Read/write access has been requested using file sharing.<br><br>OR<br><br>Read access has been requested without indicating read-and-delete file sharing.<br><br>OR<br><br>The access mode requested is not available with this method. |

## Remarks

The parameters *dwDesiredAccess* and *dwShareMode* are identical to those used in the **OpenFile** function defined in the Platform SDK. In the case of **OpenEx**, however, only a limited set of values are valid for *dwDesiredAccess*. Using any value other than those specified will result in an error.

## See also

[IWMMetadataEditor2 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmmetadataeditor2)

[IWMMetadataEditor::Open](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmmetadataeditor-open)