# lineHandoff function

## Description

The
**lineHandoff** function gives ownership of the specified call to another application. The application can be either specified directly by its file name or indirectly as the highest priority application that handles calls of the specified media mode.

## Parameters

### `hCall`

Handle to the call to be handed off. The application must be an owner of the call. The call state of *hCall* can be any state.

### `lpszFileName`

Pointer to a **null**-terminated string. If this pointer parameter is non-**NULL**, it contains the file name of the application that is the target of the handoff. If **NULL**, the handoff target is the highest priority application that has opened the line for owner privilege for the specified media mode. A valid file name does not include the path of the file.

### `dwMediaMode`

Media mode used to identify the target for the indirect handoff. The *dwMediaMode* parameter indirectly identifies the target application that is to receive ownership of the call. This parameter is ignored if *lpszFileName* is not **NULL**. This parameter uses one and only one of the
[LINEMEDIAMODE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linemediamode--constants).

## Return value

Returns zero if the request succeeds or a negative error number if an error occurs. Possible return values are:

LINEERR_INVALCALLHANDLE, LINEERR_OPERATIONFAILED, LINEERR_INVALMEDIAMODE, LINEERR_TARGETNOTFOUND, LINEERR_INVALPOINTER, LINEERR_TARGETSELF, LINEERR_NOMEM, LINEERR_UNINITIALIZED, LINEERR_NOTOWNER.

## Remarks

The
**lineHandoff** function returns LINEERR_TARGETSELF if the calling application attempted an indirect handoff (that is, set the *lpszFileName* parameter to **NULL**) and TAPI determined that the application is itself the highest priority application for the given media mode. If LINEERR_TARGETNOTFOUND is returned, a target for the call handoff was not found. This can occur if the named application did not open the same line with the LINECALLPRIVILEGE_OWNER bit in the *dwPrivileges* parameter of
[lineOpen](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineopen). Or, in the case of media-mode handoff, no application has opened the same line with the LINECALLPRIVILEGE_OWNER bit in the *dwPrivileges* parameter of
**lineOpen** and with the media mode specified in the *dwMediaModes* parameter of
**lineOpen**.

Call handoff allows ownership of a call to be passed among applications. There are two types of handoff. In the first type, if the application knows the file name of the target application, it can simply specify that file name. If an instance of the target application has opened the line device, ownership of the call is passed to the other application; otherwise, the handoff fails and an error is returned. This form of handoff succeeds if the call handle is handed off to the same file name as the application requesting the handoff.

The second type of handoff is based on media mode. In this case, the application indirectly specifies the target application by means of a media mode. The highest priority application that has currently opened the line device for that media mode is the target for the handoff. If there is no such application, the handoff fails and an error is returned.

The
**lineHandoff** function does not change the media mode of a call. To change the media mode of a call, the application should use
[lineSetMediaMode](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetmediamode) on the call, specifying the new media mode. This changes the call's media mode as stored in the call's
[LINECALLINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallinfo) structure.

If handoff succeeds, the receiving application receives a
[LINE_CALLSTATE](https://learn.microsoft.com/windows/desktop/Tapi/line-callstate) message for the call. This message indicates that the receiving application has owner privilege to the call (*dwParam3*). In addition, the number of owners and/or monitors for the call may have changed. This is reported by the
[LINE_CALLINFO](https://learn.microsoft.com/windows/desktop/Tapi/line-callinfo) message, and the receiving application can then invoke
[lineGetCallStatus](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetcallstatus) and
[lineGetCallInfo](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetcallinfo) to retrieve more information about the received call.

The receiving application should first check the media mode in
[LINECALLINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallinfo). If only a single media mode flag is set, the call is officially of that media mode, and the application can act accordingly. If UNKNOWN and other media mode flags are set, then the media mode of the call is officially UNKNOWN but is assumed to be of one of the media modes for which a flag is set in
**LINECALLINFO**. The application should assume that it ought to probe for the highest priority media mode.

If the probe succeeds (either for that media mode or for another one), the application should set the media mode member in
[LINECALLINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallinfo) to the single media mode that was recognized. If the media mode flag matches the
**LINECALLINFO** media mode, the application can act accordingly. If it makes a determination for another media mode, it must first hand off the call to that media mode.

If the probe fails, the application should clear the corresponding media mode flag in
[LINECALLINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallinfo) and hand off the call, specifying *dwMediaMode* as LINEMEDIAMODE_UNKNOWN. It should also deallocate its call handle (or revert back to monitoring).

If none of the media modes succeeded in making a determination, only the UNKNOWN flag remains set in the media mode field of
[LINECALLINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallinfo) at the time the media application attempts to hand off the call to UNKNOWN. The final
**lineHandoff** fails if the application is the only remaining owner of the call. This informs the application that it should drop the call and deallocate its handle, in which case the call is abandoned. The privileges of the invoking application to the call are unchanged by this operation, but the application can change its privileges to a call with
[lineSetCallPrivilege](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetcallprivilege).

## See also

[Basic Telephony Services Reference](https://learn.microsoft.com/windows/desktop/Tapi/basic-telephony-services-reference)

[Handoffs Overview](https://learn.microsoft.com/windows/desktop/Tapi/handoffs-ovr)

[LINECALLINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallinfo)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)

[lineGetCallStatus](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetcallstatus)

[lineOpen](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineopen)

[lineSetCallPrivilege](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetcallprivilege)

[lineSetMediaMode](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetmediamode)