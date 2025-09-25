# WLAN_RAW_DATA_LIST structure

## Description

The **WLAN_RAW_DATA_LIST** structure contains raw data in the form of an array of data blobs that are used by some Native Wifi functions.

## Members

### `dwTotalSize`

The total size, in bytes, of the **WLAN_RAW_DATA_LIST** structure.

### `dwNumberOfItems`

The number of raw data entries or blobs in the **WLAN_RAW_DATA_LIST** structure. The maximum value of the **dwNumberOfItems** may be restricted by the type of data that is stored in the **WLAN_RAW_DATA_LIST** structure.

### `dwDataOffset`

### `dwDataSize`

### `DataList`

An array of raw data entries or blobs that make up the data list.

#### dwDataOffset

The offset, in bytes, of the data blob from the beginning of current blob descriptor. For details, see the example in the Remarks section below.

#### dwDataSize

The size, in bytes, of the data blob.

## Remarks

The **WLAN_RAW_DATA_LIST** structure is used to encapsulate a list of data blobs into a flat memory block. It should be interpreted as a list of headers followed by data blobs.

To create a **WLAN_RAW_DATA_LIST**, an application needs to allocate a memory block that is large enough to hold the headers and the data blobs, and then cast the memory block to a pointer to a **WLAN_RAW_DATA_LIST** structure.

The following is the memory layout of an example **WLAN_RAW_DATA_LIST** structure that contains two data blobs.

|  |  |  |  |
| --- | --- | --- | --- |
| Memory Offset | Field | Value | Comments |
| 0 | dwTotalSize | 84 |  |
| 4 | dwNumberOfItems | 2 |  |
| 8 | dwDataOffset | 16 | Offset of the first blob: 16 = 24 - 8 |
| 12 | dwDataSize | 20 | Size of the first blob. |
| 16 | dwDataOffset | 28 | Offset of the second blob: 44 - 16. |
| 20 | dwDataSize | 24 | Size of the second blob. |
| 24 |  | 20 | Start of the first blob. |
| 44 |  | 40 | Start of the second blob. |

The **WLAN_RAW_DATA_LIST** structure is currently used by the [WlanSetPsdIEDataList](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetpsdiedatalist) function to set the proximity service discovery (PSD) information element (IE) data list for an application.

When used to store a PSD IE data list, the **DOT11_PSD_IE_MAX_ENTRY_NUMBER** constant defined in the *Wlanapi.h* header file is the maximum value of the **dwNumberOfItems** member for the number of blobs in the **WLAN_RAW_DATA_LIST** structure. The **DOT11_PSD_IE_MAX_DATA_SIZE** constant defined in the *Wlanapi.h* header file is the maximum value of the **dwDataSize** member for any blob.

| Constant | Value | Description |
| --- | --- | --- |
| **DOT11_PSD_IE_MAX_DATA_SIZE** | 240 | The maximum data size, in bytes, of a PSD IE data entry. |
| **DOT11_PSD_IE_MAX_ENTRY_NUMBER** | 5 | The maximum number of PSD IE data entries. |

For more information about PSD IEs, including a discussion of the format of an IE, see [WlanSetPsdIEDataList](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetpsdiedatalist).

## See also

[WLAN_RAW_DATA](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_raw_data)

[WlanExtractPsdIEDataList](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanextractpsdiedatalist)

[WlanScan](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanscan)

[WlanSetPsdIEDataList](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetpsdiedatalist)