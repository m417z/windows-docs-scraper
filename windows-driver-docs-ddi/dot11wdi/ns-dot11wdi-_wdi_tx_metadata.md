# _WDI_TX_METADATA structure

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

The
WDI_TX_METADATA structure defines the TX metadata.

## Members

### `PortID`

Port ID of the frame.

### `PeerID`

Peer ID of the frame (only if **TargetPriorityQueueing** is false).

### `ExTID`

Extended TID of the frame (only if **TargetPriorityQueueing** is false).

### `IsUnicast`

Specifies if the frame is for a unicast recipient address.

### `bAllowLegacyRates`

Specifies if legacy rates should be used for transmitting the frame.

### `Ethertype`

Specifies the Ethertype of the frame.

### `bTxCompleteRequired`

Specifies if an [NdisWdiTxSendCompleteIndication](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-ndis_wdi_tx_send_complete_ind) is required for this frame.

### `PnLength`

Specifies the PnLength for the frame. This is only applicable to Requeued/Replayed TX frames. Otherwise, set to zero.

### `TxCost`

Specifies the number of credits required to dequeue the frame.

### `ExemptionAction`

Specifies the [WDI_EXEMPTION_ACTION_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ne-dot11wdi-_wdi_exemption_action_type) value for this frame.

### `MpduPn`

Specifies the MpduPn for the frame. This is only applicable to Requeued/Replayed TX frames. Otherwise, set to zero.

### `ReplayIHVReserved0`

Reserved for use by the IHV miniport for Requeued/Replayed TX frames. This is only applicable to Requeued/Replayed TX frames. Otherwise, set to zero.

### `ReplayIHVReserved1`

Reserved for use by the IHV miniport for Requeued/Replayed TX frames. This is only applicable to Requeued/Replayed TX frames. Otherwise, set to zero.

### `SeqCtl`

Specifies the SeqCtl (if necessary). This is only applicable to Requeued/Replayed TX frames. Otherwise, set to zero.

### `wPad`

Reserved.

## See also

[WDI_EXEMPTION_ACTION_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ne-dot11wdi-_wdi_exemption_action_type)

[WDI_TXRX_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_wdi_txrx_target_capabilities)