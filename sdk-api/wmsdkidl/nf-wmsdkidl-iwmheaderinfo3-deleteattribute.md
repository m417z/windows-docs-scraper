# IWMHeaderInfo3::DeleteAttribute

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **DeleteAttribute** method removes an attribute from the file header.

## Parameters

### `wStreamNum` [in]

**WORD** containing the stream number for which the attribute applies. Setting this value to zero indicates a file-level attribute.

### `wIndex` [in]

**WORD** containing the index of the attribute to be deleted.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_NOTIMPL** | The method is not implemented on a reader object. |
| **NS_E_INVALIDREQUEST** | *wStreamNum* is not a valid stream number, or there is not an attribute at *wIndex*. |

## Remarks

You can use 0xFFFF for the stream number to specify an attribute using its global index. Global index values range from 0 to one less than the count of attributes received from a call to [IWMHeaderInfo3::GetAttributeCountEx](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmheaderinfo3-getattributecountex) where the stream number was set to 0xFFFF.

When deleting multiple attributes, you should do so in descending order by index value. For convenience, this is the order in which index values are retrieved by [IWMHeaderInfo3::GetAttributeIndices](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmheaderinfo3-getattributeindices).

## See also

[IWMHeaderInfo3 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmheaderinfo3)