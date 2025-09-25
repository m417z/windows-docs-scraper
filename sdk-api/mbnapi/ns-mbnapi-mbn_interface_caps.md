# MBN_INTERFACE_CAPS structure

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

The **MBN_INTERFACE_CAPS** structure represents the interface capabilities. This structure is returned by the [GetInterfaceCapability](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbninterface-getinterfacecapability) method of [IMbnInterface](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbninterface).

## Members

### `cellularClass`

An [MBN_CELLULAR_CLASS](https://learn.microsoft.com/windows/desktop/api/mbnapi/ne-mbnapi-mbn_cellular_class) value that specifies the cellular technology used by the device.

### `voiceClass`

An [MBN_VOICE_CLASS](https://learn.microsoft.com/windows/desktop/api/mbnapi/ne-mbnapi-mbn_voice_class) value that specifies how voice calls are handled.

### `dataClass`

A bitwise OR combination of [MBN_DATA_CLASS](https://learn.microsoft.com/windows/desktop/api/mbnapi/ne-mbnapi-mbn_data_class) values that specifies which data services are supported. For GSM devices, only the GSM-based data services can be present, that is, only GPRS, EDGE, UMTS, LTE, and HSDPA are valid values for GSM devices.

For CDMA devices, only the CDMA-related data services will be present, that is, only 1xRTT, 1xEV-DO, and 1xEV-DO RevA are valid values for CDMA devices. 1xEV-DO RevB is reserved for future use.

This field has the bit value **MBN_DATA_CLASS_CUSTOM** set if the data class some other data class which is not defined in the enumeration is also supported by device. If **MBN_DATA_CLASS_CUSTOM** is set then information regarding custom data class is available in *customDataClass* field.

### `customDataClass`

Contains the name of the custom data class. If the **MBN_DATA_CLASS_CUSTOM** bit of **dataClass** is not set, then the string is **NULL**. Otherwise, the caller must free this string by calling [SysFreeString](https://learn.microsoft.com/windows/win32/api/oleauto/nf-oleauto-sysfreestring).

### `gsmBandClass`

A bit field that specifies the frequency bands supported by the GSM device. **MBN_BAND_CLASS_I** through **MBN_BAND_CLASS_X** and **MBN_BAND_CLASS_CUSTOM** are valid values. These values are defined by [MBN_BAND_CLASS](https://learn.microsoft.com/windows/desktop/api/mbnapi/ne-mbnapi-mbn_band_class). If **gsmBandClass** is set to **MBN_BAND_CLASS_CUSTOM**, additional information about the band class appears in **customBandClass**.

The following table provides additional information about the [MBN_BAND_CLASS](https://learn.microsoft.com/windows/desktop/api/mbnapi/ne-mbnapi-mbn_band_class) values.

| MBN_BAND_CLASS Value | Designated spectrum | Industry name | Uplink (MS to BTS) | Downlink (BTS to MS) | Regions |
| --- | --- | --- | --- | --- | --- |
| **MBN_BAND_CLASS_I** | UMTS2100 | IMT | 1920-1980 | 2110-2170 | Europe, Korea, Japan China |
| **MBN_BAND_CLASS_II** | UMT21900 | PCS1900 | 1850-1910 | 1930-1990 | North America, Latin America |
| **MBN_BAND_CLASS_III** | UMTS1800 | DCS1800 | 1710-1785 | 1805-1880 | Europe, China |
| **MBN_BAND_CLASS_IV** | AWS | AWS, 1.7/2.1 | 1710-1785 | 2110-2155 | North America, Latin America |
| **MBN_BAND_CLASS_V** | UMTS850 | GSM850 | 824-849 | 869-894 | North America, Latin America |
| **MBN_BAND_CLASS_VI** | UMTS800 | UMTS800 | 830-840 | 875-885 | Japan |
| **MBN_BAND_CLASS_VII** | UMTS2600 | UMTS2600 | 2500-2570 | 2620-2690 | Europe |
| **MBN_BAND_CLASS_VIII** | UMTS900 | EGSM900 | 880-915 | 925-960 | Europe, China |
| **MBN_BAND_CLASS_IX** | UMTS1700 | UMTS1700 | 1750-1770 | 1845-1880 | Japan |
| **MBN_BAND_CLASS_X** |  |  | 1710-1770 | 2110-2170 |  |

### `cdmaBandClass`

A bit field that specifies the frequency bands supported by the CDMA device. **MBN_BAND_CLASS_0** through **MBN_BAND_CLASS_XVII**, **MBN_BAND_CLASS_NONE**, and **MBN_BAND_CLASS_CUSTOM** are valid values. These values are defined by [MBN_BAND_CLASS](https://learn.microsoft.com/windows/desktop/api/mbnapi/ne-mbnapi-mbn_band_class). If **cdmaBandClass** is set to **MBN_BAND_CLASS_CUSTOM**, additional information about the band class appears in **customBandClass**.

The following table provides additional information about MBN_BAND_CLASS values.

| MBN_BAND_CLASS Value | Industry Name | Uplink (MS to BTS) | Downlink (BTS to MS) |
| --- | --- | --- | --- |
| **MBN_BAND_CLASS_0** | 800MHx Cellular | 824.025.844.995 | 869.025.889.995 |
| **MBN_BAND_CLASS_I** | 1900MHz Band | 1850-1910 | 1930-1990 |
| **MBN_BAND_CLASS_II** | TACS Band | 872.025.914.9875 | 917.0125.959.9875 |
| **MBN_BAND_CLASS_III** | JTACS Band | 887.0125.924.9875 | 832.0125.869.9875 |
| **MBN_BAND_CLASS_IV** | Korean PCS Band | 1750-1780 | 1840-1870 |
| **MBN_BAND_CLASS_V** | 450 MHz Band | 410-483.475 | 420-493.475 |
| **MBN_BAND_CLASS_VI** | 2 GHz Band | 1920-1979.950 | 2110-2169.950 |
| **MBN_BAND_CLASS_VII** | 700 MHz Band | 776-794 | 746-764 |
| **MBN_BAND_CLASS_VIII** | 1800 MHz Band | 1710-1784.950 | 1805-1879.95 |
| **MBN_BAND_CLASS_IX** | 900 MHz Band | 880-914-950 | 925-959.950 |
| **MBN_BAND_CLASS_X** | Secondary 800 MHz Band | 806-900.975 | 851-939.975 |
| **MBN_BAND_CLASS_XI** | 400 MHz European PAMR Band | 410-483.475 | 420-493.475 |
| **MBN_BAND_CLASS_XII** | 800 MHz PAMR Band | 870.125-875.9875 | 915.0125-920.9875 |
| **MBN_BAND_CLASS_XIII** | 2.5 GHz IMT200 Extension Band | 2500-2570 | 2620-2690 |
| **MBN_BAND_CLASS_XIV** | US PCS 1.9 GHz Band | 1850-1915 | 1930-1995 |
| **MBN_BAND_CLASS_XV** | AWS Band | 1710-1755 | 2110-2155 |
| **MBN_BAND_CLASS_XVI** | US 2.5 GHz Band | 2502-2568 | 2624-2690 |
| **MBN_BAND_CLASS_XVII** | US 2.5 GHz Forward Link Only Band |  | 2624-2690 |

### `customBandClass`

Contains the name of the custom band class. If the **MBN_BAND_CLASS_CUSTOM** bit of **cdmaBandClass** and **gsmBandClass** is not set, then the string is **NULL**. Otherwise, the caller must free this string by calling [SysFreeString](https://learn.microsoft.com/windows/win32/api/oleauto/nf-oleauto-sysfreestring).

### `smsCaps`

A bitwise OR combination of [MBN_SMS_CAPS](https://learn.microsoft.com/windows/desktop/api/mbnapi/ne-mbnapi-mbn_sms_caps) values that specifies the SMS capabilities.

### `controlCaps`

A bitwise OR combination of [MBN_CTRL_CAPS](https://learn.microsoft.com/windows/desktop/api/mbnapi/ne-mbnapi-mbn_ctrl_caps) values that represents the Mobile Broadband control capabilities for this interface.

### `deviceID`

Contains the device ID. For GSM devices, this must be the IMEI (up to 15 digits). For CDMA devices, this must be the ESN (11 digits) / MEID (17 digits). The maximum length of the string is **MBN_DEVICEID_LEN**. For the definition of **MBN_DEVICEID_LEN**, see [MBN_INTERFACE_CAPS_CONSTANTS](https://learn.microsoft.com/windows/desktop/api/mbnapi/ne-mbnapi-mbn_interface_caps_constants). The caller must free this string by calling [SysFreeString](https://learn.microsoft.com/windows/win32/api/oleauto/nf-oleauto-sysfreestring).

### `manufacturer`

Contains the name of the device manufacturer. This string can be empty. The maximum length of the string is **MBN_MANUFACTURER_LEN**. For the definition of **MBN_MANUFACTURER_LEN**, see [MBN_INTERFACE_CAPS_CONSTANTS](https://learn.microsoft.com/windows/desktop/api/mbnapi/ne-mbnapi-mbn_interface_caps_constants). The caller must free this string by calling [SysFreeString](https://learn.microsoft.com/windows/win32/api/oleauto/nf-oleauto-sysfreestring).

### `model`

Contains the device model. This string can be empty. The maximum length of this string is **MBN_MODEL_LEN**. For the definition of **MBN_MODEL_LEN**, see [MBN_INTERFACE_CAPS_CONSTANTS](https://learn.microsoft.com/windows/desktop/api/mbnapi/ne-mbnapi-mbn_interface_caps_constants). The caller must free this string by calling [SysFreeString](https://learn.microsoft.com/windows/win32/api/oleauto/nf-oleauto-sysfreestring).

### `firmwareInfo`

Contains the firmware-specific information for this device. This string can be empty. The maximum length of the string is **MBN_FIRMWARE_LEN**. For the definition of **MBN_FIRMWARE_LEN**, see [MBN_INTERFACE_CAPS_CONSTANTS](https://learn.microsoft.com/windows/desktop/api/mbnapi/ne-mbnapi-mbn_interface_caps_constants). The caller must free this string by calling [SysFreeString](http://msdn.microsoft.com/en-us/library/ms221481.aspx).