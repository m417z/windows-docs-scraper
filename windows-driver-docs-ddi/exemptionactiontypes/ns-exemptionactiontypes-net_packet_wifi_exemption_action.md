## Description

The **NET_PACKET_WIFI_EXEMPTION_ACTION** structure contains the exemption action information for a packet.

## Members

### `ExemptionAction`

A bit field that specifies a flag from [**WDI_EXEMPTION_ACTION_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wificxintf/ne-dot11wificxintf-wdi_exemption_action_type).

## Remarks

Client drivers can obtain this structure for a packet by calling [**WifiExtensionGetExemptionAction**](https://learn.microsoft.com/windows-hardware/drivers/ddi/exemptionaction/nf-exemptionaction-wifiextensiongetexemptionaction).

## See also

[**WifiExtensionGetExemptionAction**](https://learn.microsoft.com/windows-hardware/drivers/ddi/exemptionaction/nf-exemptionaction-wifiextensiongetexemptionaction)

[**WDI_EXEMPTION_ACTION_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wificxintf/ne-dot11wificxintf-wdi_exemption_action_type)