# IDvbParentalRatingDescriptor::GetRecordRating

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

 Gets a code that indicates the age-based rating for a Digital Video Broadcast (DVB) broadcast from a DVB parental rating descriptor.

## Parameters

### `bRecordIndex` [in]

Zero-based index of the descriptor to return. To get the number of descriptors, call [IDvbParentalRatingDescriptor::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-idvbparentalratingdescriptor-getcountofrecords).

### `pszCountryCode`

Receives the ISO 3166 country code from the parental rating descriptor.

### `pbVal` [out]

Gets the rating code. This can be any of the following values.

| Value | Meaning |
| --- | --- |
| 0x00 | Undefined. |
| 0x01-0x0F | Minimum age is 3 years. For example, 0x0A implies that end users should be at least 13 years old. |
| 0x10-0xFF | Broadcaster defined. |

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDvbParentalRatingDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-idvbparentalratingdescriptor)