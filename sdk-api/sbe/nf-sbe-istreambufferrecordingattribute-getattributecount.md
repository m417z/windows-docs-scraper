# IStreamBufferRecordingAttribute::GetAttributeCount

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **GetAttributeCount** method returns the number of attributes that are currently defined for this stream buffer file.

## Parameters

### `ulReserved` [in]

Reserved. Set this parameter to zero.

### `pcAttributes` [out]

Pointer to a variable that receives the number of attributes.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_POINTER** | NULL pointer argument |
| **S_OK** | Success |

## See also

[IStreamBufferRecordingAttribute Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nn-sbe-istreambufferrecordingattribute)