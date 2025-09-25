# WLAN_RATE_SET structure

## Description

The set of supported data rates.

## Members

### `uRateSetLength`

The length, in bytes, of **usRateSet**.

### `usRateSet`

An array of supported data transfer rates. DOT11_RATE_SET_MAX_LENGTH is defined in windot11.h to have a value of 126.

Each supported data transfer rate is stored as a USHORT. The first bit of the USHORT specifies whether the rate is a basic rate. A *basic rate* is the data transfer rate that all stations in a basic service set (BSS) can use to receive frames from the wireless medium. If the rate is a basic rate, the first bit of the USHORT is set to 1.

To calculate the data transfer rate in Mbps for an arbitrary array entry rateSet[i], use the following equation:

`rate_in_mbps = (rateSet[i] & 0x7FFF) * 0.5`

## See also

[WLAN_BSS_ENTRY](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_bss_entry)