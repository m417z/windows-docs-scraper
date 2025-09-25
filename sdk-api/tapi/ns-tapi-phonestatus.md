# PHONESTATUS structure

## Description

The
**PHONESTATUS** structure describes the current status of a phone device. The
[phoneGetStatus](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonegetstatus) and
[TSPI_phoneGetStatus](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_phonegetstatus) functions return this structure.

## Members

### `dwTotalSize`

Total size allocated to this data structure, in bytes.

### `dwNeededSize`

Size for this data structure that is needed to hold all the returned information, in bytes.

### `dwUsedSize`

Size of the portion of this data structure that contains useful information, in bytes.

### `dwStatusFlags`

Status flags for this phone device. This member uses one of the
[PHONESTATUSFLAGS_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/phonestatusflags--constants).

### `dwNumOwners`

Number of application modules with owner privilege for the phone.

### `dwNumMonitors`

Number of application modules with monitor privilege for the phone.

### `dwRingMode`

Current ring mode of a phone device.

### `dwRingVolume`

Current ring volume of a phone device. This is a value between 0x00000000 (silence) and 0x0000FFFF (maximum volume).

### `dwHandsetHookSwitchMode`

Current hookswitch mode of the phone's handset. This member uses one of the
[PHONEHOOKSWITCHMODE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/phonehookswitchmode--constants).

### `dwHandsetVolume`

Current speaker volume of the phone's handset device. This is a value between 0x00000000 (silence) and 0x0000FFFF (maximum volume).

### `dwHandsetGain`

Current microphone gain of the phone's handset device. This is a value between 0x00000000 (silence) and 0x0000FFFF (maximum gain).

### `dwSpeakerHookSwitchMode`

Current hookswitch mode of the phone's speakerphone. This member uses one of the
[PHONEHOOKSWITCHMODE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/phonehookswitchmode--constants).

### `dwSpeakerVolume`

Current speaker volume of the phone's speaker device. This is a value between 0x00000000 (silence) and 0x0000FFFF (maximum volume).

### `dwSpeakerGain`

Current microphone gain of the phone's speaker device. This is a value between 0x00000000 (silence) and 0x0000FFFF (maximum gain).

### `dwHeadsetHookSwitchMode`

Current hookswitch mode of the phone's headset. This member uses one of the
[PHONEHOOKSWITCHMODE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/phonehookswitchmode--constants).

### `dwHeadsetVolume`

Current speaker volume of the phone's headset device. This is a value between 0x00000000 (silence) and 0x0000FFFF (maximum volume).

### `dwHeadsetGain`

Current microphone gain of the phone's headset device. This is a value between 0x00000000 (silence) and 0x0000FFFF (maximum gain).

### `dwDisplaySize`

Size of the display information, in bytes.

### `dwDisplayOffset`

Offset from the beginning of this structure to the variably sized field containing the phone's current display information. The size of the field is specified by **dwDisplaySize**.

### `dwLampModesSize`

Size of the current lamp modes array, in bytes.

### `dwLampModesOffset`

Offset from the beginning of this structure to the variably sized field containing the phone's current lamp modes. The size of the field is specified by **dwLampModesSize**.

### `dwOwnerNameSize`

Size of the name of the current owner, including the **null** terminator, in bytes.

### `dwOwnerNameOffset`

Offset from the beginning of the structure to the variably sized field containing the name of the application that is the current owner of the phone device. The name is the application name provided by the application when it invoked with
[phoneInitialize](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phoneinitialize) or
[phoneInitializeEx](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phoneinitializeexa). If no application name was supplied, the application's filename is used instead. The size of the field is specified by **dwOwnerNameSize**. If the phone currently has no owner, **dwOwnerNameSize** is zero.

### `dwDevSpecificSize`

Size of the device-specific field, in bytes. If the device-specific information is a pointer to a string, the size must include the **null** terminator.

### `dwDevSpecificOffset`

Offset from the beginning of this structure to the variably sized device-specific field. The size of the field is specified by **dwDevSpecificSize**.

### `dwPhoneFeatures`

Flags that indicate which Telephony API functions can be invoked on the phone, considering the availability of the feature in the device capabilities, the current device state, and device ownership of the invoking application. A zero indicates the corresponding feature cannot be invoked by the application on the phone in its current state; a one indicates the feature can be invoked. This member uses one or more of the
[PHONEFEATURE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/phonefeature--constants).

## Remarks

Device-specific extensions should use the DevSpecific (**dwDevSpecificSize** and **dwDevSpecificOffset**) variably sized area of this data structure.

The **dwPhoneFeatures** member is available only to applications that open the phone device with an API version of 2.0 or later.

## See also

[TSPI_phoneGetStatus](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_phonegetstatus)

[phoneGetStatus](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonegetstatus)

[phoneInitialize](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phoneinitialize)

[phoneInitializeEx](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phoneinitializeexa)