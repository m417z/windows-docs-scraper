# LINECARDENTRY structure

## Description

The
**LINECARDENTRY** structure describes a calling card. The
[LINETRANSLATECAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linetranslatecaps) structure can contain an array of
**LINECARDENTRY** structures.

## Members

### `dwPermanentCardID`

Permanent identifier that identifies the card.

### `dwCardNameSize`

Size of the card name string including **null** terminator, in bytes.

### `dwCardNameOffset`

Offset from the beginning of the structure to a **null**-terminated string that describes the card in a user-friendly manner. The size of the field is specified by **dwCardNameSize**.

### `dwCardNumberDigits`

Number of digits in the existing card number. The card number itself is not returned for security reasons (it is stored in scrambled form by TAPI). The application can use this to insert filler bytes into a text control in "password" mode to show that a number exists.

### `dwSameAreaRuleSize`

Size of the same-area dialing rule including the **null** terminator, in bytes.

### `dwSameAreaRuleOffset`

Offset from the beginning of the
[LINETRANSLATECAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linetranslatecaps) structure to the dialing rule defined for calls to numbers in the same area code. The rule is a **null**-terminated string. The size of the field is specified by **dwSameAreaRuleSize**.

### `dwLongDistanceRuleSize`

Size of the long distance dialing rule including the **null** terminator, in bytes.

### `dwLongDistanceRuleOffset`

Offset from the beginning of the structure to the dialing rule defined for calls to numbers in the other areas in the same country/region. The rule is a **null**-terminated string. The size of the field is specified by **dwLongDistanceRuleSize**.

### `dwInternationalRuleSize`

Size of the international dialing rule including the **null** terminator, in bytes.

### `dwInternationalRuleOffset`

Offset from the beginning of the structure to the dialing rule defined for calls to numbers in other countries/regions. The rule is a **null**-terminated string. The size of the field is specified by **dwInternationalRuleSize**.

### `dwOptions`

Indicates other settings associated with this calling card, using the
[LINECARDOPTION_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linecardoption--constants).

## Remarks

Older applications are compiled without knowledge of these new fields, and using a SIZEOF(LINECARDENTRY) smaller than the new size. Because this is an array in the variable portion of a
[LINETRANSLATECAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linetranslatecaps) structure, it is imperative that older applications receive
**LINECARDENTRY** structures in the format they previously expected, or they are not able to index properly through the array. The application passes in a *dwAPIVersion* parameter with the
[lineGetTranslateCaps](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegettranslatecaps) function, which can be used for guidance by TAPI in handling this situation. The
**lineGetTranslateCaps** function should use the
**LINECARDENTRY** fields and size that match the indicated API version, when building the
[LINETRANSLATECAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linetranslatecaps) structure to be returned to the application.

This structure may not be extended.

## See also

[LINETRANSLATECAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linetranslatecaps)

[lineGetTranslateCaps](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegettranslatecaps)