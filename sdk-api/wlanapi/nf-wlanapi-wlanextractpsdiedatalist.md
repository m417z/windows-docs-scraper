# WlanExtractPsdIEDataList function

## Description

The **WlanExtractPsdIEDataList** function extracts the proximity service discovery (PSD) information element (IE) data list from raw IE data included in a beacon.

## Parameters

### `hClientHandle` [in]

The client's session handle, obtained by a previous call to the [WlanOpenHandle](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanopenhandle) function.

### `dwIeDataSize` [in]

The size, in bytes, of the *pRawIeData* parameter.

### `pRawIeData` [in]

The raw IE data for all IEs in the list.

### `strFormat` [in]

Describes the format of a PSD IE. Only IEs with a matching format are returned.

### `pReserved`

Reserved for future use. Must be set to **NULL**.

### `ppPsdIEDataList` [out]

A pointer to a [PWLAN_RAW_DATA_LIST](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_raw_data_list) structure that contains the formatted data list.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value may be one of the following return codes.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | *hClientHandle* is **NULL** or invalid, *dwIeDataSize* is 0, *pRawIeData* is **NULL**, or *pReserved* is not **NULL**. |
| **ERROR_INVALID_HANDLE** | The handle *hClientHandle* was not found in the handle table. |
| **ERROR_NOT_SUPPORTED** | This function was called from an unsupported platform. This value will be returned if this function was called from a Windows XP with SP3 or Wireless LAN API for Windows XP with SP2 client. |
| **RPC_STATUS** | Various error codes. |

## Remarks

For more information about PSD IEs, including a discussion of the format of an IE, see [WlanSetPsdIEDataList](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetpsdiedatalist).

## See also

[WLAN_RAW_DATA_LIST](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_raw_data_list)

[WlanSetPsdIEDataList](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetpsdiedatalist)