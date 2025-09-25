# _WWAN_DEVICE_CAPS_EX structure

## Description

> [!IMPORTANT]
> ### Bias-free communication
>
> Microsoft supports a diverse and inclusive environment. This article contains references to terminology that the Microsoft [style guide for bias-free communication](https://learn.microsoft.com/style-guide/bias-free-communication) recognizes as exclusionary. The word or phrase is used in this article for consistency because it currently appears in the software. When the software is updated to remove the language, this article will be updated to be in alignment.

The **WWAN_DEVICE_CAPS_EX** structure represents the capabilities of the mobile broadband device. **WWAN_DEVICE_CAPS_EX** extends the existing [WWAN_DEVICE_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_device_caps) structure by adding an **Executor Index** member, for tracking specific executors, and a **WwanOptionalServiceCaps** member, for Microsoft service extensions.

## Members

### `WwanDeviceType`

The type of the device. Miniport drivers must set the device type to be a value other than
**WwanDeviceTypeUnknown**.

### `WwanCellularClass`

The cellular class of the device. Miniport drivers must set the cellular class to be a value other
than
**WwanCellularClassUnknown**. The values in this member control features that are specific to
cellular technology, such as network provider registration modes.

Miniport drivers that support multi-mode should set this to **WwanCellularClassGsm.**

### `WwanVoiceClass`

The voice class of the device. This member informs the MB Service about the presence of circuit
voice service, and how such service interacts with data service. Be aware that the MB Service does not
support circuit-switched voice natively, nor does it preclude it. It is up to the miniport driver to
determine how to support circuit voice. This
**WwanVoiceClass** member allows the MB Service to support this feature in the future.

### `WwanSimClass`

The class of the Subscriber Identity Module (SIM card) specified by the [**WWAN_SIM_CLASS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_sim_class) enum. Miniport drivers must set the SIM class to
be a value other than
**WwanSimClassUnknown**.

### `WwanDataClass`

A bitmap that represents the data-class(es) that the device supports. The following table shows
the possible values for this member.

| Value | Meaning |
| --- | --- |
| WWAN_DATA_CLASS_NONE | The device does not support data service. |
| WWAN_DATA_CLASS_GPRS | General Packet Radio Service (GPRS) data service is supported. This value applies only to GSM-based devices. |
| WWAN_DATA_CLASS_EDGE | Enhanced Data for Global Evolution (EDGE) data service is supported. This value applies only to GSM-based devices. |
| WWAN_DATA_CLASS_UMTS | Universal Mobile Telecommunications System (UMTS) data service is supported. This value applies only to GSM-based devices. |
| WWAN_DATA_CLASS_HSDPA | High-Speed Downlink Packet Access (HSDPA) data service is supported. This value applies only to GSM-based devices. |
| WWAN_DATA_CLASS_HSUPA | High-Speed Uplink Packet Access (HSUPA) data service is supported. This value applies only to GSM-based devices. |
| WWAN_DATA_CLASS_LTE | LTE data service is supported. This value applies only to GSM-based devices. |
| WWAN_DATA_CLASS_5G_NSA | Non-standalone 5G data service is supported. For more info about 5G data class support, see [MB 5G data class support](https://learn.microsoft.com/windows-hardware/drivers/network/mb-5g-data-class-support). |
| WWAN_DATA_CLASS_SA | Standalone 5G data service is supported. For more info about 5G data class support, see [MB 5G data class support](https://learn.microsoft.com/windows-hardware/drivers/network/mb-5g-data-class-support). |
| WWAN_DATA_CLASS_1XRTT | CDMA 1x Radio Transmission Technology (1xRTT, also known as cdma2000, CDMA2000 1x, and so on) data service is supported. This value applies only to CDMA-based devices. |
| WWAN_DATA_CLASS_1XEVDO | CDMA Evolution-Data Optimized (originally Data Only, 1xEDVO, also known as CDMA2000 1x EV-DO, or 1x EVDO) data service is supported. This value applies only to CDMA-based devices. |
| WWAN_DATA_CLASS_1XEVDO_REVA | 1xEVDO RevA data service is supported. This value applies only to CDMA-based devices. |
| WWAN_DATA_CLASS_1XEVDV | CDMA Evolution-Data/Voice (also known as CDMA 2000 1x EV-DV, or 1x EVDV) data service is supported. This value applies only to CDMA-based devices. |
| WWAN_DATA_CLASS_3XRTT | CDMA 3x Radio Transmission Technology (3xRTT) data service is supported. This value applies only to CDMA-based devices. |
| WWAN_DATA_CLASS_1XEVDO_REVB | 1xEVDO RevB data service is supported. This value applies only to CDMA-based devices. |
| WWAN_DATA_CLASS_UMB | UMB data service is supported. This value applies only to CDMA-based devices. |
| WWAN_DATA_CLASS_CUSTOM | The device supports a data service not listed in this table. |

### `CustomDataClass`

A NULL-terminated string that represents the name of the custom data-class. This member is valid
only when the miniport driver sets the WWAN_DATA_CLASS_CUSTOM bit in the
**WwanDataClass** member.

### `WwanGsmBandClass`

A bitmap that represents the frequency bands GSM-based devices support. The following table shows
the possible values for this member.

| Value | Meaning |
| --- | --- |
| WWAN_BAND_CLASS_UNKNOWN | The frequency band that is supported by the device is not given. |
| WWAN_BAND_CLASS_I | The device supports the UMTS2100 spectrum. |
| WWAN_BAND_CLASS_II | The device supports the UMTS1900 spectrum. |
| WWAN_BAND_CLASS_III | The device supports the UMTS1800 spectrum. |
| WWAN_BAND_CLASS_IV | The device supports the AWS spectrum. |
| WWAN_BAND_CLASS_V | The device supports the UMTS850 spectrum. |
| WWAN_BAND_CLASS_VI | The device supports the UMTS800 spectrum. |
| WWAN_BAND_CLASS_VII | The device supports the UMTS2600 spectrum. |
| WWAN_BAND_CLASS_VIII | The device supports the UMTS900 spectrum. |
| WWAN_BAND_CLASS_IX | The device supports the UMTS1700 spectrum. |
| WWAN_BAND_CLASS_X |  |
| WWAN_BAND_CLASS_CUSTOM | The device supports a spectrum other than those listed in this table. |

If the miniport driver specifies WWAN_BAND_CLASS_CUSTOM, it should also provide the name of the
data-class in
**CustomBandClass** .

For more information about these values, see
[OID_WWAN_DEVICE_CAPS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-device-caps).

### `WwanCdmaBandClass`

A bitmap that represents the frequency bands CDMA-based devices support. The following table shows
the possible values for this member.

| Value | Meaning |
| --- | --- |
| WWAN_BAND_CLASS_UNKNOWN | The frequency band that is supported by the device is not given. |
| WWAN_BAND_CLASS_0 | The device supports the 800MHz band. |
| WWAN_BAND_CLASS_I | The device supports the 1900MHz band. |
| WWAN_BAND_CLASS_II | The device supports the TACS band. |
| WWAN_BAND_CLASS_III | The device supports the JTACS band. |
| WWAN_BAND_CLASS_IV | The device supports the Korean PCS band. |
| WWAN_BAND_CLASS_V | The device supports the 450 MHz band. |
| WWAN_BAND_CLASS_VI | The device supports the 2 GHz band. |
| WWAN_BAND_CLASS_VII | The device supports the 700 MHz band. |
| WWAN_BAND_CLASS_VIII | The device supports the 1800 MHz band. |
| WWAN_BAND_CLASS_IX | The device supports the 900 MHz band. |
| WWAN_BAND_CLASS_X | The device supports the secondary 800 MHz band. |
| WWAN_BAND_CLASS_XI | The device supports the 400 MHz European PAMR band. |
| WWAN_BAND_CLASS_XII | The device supports the 800 MHz PAMR band. |
| WWAN_BAND_CLASS_XIII | The device supports the 2.5GHz IMT2000 Extension band. |
| WWAN_BAND_CLASS_XIV | The device supports the US PCS 1.9GHz band. |
| WWAN_BAND_CLASS_XV | The device supports the AWS band. |
| WWAN_BAND_CLASS_XVI | The device supports the US 2.5GHz band. |
| WWAN_BAND_CLASS_XVII | The device supports the US 2.5 GHz Forward Link Only band. |
| WWAN_BAND_CLASS_CUSTOM | The device supports a band other than the bands listed in this table. |

If the miniport driver specifies WWAN_BAND_CLASS_CUSTOM, it should also provide the name of the
data-class in
**CustomBandClass** .

For more information about these values, see
[OID_WWAN_DEVICE_CAPS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-device-caps).

### `CustomBandClass`

A NULL-terminated string that represents the name of the custom band class. This member is valid
only when the miniport driver sets the WWAN_BAND_CLASS_CUSTOM bit in either the
**WwanGsmBandClass** or
**WwanCdmaBandClass** members, as appropriate.

### `WwanSmsCaps`

A bitmap that represents the type of SMS messages and directional flow that the device supports.
The following table shows the valid SMS capabilities settings.

| Value | Meaning |
| --- | --- |
| WWAN_SMS_CAPS_NONE | The device does not support SMS messages. |
| WWAN_SMS_CAPS_PDU_SEND | For GSM-based devices, this value means that the device supports sending PDU-style SMS messages.<br><br>For CDMA-based devices, this value means that the device is capable of sending SMS messages in binary format as defined in section "3.4.2.1 SMS Point-to-Point Message" in 3GPP2 specification C.S0015-A "Short Message Service (SMS) for Wideband Spread Spectrum Systems". |
| WWAN_SMS_CAPS_PDU_RECEIVE | For GSM-based devices, this value means that the device supports receiving PDU-style SMS messages.<br><br>For CDMA-based devices, this value means that the device is capable of reading the SMS messages in binary format as defined in section "3.4.2.1 SMS Point-to-Point Message" in the 3GPP2 specification C.S0015-A "Short Message Service (SMS) for Wideband Spread Spectrum Systems". |
| WWAN_SMS_CAPS_TEXT_SEND | The device supports sending Text-style SMS messages. This flag applies for CDMA-based devices. |
| WWAN_SMS_CAPS_TEXT_RECEIVE | The device supports receiving Text-style SMS messages. This flag applies for CDMA-based devices. |

Miniport drivers should set this member to reflect support for only GSM PDU format for receiving and sending SMS when the current home provider is multi-mode capable. Therefore, if the miniport driver receives a SMS in the cellular class native format, for example CDMA TEXT or CDMA PDU, then the miniport driver is required to do the translation to GSM PDU and indicate it to the MB Service. Similarly if the miniport driver receives a send request in GSM PDU format then it is required to do the translation to its native cellular class format.

### `WwanControlCaps`

A bitmap that represents the control capabilities that the device supports. The following table
shows the valid WwanControlCaps settings for GSM-based and CDMA-based devices.

| Value | Meaning |
| --- | --- |
| WWAN_CTRL_CAPS_REG_MANUAL | Indicates whether the provider network allows manual network selection. Miniport drivers for GSM-based devices should specify this flag. Miniport drivers for CDMA-based devices should not specify this flag. |
| WWAN_CTRL_CAPS_HW_RADIO_SWITCH | Indicates the presence of a hardware radio power switch. This corresponds to the **WwanDeviceTypeEmbedded** value of the WWAN_DEVICE_TYPE enumeration. |
| WWAN_CTRL_CAPS_CDMA_MOBILE_IP | Indicates that the CDMA-based device is configured to support mobile IP. This flag applies only to CDMA-based devices.<br><br>Miniport drivers should not set this flag when the current home provider is multi-mode capable. |
| WWAN_CTRL_CAPS_CDMA_SIMPLE_IP | Indicates that the CDMA-based device is configured for simple IP support. This flag applies only to CDMA-based devices.<br><br>Miniport drivers should not set this flag when the current home provider is multi-mode capable. |
| WWAN_CTRL_CAPS_CDMA_MOBILE_IP ored with WWAN_CTRL_CAPS_CDMA_SIMPLE_IP | Indicates that the CDMA-based device is configured to support mobile IP, with simple IP as a fallback option. |
| WWAN_CTRL_CAPS_PROTECT_UNIQUEID | Indicates that Windows should not display the International Mobile Subscriber Identity (IMSI). |
| WWAN_CTRL_CAPS_USSD | Indicates that the GSM-based MB device is configured to support the USSD protocol. This flag applies only to GSM-based devices.<br><br>Miniport drivers that support sending and receiving USSD messages set this flag.<br><br>Miniport drivers can set this flag when the current multi-mode capable home providers GSM side of the network supports USSD even if the CDMA side of the network does not support USSD. |
| WWAN_CTRL_CAPS_MODEL_MULTI_CARRIER | Indicates that the MB device supports registering and connecting to multiple network operators. |
| WWAN_CTRL_CAPS_MULTI_MODE | This flag indicates that the current home provider supports multiple cellular classes/RATs (Radio Access Technologies). |

Miniport drivers of CDMA-based devices must specify WWAN_CTRL_CAPS_CDMA_MOBILE_IP, or
WWAN_CTRL_CAPS_CDMA_SIMPLE_IP, or both flags to inform the MB Service about the type of IP that the
device supports.

### `DeviceId`

A NULL-terminated string that represents the device ID.

For GSM-based devices, the string must
conform to the International Mobile Equipment Identity (IMEI) format (up to 15 digits).

For CDMA-based
devices, the string must conform to both the Electronic Serial Number (ESN, 11 digits) and Mobile
Equipment Identifier (MEID, 17 digits) formats.

For multi-mode capable miniport drivers, for example those that set the **WWAN_CTRL_CAPS_MULTI_MODE** flag in **WwanControlCaps**, only the GSM-based **DeviceId** must be reported.

This value should be stored in the device's memory and
must be available even when the MB device/SIM requires a PIN to unlock.

### `Manufacturer`

A NULL-terminated string that represents the manufacturer of the device. This member is
optional.

### `Model`

A NULL-terminated string that represents the model of the device. This member is optional.

### `FirmwareInfo`

A NULL-terminated string that represents the firmware specific information about the device. This
member is optional.

### `MaxActivatedContexts`

The maximum number of activated contexts that are supported by the device. Miniport drivers should
enforce this limit by failing any activation attempts that exceed
**MaxActivatedContexts**.

### `WwanAuthAlgoCaps`

A bitmap that represents the types of authentication methods the MB device supports.

| Value | Meaning |
| --- | --- |
| WWAN_AUTH_ALGO_CAPS_NONE | The MB device does not support any authentication methods. |
| WWAN_AUTH_ALGO_CAPS_SIM | The MB device supports the SIM authentication method. |
| WWAN_AUTH_ALGO_CAPS_AKA | The MB device supports the AKA authentication method. |
| WWAN_AUTH_ALGO_CAPS_AKAP | The MB device supports the AKA' (AKA Prime) authentication method. |

### `ExecutorIndex`

The **WwanDeviceType** member for **WWAN_DEVICE_CAPS_EX** no longer refers to the modem device but rather to an individual executor. Each device is an RF executor entity of which the OS is aware.

### `WwanOptionalServiceCaps`

A ULONG structure that represents the Microsoft service extensions the underlying modem supports. It is a 64-bit bitmap structure that whose undefined bits are reserved and must be set to "0." As new service extensions are introduced, the reserved bits will be used to represent the new service extensions.

| Value | Mask | Meaning |
| --- | --- | --- |
| WWAN_OPTIONAL_SERVICE_CAPS_NONE | 0h | The device and driver do not support optional service extensions. |
| WWAN_OPTIONAL_SERVICE_CAPS_LTE_ATTACH | 1h | The device and driver support LTE attach configuration and the following MBIM CIDs:<br><br>* MBIM_CID_MS_LTE_ATTACH_CONFIG<br>* MBIM_CID_MS_LTE_ATTACH_STATUS |
| WWAN_OPTIONAL_SERVICE_CAPS_CONTEXT_MGMT | 2h | The device and driver support the OS managing modem provisioned contexts and the following MBIM CID:<br><br>* MBIM_CID_PROVISIONED_CONTEXT_V2 |
| WWAN_OPTIONAL_SERVICE_CAPS_MULTI_SIM | 4h | The device and driver support multi-SIM/multi-executors and the following OIDs:<br><br>* [OID_WWAN_SYS_CAPS_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-sys-caps)<br>* [OID_WWAN_DEVICE_SLOT_MAPPING_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-device-slot-mappings)<br>* [OID_WWAN_SLOT_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-slot-info-status) |
| WWAN_OPTIONAL_SERVICE_CAPS_EX_SAR | 8h | The device and driver support SAR configuration from the OS and the following MBIM CIDs:<br><br>* MBIM_CID_MS_SAR_CONFIG<br>* MBIM_CID_MS_TRANSMISSION_STATUS |
| WWAN_OPTIONAL_SERVICE_CAPS_NETWORK_BLACKLIST | 16h | The device and driver support configuration of network blocked senders list from the OS and the following MBIM CID:<br><br>* MBIM_CID_MS_NETWORK_BLACKLIST |
| WWAN_OPTIONAL_SERVICE_CAPS_5G_NSA | The device and driver support all new 5G-related extensions in Windows 10, version 1903. The following table shows the NDIS messages and their revisions that the miniport driver must support if this bit is set.<br><br>OID | Message | Revision || WWAN_DEVICE_CAPS_EX | NDIS_WWAN_DEVICE_CAPS_EX | 1 | | WWAN_REGISTER_STATE | NDIS_WWAN_REGISTRATION_STATE | 3 | | WWAN_PACKET_SERVICE | NDIS_WWAN_PACKET_SERVICE_STATE | 2 | | WWAN_SIGNAL_STATE | NDIS_WWAN_SIGNAL_STATE | 2 | | |

### `CellularClassListHeader`

A formatted WWAN_LIST_HEADER object that represents a list of cellular classes that a multi-mode capable device supports. The **ElementType** member in WWAN_LIST_HEADER should always be set to **WwanStructCellularClass**. The **ElementCount** member in WWAN_LIST_HEADER is set to the number of cellular classes that follow the WWAN_LIST_HEADER structure. MB devices that are not multi-mode capable should set **ElementCount** to 0.

### `WwanSimClassBitMasks`

A bitmap that represents SIM class masks. It must at least contain the mask corresponding to the **WwanSimClass** field.

|Value|
|--- |
|WWAN_SIM_CLASS_MASK_UNKNOWN 0x00000000|
|WWAN_SIM_CLASS_MASK_EMBEDDED 0x00000001|
|WWAN_SIM_CLASS_MASK_REMOVABLE 0x00000002|
|WWAN_SIM_CLASS_MASK_REMOTE 0x00000004|

### `WwanWCDMABandClass`

The band number defined in 3GPP TS25.101 for FDD. The LSB indicates band number 1 (2100MHz).

### `WwanLTEBandClass`

### `WwanNRBandClass`

### `WwanDataSubClass`

A bitmap that represents the data subclass(es) that the device supports.

|Value|Meaning|
|--- |--- |
|WWAN_DATA_SUBCLASS_NONE|There are no subclasses under the accompanying data class.|
|WWAN_DATA_SUBCLASS_5G_ENDC|Evolved Universal Mobile Telecommunications System (UMTS) Terrestrial Radio Access (E-UTRAN) and NR dual connectivity as in 5G Option 3 are supported. Only valid under the WWAN_DATA_CLASS_5G data class.|
|WWAN_DATA_SUBCLASS_5G_NR|Standalone NR as in 5G Option 2 is supported. Only valid under the WWAN_DATA_CLASS_5G data class.|
|WWAN_DATA_SUBCLASS_5G_NEDC|NR and EUTRAN dual connectivity as in 5G Option 4 are supported. Only valid under the WWAN_DATA_CLASS_5G data class.|
|WWAN_DATA_SUBCLASS_5G_ELTE|Standalone eLTE as in 5G option 5 is supported. Only valid under the WWAN_DATA_CLASS_5G data class.|
|WWAN_DATA_SUBCLASS_5G_NGENDC|Next-gen eLTE and NR dual connectivity as in 5G option 7 are supported. Only valid under the WWAN_DATA_CLASS_5G data class.|

### `WwanMiscCaps`

A bitmap that represents miscellaneous capabilities that the device supports.
|Value|
|--- |
|WWAN_DEVICE_MISC_CAPS_NONE 0x00000000|
|WWAN_DEVICE_MISC_CAPS_ETHERNET_PDU_SESSION 0x00000001|
|WWAN_DEVICE_MISC_CAPS_UNSTRUCTURED_PDU_SESSION 0x00000002|
|WWAN_DEVICE_MISC_CAPS_ESIM 0x00000004|
|WWAN_DEVICE_MISC_CAPS_REFLECTIVE_QOS 0x00000008|

## Remarks

Miniport drivers should specify WWAN_DATA_CLASS_CUSTOM if the data service supported by the device
does not belong to any of the other values defined in the table for the
**WwanDataClass** member. If a miniport driver sets the WWAN_DATA_CLASS_CUSTOM flag, the miniport
driver should also provide the name of the data-class in the
**CustomDataClass** member.

For GSM-based devices, only GSM-based data-classes must be specified. For example, GPRS, EDGE, UMTS,
HSDPA, LTE, and TD-SCDMA. If your miniport driver supports TD-SCDMA, then it should specify
WWAN_DATA_CLASS_CUSTOM in the
**WwanDataClass** member and the string "TD-SCDMA" in the
**CustomDataClass** member.

For CDMA-based devices, only CDMA-related data services must be specified. For example, 1xRTT,
1xEV-DO, 1xEV-DO RevA, and UMB. 1xEV-DO RevB is defined for future use. 1xEV-DV and 3xRTT are also
defined for completeness.

## See also

[NDIS_WWAN_DEVICE_CAPS_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_device_caps_ex)

[OID_WWAN_DEVICE_CAPS_EX](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-device-caps-ex)

[WWAN_DEVICE_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_device_caps)