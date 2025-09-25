# IWMHeaderInfo3::ModifyAttribute

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **ModifyAttribute** method modifies the settings of an existing attribute.

## Parameters

### `wStreamNum` [in]

**WORD** containing the stream number to which the attribute applies. Pass zero for file-level attributes.

### `wIndex` [in]

**WORD** containing the index of the attribute to change.

### `Type` [in]

Type of data used for the new attribute value. For more information about the types of data supported, see [WMT_ATTR_DATATYPE](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/ne-wmsdkidl-wmt_attr_datatype).

### `wLangIndex` [in]

**WORD** containing the language index of the language to be associated with the new attribute. This is the index of the language in the language list for the file.

### `pValue` [in]

Pointer to an array of bytes containing the attribute value.

### `dwLength` [in]

**DWORD** containing the length of the attribute value, in bytes.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | An illegal parameter combination, data type, or attribute name was used. |
| **E_NOTIMPL** | The method is not implemented on a reader object. |
| **E_POINTER** | A pointer is not valid. |
| **NS_E_ATTRIBUTE_READ_ONLY** | The attribute cannot be changed. |
| **NS_E_INVALID_REQUEST** | *wStreamNum* is not a valid stream number, or there is no attribute at *wIndex*. |

## Remarks

You can use 0xFFFF for the stream number to specify an attribute using its global index. Global index values range from 0 to one less than the count of attributes received from a call to [IWMHeaderInfo3::GetAttributeCountEx](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmheaderinfo3-getattributecountex) where the stream number was set to 0xFFFF.

When setting attributes for MP3 files, the metadata editor will automatically insert a byte-order mark in accordance with the Unicode specification. If you manually insert a byte-order mark, this method will not fail, but the value will then have two marks, which can cause problems when reading the attribute.

The objects of the Windows Media Format SDK perform type checking on some supported metadata attributes, but not all of them. You should ensure that any attributes you use are set using the data type specified in the [Attributes](https://learn.microsoft.com/windows/desktop/wmformat/attributes) section of this documentation. Likewise, you cannot assume that an attribute set by another application will use the correct data type.

## See also

[IWMHeaderInfo3 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmheaderinfo3)