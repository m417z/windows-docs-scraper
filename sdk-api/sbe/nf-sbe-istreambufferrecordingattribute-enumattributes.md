# IStreamBufferRecordingAttribute::EnumAttributes

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **EnumAttributes** method enumerates the existing attributes of the stream buffer file. This method returns an enumerator object, which the caller can then use to enumerate the attributes.

## Parameters

### `ppIEnumStreamBufferAttrib` [out]

Receives an [IEnumStreamBufferRecordingAttrib](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nn-sbe-ienumstreambufferrecordingattrib) interface pointer.
The caller must release the interface.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | Insufficient memory |
| **E_POINTER** | NULL pointer argument |
| **S_OK** | Success |

## See also

[IStreamBufferRecordingAttribute Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nn-sbe-istreambufferrecordingattribute)