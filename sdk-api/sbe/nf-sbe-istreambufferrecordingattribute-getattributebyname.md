# IStreamBufferRecordingAttribute::GetAttributeByName

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **GetAttributeByName** method retrieves an attribute, specified by name.

## Parameters

### `pszAttributeName` [in]

Wide-character string that contains the name of the attribute.

### `pulReserved` [in]

Reserved. Set this parameter to zero.

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
| **VFW_E_BUFFER_OVERFLOW** | The buffer given in *pbAttribute* is too small. |

## See also

[IStreamBufferRecordingAttribute Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nn-sbe-istreambufferrecordingattribute)