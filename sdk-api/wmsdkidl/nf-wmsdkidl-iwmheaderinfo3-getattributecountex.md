# IWMHeaderInfo3::GetAttributeCountEx

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetAttributeCountEx** method retrieves the total number of attributes associated with a specified stream number. You can also use this method to get the number of attributes not associated with a specific stream (file-level attributes), or to get the total number of attributes in the file, regardless of stream number.

## Parameters

### `wStreamNum` [in]

**WORD** containing the stream number for which to retrieve the attribute count. Pass zero to retrieve the count of attributes that apply to the file rather than a specific stream. Pass 0xFFFF to retrieve the total count of all attributes in the file, both stream-specific and file-level.

### `pcAttributes` [out]

Pointer to a **WORD** containing the number of attributes that exist for the specified stream.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *pcAttributes* is not a valid pointer. |
| **NS_E_INVALIDREQUEST** | *wStreamNum* is not a valid stream number. |

## Remarks

The maximum number of attributes for a single stream is 65535, the capacity of the **WORD** parameter, *pcAttributes*. If you pass 0xFFFF as *wStreamNum*, this method will return the total number of attributes for the entire file. This number could potentially be greater than the capacity of *pcAttributes*. If the number of attributes in the file is greater than 65535, this method will produce unpredictable results. In reality, no file should ever have this many attributes. If your application makes use of an extremely large number of attributes, simply make individual calls to **GetAttributeCountEx** for each stream and for the file-level attributes.

## See also

[IWMHeaderInfo3 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmheaderinfo3)