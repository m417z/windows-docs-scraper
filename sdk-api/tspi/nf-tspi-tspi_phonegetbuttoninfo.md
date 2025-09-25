# TSPI_phoneGetButtonInfo function

## Description

The
**TSPI_phoneGetButtonInfo** function returns information about a specified button.

## Parameters

### `hdPhone`

The handle to the phone to be queried.

### `dwButtonLampID`

A button on the phone device.

### `lpButtonInfo`

A pointer to memory into which the service provider writes a variably sized structure of type
[PHONEBUTTONINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phonebuttoninfo). This data structure describes the mode and function, and provides additional descriptive text corresponding to the button. Prior to calling
**TSPI_phoneGetButtonInfo**, the application sets the **dwTotalSize** member of this structure to indicate the amount of memory available to TAPI for returning information.

## Return value

Returns zero if the function succeeds, or an error number if an error occurs. Possible return values are as follows:

PHONEERR_INVALPHONEHANDLE, PHONEERR_OPERATIONFAILED, PHONEERR_INVALBUTTONLAMPID, PHONEERR_OPERATIONUNAVAIL, PHONEERR_INVALPHONESTATE, PHONEERR_RESOURCEUNAVAIL, PHONEERR_NOMEM.

## Remarks

The
**TSPI_phoneGetButtonInfo** function returns the PHONEERR_NOMEM value if the service provider cannot access the memory containing the button information.

The service provider fills in all the members of the
[PHONEBUTTONINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phonebuttoninfo) data structure, except for **dwTotalSize**, which is filled in by TAPI. The service provider must not overwrite the **dwTotalSize** member.

## See also

[PHONEBUTTONINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phonebuttoninfo)

[PHONECAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phonecaps)

[TSPI_phoneSetButtonInfo](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_phonesetbuttoninfo)