# LINEADDRESSCAPS structure

## Description

The
**LINEADDRESSCAPS** structure describes the capabilities of a specified address. The
[lineGetAddressCaps](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetaddresscaps) function and the
[TSPI_lineGetAddressCaps](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linegetaddresscaps) function return the
**LINEADDRESSCAPS** structure.

## Members

### `dwTotalSize`

Total size allocated to this data structure, in bytes.

### `dwNeededSize`

Size for this data structure that is needed to hold all the returned information, in bytes.

### `dwUsedSize`

Size of the portion of this data structure that contains useful information, in bytes.

### `dwLineDeviceID`

Device identifier of the line device with which this address is associated.

### `dwAddressSize`

Size of the address field, in bytes.

### `dwAddressOffset`

Offset from the beginning of the structure to the variably sized address field. The size of the field is specified by **dwAddressSize**.

### `dwDevSpecificSize`

Size of the device-specific field, in bytes.

### `dwDevSpecificOffset`

Offset from the beginning of the structure to the variably sized device-specific field. The size of the field is specified by **dwDevSpecificSize**.

### `dwAddressSharing`

Sharing mode of the address. This member can be one of the
[LINEADDRESSSHARING_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/lineaddresssharing--constants).

### `dwAddressStates`

Address states changes for which the application may get notified in the LINE_ADDRESSSTATE message. This member uses one or more of the
[LINEADDRESSSTATE_ constants](https://learn.microsoft.com/windows/desktop/Tapi/lineaddressstate--constants).

### `dwCallInfoStates`

Call information elements that are meaningful for all calls on this address. An application may get notified about changes in some of these states in
[LINE_CALLINFO](https://learn.microsoft.com/windows/desktop/Tapi/line-callinfo) messages. This member uses one or more of the
[LINECALLINFOSTATE_ constants](https://learn.microsoft.com/windows/desktop/Tapi/linecallinfostate--constants).

### `dwCallerIDFlags`

Party identifier information types that can be provided for calls on this address. The caller is the originator of the session. One or more of the
[LINECALLPARTYID_ constants](https://learn.microsoft.com/windows/desktop/Tapi/linecallpartyid--constants).

### `dwCalledIDFlags`

Party identifier information types that can be provided for calls on this address. Here, "called" refers to the original destination. One or more of the
[LINECALLPARTYID_ constants](https://learn.microsoft.com/windows/desktop/Tapi/linecallpartyid--constants).

### `dwConnectedIDFlags`

Party identifier information types that can be provided for calls on this address. One or more of the
[LINECALLPARTYID_ constants](https://learn.microsoft.com/windows/desktop/Tapi/linecallpartyid--constants).

### `dwRedirectionIDFlags`

Party identifier information types that can be provided for calls on this address. Here, "redirection" is the new destination. One or more of the
[LINECALLPARTYID_ constants](https://learn.microsoft.com/windows/desktop/Tapi/linecallpartyid--constants).

### `dwRedirectingIDFlags`

Party identifier information types that can be provided for calls on this address. Here, "redirecting" is the address which invoked redirection. One or more of the
[LINECALLPARTYID_ constants](https://learn.microsoft.com/windows/desktop/Tapi/linecallpartyid--constants).

### `dwCallStates`

Call states that can be reported for calls on this address. This member uses one or more of the
[LINECALLSTATE_ constants](https://learn.microsoft.com/windows/desktop/Tapi/linecallstate--constants).

### `dwDialToneModes`

Dial tone modes that can be reported for calls made on this address. This member is meaningful only if the *dialtone* call state can be reported. This member uses one or more of the
[LINEDIALTONEMODE_ constants](https://learn.microsoft.com/windows/desktop/Tapi/linedialtonemode--constants).

### `dwBusyModes`

Busy modes that can be reported for calls made on this address. This member is meaningful only if the *busy* call state can be reported. This member uses one or more of the
[LINEBUSYMODE_ constants](https://learn.microsoft.com/windows/desktop/Tapi/linebusymode--constants).

### `dwSpecialInfo`

Special information types that can be reported for calls made on this address. This member is meaningful only if the *specialInfo* call state can be reported. This member uses one or more of the
[LINESPECIALINFO_ constants](https://learn.microsoft.com/windows/desktop/Tapi/linespecialinfo--constants).

### `dwDisconnectModes`

Disconnect modes that can be reported for calls made on this address. This member is meaningful only if the *disconnected* call state can be reported. This member uses one or more of the
[LINEDISCONNECTMODE_ constants](https://learn.microsoft.com/windows/desktop/Tapi/linedisconnectmode--constants).

### `dwMaxNumActiveCalls`

Maximum number of active call appearances that the address can handle. This number does not include calls on hold or calls on hold pending transfer or conference.

### `dwMaxNumOnHoldCalls`

Maximum number of call appearances at the address that can be on hold.

### `dwMaxNumOnHoldPendingCalls`

Maximum number of call appearances at the address that can be on hold pending transfer or conference.

### `dwMaxNumConference`

Maximum number of parties that can join a single conference call on this address.

### `dwMaxNumTransConf`

Number of parties (including "self") that can be added in a conference call that is initiated as a generic consultation call using
[lineSetupTransfer](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetuptransfer).

### `dwAddrCapFlags`

Packed bit flags that describe a variety of address capabilities. This member uses one or more of the
[LINEADDRCAPFLAGS_ constants](https://learn.microsoft.com/windows/desktop/Tapi/lineaddrcapflags--constants).

### `dwCallFeatures`

Switching capabilities or features available for all calls on this address using the
[LINECALLFEATURE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linecallfeature--constants). This member represents the call-related features that may possibly be available on an address (static availability as opposed to dynamic availability). Invoking a supported feature requires the call to be in the proper state and the underlying line device to be opened in a compatible mode. A zero in a bit position indicates that the corresponding feature is never available. A one indicates that the corresponding feature may be available if the application has the right privileges to the call and the call is in the appropriate state for the operation to be meaningful. This member allows an application to discover which call features can be (and which can never be) supported by the address.

### `dwRemoveFromConfCaps`

Address's capabilities for removing calls from a conference call. This member uses one of the
[LINEREMOVEFROMCONF_ constants](https://learn.microsoft.com/windows/desktop/Tapi/lineremovefromconf--constants).

### `dwRemoveFromConfState`

Uses the LINECALLSTATE_ constants to specify the state of the call after it has been removed from a conference call.

### `dwTransferModes`

Address's capabilities for resolving transfer requests. This member uses one of the
[LINETRANSFERMODE_ constants](https://learn.microsoft.com/windows/desktop/Tapi/linetransfermode--constants).

### `dwParkModes`

Different call park modes available at this address. This member uses one of the
[LINEPARKMODE_ constants](https://learn.microsoft.com/windows/desktop/Tapi/lineparkmode--constants).

### `dwForwardModes`

Different modes of forwarding available for this address. This member uses the
[LINEFORWARDMODE_ constants](https://learn.microsoft.com/windows/desktop/Tapi/lineforwardmode--constants).

### `dwMaxForwardEntries`

Maximum number of entries that can be passed to
[lineForward](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineforward) in the *lpForwardList* parameter.

### `dwMaxSpecificEntries`

Maximum number of entries in the *lpForwardList* parameter passed to
[lineForward](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineforward) that can contain forwarding instructions based on a specific caller ID (selective call forwarding). This member is zero if selective call forwarding is not supported.

### `dwMinFwdNumRings`

Minimum number of rings that can be set to determine when a call is officially considered "no answer."

### `dwMaxFwdNumRings`

Maximum number of rings that can be set to determine when a call is officially considered "no answer." If this number of rings cannot be set, then **dwMinFwdNumRings** and **dwMaxNumRings** are equal.

### `dwMaxCallCompletions`

Maximum number of concurrent call completion requests that can be outstanding on this line device. Zero implies that call completion is not available.

### `dwCallCompletionConds`

Different call conditions under which call completion can be requested. This member uses one or more of the LINECALLCOMPLCOND_ constants.

### `dwCallCompletionModes`

Way in which the call can be completed. This member uses one of the LINECALLCOMPLMODE_ constants.

### `dwNumCompletionMessages`

Number of call completion messages that can be selected from when using the LINECALLCOMPLMODE_MESSAGE option. Individual messages are identified by values in the range zero through one less than **dwNumCompletionMessages**.

### `dwCompletionMsgTextEntrySize`

Size of each of the call completion text descriptions specified by **dwCompletionMsgTextSize** and **dwCompletionMsgTextOffset**, in bytes.

### `dwCompletionMsgTextSize`

Size of the call completion text, in bytes.

### `dwCompletionMsgTextOffset`

Offset from the beginning of this data structure to the variably sized field containing descriptive text about each of the call completion messages. Each message is **dwCompletionMsgTextEntrySize** bytes long. The string format of these textual descriptions is indicated by **dwStringFormat** in the line's device capabilities. The size of the field is specified by **dwCompletionMsgTextSize**.

### `dwAddressFeatures`

Features available for this address using the
[LINEADDRFEATURE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/lineaddrfeature--constants). Invoking a supported feature requires the address to be in the proper state and the underlying line device to be opened in a compatible mode. A zero in a bit position indicates that the corresponding feature is never available. A one indicates that the corresponding feature may be available if the address is in the appropriate state for the operation to be meaningful. This member allows an application to discover which address features can be (and which can never be) supported by the address.

### `dwPredictiveAutoTransferStates`

Call state or states upon which a call made by a predictive dialer can be set to automatically transfer the call to another address; one or more of the
[LINECALLSTATE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linecallstate--constants). The value 0 indicates automatic transfer based on call state is unavailable.

### `dwNumCallTreatments`

Number of entries in the array of
[LINECALLTREATMENTENTRY](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecalltreatmententry) structures delimited by **dwCallTreatmentListSize** and **dwCallTreatmentListOffset**.

### `dwCallTreatmentListSize`

Size of the call treatment array, in bytes.

### `dwCallTreatmentListOffset`

Offset from the beginning of the structure to an array of
[LINECALLTREATMENTENTRY](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecalltreatmententry) structures the specify the call treatments supported on the address (that can be selected using
[lineSetCallTreatment](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetcalltreatment)). The value is **dwNumCallTreatments** times SIZEOF(LINECALLTREATMENTENTRY). The size of the field is specified by **dwCallTreatmentListSize**.

### `dwDeviceClassesSize`

Size of the list of supported device classes, in bytes.

### `dwDeviceClassesOffset`

Offset from the beginning of the structure to a string consisting of the device class identifiers supported on this address for use with
[lineGetID](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetid). The elements are separated by **null** characters, and the last class identifier is followed by two **null** characters. The size of the field is specified by **dwDeviceClassesSize**.

### `dwMaxCallDataSize`

Maximum number of bytes that an application can set in
[LINECALLINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallinfo) using
[lineSetCallData](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetcalldata).

### `dwCallFeatures2`

Additional switching capabilities or features available for all calls on this address using the
[LINECALLFEATURE2_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linecallfeature2--constants). It is an extension of the **dwCallFeatures** member.

### `dwMaxNoAnswerTimeout`

Maximum value in seconds that can be set in the **dwNoAnswerTimeout** member in
[LINECALLPARAMS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallparams) when making a call. A value of 0 indicates that automatic abandonment of unanswered calls is not supported by the service provider, or that the timeout value is not adjustable by applications.

### `dwConnectedModes`

LINECONNECTEDMODE_ values that can appear in the **dwCallStateMode** member of
[LINECALLSTATUS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallstatus) and in
[LINE_CALLSTATE](https://learn.microsoft.com/windows/desktop/Tapi/line-callstate) messages for calls on this address.

### `dwOfferingModes`

LINEOFFERINGMODE_ values that can appear in the **dwCallStateMode** member of
[LINECALLSTATUS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallstatus) and in LINE_CALLSTATE messages for calls on this address.

### `dwAvailableMediaModes`

Media types (modes) that can be invoked on new calls created on this address, when the **dwAddressFeatures** member indicates that new calls are possible. If this member is zero, it indicates that the service provider either does not know or cannot indicate which media types are available, in which case any or all of the media types indicated in the **dwMediaModes** member in
[LINEDEVCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevcaps) may be available.

## Remarks

Device-specific extensions should use the **DevSpecific** (**dwDevSpecificSize** and **dwDevSpecificOffset**) variably sized area of this data structure.

Older applications are compiled without this member in the
**LINEADDRESSCAPS** structure, and using a SIZEOF(LINEADDRESSCAPS) smaller than the new size. The application passes in a *dwAPIVersion* parameter with the
[lineGetAddressCaps](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetaddresscaps) function, which can be used for guidance by TAPI in handling this situation. If the application passes in a **dwTotalSize** member less than the size of the fixed portion of the structure as defined in the **dwAPIVersion** member specified, LINEERR_STRUCTURETOOSMALL is returned. If sufficient memory has been allocated by the application, before calling
[TSPI_lineGetAddressCaps](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linegetaddresscaps), TAPI sets the **dwNeededSize** and **dwUsedSize** members to the fixed size of the structure as it existed in the specified API version.

New service providers (that support the new API version) must examine the API version passed in. If the API version is less than the highest version supported by the provider, the service provider must not fill in fields not supported in older API versions, as these would fall in the variable portion of the older structure.

New applications must be cognizant of the API version negotiated, and not examine the contents of fields in the fixed portion beyond the original end of the fixed portion of the structure for the negotiated API version.

The members **dwPredictiveAutoTransferStates** through **dwAvailableMediaModes** are available only to applications that request an API version of 2.0 or later when calling
[lineGetAddressCaps](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetaddresscaps).

## See also

[LINEADDRESSSTATUS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineaddressstatus)

[LINECALLINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallinfo)

[LINECALLPARAMS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallparams)

[LINECALLSTATUS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallstatus)

[LINECALLTREATMENTENTRY](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecalltreatmententry)

[LINEDEVCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevcaps)

[LINEDIALPARAMS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedialparams)

[LINE_ADDRESSSTATE](https://learn.microsoft.com/windows/desktop/Tapi/line-addressstate)

[LINE_CALLINFO](https://learn.microsoft.com/windows/desktop/Tapi/line-callinfo)

[LINE_CALLSTATE](https://learn.microsoft.com/windows/desktop/Tapi/line-callstate)

[LINE_LINEDEVSTATE](https://learn.microsoft.com/windows/desktop/Tapi/line-linedevstate)

[TSPI_lineGetAddressCaps](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linegetaddresscaps)

[lineCompleteCall](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linecompletecall)

[lineForward](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineforward)

[lineGenerateDigits](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegeneratedigits)

[lineGetAddressCaps](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetaddresscaps)

[lineGetID](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetid)

[lineSetCallData](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetcalldata)

[lineSetCallTreatment](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetcalltreatment)