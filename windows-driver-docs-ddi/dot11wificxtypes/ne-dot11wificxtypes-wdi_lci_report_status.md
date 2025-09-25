## Description

> [!IMPORTANT]
> This topic is part of the [WiFiCx driver model](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx). WiFiCx is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The previous Wi-Fi driver model [WDI](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) is in maintenance mode and will only receive high priority fixes.

The **WDI_LCI_REPORT_STATUS** enumeration defines the response status for an LCI report, if the report were requested in a Fine Timing Measurement (FTM) request.

## Constants

### `WDI_LCI_REPORT_STATUS_SUCCESS:0`

The LCI report was successfully obtained.

### `WDI_LCI_REPORT_STATUS_FAILURE:1`

A failure occurred while getting the report.

### `WDI_LCI_REPORT_STATUS_INCAPABLE:2`

The **Incapable** bit of the Measurement Report Mode field is set. For more info, see section 9.4.2.22, the Measurement Report element, of the [802-11-2016 standard](https://standards.ieee.org/standard/802_11-2016.html).

### `WDI_LCI_REPORT_STATUS_REFUSED:3`

The **Refused** bit of the Measurement Report Mode field is set. For more info, see section 9.4.2.22, the Measurement Report element, of the [802-11-2016 standard](https://standards.ieee.org/standard/802_11-2016.html).

## Remarks

This enumeration is a value in the [WDI_TLV_FTM_RESPONSE](https://learn.microsoft.com/windows-hardware/drivers/netcx/wdi-tlv-ftm-response) TLV.

## See also

[WDI_TLV_FTM_RESPONSE](https://learn.microsoft.com/windows-hardware/drivers/netcx/wdi-tlv-ftm-response)

[NDIS_STATUS_WDI_INDICATION_REQUEST_FTM_COMPLETE](https://learn.microsoft.com/windows-hardware/drivers/netcx/ndis-status-wdi-indication-request-ftm-complete)

[OID_WDI_TASK_REQUEST_FTM](https://learn.microsoft.com/windows-hardware/drivers/netcx/oid-wdi-task-request-ftm)