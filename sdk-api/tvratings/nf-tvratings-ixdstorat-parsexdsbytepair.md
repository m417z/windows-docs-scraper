# IXDSToRat::ParseXDSBytePair

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **ParseXDSBytePair** method parses a single byte pair from an XDS stream. If the byte pair is the last pair in a completed ratings packet, the method returns the rating information.

## Parameters

### `byte1` [in]

The first byte of the byte pair.

### `byte2` [in]

The second byte of the byte pair.

### `pEnSystem` [out]

Receives the rating system, as a member of the [EnTvRat_System](https://learn.microsoft.com/previous-versions/dd375612(v=vs.85)) enumeration type.

### `pEnLevel` [out]

Receives the rating level, as a member of the [EnTvRat_GenericLevel](https://learn.microsoft.com/previous-versions/dd375610(v=vs.85)) enumeration type. The meaning of this value depends on the rating system.

### `plBfEnAttributes` [out]

Receives a bitwise combination of zero or more flags from the [BfEnTvRat_GenericAttributes](https://learn.microsoft.com/previous-versions/dd318226(v=vs.85)) enumeration. These flags specify additional content attributes, such as violence or adult language. They do not apply to every rating system.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **S_FALSE** | No rating has been detected in the stream yet. |

## Remarks

The XDS Codec filter calls this method to pass XDS data to the **XDSToRat** object, one pair of bytes at a time. The **XDSToRat** object must store enough information between calls to be able to parse a complete ratings packet.

This method returns S_FALSE until the **XDSToRat** object decodes a complete ratings packet. At that point, the method returns S_OK and returns the rating information in the *pEnSystem*, *pEnLevel*, and *plBfEnAttributes* parameters. Subsequent calls return S_FALSE again until the next packet is decoded.

Ratings values may be delivered by either the XDS Content Advisory packet, or the Composite Packet-1 packet. For details, see sections 9.5.1.5 and 9.5.1.10, respectively, of the EIA/CEA-608B specification.

This method should also detect the Current Class Program Identification Number and Program Name packets indicating the end of show and return an S_OK value along with the values in the following table.

Return the following values for non-ratings packets.

| Parameter | Value |
| --- | --- |
| *pEnSystem* | **TvRat-SystemDontKnow** |
| *pEnLevel* | **TvRat_LevelDontKnow** |
| *plBfEnAttributes* | **BfAttrNone** |

For details, see section 9.5.1.5.4 (General Content Advisory Requirements) of the EIA/CEA-608-B specification.

## See also

[IXDSToRat Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tvratings/nn-tvratings-ixdstorat)