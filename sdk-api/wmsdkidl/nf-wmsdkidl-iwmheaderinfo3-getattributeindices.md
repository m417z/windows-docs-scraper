# IWMHeaderInfo3::GetAttributeIndices

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetAttributeIndices** method retrieves a list of valid attribute indices within specified parameters. You can retrieve indices for all attributes with the same name or for all attributes in a specified language. The indices found are for a single specific stream. Alternatively, you can retrieve the specified indices for the entire file.

## Parameters

### `wStreamNum` [in]

**WORD** containing the stream number for which to retrieve attribute indices. Passing zero retrieves indices for file-level attributes. Passing 0xFFFF retrieves indices for all appropriate attributes, regardless of their association to streams.

### `pwszName` [in]

Pointer to a wide-character null-terminated string containing the attribute name for which you want to retrieve indices. Pass NULL to retrieve indices for attributes based on language. Attribute names are limited to 1024 wide characters.

### `pwLangIndex` [in]

Pointer to a **WORD** containing the language index of the language for which to retrieve attribute indices. Pass NULL to retrieve indices for attributes by name.

### `pwIndices` [out]

Pointer to a **WORD** array containing the indices that meet the criteria described by the input parameters. Pass NULL to retrieve the size of the array, which will be returned in *pwCount*.

### `pwCount` [in, out]

On output, pointer to a **WORD** containing the number of elements in the *pwIndices* array.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **NS_E_SDK_BUFFERTOOSMALL** | The size specified in *pwCount* is too small. |
| **NS_E_INVALID_REQUEST** | *wStreamNum* is not a valid stream number, *pwLangIndex* is not a valid language index, or *pwszName* is not a valid name. |
| **E_POINTER** | A pointer is not valid. |

## Remarks

You must make two calls to **GetAttributeIndices** for each set of indices retrieved. On the first call, pass NULL as *pwIndices*. On return, the variable pointed to by *pwCount* is set to the number of elements required for the array of indices. Then allocate memory for the array and make the second call, passing a pointer to the array as *pwIndices*.

If you use 0xFFFF for the stream number, the index values returned will be global indices. Only use a global index for calls to other methods of the IWMHeaderInfo3 interface if you will also be using 0xFFFF for the stream number. The global index value for an attribute will be different than the value used when specifying a specific stream number (or stream 0 for file-level attributes).

Index values obtained by using this method are given in descending order by index. This is to aid in deleting attributes, which should always be done in descending order.

## See also

[IWMHeaderInfo3 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmheaderinfo3)