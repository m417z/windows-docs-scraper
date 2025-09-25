# PHONEBUTTONINFO structure

## Description

The
**PHONEBUTTONINFO** structure contains information about a button on a phone device. This structure is used by multiple TAPI and TSPI functions.

## Members

### `dwTotalSize`

Total size allocated to this data structure, in bytes.

### `dwNeededSize`

Size for this data structure that is needed to hold all the returned information, in bytes.

### `dwUsedSize`

Size of the portion of this data structure that contains useful information, in bytes.

### `dwButtonMode`

Mode or general usage class of the button. This member uses one of the
[PHONEBUTTONMODE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/phonebuttonmode--constants).

### `dwButtonFunction`

Function assigned to the button. This member uses one of the
[PHONEBUTTONFUNCTION_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/phonebuttonfunction--constants).

### `dwButtonTextSize`

Size of the descriptive text for the button, in bytes.

### `dwButtonTextOffset`

Offset from the beginning of this structure to the variably sized field containing descriptive text for this button. The format of this information is as specified in the **dwStringFormat** member of the phone's device capabilities. The size of the field is specified by **dwButtonTextSize**.

### `dwDevSpecificSize`

Size of the device-specific field, in bytes. If the device-specific field is a pointer to a string, the size must include the **null** terminator.

### `dwDevSpecificOffset`

Offset from the beginning of the structure to the variably sized device-specific field. The size of the field is specified by **dwDevSpecificSize**.

### `dwButtonState`

For the
[phoneGetButtonInfo](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonegetbuttoninfo) function, this field indicates the current state of the button, using the
[PHONEBUTTONSTATE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/phonebuttonstate--constants). This field is ignored by the
[phoneSetButtonInfo](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonesetbuttoninfo) function.

## Remarks

Device-specific extensions should use the DevSpecific (**dwDevSpecificSize** and **dwDevSpecificOffset**) variably sized area of this data structure.

Older applications are compiled without this field in the
**PHONEBUTTONINFO** structure, and using a SIZEOF PHONEBUTTONINFO smaller than the new size. The application passes in a *dwAPIVersion* parameter with the
[phoneOpen](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phoneopen) function, which can be used for guidance by TAPI in handling this situation. If the application passes in a **dwTotalSize** less than the size of the fixed portion of the structure as defined in the specified **dwAPIVersion**, PHONEERR_STRUCTURETOOSMALL is returned. If sufficient memory has been allocated by the application, before calling the
[TSPI_phoneGetButtonInfo](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_phonegetbuttoninfo) function, TAPI sets the **dwNeededSize** and **dwUsedSize** members to the fixed size of the structure as it existed in the specified API version.

New service providers (which support the new API version) must examine the API version passed in. If the API version is less than the highest version supported by the provider, the service provider must not fill in fields not supported in older API versions, as these would fall in the variable portion of the older structure.

New applications must be cognizant of the API version negotiated, and not examine the contents of fields in the fixed portion beyond the original end of the fixed portion of the structure for the negotiated API version.

## See also

[TSPI_phoneGetButtonInfo](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_phonegetbuttoninfo)

[TSPI_phoneSetButtonInfo](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_phonesetbuttoninfo)

[phoneGetButtonInfo](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonegetbuttoninfo)

[phoneOpen](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phoneopen)

[phoneSetButtonInfo](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonesetbuttoninfo)