# LINECOUNTRYENTRY structure

## Description

The
**LINECOUNTRYENTRY** structure provides the data for a single country/region entry. An array of one or more of these structures is part of the
[LINECOUNTRYLIST](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecountrylist) structure returned by the
[lineGetCountry](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetcountry) function.

## Members

### `dwCountryID`

Country/region identifier of the entry. The country/region identifier is an internal identifier that allows multiple entries to exist in the country/region list with the same country/region code, for example, all countries or regions in North America and the Caribbean share the country/region code 1, but require separate entries in the list.

### `dwCountryCode`

Country/region code of the country/region represented by the entry; that is, the digits dialed in an international call. Only this value should be displayed to users. Country/region identifiers should never be displayed.

### `dwNextCountryID`

Country/region identifier of the next entry in the country/region list. Because country/region codes and identifiers are not assigned in any regular numeric sequence, the country/region list is a single linked list, with each entry pointing to the next. The last country/region in the list has a **dwNextCountryID** value of zero. When the
[LINECOUNTRYLIST](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecountrylist) structure is used to obtain the entire list, the entries in the list are in sequence as linked by their **dwNextCountryID** members.

### `dwCountryNameSize`

Size, in bytes, of the name of the country/region including the **null** terminator.

### `dwCountryNameOffset`

Offset from the beginning of the structure to a **null**-terminated string that specifies the name of the country/region. The size of the field is specified by **dwCountryNameSize**.

### `dwSameAreaRuleSize`

Size, in bytes, of the direct-dialed dialing rule including the **null** terminator.

### `dwSameAreaRuleOffset`

Offset from the beginning of the structure to a **null**-terminated string that contains the dialing rule for direct-dialed calls to the same area code. The size of the field is specified by **dwSameAreaRuleSize**.

### `dwLongDistanceRuleSize`

Size, in bytes, of the long-distance dialing rule including the **null** terminator.

### `dwLongDistanceRuleOffset`

Offset from the beginning of the structure to a **null**-terminated string that contains the dialing rule for direct-dialed calls to other areas in the same country/region. The size of the field is specified by **dwLongDistanceRuleSize**.

### `dwInternationalRuleSize`

Size, in bytes, of the international dialing rule including the **null** terminator.

### `dwInternationalRuleOffset`

Offset from the beginning of the
[LINECOUNTRYLIST](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecountrylist) structure to a **null**-terminated string that contains the dialing rule for direct-dialed calls to other countries/regions. The size of the field is specified by **dwInternationalRuleSize**.

## Remarks

This structure cannot be extended.

## See also

[LINECOUNTRYLIST](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecountrylist)

[lineGetCountry](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetcountry)