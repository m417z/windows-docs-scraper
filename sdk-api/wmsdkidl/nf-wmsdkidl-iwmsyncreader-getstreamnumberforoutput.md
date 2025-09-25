# IWMSyncReader::GetStreamNumberForOutput

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetStreamNumberForOutput** method retrieves the stream number that corresponds with the specified output.

## Parameters

### `dwOutputNum` [in]

**DWORD** value specifying the output number for which you want to retrieve a stream number.

### `pwStreamNum` [out]

Pointer to a **WORD** value that receives the stream number that corresponds to the output specified by *dwOutput*.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **NS_E_INVALID_REQUEST** | *dwOutput* specifies an invalid output number. |

## Remarks

In the case of outputs that equate to mutual exclusions, only the active stream number is retrieved. If you need to get all of the stream numbers associated with such an output, you must access the profile information for the file.

## See also

[IWMProfile Interface](https://learn.microsoft.com/windows/desktop/wmformat/iwmprofile)

[IWMSyncReader Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmsyncreader)