# LINECALLPARAMS structure

## Description

The
**LINECALLPARAMS** structure describes parameters supplied when making calls using the
[lineMakeCall](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linemakecall) and
[TSPI_lineMakeCall](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linemakecall) functions. The
**LINECALLPARAMS** structure is also used as a parameter in other operations, such as the
[lineOpen](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineopen) function.

The comments to the right of the syntax block indicate the default values used when this structure is not provided to
[lineMakeCall](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linemakecall).

## Members

### `dwTotalSize`

Total size allocated to this data structure, in bytes. This size should be big enough to hold all the fixed and variably sized portions of this data structure.

### `dwBearerMode`

Bearer mode for the call. This member uses one of the
[LINEBEARERMODE_ constants](https://learn.microsoft.com/windows/desktop/Tapi/linebearermode--constants).

If **dwBearerMode** is zero, the default value is LINEBEARERMODE_VOICE.

### `dwMinRate`

Minimum data rate requested for the call's data stream, in bps (bits per second).

### `dwMaxRate`

Maximum data rate requested for the call's data stream, in bps (bits per second). When making a call, the service provider attempts to provide the highest available rate in the requested range (**dwMinRate** to **dwMaxRate**). If a specific data rate is required, both **dwMinRate** and **dwMaxRate** should be set to that value. If an application works best with one rate but is able to degrade to lower rates, the application should specify these as the maximum and minimum rates, respectively. If **dwMaxRate** is zero, the default value is as specified by the **dwMaxRate** member of the
[LINEDEVCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevcaps) structure. This is the maximum rate supported by the device.

### `dwMediaMode`

Expected media type of the call. This member uses one of the
[LINEMEDIAMODE_ constants](https://learn.microsoft.com/windows/desktop/Tapi/linemediamode--constants).

If **dwMediaMode** is zero, the default value is LINEMEDIAMODE_INTERACTIVEVOICE.

### `dwCallParamFlags`

Collection of Boolean call-setup parameters. This member uses one or more of the
[LINECALLPARAMFLAGS_ constants](https://learn.microsoft.com/windows/desktop/Tapi/linecallparamflags--constants).

### `dwAddressMode`

Mode by which the originating address is specified. This member uses one of the
[LINEADDRESSMODE_ constants](https://learn.microsoft.com/windows/desktop/Tapi/lineaddressmode--constants).

**Note** The **dwAddressMode** member cannot be LINEADDRESSMODE_ADDRESSID for the
[lineOpen](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineopen) function call. However, this restriction does not apply to [lineMakeCall](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linemakecall).

### `dwAddressID`

Address identifier of the originating address if **dwAddressMode** is set to LINEADDRESSMODE_ADDRESSID. An address identifier is permanently associated with an address; the identifier remains constant across operating system upgrades.

### `DialParams`

Dial parameters to be used on this call, of type
[LINEDIALPARAMS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedialparams). When a value of 0 is specified for this field, the default value for the field is used as indicated in the **DefaultDialParams** member of the
[LINEDEVCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevcaps) structure. If a nonzero value is specified for a field that is outside the range specified by the corresponding fields in **MinDialParams** and **MaxDialParams** in the
**LINEDEVCAPS** structure, the nearest value within the valid range is used instead.

### `dwOrigAddressSize`

Size of the originating address field, in bytes.

### `dwOrigAddressOffset`

Offset from the beginning of the structure to the variably sized field holding the originating address. The format of this address is dependent on the **dwAddressMode** member. The size of the field is specified by **dwOrigAddressSize**.

### `dwDisplayableAddressSize`

Size of the displayable string including the **null** terminator, in bytes.

### `dwDisplayableAddressOffset`

Displayable string used for logging purposes. The content of these members is recorded in the **dwDisplayableAddressOffset** and **dwDisplayableAddressSize** members of the call's LINECALLINFO message. The
[lineTranslateAddress](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linetranslateaddress) function returns appropriate information to be placed in this field in the **dwDisplayableAddressSize** and **dwDisplayableAddressOffset** members of the
[LINETRANSLATEOUTPUT](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linetranslateoutput) structure. The size of the field is specified by **dwDisplayableAddressSize**.

### `dwCalledPartySize`

Size of the called-party information, in bytes.

### `dwCalledPartyOffset`

Offset from the beginning of the structure to the variably sized field holding called-party information. This information can be specified by the application that makes the call and is made available in the call's information structure for logging purposes. The format of this field is that of **dwStringFormat**, as specified in
[LINEDEVCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevcaps). The size of the field is specified by **dwCalledPartySize**.

### `dwCommentSize`

Size of the call comment field, in bytes.

### `dwCommentOffset`

Offset from the beginning of the structure to the variably sized field holding comments about the call. This information can be specified by the application that makes the call and is made available in the call's information structure for logging purposes. The format of this field is that of **dwStringFormat**, as specified in
[LINEDEVCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevcaps). The size of the field is specified by **dwCommentSize**.

### `dwUserUserInfoSize`

Size of the user-user information including the **null** terminator, in bytes.

### `dwUserUserInfoOffset`

Offset from the beginning of the structure to the variably sized field holding user-user information. The protocol discriminator field for the user-user information, if required, should appear as the first byte of the data pointed to by **dwUserUserInfoOffset**, and must be accounted for in **dwUserUserInfoSize**.

### `dwHighLevelCompSize`

Size of the high-level compatibility information, in bytes.

### `dwHighLevelCompOffset`

Offset from the beginning of the structure to the variably sized field holding high-level compatibility information. The size of the field is specified by **dwHighLevelCompSize**.

### `dwLowLevelCompSize`

Size of the low-level compatibility information, in bytes.

### `dwLowLevelCompOffset`

Offset from the beginning of the structure to the variably sized field holding low-level compatibility information. The size of the field is specified by **dwLowLevelCompSize**.

### `dwDevSpecificSize`

Size of the device-specific information, in bytes.

### `dwDevSpecificOffset`

Offset from the beginning of the structure to the variably sized field holding device-specific information. The size of the field is specified by **dwDevSpecificSize**.

### `dwPredictiveAutoTransferStates`

[LINECALLSTATE_ constants](https://learn.microsoft.com/windows/desktop/Tapi/linecallstate--constants), entry into which causes the call to be blind-transferred to the specified target address. Set to zero if automatic transfer is not desired.

### `dwTargetAddressSize`

Size of the target dialable address string including the **null** terminator, in bytes.

### `dwTargetAddressOffset`

Offset from the beginning of the structure to a string specifying the target dialable address (not **dwAddressID**); used in the case of certain automatic actions. In the case of predictive dialing, specifies the address to which the call should be automatically transferred. The size of the string is specified by **dwTargetAddressSize**.

This is essentially the same string that would be passed to
[lineBlindTransfer](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineblindtransfer) if automatic transfer were not being used. Set to zero if automatic transfer is not desired. In the case of a No Hold Conference, specifies the address that should be conferenced to the call. In the case of a One Step Transfer, specifies the address to dial on the consultation call.

### `dwSendingFlowspecSize`

Size of the quality of service information, in bytes.

### `dwSendingFlowspecOffset`

Offset from the beginning of the structure to a
[FLOWSPEC](https://learn.microsoft.com/windows/desktop/api/qos/ns-qos-flowspec) structure followed by WinSock provider-specific data, equivalent to what would have been stored in **SendingFlowspec** in a
[QOS](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-qos) structure. Specifies the quality of service desired in the sending direction on the call. The provider-specific portion following the **FLOWSPEC** structure must not contain pointers to other blocks of memory, because TAPI does not know how to marshal the data pointed to by the private pointer(s) and convey it through interprocess communication to the application. The size of the field is specified by **dwSendingFlowspecSize**.

### `dwReceivingFlowspecSize`

Size of the quality of service information, in bytes.

### `dwReceivingFlowspecOffset`

Offset from the beginning of the structure to a [FLOWSPEC](https://learn.microsoft.com/windows/desktop/api/qos/ns-qos-flowspec) structure followed by WinSock provider-specific data, equivalent to what would have been stored in **ReceivingFlowspec** in a [QOS](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-qos) structure. Specifies the quality of service desired in the receiving direction on the call. The provider-specific portion following the **FLOWSPEC** structure must not contain pointers to other blocks of memory, because TAPI does not know how to marshal the data pointed to by the private pointer(s) and convey it through interprocess communication to the application. The size of the field is specified by **dwReceivingFlowspecSize**.

### `dwDeviceClassSize`

Size of the device class string including the **null** terminator, in bytes.

### `dwDeviceClassOffset`

Offset from the beginning of the structure to a **null**-terminated string that indicates the device class of the device whose configuration is specified in *DeviceConfig*. Valid device class strings are the same as those specified for the
[lineGetID](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetid) function. The size of the string is specified by **dwDeviceClassSize**.

### `dwDeviceConfigSize`

Size of the device configuration data, in bytes.

### `dwDeviceConfigOffset`

Offset from the beginning of the structure to the opaque configuration data structure. This value is returned in the **dwStringSize** member in the
[VARSTRING](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-varstring) structure returned by
[lineGetDevConfig](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetdevconfig). If the size is zero, the default device configuration is used. This allows the application to set the device configuration before the call is initiated. The size of the field is specified by **dwDeviceConfigSize**.

### `dwCallDataSize`

Size of the application-settable call data, in bytes.

### `dwCallDataOffset`

Offset from the beginning of the structure to the application-settable call data to be initially attached to the call. The size of the field is specified by **dwCallDataSize**.

### `dwNoAnswerTimeout`

Number of seconds, after the completion of dialing, that the call should be allowed to wait in the PROCEEDING or RINGBACK states, before it is automatically abandoned by the service provider with a LINECALLSTATE_DISCONNECTED and LINEDISCONNECTMODE_NOANSWER. A value of 0 indicates that the application does not desire automatic call abandonment.

### `dwCallingPartyIDSize`

Size of the calling-party ID string including the **null** terminator, in bytes, including the **null**-terminating character.

### `dwCallingPartyIDOffset`

Offset from the beginning of the structure to a **null**-terminated string that specifies the identity of the party placing the call. If the content of the identifier is acceptable and a path is available, the service provider passes the identifier along to the called party to indicate the identity of the calling party. The size of the field is specified by **dwCallingPartyIDSize**.

### `dwAddressType`

[Address type](https://learn.microsoft.com/windows/desktop/Tapi/lineaddresstype--constants) used for the call. This member of the structure is available only if the negotiated TAPI version is 3.0 or higher.

## Remarks

Device-specific extensions should use the DevSpecific (**dwDevSpecificSize** and **dwDevSpecificOffset**) variably sized area of this data structure.

This structure is used as a parameter to
[lineMakeCall](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linemakecall) when setting up a call. Its fields allow the application to specify the quality of service requested from the network as well as a variety of ISDN call-setup parameters. If no
**LINECALLPARAMS** structure is supplied to
[lineMakeCall](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linemakecall), a default POTS voice-grade call is requested with the default values listed above.

**Note** The fields **DialParams** through **dwDevSpecificOffset** are ignored when an *lpCallParams* parameter is specified with the
[lineOpen](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineopen) function.

The members **dwPredictiveAutoTransferStates** through **dwCallingPartyIDOffset** are available only to applications that open the line device with an API version of 2.0 or later.

## See also

[LINEDEVCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevcaps)

[LINEDIALPARAMS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedialparams)

[LINETRANSLATEOUTPUT](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linetranslateoutput)

[TSPI_lineMakeCall](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linemakecall)

[VARSTRING](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-varstring)

[lineBlindTransfer](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineblindtransfer)

[lineGetDevConfig](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetdevconfig)

[lineGetID](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetid)

[lineMakeCall](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linemakecall)

[lineOpen](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineopen)

[lineTranslateAddress](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linetranslateaddress)