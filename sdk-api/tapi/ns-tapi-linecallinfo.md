# LINECALLINFO structure

## Description

The
**LINECALLINFO** structure contains information about a call. This information remains relatively fixed for the duration of the call. Multiple functions use
**LINECALLINFO**. The structure is returned by the
[lineGetCallInfo](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetcallinfo) function and the
[TSPI_lineGetCallInfo](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linegetcallinfo) function. If a part of the structure does change, then a
[LINE_CALLINFO](https://learn.microsoft.com/windows/desktop/Tapi/line-callinfo) message is sent to the application indicating which information item has changed.

Dynamically changing information about a call, such as call progress status, is available in the
[LINECALLSTATUS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallstatus) structure, returned by a call to the
[lineGetCallStatus](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetcallstatus) function.

## Members

### `dwTotalSize`

Total size allocated to this data structure, in bytes.

### `dwNeededSize`

Size for this data structure that is needed to hold all the returned information, in bytes.

### `dwUsedSize`

Size of the portion of this data structure that contains useful information, in bytes.

### `hLine`

Handle to the line device with which this call is associated.

### `dwLineDeviceID`

Device identifier of the line device with which this call is associated.

### `dwAddressID`

Address identifier of the address on the line on which this call exists. An address identifier is permanently associated with an address; the identifier remains constant across operating system upgrades.

### `dwBearerMode`

Current bearer mode of the call. This member uses one of the
[LINEBEARERMODE_ constants](https://learn.microsoft.com/windows/desktop/Tapi/linebearermode--constants).

### `dwRate`

Rate of the call's data stream, in bps (bits per second).

### `dwMediaMode`

Media type of the information stream currently on the call. This is the media type as determined by the owner of the call, which is not necessarily the same as that of the last
[LINE_MONITORMEDIA](https://learn.microsoft.com/windows/desktop/Tapi/line-monitormedia) message. This member is not directly affected by the LINE_MONITORMEDIA messages. This member uses the
[LINEMEDIAMODE_ constants](https://learn.microsoft.com/windows/desktop/Tapi/linemediamode--constants).

### `dwAppSpecific`

Not interpreted by the API implementation and service provider. It can be set by any owner application of this call with the
[lineSetAppSpecific](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetappspecific) function.

### `dwCallID`

In some telephony environments, the switch or service provider can assign a unique identifier to each call. This allows the call to be tracked across transfers, forwards, or other events. The domain of these call IDs and their scope is service provider-defined. The **dwCallID** member makes this unique identifier available to the applications.

### `dwRelatedCallID`

Telephony environments that use the call ID often may find it necessary to relate one call to another. The **dwRelatedCallID** member may be used by the service provider for this purpose.

### `dwCallParamFlags`

Collection of call-related parameters when the call is outgoing. These are the same call parameters specified in
[lineMakeCall](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linemakecall), one or more of the
[LINECALLPARAMFLAGS_ constants](https://learn.microsoft.com/windows/desktop/Tapi/linecallparamflags--constants).

### `dwCallStates`

One or more of the LINECALLSTATE_ constants, that indicates the states in which the application can be notified on this call. The **dwCallStates** member is constant in
**LINECALLINFO** and does not change depending on the call state.

### `dwMonitorDigitModes`

Various digit modes. This member is one or more of the
[LINEDIGITMODE_ constants](https://learn.microsoft.com/windows/desktop/Tapi/linedigitmode--constants), for which monitoring is currently enabled.

### `dwMonitorMediaModes`

Various media types for which monitoring is currently enabled. This member is one or more of the
[LINEMEDIAMODE_ constants](https://learn.microsoft.com/windows/desktop/Tapi/linemediamode--constants).

### `DialParams`

Dialing parameters currently in effect on the call, of type
[LINEDIALPARAMS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedialparams). Unless these parameters are set by either
[lineMakeCall](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linemakecall) or
[lineSetCallParams](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetcallparams), their values are the same as the defaults used in the
[LINEDEVCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevcaps) structure.

### `dwOrigin`

Identifies where the call originated. This member can be one of the
[LINECALLORIGIN_ constants](https://learn.microsoft.com/windows/desktop/Tapi/linecallorigin--constants).

### `dwReason`

Reason why the call occurred. This member can be one of the
[LINECALLREASON_ constants](https://learn.microsoft.com/windows/desktop/Tapi/linecallreason--constants).

### `dwCompletionID`

Completion identifier for the incoming call if it is the result of a completion request that terminates. This identifier is meaningful only if **dwReason** is LINECALLREASON_CALLCOMPLETION.

### `dwNumOwners`

Number of application modules with different call handles with owner privilege for the call.

### `dwNumMonitors`

Number of application modules with different call handles with monitor privilege for the call.

### `dwCountryCode`

Country or region code of the destination party. Zero if unknown.

### `dwTrunk`

Number of the trunk over which the call is routed. This member is used for both incoming and outgoing calls. The **dwTrunk** member should be set to 0xFFFFFFFF if it is unknown.

### `dwCallerIDFlags`

Determines the validity and content of the caller, or originator, party identifier information. This member uses one of the
[LINECALLPARTYID_ constants](https://learn.microsoft.com/windows/desktop/Tapi/linecallpartyid--constants).

### `dwCallerIDSize`

Size of the caller ID number, in bytes.

### `dwCallerIDOffset`

Offset from the beginning of this structure to the variably sized field containing the caller party ID number information. The size of the field is specified by **dwCallerIDSize**.

### `dwCallerIDNameSize`

Size of the caller ID name including the null terminator, in bytes.

### `dwCallerIDNameOffset`

Offset from the beginning of this structure to the variably sized field containing the caller party ID name information. The size of the field is specified by **dwCallerIDNameSize**.

### `dwCalledIDFlags`

Determines the validity and content of the called-party ID information. The called party corresponds to the originally addressed party. This member uses one of the
[LINECALLPARTYID_ constants](https://learn.microsoft.com/windows/desktop/Tapi/linecallpartyid--constants).

### `dwCalledIDSize`

Size of the called-party ID number, in bytes.

### `dwCalledIDOffset`

Offset from the beginning of the structure to the variably sized field containing the called-party ID number information. The size of the field is specified by **dwCalledIDSize**.

### `dwCalledIDNameSize`

Size of the called-party ID name including the null terminator, in bytes.

### `dwCalledIDNameOffset`

Offset from the beginning of the structure to the variably sized field containing the called-party ID name information. The size of the field is specified by **dwCalledIDNameSize**.

### `dwConnectedIDFlags`

Determines the validity and content of the connected party ID information. The connected party is the party that was actually connected to. This may be different from the called-party ID if the call was diverted. This member uses one of the
[LINECALLPARTYID_ constants](https://learn.microsoft.com/windows/desktop/Tapi/linecallpartyid--constants).

### `dwConnectedIDSize`

Size of the connected-party ID number, in bytes.

### `dwConnectedIDOffset`

Offset from the beginning of this structure to the variably sized field containing the connected-party ID number information. The size of the field is specified by **dwConnectedIDSize**.

### `dwConnectedIDNameSize`

Size of the connected-party ID name including the null terminator, in bytes.

### `dwConnectedIDNameOffset`

Offset from the beginning of this structure to the variably sized field containing the connected-party ID name information. The size of the field is specified by **dwConnectedIDNameSize**.

### `dwRedirectionIDFlags`

Determines the validity and content of the redirection party identifier information. The redirection party identifies the address to which the session was redirected. This member uses one of the
[LINECALLPARTYID_ constants](https://learn.microsoft.com/windows/desktop/Tapi/linecallpartyid--constants).

### `dwRedirectionIDSize`

Size of the redirection-party ID number, in bytes.

### `dwRedirectionIDOffset`

Offset from the beginning of the structure to the variably sized field containing the redirection-party ID number information. The size of the field is specified by **dwRedirectionIDSize**.

### `dwRedirectionIDNameSize`

Size of the redirection-party ID name, in bytes.

### `dwRedirectionIDNameOffset`

Offset from the beginning of the structure to the variably sized field containing the redirection-party ID name information. The size of the field is specified by **dwRedirectionIDNameSize**.

### `dwRedirectingIDFlags`

Determines the validity and content of the redirecting party identifier information. The redirecting party identifies the address which redirect the session. This member uses one of the
[LINECALLPARTYID_ constants](https://learn.microsoft.com/windows/desktop/Tapi/linecallpartyid--constants).

### `dwRedirectingIDSize`

Size of the redirecting-party ID number, in bytes.

### `dwRedirectingIDOffset`

Offset from the beginning of the structure to the variably sized field containing the redirecting-party ID number information. The size of the field is specified by **dwRedirectingIDSize**.

### `dwRedirectingIDNameSize`

Size of the redirecting-party ID name including the null terminator, in bytes.

### `dwRedirectingIDNameOffset`

Offset from the beginning of the structure to the variably sized field containing the redirecting-party ID name information. The size of the field is specified by **dwRedirectingIDNameSize**.

### `dwAppNameSize`

Size of the application name field including the null terminator, in bytes.

### `dwAppNameOffset`

Offset from the beginning of the structure to the variably sized field holding the user-friendly name of the application that first originated, accepted, or answered the call. This is the name that an application can specify in
[lineInitializeEx](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineinitializeexa). If the application specifies no such name, then the application's module filename is used instead. The size of the field is specified by **dwAppNameSize**.

### `dwDisplayableAddressSize`

Size of the displayable address string including the null terminator, in bytes.

### `dwDisplayableAddressOffset`

Displayable string is used for logging purposes. The information is obtained from
[LINECALLPARAMS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallparams) for functions that initiate calls. The
[lineTranslateAddress](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linetranslateaddress) function returns appropriate information to be placed in this field in the **dwDisplayableAddressSize** and **dwDisplayableAddressOffset** members of the
[LINETRANSLATEOUTPUT](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linetranslateoutput) structure.

### `dwCalledPartySize`

Size of the called-party description field, in bytes.

### `dwCalledPartyOffset`

Offset from the beginning of the structure to the variably sized field that specifies the user-friendly description of the called party. This information can be specified with
[lineMakeCall](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linemakecall) and can be optionally specified in the *lpCallParams* parameter whenever a new call is established. It is useful for call logging purposes. The size of the field is specified by **dwCalledPartySize**.

### `dwCommentSize`

Size of the comment field, in bytes.

### `dwCommentOffset`

Offset from the beginning of the structure to the variably sized field holding a comment about the call provided by the application that originated the call using
[lineMakeCall](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linemakecall). This information can be optionally specified in the *lpCallParams* parameter whenever a new call is established. The size of the field is specified by **dwCommentSize**.

### `dwDisplaySize`

Size of the raw display information, in bytes.

### `dwDisplayOffset`

Offset from the beginning of the structure to the variably sized field holding raw display information. Depending on the telephony environment, a service provider may extract functional information from this member pair for formatting and presentation most appropriate for this telephony configuration. The size of the field is specified by **dwDisplaySize**.

### `dwUserUserInfoSize`

Size of the user-user information, in bytes. If the user-user information is a pointer to a string, the size must include the null terminator.

### `dwUserUserInfoOffset`

Offset from the beginning of the structure to the variably sized field holding user-user information. The protocol discriminator field for the user-user information, if used, appears as the first byte of the data pointed to by **dwUserUserInfoOffset**, and is accounted for in **dwUserUserInfoSize**.

### `dwHighLevelCompSize`

Size of the high-level compatibility information, in bytes.

### `dwHighLevelCompOffset`

Offset from the beginning of the structure to the variably sized field holding high-level compatibility information. The format of this information is specified by other standards (ISDN Q.931). The size of the field is specified by **dwHighLevelCompSize**.

### `dwLowLevelCompSize`

Size of the low-level compatibility information, in bytes.

### `dwLowLevelCompOffset`

Offset from the beginning of the structure to the variably sized field holding low-level compatibility information. The format of this information is specified by other standards (ISDN Q.931). The size of the field is specified by **dwLowLevelCompSize**.

### `dwChargingInfoSize`

Size of the charging information, in bytes.

### `dwChargingInfoOffset`

Offset from the beginning of the structure to the variably sized field holding charging information. The format of this information is specified by other standards (ISDN Q.931). The size of the field is specified by **dwChargingInfoSize**.

### `dwTerminalModesSize`

Size of the current terminal modes array, in bytes.

### `dwTerminalModesOffset`

Offset from the beginning of the structure to the variably sized device field containing an array with **DWORD**-sized entries. Array entries are indexed by terminal identifiers, in the range from zero to one less than **dwNumTerminals**. Each entry in the array specifies the current terminal modes for the corresponding terminal set with the
[lineSetTerminal](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetterminal) function for this call's media stream, as specified by one of the
[LINETERMMODE_ constants](https://learn.microsoft.com/windows/desktop/Tapi/linetermmode--constants). The size of the array is specified by **dwTerminalModesSize**.

### `dwDevSpecificSize`

Size of the device-specific field, in bytes.

### `dwDevSpecificOffset`

Offset from the beginning of the structure to the variably-sized field holding device-specific information. The size of the field is specified by **dwDevSpecificSize**.

### `dwCallTreatment`

Call treatment currently being applied on the call or that is applied when the call enters the next applicable state. Can be zero if call treatments are not supported.

### `dwCallDataSize`

Size of the application-settable call data, in bytes.

### `dwCallDataOffset`

Offset from the beginning of the structure to the application-settable call data. The size of the field is specified by **dwCallDataSize**.

### `dwSendingFlowspecSize`

Size of the quality of service information, in bytes.

### `dwSendingFlowspecOffset`

Offset from the beginning of the structure to a
[FLOWSPEC](https://learn.microsoft.com/windows/desktop/api/qos/ns-qos-flowspec) structure followed by WinSock provider-specific data, equivalent to what would have been stored in **SendingFlowspec** in a
[QOS](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-qos) structure. Specifies the quality of service currently in effect in the sending direction on the call. The provider-specific portion following the **FLOWSPEC** structure must not contain pointers to other blocks of memory, because TAPI does not know how to marshal the data pointed to by the private pointer(s) and convey it through interprocess communication to the application. The size of the field is specified by **dwSendingFlowspecSize**.

### `dwReceivingFlowspecSize`

Size of the quality of service information, in bytes.

### `dwReceivingFlowspecOffset`

Offset from the beginning of the structure to a [FLOWSPEC](https://learn.microsoft.com/windows/desktop/api/qos/ns-qos-flowspec) structure followed by WinSock provider-specific data, equivalent to what would have been stored in **ReceivingFlowspec** in a [QOS](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-qos) structure. Specifies the quality of service current in effect in the receiving direction on the call. The provider-specific portion following the **FLOWSPEC** structure must not contain pointers to other blocks of memory, because TAPI does not know how to marshal the data pointed to by the private pointer(s) and convey it through interprocess communication to the application. The size of the field is specified by **dwReceivingFlowspecSize**.

### `dwCallerIDAddressType`

[Address type](https://learn.microsoft.com/windows/desktop/Tapi/lineaddresstype--constants) of the caller. This member of the structure is available only if the negotiated TAPI version is 3.0 or higher.

### `dwCalledIDAddressType`

[Address type](https://learn.microsoft.com/windows/desktop/Tapi/lineaddresstype--constants) of the called party. This member of the structure is available only if the negotiated TAPI version is 3.0 or higher.

### `dwConnectedIDAddressType`

[Address type](https://learn.microsoft.com/windows/desktop/Tapi/lineaddresstype--constants) of the destination to which the call was actually connected. This member of the structure is available only if the negotiated TAPI version is 3.0 or higher.

### `dwRedirectionIDAddressType`

[Address type](https://learn.microsoft.com/windows/desktop/Tapi/lineaddresstype--constants) of the new call destination. This member of the structure is available only if the negotiated TAPI version is 3.0 or higher.

### `dwRedirectingIDAddressType`

[Address type](https://learn.microsoft.com/windows/desktop/Tapi/lineaddresstype--constants) of the location which redirected the call. This member of the structure is available only if the negotiated TAPI version is 3.0 or higher.

## Remarks

Device-specific extensions should use the DevSpecific (**dwDevSpecificSize** and **dwDevSpecificOffset**) variably sized area of this data structure.

The
**LINECALLINFO** data structure contains relatively fixed information about a call. This structure is returned with
[lineGetCallInfo](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetcallinfo). When information items in this data structure have changed, a LINE_CALLINFO message is sent to the application. A parameter to this message is the information item or field that changed.

The members **dwCallTreatment** through **dwReceivingFlowspecOffset** are available only to applications that open the line device with an API version of 2.0 or later.

**Note** The preferred format for specification of the contents of the **dwCallID** field and the other five similar fields (**dwCallerIDFlag**, **dwCallerIDSize**, **dwCallerIDOffset**, **dwCallerIDNameSize**, and **dwCallerIDNameOffset**) is the TAPI canonical number format. For example, a ICLID of "4258828080" received from the switch should be converted to "+1 (425) 8828080" before being placed in the
**LINECALLINFO** structure. This standardized format facilitates searching of databases and callback functions implemented in applications.

## See also

[LINECALLSTATUS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallstatus)

[LINEDEVCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevcaps)

[LINEDIALPARAMS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedialparams)

[LINETRANSLATEOUTPUT](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linetranslateoutput)

[LINE_CALLINFO](https://learn.microsoft.com/windows/desktop/Tapi/line-callinfo)

[LINE_MONITORMEDIA](https://learn.microsoft.com/windows/desktop/Tapi/line-monitormedia)

[TSPI_lineGetCallInfo](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linegetcallinfo)

[lineGenerateDigits](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegeneratedigits)

[lineGetCallInfo](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetcallinfo)

[lineGetCallStatus](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetcallstatus)

[lineInitializeEx](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineinitializeexa)

[lineMakeCall](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linemakecall)

[lineSecureCall](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesecurecall)

[lineSetAppSpecific](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetappspecific)

[lineSetCallParams](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetcallparams)

[lineSetTerminal](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetterminal)

[lineTranslateAddress](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linetranslateaddress)