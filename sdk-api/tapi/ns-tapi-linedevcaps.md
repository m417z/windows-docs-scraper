# LINEDEVCAPS structure

## Description

The
**LINEDEVCAPS** structure describes the capabilities of a line device. The
[lineGetDevCaps](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetdevcaps) function and the
[TSPI_lineGetDevCaps](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linegetdevcaps) function return the
**LINEDEVCAPS** structure.

## Members

### `dwTotalSize`

Total size allocated to this data structure, in bytes.

### `dwNeededSize`

Size needed for this data structure to hold all the returned information, in bytes.

### `dwUsedSize`

Size of the portion of this data structure that contains useful information, in bytes.

### `dwProviderInfoSize`

Size of the variably sized field containing service provider information, in bytes.

### `dwProviderInfoOffset`

Offset from the beginning of the structure to the service provider information, in bytes.

The **dwProviderInfoSize** and **dwProviderInfoOffset** members are intended to provide information about the provider hardware and/or software, such as the vendor name and version numbers of hardware and software. This information can be useful when a user needs to call customer service with problems regarding the provider.

### `dwSwitchInfoSize`

Size of the variably sized device field containing switch information, in bytes.

### `dwSwitchInfoOffset`

Offset from the beginning of the structure to the switch information, in bytes.

The **dwSwitchInfoSize** and **dwSwitchInfoOffset** members are intended to provide information about the switch to which the line device is connected, such as the switch manufacturer, the model name, the software version, and so on. This information can be useful when a user needs to call customer service with problems regarding the switch.

### `dwPermanentLineID`

Permanent identifier by which the line device is known in the system's configuration. It is a permanent name for the line device. This permanent name (as opposed to *dwDeviceID*) does not change as lines are added or removed from the system, and persists through operating system upgrades. It can therefore be used to link line-specific information in .ini files (or other files) in a way that is not affected by adding or removing other lines or by changing the operating system.

### `dwLineNameSize`

Size of the variably sized device field containing a user configurable name for this line device, in bytes.

### `dwLineNameOffset`

Offset from the beginning of this data structure to the name for this line device. This name can be configured by the user when configuring the line device's service provider, and is provided for the user's convenience. The size of the field is specified by **dwLineNameSize**.

### `dwStringFormat`

String format used with this line device. This member uses one of the
[STRINGFORMAT_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/stringformat--constants).

### `dwAddressModes`

Mode by which the originating address is specified. This member uses the
[LINEADDRESSMODE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/lineaddressmode--constants).

### `dwNumAddresses`

Number of addresses associated with this line device. Individual addresses are referred to by address identifiers. Address identifiers range from zero to one less than the value indicated by **dwNumAddresses**.

### `dwBearerModes`

Flag array that indicates the different bearer modes that the address is able to support. This member uses one or more of the
[LINEBEARERMODE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linebearermode--constants).

### `dwMaxRate`

Maximum data rate for information exchange over the call, in bits per second.

### `dwMediaModes`

Flag array that indicates the different media types the address is able to support. This member uses one or more of the
[LINEMEDIAMODE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linemediamode--constants).

### `dwGenerateToneModes`

Tones that can be generated on this line. This member uses one or more of the
[LINETONEMODE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linetonemode--constants).

### `dwGenerateToneMaxNumFreq`

Maximum number of frequencies that can be specified in describing a general tone using the
[LINEGENERATETONE](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linegeneratetone) data structure when generating a tone using
[lineGenerateTone](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegeneratetone). A value of 0 indicates that tone generation is not available.

### `dwGenerateDigitModes`

Digit modes than can be generated on this line. This member uses one or more of the
[LINEDIGITMODE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linedigitmode--constants).

### `dwMonitorToneMaxNumFreq`

Maximum number of frequencies that can be specified in describing a general tone using the
[LINEMONITORTONE](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linemonitortone) data structure when monitoring a general tone using
[lineMonitorTones](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linemonitortones). A value of 0 indicates that tone monitor is not available.

### `dwMonitorToneMaxNumEntries`

Maximum number of entries that can be specified in a tone list to
[lineMonitorTones](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linemonitortones).

### `dwMonitorDigitModes`

Digit modes than can be detected on this line. This member uses one or more of the
[LINEDIGITMODE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linedigitmode--constants).

### `dwGatherDigitsMinTimeout`

Minimum value that can be specified for both the first digit and inter-digit timeout values used by
[lineGatherDigits](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegatherdigits), in milliseconds. If both **dwGatherDigitsMinTimeout** and **dwGatherDigitsMaxTimeout** are zero, timeouts are not supported.

### `dwGatherDigitsMaxTimeout`

Maximum value that can be specified for both the first digit and inter-digit timeout values used by
[lineGatherDigits](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegatherdigits), in milliseconds. If both **dwGatherDigitsMinTimeout** and **dwGatherDigitsMaxTimeout** are zero, timeouts are not supported.

### `dwMedCtlDigitMaxListSize`

Maximum number of entries that can be specified in the digit list parameter of
[lineSetMediaControl](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetmediacontrol).

