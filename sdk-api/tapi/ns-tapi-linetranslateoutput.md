# LINETRANSLATEOUTPUT structure

## Description

The
**LINETRANSLATEOUTPUT** structure describes the result of an address translation. The
[lineTranslateAddress](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linetranslateaddress) function uses this structure.

## Members

### `dwTotalSize`

Total size allocated to this data structure, in bytes.

### `dwNeededSize`

Size needed for this data structure to hold all the returned information, in bytes.

### `dwUsedSize`

Size of the portion of this data structure that contains useful information, in bytes.

### `dwDialableStringSize`

Size dialable string, in bytes, including the terminating **NULL**.

### `dwDialableStringOffset`

Offset from the beginning of this structure to the translated output that can be passed to the
[lineMakeCall](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linemakecall),
[lineDial](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linedial), or other function requiring a dialable string. The output is always a **null**-terminated string. Ancillary fields such as name and subaddress are included in this output string if they were in the input string. This string may contain private information such as calling card numbers. It should not be displayed to the user, to prevent inadvertent visibility to unauthorized persons. The size of the field is specified by **dwDialableStringSize**.

### `dwDisplayableStringSize`

Size of the translated output that can be displayed to the user, including the **null** terminator, in bytes.

### `dwDisplayableStringOffset`

Offset to the translated output that can be displayed to the user for confirmation. It is identical to **DialableString**, except the calling card digits are replaced with the friendly name of the card enclosed within bracket characters (for example, "[AT&T Card]"), and ancillary fields such as name and subaddress are removed. Use an appropriate message in **dwDisplayableStringOffset**, because the string might be displayed publicly in the call-status dialog box. This information is also appropriate to include in call logs. The size of the field is specified by **dwDisplayableStringSize**.

### `dwCurrentCountry`

Country or region code configured in **CurrentLocation**. This value may be used to control the display by the application of certain user interface elements, for local call progress tone detection, and for other purposes.

### `dwDestCountry`

Destination country/region code of the translated address. This value may be passed to the *dwCountryCode* parameter of
[lineMakeCall](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linemakecall) and other dialing functions (so that the call progress tones of the destination country/region such as a busy signal are properly detected). This field is set to zero if the destination address passed to
[lineTranslateAddress](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linetranslateaddress) is not in canonical format.

### `dwTranslateResults`

Information derived from the translation process, which may assist the application in presenting user-interface elements. This field uses one of the
[LINETRANSLATERESULT_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linetranslateresult--constants).

## Remarks

This structure cannot be extended.

## See also

[lineDial](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linedial)

[lineMakeCall](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linemakecall)

[lineTranslateAddress](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linetranslateaddress)