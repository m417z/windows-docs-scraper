# PHONECAPS structure

## Description

The
**PHONECAPS** structure describes the capabilities of a phone device. The
[phoneGetDevCaps](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonegetdevcaps) and
[TSPI_phoneGetDevCaps](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_phonegetdevcaps) functions return this structure.

## Members

### `dwTotalSize`

Total size allocated to this data structure, in bytes.

### `dwNeededSize`

Size for this data structure that is needed to hold all the returned information, in bytes.

### `dwUsedSize`

Size of the portion of this data structure that contains useful information, in bytes.

### `dwProviderInfoSize`

Size of the provider-specific information, in bytes. If the provider-specific information is a pointer to a string, the size must include the **null** terminator.

### `dwProviderInfoOffset`

Offset from the beginning of the structure to the variably sized field containing service provider-specific information.

This member provides information about the provider hardware and/or software, such as the vendor name and version numbers of hardware and software. This information can be useful when a user needs to call customer service with problems regarding the provider. The size of the field is specified by **dwProviderInfoSize**.

### `dwPhoneInfoSize`

Size of the phone-specific information, in bytes. If the phone-specific information is a pointer to a string, the size must include the **null** terminator.

### `dwPhoneInfoOffset`

Offset from the beginning of the structure to the variably sized device field containing phone-specific information.

This member provides information about the attached phone device, such as the phone device manufacturer, the model name, the software version, and so on. This information can be useful when a user needs to call customer service with problems regarding the phone. The size of the field is specified by **dwPhoneInfoSize**.

### `dwPermanentPhoneID`

Permanent identifier by which the phone device is known in the system's configuration.

### `dwPhoneNameSize`

Size of the configurable name for the phone, including the **null** terminator, in bytes.

### `dwPhoneNameOffset`

Offset from the beginning of the structure to the variably sized device field containing a user configurable name for this phone device. This name can be configured by the user when configuring the phone device's service provider and is provided for the user's convenience. The size of the field is specified by **dwPhoneNameSize**.

### `dwStringFormat`

String format to be used with this phone device. This member uses one of the
[STRINGFORMAT_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/stringformat--constants).

### `dwPhoneStates`

State changes for this phone device for which the application can be notified in a
[PHONE_STATE](https://learn.microsoft.com/windows/desktop/Tapi/phone-state) message. This member one or more of the
[PHONESTATE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/phonestate--constants).

### `dwHookSwitchDevs`

Phone's hookswitch devices. This member uses one of the
[PHONEHOOKSWITCHDEV_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/phonehookswitchdev--constants).

### `dwHandsetHookSwitchModes`

Hookswitch mode of the handset. The member is only meaningful if the hookswitch device is listed in **dwHookSwitchDevs**. It uses one of the
[PHONEHOOKSWITCHMODE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/phonehookswitchmode--constants).

### `dwSpeakerHookSwitchModes`

Hookswitch mode of the speaker. The member is only meaningful if the hookswitch device is listed in **dwHookSwitchDevs**. It uses one of the PHONEHOOKSWITCHMODE_ Constants.

### `dwHeadsetHookSwitchModes`

Hookswitch mode of the headset. The member is only meaningful if the hookswitch device is listed in **dwHookSwitchDevs**. It uses one of the
[PHONEHOOKSWITCHMODE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/phonehookswitchmode--constants).

### `dwVolumeFlags`

Volume-setting capabilities of the phone device's speaker components. If the bit in position PHONEHOOKSWITCHDEV_ is **TRUE**, the volume of the corresponding hookswitch device's speaker component can be adjusted with
[phoneSetVolume](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonesetvolume).

### `dwGainFlags`

Gain-setting capabilities of the phone device's microphone components. If the bit position PHONEHOOKSWITCHDEV_ is **TRUE**, the volume of the corresponding hookswitch device's microphone component can be adjusted with
[phoneSetGain](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonesetgain).

### `dwDisplayNumRows`

Display capabilities of the phone device by describing the number of rows in the phone display. The **dwDisplayNumRows** and **dwDisplayNumColumns** members are both zero for a phone device without a display.

### `dwDisplayNumColumns`

Display capabilities of the phone device by describing the number of columns in the phone display. The **dwDisplayNumRows** and **dwDisplayNumColumns** members are both zero for a phone device without a display.

### `dwNumRingModes`

Ring capabilities of the phone device. The phone is able to ring with **dwNumRingModes** different ring patterns, identified as 1, 2, through **dwNumRingModes** minus one. If the value of this member is 0, applications have no control over the ring mode of the phone. If the value of this member is greater than 0, it indicates the number of ring modes in addition to silence that are supported by the service provider. A value of 0 in the *lpdwRingMode* parameter of
[phoneGetRing](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonegetring) or the *dwRingMode* parameter of
[phoneSetRing](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonesetring) indicates silence (the phone is not ringing or should not be rung), and *dwRingMode* values of 1 to **dwNumRingModes** are valid ring modes for the phone device.

### `dwNumButtonLamps`

Number of button/lamps on the phone device that are detectable in TAPI. Button/lamps are identified by their identifier. Valid button/lamp identifiers range from zero to **dwNumButtonLamps** minus one. The keypad buttons '0', through '9', '*', and '#' are assigned the identifiers 0 through 12.

### `dwButtonModesSize`

Size of the button modes array, in bytes.

### `dwButtonModesOffset`

Offset from the beginning of this structure to the variably sized field containing the button modes of the phone's buttons. The array is indexed by button/lamp identifier. This array uses the
[PHONEBUTTONMODE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/phonebuttonmode--constants). The size of the array is specified by **dwButtonModesSize**.

### `dwButtonFunctionsSize`

Size of the button functions field, in bytes.

### `dwButtonFunctionsOffset`

Offset from the beginning of this structure to the variably sized field containing the button functions of the phone's buttons. The array is indexed by button/lamp identifier. This array uses the
[PHONEBUTTONFUNCTION_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/phonebuttonfunction--constants). The size of the array is specified by **dwButtonFunctionsSize**.

### `dwLampModesSize`

Size of the lamp modes array, in bytes.

### `dwLampModesOffset`

Offset from the beginning of this structure to the variably sized field containing the lamp modes of the phone's lamps. The array is indexed by button/lamp identifier. This array uses the
[PHONELAMPMODE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/phonelampmode--constants). The size of the array is specified by **dwLampModesSize**.

### `dwNumSetData`

Number of different download areas in the phone device. The different areas are referred to using the data IDs 0, 1, , **dwNumSetData** minus one. If this member is zero, the phone does not support the download capability.

### `dwSetDataSize`

Size of the data size array, in bytes.

### `dwSetDataOffset`

Offset from the beginning of this structure to the variably sized field containing the sizes (in bytes) of the phone's download data areas. This is an array with **DWORD**-sized elements indexed by data identifier. The size of the array is specified by **dwSetDataSize**.

### `dwNumGetData`

Number of different upload areas in the phone device. The different areas are referred to using the data IDs 0, 1, , **dwNumGetData** minus one. If this field is zero, the phone does not support the upload capability.

### `dwGetDataSize`

Size of the data size array, in bytes.

### `dwGetDataOffset`

Offset from the beginning of this structure to the variably sized field containing the sizes (in bytes) of the phone's upload data areas. This is an array with **DWORD**-sized elements indexed by data identifier. The size of the array is specified by **dwGetDataSize**.

### `dwDevSpecificSize`

Size of the device-specific field, in bytes. If the device specific information is a pointer to a string, the size must include the **null** terminator.

### `dwDevSpecificOffset`

Offset from the beginning of this structure to the variably sized device-specific field. The size of the field is specified by **dwDevSpecificSize**.

### `dwDeviceClassesSize`

Size of the supported device class identifiers, in bytes.

### `dwDeviceClassesOffset`

Offset from the beginning of this structure to a string consisting of the device class identifiers supported on this device for use with
[phoneGetID](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonegetid). The identifiers are separated by **NULL**s, and the last identifier in the list is followed by two **NULL**s. The size of the field is specified by **dwDeviceClassesSize**.

### `dwPhoneFeatures`

Flags that indicate which Telephony API functions can be invoked on the phone. A zero indicates the corresponding feature is not implemented and can never be invoked by the application on the phone; a one indicates the feature may be invoked depending on the device state and other factors. This member uses
[PHONEFEATURE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/phonefeature--constants).

### `dwSettableHandsetHookSwitchModes`

[PHONEHOOKSWITCHMODE_](https://learn.microsoft.com/windows/desktop/Tapi/phonehookswitchmode--constants) values that can be set on the handset using
[phoneSetHookSwitch](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonesethookswitch).

### `dwSettableSpeakerHookSwitchModes`

PHONEHOOKSWITCHMODE_ values that can be set on the speakerphone using
[phoneSetHookSwitch](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonesethookswitch).

### `dwSettableHeadsetHookSwitchModes`

PHONEHOOKSWITCHMODE_ values that can be set on the headset using
[phoneSetHookSwitch](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonesethookswitch).

### `dwMonitoredHandsetHookSwitchModes`

PHONEHOOKSWITCHMODE_ values that can be detected and reported for the handset in a
[PHONE_STATE](https://learn.microsoft.com/windows/desktop/Tapi/phone-state) message and by
[phoneGetHookSwitch](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonegethookswitch).

### `dwMonitoredSpeakerHookSwitchModes`

PHONEHOOKSWITCHMODE_ values that can be detected and reported for the speakerphone in a PHONE_STATE message and by
[phoneSetHookSwitch](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonesethookswitch).

### `dwMonitoredHeadsetHookSwitchModes`

[PHONEHOOKSWITCHMODE_](https://learn.microsoft.com/windows/desktop/Tapi/phonehookswitchmode--constants) values that can be detected and reported for the headset in a PHONE_STATE message and by
[phoneSetHookSwitch](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonesethookswitch).

### `PermanentPhoneGuid`

The GUID permanently associated with this phone.

## Remarks

Device-specific extensions should use the DevSpecific (**dwDevSpecificSize** and **dwDevSpecificOffset**) variably sized area of this data structure.

The members **dwDeviceClassesSize** through **dwMonitoredHeadsetHookSwitchModes** are available only to applications that open the phone device with an API version of 2.0 or later.

## See also

[PHONE_BUTTON](https://learn.microsoft.com/windows/desktop/Tapi/phone-button)

[PHONE_CLOSE](https://learn.microsoft.com/windows/desktop/Tapi/phone-close)

[PHONE_STATE](https://learn.microsoft.com/windows/desktop/Tapi/phone-state)

[TSPI_phoneGetDevCaps](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_phonegetdevcaps)

[phoneGetDevCaps](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonegetdevcaps)

[phoneGetHookSwitch](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonegethookswitch)

[phoneGetRing](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonegetring)

[phoneSetGain](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonesetgain)

[phoneSetHookSwitch](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonesethookswitch)

[phoneSetRing](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonesetring)

[phoneSetVolume](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonesetvolume)