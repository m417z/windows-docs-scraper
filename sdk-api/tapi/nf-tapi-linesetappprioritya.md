# lineSetAppPriorityA function

## Description

The
**lineSetAppPriority** function enables an application to set its priority in the handoff priority list for a particular media type or Assisted Telephony request mode, or to remove itself from the priority list.

## Parameters

### `lpszAppFilename`

A pointer to a string that contains the application executable module filename, without the directory data. In TAPI version 2.0 or later, the parameter can specify a filename in either long or 8.3 filename format.

### `dwMediaMode`

A media type for which the priority of the application is to be set. The value can be one or more of the
[LINEMEDIAMODE](https://learn.microsoft.com/windows/desktop/Tapi/linemediamode--constants) constants. The value zero should be used to set the application priority for Assisted Telephony requests.

### `lpExtensionID`

A pointer to a structure of type
[LINEEXTENSIONID](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineextensionid). This parameter is ignored.

### `dwRequestMode`

The conditions for this parameter are, if the *dwMediaMode* parameter is zero, this parameter specifies the Assisted Telephony request mode for which priority is to be set. It must be LINEREQUESTMODE_MAKECALL. This parameter is ignored if *dwMediaMode* is nonzero.

### `lpszExtensionName`

This parameter is ignored.

### `dwPriority`

A parameter that indicates a new priority for the application. If the value 0 is passed, the application is removed from the priority list for the specified media or request mode; if it was not already present, no error is generated. If the value 1 is passed, the application is inserted as the highest-priority application for the media or request mode; it is removed from a lower-priority position, if already in the list. Any other value generates an error.

## Return value

Returns zero if the request succeeds or a negative error number if an error occurs. Possible return values are:

**LINEERR_INIFILECORRUPT**, **LINEERR_INVALREQUESTMODE**, **LINEERR_INVALAPPNAME**, **LINEERR_NOMEM**, **LINEERR_INVALMEDIAMODE**, **LINEERR_OPERATIONFAILED**, **LINEERR_INVALPARAM**, **LINEERR_RESOURCEUNAVAIL**, **LINEERR_INVALPOINTER**.

## Remarks

If **LINEERR_INVALMEDIAMODE** is returned, the value specified in *dwMediaMode* is not zero and not one of the
[LINEMEDIAMODE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linemediamode--constants).

This function updates the stored priority list. If the telephony system is initialized, it also sets the current, active priorities for applications then running; the new priority is used on the next incoming call or
[lineHandoff](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linehandoff) based on media type.

The Priorities set with **lineSetAppPriority** will persist across restarts of the system or restarts of tapisrv. The [lineOpen](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineopen) function opens the line with no specified call priorities. By default, the highest priority application will be the one that first called **lineOpen**.

> [!NOTE]
> The tapi.h header defines lineSetAppPriority as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[LINEEXTENSIONID](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineextensionid)

[Supplementary Line Service Functions](https://learn.microsoft.com/windows/desktop/Tapi/supplementary-line-service-functions)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)

[lineHandoff](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linehandoff)