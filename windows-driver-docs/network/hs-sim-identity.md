# HS\_SIM\_IDENTITY structure

[!include[Wi-Fi Hotspot Offloading deprecation](https://learn.microsoft.com/windows-hardware/drivers/includes/wi-fi-hotspot-offloading-deprecation)]

The **HS\_SIM\_IDENTITY** structure contains SIM identification information required for EAP-SIM or EAP-AKA authentication.

## Members

**SimType**
The type of SIM, whether GSM or CDMA, or none. If the network is GSM, the **dwMNC** and **dwMCC** pair of fields will be defined, whereas for CDMA the **dwSID** and **dwNID** pair of fields must be defined.

**dwMNC**
Used if the SIM is GSM type.

The mobile network code (MNC) of the GSM network.

**dwMCC**
Used if the SIM is GSM type.

The mobile country code (MCC) of the GSM network.

**dwNID**
Used if the SIM is CDMA type.

The Network Identification Number (NID) of the CDMA network.

**dwSID**
Used if the SIM is CDMA type.

The System Identification Number (SID) of the CDMA network.

**dwEapMethods**
The EAP authentication method.

## Requirements

|  |  |
| --- | --- |
| Header | Hotspotoffloadplugin.h (include Hotspotoffloadplugin.h) |