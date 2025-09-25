# IWMHeaderInfo3::AddAttribute

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **AddAttribute** method adds a metadata attribute. To change the value of an existing attribute, use the [IWMHeaderInfo3::ModifyAttribute](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmheaderinfo3-modifyattribute) method.

## Parameters

### `wStreamNum` [in]

**WORD** containing the stream number of the stream to which the attribute applies. Setting this value to zero indicates an attribute that applies to the entire file.

### `pszName` [in]

Pointer to a wide-character null-terminated string containing the name of the attribute. Attribute names are limited to 1024 wide characters.

### `pwIndex` [out]

Pointer to a **WORD**. On successful completion of the method, this value is set to the index assigned to the new attribute.

### `Type` [in]

Type of data used for the new attribute. For more information about the types of data supported, see [WMT_ATTR_DATATYPE](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/ne-wmsdkidl-wmt_attr_datatype).

### `wLangIndex` [in]

**WORD** containing the language index of the language to be associated with the new attribute. This is the index of the language in the language list for the file. Setting this value to zero indicates that the default language will be used. A default language is created and set according to the regional settings on the computer running your application.

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
| **NS_E_SDK_BUFFERTOOSMALL** | The size specified by *dwLength* is too small. |
| **NS_E_INVALID_REQUEST** | *wStreamNum* is not a valid stream number. |

## Remarks

This method appends a null character to the end of the string passed in *pwszName* if one is not present. In this case, the buffer needed to retrieve the attribute name will be two bytes larger than the input buffer.

When setting attributes for MP3 files, the metadata editor automatically inserts a byte-order mark in accordance with the Unicode specification. If you manually insert a byte-order mark, this method will not fail, but the value will then have two marks, which can cause problems when reading the attribute.

The objects of the Windows Media Format SDK perform type checking on some supported metadata attributes, but not all of them. You should ensure that any attributes you use are set using the data type specified in the [Attributes](https://learn.microsoft.com/windows/desktop/wmformat/attributes) section of this documentation. Likewise, you cannot assume that an attribute set by another application will use the correct data type.

**Note** Be careful to use the correct type representations of values. For example, when setting WM/MediaClassPrimaryID or WM/MediaClassSecondaryID attributes the values need to be represented as GUIDs converted to a byte array instead of strings converted to a byte array.

## See also

[IWMHeaderInfo3 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmheaderinfo3)