# IStreamBufferRecordingAttribute::SetAttribute

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **SetAttribute** method sets an attribute on the stream buffer file.

## Parameters

### `ulReserved` [in]

Reserved. Set this parameter to zero.

### `pszAttributeName` [in]

Wide-character string that contains the name of the attribute.

### `StreamBufferAttributeType` [in]

Member of the [STREAMBUFFER_ATTR_DATATYPE](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/ne-sbe-streambuffer_attr_datatype) enumeration that defines the data type of the attribute data.

### `pbAttribute` [in]

Pointer to a buffer that contains the attribute data.

### `cbAttributeLength` [in]

The size of the buffer specified in *pbAttribute*.

## Return value

Returns an **HRESULT** value.

## Remarks

If an attribute with that name already exists, the method overwrites it with the new value.

The method fails if the recorder object is already recording.

## See also

[IStreamBufferRecordControl::Start](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nf-sbe-istreambufferrecordcontrol-start)

[IStreamBufferRecordingAttribute Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nn-sbe-istreambufferrecordingattribute)