# WLAN_RAW_DATA structure

## Description

The **WLAN_RAW_DATA** structure contains raw data in the form of a blob that is used by some Native Wifi functions.

## Members

### `dwDataSize`

The size, in bytes, of the **DataBlob** member. The maximum value of the **dwDataSize** may be restricted by type of data that is stored in the **WLAN_RAW_DATA** structure.

### `DataBlob.unique`

### `DataBlob.size_is`

### `DataBlob.size_is.dwDataSize`

### `DataBlob`

The data blob.

## Remarks

The **WLAN_RAW_DATA** structure is a raw data structure used to hold a data entry used by some Native Wifi functions. The data structure is in the form of a generalized blob that can contain any type of data.

The [WlanScan](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanscan) function uses the **WLAN_RAW_DATA** structure. The *pIeData* parameter passed to the **WlanScan** function points to a **WLAN_RAW_DATA** structure currently used to contain an information element to include in probe requests. This **WLAN_RAW_DATA** structure passed to the **WlanScan** function can contain a proximity service discovery (PSD) information element (IE) data entry.

When the **WLAN_RAW_DATA** structure is used to store a PSD IE, the **DOT11_PSD_IE_MAX_DATA_SIZE** constant defined in the *Wlanapi.h* header file is the maximum value of the **dwDataSize** member.

| Constant | Value | Description |
| --- | --- | --- |
| **DOT11_PSD_IE_MAX_DATA_SIZE** | 240 | The maximum data size, in bytes, of a PSD IE data entry. |

For more information about PSD IEs, including a discussion of the format of an IE, see the [WlanSetPsdIEDataList](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetpsdiedatalist) function.

## See also

[WLAN_RAW_DATA_LIST](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_raw_data_list)

[WlanScan](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanscan)

[WlanSetPsdIEDataList](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetpsdiedatalist)