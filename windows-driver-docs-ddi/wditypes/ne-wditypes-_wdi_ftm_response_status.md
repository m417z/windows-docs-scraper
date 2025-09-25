# WDI_FTM_RESPONSE_STATUS enumeration

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

The **WDI_FTM_RESPONSE_STATUS** defines the response status for a Fine Timing Measurement (FTM) request.

## Constants

### `WDI_FTM_RESPONSE_STATUS_SUCCESS`

The FTM was a success.

### `WDI_FTM_RESPONSE_STATUS_UNREACHABLE`

No ACK was received for the FTM request from the target, or no first FTM frame was received afterwards. The application will be advised to first trigger a new scan before retrying.

### `WDI_FTM_RESPONSE_STATUS_REJECTED`

The status indication field from Table 9-256 of the [802-11-2016 standard](https://standards.ieee.org/standard/802_11-2016.html) was set to **3**. A **RetryValue** should be provided and the application will be advised to retry only after that time has passed.

### `WDI_FTM_RESPONSE_STATUS_INCAPABLE`

The status indication field from Table 9-256 of the [802-11-2016 standard](https://standards.ieee.org/standard/802_11-2016.html) was set to **2**. The application will be advised not to retry.

### `WDI_FTM_RESPONSE_STATUS_TIMEOUT`

The FTM session was started but it did not complete before the timeout expired. A retry to this STA might work.

### `WDI_FTM_RESPONSE_STATUS_NOT_ATTEMPTED`

The FTM session was not initiated. It is highly likely that a retry to this STA will work.

### `WDI_FTM_RESPONSE_STATUS_ABORTED`

The FTM procedure did not complete because the task was aborted. It is likely that a retry to this STA will work.

### `WDI_FTM_RESPONSE_STATUS_FAILED`

The FTM procedure failed with any other failure besides the preceding failure responses. A retry to this STA might or might not work.

## Remarks

This enumeration is a value in the [WDI_TLV_FTM_RESPONSE](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-tlv-ftm-response) TLV.

## See also

[WDI_TLV_FTM_RESPONSE](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-tlv-ftm-response)

[NDIS_STATUS_WDI_INDICATION_REQUEST_FTM_COMPLETE](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-wdi-indication-request-ftm-complete)

[OID_WDI_TASK_REQUEST_FTM](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wdi-task-request-ftm)