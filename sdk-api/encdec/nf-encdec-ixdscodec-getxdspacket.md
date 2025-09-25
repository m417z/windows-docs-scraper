# IXDSCodec::GetXDSPacket

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **GetXDSPacket** method retrieves the most recent XDS packet.

## Parameters

### `pXDSClassPkt` [out]

Receives the packet class.

### `pXDSTypePkt` [out]

Receives the class-specific packet type.

### `pBstrXDSPkt` [out]

Receives the packet as a **BSTR** value.

### `pPktSeqID` [out]

Receives the number of ratings packets that have been decoded. This information can be used for diagnostic purposes.

### `pCallSeqID` [out]

Receives the number of times this method has been called for the current ratings packet. This information can be used for diagnostic purposes.

### `pTimeStart` [out]

Receives the start time of the sample containing the packet.

### `pTimeEnd` [out]

Receives the stop time of the sample containing the packet.

## Return value

Returns an **HRESULT** value. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | **NULL** pointer argument |
| **S_OK** | Success |

## Remarks

The returned **BSTR** contains binary data which might include embedded NULL characters. The caller must free the returned **BSTR** by calling **SysFreeString**.

## See also

[IXDSCodec Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/encdec/nn-encdec-ixdscodec)