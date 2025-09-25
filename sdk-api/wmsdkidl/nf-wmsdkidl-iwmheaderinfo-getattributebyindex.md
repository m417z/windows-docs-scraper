# IWMHeaderInfo::GetAttributeByIndex

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetAttributeByIndex** method returns a descriptive attribute that is stored in the header section of the ASF file. This method is replaced by [IWMHeaderInfo3::GetAttributeByIndexEx](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmheaderinfo3-getattributebyindexex) and should not be used.

## Parameters

### `wIndex` [in]

**WORD** containing the index.

### `pwStreamNum` [in]

Pointer to a **WORD** containing the stream number. Although this parameter is a pointer, the method will not change the value. For file-level attributes, use zero for the stream number.

### `pwszName` [out]

Pointer to a wide-character **null**-terminated string containing the name. Pass **NULL** to this parameter to retrieve the required length for the name. Attribute names are limited to 1024 wide characters.

### `pcchNameLen` [in, out]

On input, a pointer to a variable containing the length of the *pwszName* array in wide characters (2 bytes). On output, if the method succeeds, the variable contains the actual length of the name, including the terminating **null** character.

### `pType` [out]

Pointer to a variable containing one value from the **WMT_ATTR_DATATYPE** enumeration type.

### `pValue` [out]

Pointer to a byte array containing the value. Pass **NULL** to this parameter to retrieve the required length for the value.

### `pcbLength` [in, out]

On input, a pointer to a variable containing the length of the *pValue* array, in bytes. On output, if the method succeeds, the variable contains the actual number of bytes written to *pValue* by the method.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **NS_E_INVALID_STATE** | The object is not in a valid state, or no profile has been set. |
| **E_INVALIDARG** | *pwStreamNum* does not point to a valid stream number, or no data type was supplied. |
| **E_POINTER** | A pointer supplied in a parameter was not valid. |
| **E_UNEXPECTED** | The method failed for an unspecified reason. |
| **ASF_E_BUFFERTOOSMALL** | The *pValue* array is too small to contain the attribute value. |
| **ASF_E_NOTFOUND** | There is no attribute at *wIndex*. |

## Remarks

You should make two calls to **GetAttributeByIndex** for each attribute you want to retrieve. On the first call, pass **NULL** for *pwszName* and *pValue*. On return, the value pointed to by *pcchNameLen* is set to the number of wide characters, including the terminating **null** character, required to hold the attribute name, and the value pointed to by *pcbLength* is set to the number of bytes required to hold the attribute value. You can then create buffers of the appropriate size to receive *pwszName* and *pValue* and pass pointers to them on the second call.

Attributes in MP3 files cannot be stream-specific. When using this method with MP3 files, you must use zero for the stream number.

For a list of all the predefined attributes, see [Attributes](https://learn.microsoft.com/windows/desktop/wmformat/attributes).

The objects of the Windows Media Format SDK perform type checking on some supported metadata attributes, but not all of them. You should ensure that any attributes you use are set using the data type specified in the [Attributes](https://learn.microsoft.com/windows/desktop/wmformat/attributes) section of this documentation. Likewise, you cannot assume that an attribute set by another application will use the correct data type.

## See also

[Attributes](https://learn.microsoft.com/windows/desktop/wmformat/attributes)

[IWMHeaderInfo Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmheaderinfo)

[IWMHeaderInfo2](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmheaderinfo2)

[IWMHeaderInfo3](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmheaderinfo3)

[IWMHeaderInfo::SetAttribute](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmheaderinfo-setattribute)

[WMT_ATTR_DATATYPE](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/ne-wmsdkidl-wmt_attr_datatype)