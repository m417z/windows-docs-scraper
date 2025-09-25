# IWMMutualExclusion2::GetRecordName

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetRecordName** method retrieves the name of the specified record. A record has a name only if a name has been assigned using the [IWMMutualExclusion2::SetRecordName](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmmutualexclusion2-setrecordname) method.

## Parameters

### `wRecordNumber` [in]

**WORD** containing the number of the record for which you want to get the name.

### `pwszRecordName` [out]

Pointer to a wide-character **null**-terminated string containing the record name. Pass **NULL** to retrieve the length of the name.

### `pcchRecordName` [in, out]

On input, a pointer to a variable containing the length of the *pwszRecordName* array in wide characters (2 bytes). On output, if the method succeeds, the variable contains the length of the name, including the terminating **null** character. However, if you pass **NULL** as *pwszRecordName*, this will be set to the required length on output.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | *wRecordNumber* does not contain a valid record number.<br><br>OR<br><br>*pcchRecordName* is **NULL**. |
| **E_FAIL** | The method is unable to access the record for an unspecified reason. |

## Remarks

You should make two calls to **GetRecordName** for each record name you want to retrieve. On the first call, pass **NULL** as *pwszRecordName*. On return, the value pointed to by *pcchRecordName* will be set to the number of wide characters, including the terminating **null** character, required to hold the record name. Then you can allocate the required amount of memory for the string and pass a pointer to it as *pwszRecordName* on the second call.

Records are assigned numbers sequentially in the order they are created.

## See also

[IWMMutualExclusion2 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmmutualexclusion2)