# IXDSCodec::GetContentAdvisoryRating

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **GetContentAdvisoryRating** method retrieves the most recent ratings information parsed by the **XDSToRat** object.

## Parameters

### `pRat` [out]

Receives the most recent rating. The rating is packed into a format that is used internally by the XDS Codec filter, Encrypter/Tagger filter, and Decrypter/Detagger filter. It is not intended for use by other objects.

### `pPktSeqID` [out]

Receives the number of ratings packets that have been decoded. This information can be used for diagnostic purposes.

### `pCallSeqID` [out]

Receives the number of times this method has been called for the current ratings packet. This information can be used for diagnostic purposes.

### `pTimeStart` [out]

Receives the start time of the sample that completed the ratings packet.

### `pTimeEnd` [out]

Receives the stop time of the sample that completed the ratings packet.

## Return value

Returns an **HRESULT** value. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | NULL pointer argument |
| **S_OK** | Success |

## See also

[IXDSCodec Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/encdec/nn-encdec-ixdscodec)