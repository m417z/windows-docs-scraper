# HS\_SIM\_DATA structure

[!include[Wi-Fi Hotspot Offloading deprecation](https://learn.microsoft.com/windows-hardware/drivers/includes/wi-fi-hotspot-offloading-deprecation)]

The **HS\_SIM\_DATA** structure contains information stored in the SIM card.

## Members

**wszICCID**
The Integrated Circuit Card Identifier (ICCID) stored in the SIM card.

**wszIMEI**
The International Mobile Equipment Identity (IMEI) used to identify 3GPP phones.

**wszMEID\_ME**
The Mobile Equipment Identifier (MEID) defined by 3GPP2.

**wszSF\_EUIMID**
The Short Form Expanded User Identity Module Identifier (EUIMID) for a R-UIM or CSIM (CDMA SIM application) card.

## Requirements

|  |  |
| --- | --- |
| Header | Hotspotoffloadplugin.h (include Hotspotoffloadplugin.h) |

