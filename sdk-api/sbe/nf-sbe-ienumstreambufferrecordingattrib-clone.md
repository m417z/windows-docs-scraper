# IEnumStreamBufferRecordingAttrib::Clone

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **Clone** method makes a copy of the enumerator object. The returned object starts with the same enumeration state as the original.

## Parameters

### `ppIEnumStreamBufferAttrib` [out]

Address of a variable that receives a pointer to the **IEnumStreamBufferRecordingAttrib** interface of the new enumerator.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **E_POINTER** | NULL pointer argument. |

## See also

[IEnumStreamBufferRecordingAttrib Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nn-sbe-ienumstreambufferrecordingattrib)