# IStreamBufferRecordingAttribute::GetAttributeByIndex

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **GetAttributeByIndex** method retrieves an attribute, specified by index number.

## Parameters

### `wIndex` [in]

Zero-based index of the attribute to retrieve.

### `pulReserved` [in]

Reserved. Set this parameter to zero.

### `pszAttributeName` [out]

Pointer to a buffer that receives the name of the attribute, as a null-terminated wide-character string. Specify the size of the buffer in the *pcchNameLength* parameter. To find out the required size for the array, set *pszAttributeName* to **NULL** and check the value that is returned in *pcchNameLength*.

### `pcchNameLength` [in, out]

On input, specifies the size of the buffer given in *pszAttributeName*, in wide characters. On output, contains the number of characters that were copied to the buffer, including the null terminator. Remember that wide characters are two bytes each.

### `pStreamBufferAttributeType` [out]

Pointer to a variable that receives a member of the [STREAMBUFFER_ATTR_DATATYPE](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/ne-sbe-streambuffer_attr_datatype) enumeration. This value indicates the data type that you should use to interpret the attribute, which is returned in the *pbAttribute* parameter.

### `pbAttribute` [out]

Pointer to a buffer that receives the attribute, as an array of bytes. Specify the size of the buffer in the *pcbLength* parameter. To find out the required size for the array, set *pbAttribute* to **NULL** and check the value that is returned in *pcbLength*.

### `pcbLength` [in, out]

On input, specifies the size of the buffer given in *pbAttribute*, in bytes. On output, contains the number of bytes that were copied to the buffer.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **VFW_E_BUFFER_OVERFLOW** | One or both of the buffers is too small. |

## See also

[IStreamBufferRecordingAttribute Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nn-sbe-istreambufferrecordingattribute)