### `dwMedCtlMediaMaxListSize`

Maximum number of entries that can be specified in the media list parameter of
[lineSetMediaControl](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetmediacontrol).

### `dwMedCtlToneMaxListSize`

Maximum number of entries that can be specified in the tone list parameter of
[lineSetMediaControl](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetmediacontrol).

### `dwMedCtlCallStateMaxListSize`

Maximum number of entries that can be specified in the call state list parameter of
[lineSetMediaControl](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetmediacontrol).

### `dwDevCapFlags`

Boolean device capabilities. This member uses one or more of the
[LINEDEVCAPFLAGS_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linedevcapflags--constants).

### `dwMaxNumActiveCalls`

Maximum number of (minimum bandwidth) calls that can be active (connected) on the line at any one time. The actual number of active calls may be lower if higher bandwidth calls have been established on the line.

### `dwAnswerMode`

Effect on the active call when answering another offering call on a line device. This member uses one of the
[LINEANSWERMODE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/lineanswermode--constants).

### `dwRingModes`

Number of different ring modes that can be reported in the
[LINE_LINEDEVSTATE](https://learn.microsoft.com/windows/desktop/Tapi/line-linedevstate) message with the *ringing* indication. Different ring modes range from one to **dwRingModes**. Zero indicates no ring.

### `dwLineStates`

Different line status components for which the application may be notified in a LINE_LINEDEVSTATE message on this line. This member uses one or more of the
[LINEDEVSTATE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linedevstate--constants).

### `dwUUIAcceptSize`

Maximum size of user-user information, including the **null** terminator, that can be sent during a call accept.

### `dwUUIAnswerSize`

Maximum size of user-user information, including the **null** terminator, that can be sent during a call answer.

### `dwUUIMakeCallSize`

Maximum size of user-user information, including the **null** terminator, that can be sent during a make call.

### `dwUUIDropSize`

Maximum size of user-user information, including the **null** terminator, that can be sent during a call drop.

### `dwUUISendUserUserInfoSize`

Maximum size of user-user information, including the **null** terminator, that can be sent separately any time during a call with
[lineSendUserUserInfo](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesenduseruserinfo).

### `dwUUICallInfoSize`

Maximum size of user-user information, including the **null** terminator, that can be received in the
[LINECALLINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallinfo) structure.

### `MinDialParams`

Minimum value for the dial parameters that can be set for calls on this line, in milliseconds. Dialing parameters can be set to values in the range **MinDialParams** to **MaxDialParams**. The granularity of the actual settings is service provider-specific.

### `MaxDialParams`

Maximum value for the dial parameters that can be set for calls on this line, in milliseconds. Dialing parameters can be set to values in the range **MinDialParams** to **MaxDialParams**. The granularity of the actual settings is service provider-specific.

### `DefaultDialParams`

Default dial parameters used for calls on this line. These parameter values can be overridden on a per-call basis.

### `dwNumTerminals`

Number of terminals that can be set for this line device, its addresses, or its calls. Individual terminals are referred to by terminal IDs and range from zero to one less than the value indicated by **dwNumTerminals**.

### `dwTerminalCapsSize`

Size of the variably sized device field containing an array with entries of type
[LINETERMCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linetermcaps), in bytes.

### `dwTerminalCapsOffset`

Offset from the beginning of this structure to the variably sized device field containing an array with entries of type
[LINETERMCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linetermcaps). This array is indexed by terminal IDs, in the range from zero to **dwNumTerminals** minus one. Each entry in the array specifies the terminal device capabilities of the corresponding terminal. The size of the field is specified by **dwTerminalCapsSize**.

### `dwTerminalTextEntrySize`

Size of each of the terminal text descriptions, including the **null** terminator, pointed to by **dwTerminalTextSize** and **dwTerminalTextOffset**, in bytes.

### `dwTerminalTextSize`

Size of the variably sized field containing descriptive text about each of the line's available terminals, including the **null** terminator, in bytes

### `dwTerminalTextOffset`

Offset from the beginning of this structure to the descriptive text about each of the line's available terminals, in bytes. Each message is **dwTerminalTextEntrySize** bytes long. The string format of these textual descriptions is indicated by **dwStringFormat** in the line's device capabilities. The size of the field is specified by **dwTerminalTextSize**.

### `dwDevSpecificSize`

Size of the variably sized device-specific field, in bytes. If the device-specific information is a pointer to a string, the size must include the **null** terminator.

### `dwDevSpecificOffset`

Offset from the beginning of this structure to the device-specific field, in bytes. The size of the field is specified by **dwDevSpecificSize**.

### `dwLineFeatures`

Features available for this line using the
[LINEFEATURE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linefeature--constants). Invoking a supported feature requires the line to be in the proper state and the underlying line device to be opened in a compatible mode. A zero in a bit position indicates that the corresponding feature is never available. A one indicates that the corresponding feature may be available if the line is in the appropriate state for the operation to be meaningful. This member allows an application to discover which line features can be (and which can never be) supported by the device.

### `dwSettableDevStatus`

[LINEDEVSTATUSFLAGS](https://learn.microsoft.com/windows/desktop/Tapi/linedevstatusflags--constants) values that can be modified using
[lineSetLineDevStatus](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetlinedevstatus).

### `dwDeviceClassesSize`

Size of a string containing the device class identifiers supported on one or more addresses on this line, including the **null** terminator, in bytes.

### `dwDeviceClassesOffset`

Offset from the beginning of this structure to a string containing the device class identifiers supported on one or more addresses on this line, in bytes. These strings are for use with
[lineGetID](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetid); they are separated by **NULL**s, and the last identifier in the list is followed by two **NULL**s. The size of the field is specified by **dwDeviceClassesSize**.

### `PermanentLineGuid`

GUID permanently associated with the line device.

### `dwAddressTypes`

[Address type](https://learn.microsoft.com/windows/desktop/Tapi/lineaddresstype--constants) used for the call. This member of the structure is available only if the negotiated TAPI version is 3.0 or higher.

### `ProtocolGuid`

Current
[TAPI protocol](https://learn.microsoft.com/windows/desktop/Tapi/tapiprotocol--constants). This member of the structure is available only if the negotiated TAPI version is 3.0 or higher. The protocols are declared in tapi3.h.

### `dwAvailableTracking`

Available tracking, as represented by a
[LINECALLHUBTRACKING](https://learn.microsoft.com/windows/desktop/Tapi/linecallhubtracking--constants).constant. This member of the structure is available only if the negotiated TAPI version is 3.0 or higher.

## Remarks

Device-specific extensions should use the DevSpecific (**dwDevSpecificSize** and **dwDevSpecificOffset**) variably sized area of this data structure.

Older applications are compiled without new members in the
**LINEDEVCAPS** structure, and using a SIZEOF LINEDEVCAPS smaller than the new size. The application passes in a *dwAPIVersion* parameter with the
[lineGetDevCaps](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetdevcaps) function, which can be used for guidance by TAPI in handling this situation. If the application passes in a **dwTotalSize** member less than the size of the fixed portion of the structure as defined in the specified **dwAPIVersion**, LINEERR_STRUCTURETOOSMALL is returned. If sufficient memory has been allocated by the application, before calling
[TSPI_lineGetDevCaps](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linegetdevcaps), TAPI sets the **dwNeededSize** and **dwUsedSize** members to the fixed size of the structure as it existed in the specified API version.

New applications must be cognizant of the API version negotiated, and not examine the contents of members in the fixed portion beyond the original end of the fixed portion of the structure for the negotiated API version.

If the LINEBEARERMODE_DATA bit is set in the **dwBearerModes** member, the **dwMaxRate** member indicates the maximum rate of digital transmission on the bearer channel. The **dwMaxRate** member of the
**LINEDEVCAPS** structure can contain valid values even if the **dwBearerModes** member of the
**LINEDEVCAPS** structure is not set to LINEBEARERMODE_DATA.

If LINEBEARERMODE_DATA is not set in **dwBearerModes**, but the LINEBEARERMODE_VOICE value is set and the LINEMEDIAMODE_DATAMODEM value is set in the **dwMediaModes** member, the **dwMaxRate** member indicates the maximum SYNCHRONOUS (DCE) bit rate on the phone line for the attached modem or functional equivalent. For example, if the modem's fastest modulation speed is V.32bis at 14,400bps, **dwMaxRate** equals 14400. This is not the fastest DTE port rate (which would most likely be 38400, 57600, or 115200), but the fastest bit rate the modem supports on the phone line.

The application must be careful to check to see that LINEBEARERMODE_DATA is not set, to avoid misinterpreting the **dwMaxRate** member. It is likely to be 64000 or higher if LINEBEARERMODE_DATA is set.

It should also be noted that if the modem has not been specifically identified (for example, it is a "generic" modem), the figure indicated is a "best guess" based on examination of the modem.

The members **dwSettableDevStatus** through **dwDeviceClassesOffset** are available only to applications that open the line device with a TAPI version of 2.0 or later.

## See also

[LINECALLINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallinfo)

[LINEGENERATETONE](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linegeneratetone)

[LINEMONITORTONE](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linemonitortone)

[LINETERMCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linetermcaps)

[LINETRANSLATECAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linetranslatecaps)

[LINE_LINEDEVSTATE](https://learn.microsoft.com/windows/desktop/Tapi/line-linedevstate)

[TSPI_lineGetDevCaps](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linegetdevcaps)

[lineClose](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineclose)

[lineDial](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linedial)

[lineGatherDigits](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegatherdigits)

[lineGenerateTone](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegeneratetone)

[lineGetDevCaps](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetdevcaps)

[lineGetID](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetid)

[lineGetTranslateCaps](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegettranslatecaps)

[lineMakeCall](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linemakecall)

[lineMonitorTones](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linemonitortones)

[lineSendUserUserInfo](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesenduseruserinfo)

[lineSetMediaControl](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetmediacontrol)

[lineTranslateAddress](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linetranslateaddress)

[lineUncompleteCall](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineuncompletecall)