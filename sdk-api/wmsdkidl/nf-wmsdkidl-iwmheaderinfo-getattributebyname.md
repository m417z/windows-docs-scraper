# IWMHeaderInfo::GetAttributeByName

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetAttributeByName** method returns a descriptive attribute that is stored in the header section of the ASF file. Now that attribute names can be duplicated in a file, this method is obsolete. To find attributes of a particular name, use [IWMHeaderInfo3::GetAttributeIndices](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmheaderinfo3-getattributeindices).

## Parameters

### `pwStreamNum` [in, out]

Pointer to a **WORD** containing the stream number, or zero to indicate any stream. Although this parameter is a pointer, the method does not change the value.

### `pszName` [in]

Pointer to a **null**-terminated string containing the name of the attribute. Attribute names are limited to 1024 wide characters.

### `pType` [out]

Pointer to a variable that receives a value from the [WMT_ATTR_DATATYPE](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/ne-wmsdkidl-wmt_attr_datatype) enumeration type. The returned value specifies the data type of the attribute.

### `pValue` [out]

Pointer to a byte array that receives the value of the attribute. The caller must allocate the array. To determine the required array size, set this parameter to **NULL** and check the value returned in the *pcbLength* parameter.

### `pcbLength` [in, out]

On input, the length of the *pValue* array, in bytes. On output, if the method succeeds, the actual number of bytes that were written to *pValue*.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **ASF_E_NOTFOUND** | The specified attribute is not defined in this file. |
| **E_INVALIDARG** | *pwStreamNum* is not a valid stream number, *pszName* does not point to a wide-character string, or another parameter does not contain a valid value. |
| **E_POINTER** | A parameter is not a valid pointer. |
| **E_UNEXPECTED** | The method failed for an unspecified reason. |
| **NS_E_INVALID_STATE** | The object is not in a configurable state, or no profile has been set. |

## Remarks

Typically, an application should call this method twice for each attribute that it retrieves. On the first call, set the *pValue* parameter to **NULL**. The *pcbLength* parameter receives the buffer size needed to hold the attribute value. Then, allocate a sufficient byte array and call the method again, passing the address of the array in the *pType* parameter. The method fills the buffer with the value of the attribute. Coerce the buffer to the data type indicated by the value returned in *pType*.

If the file does not contain the specified attribute, the method might return ASF_E_NOTFOUND. The method can also succeed but return the value zero for *pcbLength*.

The objects of the Windows Media Format SDK perform type checking on some supported metadata attributes, but not all of them. You should ensure that any attributes you use are set using the data type specified in the [Attributes](https://learn.microsoft.com/windows/desktop/wmformat/attributes) section of this documentation. Likewise, you cannot assume that an attribute set by another application will use the correct data type.

Attributes in MP3 files cannot be specific to a particular stream. For MP3 files, always set the stream number to zero.

For a list of all the predefined attributes, see [Attributes](https://learn.microsoft.com/windows/desktop/wmformat/attributes).

#### Examples

The following example code shows how to retrieve the "Title" attribute.

```cpp

HRESULT hr;
IWMHeaderInfo *pInfo;
WORD wStreamNum = 0;
WMT_ATTR_DATATYPE Type;
WORD cbLength;
//
// First, retrieve the length of the string, and allocate memory.
//
hr = pInfo->GetAttributeByName( &wStreamNum, L"Title",
                                &Type, NULL, &cbLength );
if( FAILED( hr ) )
{
    return( hr );
}
WCHAR *pwszTitle = (WCHAR *) new BYTE[ cbLength ];
if( !pwszTitle )
{
    return( E_OUTOFMEMORY );
}
//
// Now, retrieve the string itself.
//
hr = pInfo->GetAttributeByName( &wStreamNum, L"Title", &Type,
                                (BYTE *) pwszTitle, &cbLength );
if( FAILED( hr ) )
{
    return( hr );
}

```

## See also

[Attributes](https://learn.microsoft.com/windows/desktop/wmformat/attributes)

[IWMHeaderInfo Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmheaderinfo)

[IWMHeaderInfo2](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmheaderinfo2)

[IWMHeaderInfo3](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmheaderinfo3)

[IWMHeaderInfo::SetAttribute](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmheaderinfo-setattribute)

[WMT_ATTR_DATATYPE](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/ne-wmsdkidl-wmt_attr_datatype)