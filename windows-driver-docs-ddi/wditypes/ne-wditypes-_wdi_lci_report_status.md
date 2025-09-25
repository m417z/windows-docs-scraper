# WDI_LCI_REPORT_STATUS enumeration

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

The **WDI_LCI_REPORT_STATUS** enumeration defines the response status for an LCI report, if the report were requested in a Fine Timing Measurement (FTM) request.

## Constants

### `WDI_LCI_REPORT_STATUS_SUCCESS`

The LCI report was successfully obtained.

### `WDI_LCI_REPORT_STATUS_FAILURE`

A failure occurred while getting the report.

### `WDI_LCI_REPORT_STATUS_INCAPABLE`

The **Incapable** bit of the Measurement Report Mode field is set. For more info, see section 9.4.2.22, the Measurement Report element, of the [802-11-2016 standard](https://standards.ieee.org/standard/802_11-2016.html).

### `WDI_LCI_REPORT_STATUS_REFUSED`

The **Refused** bit of the Measurement Report Mode field is set. For more info, see section 9.4.2.22, the Measurement Report element, of the [802-11-2016 standard](https://standards.ieee.org/standard/802_11-2016.html).

## Remarks

This enumeration is a value in the [WDI_TLV_FTM_RESPONSE](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-tlv-ftm-response) TLV.

## See also

[WDI_TLV_FTM_RESPONSE](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-tlv-ftm-response)

[NDIS_STATUS_WDI_INDICATION_REQUEST_FTM_COMPLETE](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-wdi-indication-request-ftm-complete)

[OID_WDI_TASK_REQUEST_FTM](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wdi-task-request-ftm)