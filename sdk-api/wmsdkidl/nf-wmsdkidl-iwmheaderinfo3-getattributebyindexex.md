# IWMHeaderInfo3::GetAttributeByIndexEx

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetAttributeByIndexEx** method retrieves the value of an attribute specified by the attribute index. You can use this method in conjunction with the [GetAttributeCountEx](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmheaderinfo3-getattributecountex) method to retrieve all of the attributes associated with a particular stream number.

## Parameters

### `wStreamNum` [in]

**WORD** containing the stream number to which the attribute applies. Set to zero to retrieve a file-level attribute.

### `wIndex` [in]

**WORD** containing the index of the attribute to be retrieved.

### `pwszName` [out]

Pointer to a wide-character **null**-terminated string containing the attribute name. Pass **NULL** to retrieve the size of the string, which will be returned in *pwNameLen*.

### `pwNameLen` [in, out]

Pointer to a **WORD** containing the size of *pwszName*, in wide characters. This size includes the terminating **null** character. Attribute names are limited to 1024 wide characters.

### `pType` [out]

Type of data used for the attribute. For more information about the types of data supported, see [WMT_ATTR_DATATYPE](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/ne-wmsdkidl-wmt_attr_datatype).

### `pwLangIndex` [out]

Pointer to a **WORD** containing the language index of the language associated with the attribute. This is the index of the language in the language list for the file.

### `pValue` [out]

Pointer to an array of bytes containing the attribute value. Pass **NULL** to retrieve the size of the attribute value, which will be returned in *pdwDataLength*.

### `pdwDataLength` [in, out]

Pointer to a **DWORD** containing the length, in bytes, of the attribute value pointed to by *pValue*.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **NS_E_SDK_BUFFERTOOSMALL** | The size specified for the name or value is too small. |
| **NS_E_INVALID_REQUEST** | *wStreamNum* is not a valid stream number, or there is no attribute at *wIndex*. |
| **E_POINTER** | A pointer is not valid. |

## Remarks

You can use 0xFFFF for the stream number to specify an attribute using its global index. Global index values range from 0 to one less than the count of attributes received from a call to [IWMHeaderInfo3::GetAttributeCountEx](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmheaderinfo3-getattributecountex) where the stream number was set to 0xFFFF.

The objects of the Windows Media Format SDK perform type checking on some supported metadata attributes, but not all of them. You should ensure that any attributes you use are set using the data type specified in the [Attributes](https://learn.microsoft.com/windows/desktop/wmformat/attributes) section of this documentation. Likewise, you cannot assume that an attribute set by another application will use the correct data type.

## See also

[IWMHeaderInfo3 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmheaderinfo3)