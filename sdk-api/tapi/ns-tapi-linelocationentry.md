# LINELOCATIONENTRY structure

## Description

The
**LINELOCATIONENTRY** structure describes a location used to provide an address translation context. The
[LINETRANSLATECAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linetranslatecaps) structure can contain an array of
**LINELOCATIONENTRY** structures.

## Members

### `dwPermanentLocationID`

Permanent. Identifies the location.

### `dwLocationNameSize`

Size, in characters, of a **null**-terminated location name string including the **null**-terminating character.

### `dwLocationNameOffset`

Offset size, specified in **dwLocationNameSize**, from the beginning of the [LINETRANSLATECAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linetranslatecaps) structure (that contains this entry) to a **null**-terminated string that describes the location in a user-friendly manner.

### `dwCountryCode`

Country or region code of the location.

### `dwCityCodeSize`

Size, in characters, of the **null**-terminated city code string, including the **null**-terminating character.

### `dwCityCodeOffset`

Offset, specified in **dwCityCodeSize**, from the beginning of this structure to a **null**-terminated string specifying the city/area code associated with the location. This information, with the country or region code, can be used by applications to "default" entry fields for the user when entering phone numbers, to encourage the entry of proper canonical numbers.

### `dwPreferredCardID`

Preferred calling card when dialing from this location.

### `dwLocalAccessCodeSize`

Size, in bytes, of the local access code string, including the **null** terminator.

### `dwLocalAccessCodeOffset`

Offset size, specified in **dwLocalAccessCodeSize**, from the beginning of the
[LINETRANSLATECAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linetranslatecaps) structure to a **null**-terminated string containing the access code to be dialed before calls to addresses in the local calling area.

### `dwLongDistanceAccessCodeSize`

Size, in bytes, of the long distance access code, including the **null** terminator.

### `dwLongDistanceAccessCodeOffset`

Offset size, specified in **dwLongDistanceAccessCodeSize**, from the beginning of the
[LINETRANSLATECAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linetranslatecaps) structure to a **null**-terminated string containing the access code to be dialed before calls to addresses outside the local calling area.

### `dwTollPrefixListSize`

Size, in bytes, of the toll prefix, including the **null** terminator.

### `dwTollPrefixListOffset`

Offset size, specified in **dwTollPrefixListSize**, from the beginning of the
[LINETRANSLATECAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linetranslatecaps) structure to a **null**-terminated string containing the toll prefix list for the location. The string contains only prefixes consisting of the digits "0" through "9", separated from each other by a single "," (comma) character.

### `dwCountryID`

Identifier of the country/region selected for the location. This can be used with the
[lineGetCountry](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetcountry) function to obtain additional information about the specific country/region, such as the country/region name (the **dwCountryCode** member cannot be used for this purpose because country/region codes are not unique).

### `dwOptions`

Options in effect for this location, with values taken from the
[LINELOCATIONOPTION_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linelocationoption--constants).

### `dwCancelCallWaitingSize`

Size, in bytes, of the cancel-call-waiting string.

### `dwCancelCallWaitingOffset`

Offset size, specified in **dwCancelCallWaitingSize**, from the beginning of the
[LINETRANSLATECAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linetranslatecaps) structure to a **null**-terminated string containing the dial digits and modifier characters that should be prefixed to the dialable string (after the pulse/tone character) when an application sets the LINETRANSLATEOPTION_CANCELCALLWAITING bit in the *dwTranslateOptions* parameter of
[lineTranslateAddress](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linetranslateaddress). If no prefix is defined, **dwCancelCallWaitingSize** may be set to zero, or 1, and **dwCancelCallWaitingOffset** may point to an empty string (single **NULL** byte).

## Remarks

This structure cannot be extended.

Older applications are compiled without knowledge of these new fields, and using a SIZEOF LINELOCATIONENTRY smaller than the new size. Because this is an array in the variable portion of a
[LINETRANSLATECAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linetranslatecaps) structure, it is imperative that older applications receive
**LINELOCATIONENTRY** structures in the format they previously expected, or they are not able to index through the array properly. The application passes in a *dwAPIVersion* parameter with the
[lineGetTranslateCaps](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegettranslatecaps) function, which can be used for guidance by TAPI in handling this situation. The
**lineGetTranslateCaps** function should use the
**LINELOCATIONENTRY** members and size that match the indicated API version, when building the
[LINETRANSLATECAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linetranslatecaps) structure to be returned to the application.

## See also

[LINETRANSLATECAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linetranslatecaps)

[lineGetCountry](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetcountry)

[lineGetTranslateCaps](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegettranslatecaps)

[lineTranslateAddress](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linetranslateaddress)