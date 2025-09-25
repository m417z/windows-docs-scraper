# IWMMutualExclusion2::SetRecordName

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetRecordName** method assigns a name to a record. You should assign a name to every record so that you can easily identify the records in the future.

## Parameters

### `wRecordNumber` [in]

**WORD** containing the record number to which you want to assign a name.

### `pwszRecordName` [in]

Pointer to a wide-character null-terminated string containing the name you want to assign to the record. Record names are limited to 256 wide characters.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_OUTOFMEMORY** | The method was unable to allocate memory for the name. |

## Remarks

If you pass an empty string as *pwszRecordName*, the method returns S_OK, but nothing is done.

## See also

[IWMMutualExclusion2 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmmutualexclusion2)

[IWMMutualExclusion2::GetRecordName](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmmutualexclusion2-getrecordname)