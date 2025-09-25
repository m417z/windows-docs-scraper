# IWMHeaderInfo::SetAttribute

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetAttribute** method sets a descriptive attribute that is stored in the header section of the ASF file. This method is replaced by [IWMHeaderInfo3::AddAttribute](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmheaderinfo3-addattribute), and should not be used.

## Parameters

### `wStreamNum` [in]

**WORD** containing the stream number. To set a file-level attribute, pass zero.

### `pszName` [in]

Pointer to a wide-character null-terminated string containing the name of the attribute. Attribute names are limited to 1024 wide characters.

### `Type` [in]

A value from the **WMT_ATTR_DATATYPE** enumeration type.

### `pValue` [in]

Pointer to a byte array containing the value of the attribute.

### `cbLength` [in]

The size of *pValue*, in bytes.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | A parameter does not contain a valid value. |
| **E_NOTIMPL** | Not implemented. |
| **E_UNEXPECTED** | The method failed for an unspecified reason. |
| **NS_E_INVALID_STATE** | The object is not in a configurable state, or no profile has been set. |

## Remarks

Refer to the [Attributes](https://learn.microsoft.com/windows/desktop/wmformat/attributes) section for a list of predefined attributes. For predefined attributes, the *Type* parameter must match the data type defined for that attribute. For custom attributes, you can specify any type except WMT_TYPE_GUID, but the buffer size (given by *cbLength*) must match the type. See [WMT_ATTR_DATATYPE](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/ne-wmsdkidl-wmt_attr_datatype) for more information.

The **IWMHeaderInfo** interface does not support the WMT_TYPE_GUID data type. To use this data type, you must use the methods of the **IWMHeaderInfo3** interface.

Attributes in MP3 files cannot be specific to a particular stream. For MP3 files, always set the stream number to zero. When setting attributes for MP3 files, the metadata editor will automatically insert a byte-order mark in accordance with the Unicode specification. If you manually insert a byte-order mark, this method will not fail, but the value will then have two marks, which can cause problems when reading the attribute.

This method does not support attributes with values larger than 64 kilobytes. To include large attributes in your file, use the methods of the **IWMHeaderInfo3** interface.

The writer object supports this method only before the [IWMWriter::BeginWriting](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriter-beginwriting) method has been called. The reader and synchronous reader objects do not support this method.

Before you can use this method through the **IWMHeaderInfo** interface of a writer object to set [DRM](https://learn.microsoft.com/windows/desktop/wmformat/wmformat-glossary) attributes, you must set a profile for the writer to use.

The objects of the Windows Media Format SDK perform type checking on some supported metadata attributes, but not all of them. You should ensure that any attributes you use are set using the data type specified in the [Attributes](https://learn.microsoft.com/windows/desktop/wmformat/attributes) section of this documentation. Likewise, you cannot assume that an attribute set by another application will use the correct data type.

## See also

[Attributes](https://learn.microsoft.com/windows/desktop/wmformat/attributes)

[IWMHeaderInfo Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmheaderinfo)

[IWMHeaderInfo2](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmheaderinfo2)

[IWMHeaderInfo3 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmheaderinfo3)

[IWMHeaderInfo::GetAttributeByIndex](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmheaderinfo-getattributebyindex)

[IWMHeaderInfo::GetAttributeByName](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmheaderinfo-getattributebyname)

[IWMHeaderInfo::GetAttributeCount](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmheaderinfo-getattributecount)

[WMT_ATTR_DATATYPE](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/ne-wmsdkidl-wmt_attr_datatype)