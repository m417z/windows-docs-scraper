# _DOT11_PEER_STATISTICS structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The DOT11_PEER_STATISTICS structure records statistical counters for the IEEE media access control
(MAC) sublayer of a peer station within an independent basic service set (IBSS) network.

**Note** IBSS (Ad hoc) and SoftAP are deprecated. Starting with Windows 8.1 and Windows Server 2012 R2, use [Wi-Fi Direct](https://learn.microsoft.com/windows-hardware/drivers/partnerapps/wi-fi-direct).

## Members

### `ullDecryptSuccessCount`

The number of received encrypted packets that the peer station successfully decrypted.

### `ullDecryptFailureCount`

The number of encrypted packets that the peer station failed to decrypt.

### `ullTxPacketSuccessCount`

The number of MAC service data unit (MSDU) packets and MAC management protocol data unit (MMPDU)
frames that the IEEE MAC sublayer of the peer station successfully transmitted.

### `ullTxPacketFailureCount`

The number of MSDU packets and MMPDU frames that the IEEE MAC sublayer of the peer station
attempted to transmit, but that failed to transmit.

### `ullRxPacketSuccessCount`

The number of MSDU packets and MMPDU frames that the IEEE MAC sublayer of the peer station
successfully received.

### `ullRxPacketFailureCount`

The number of MSDU packets and MMPDU frames that the IEEE MAC sublayer of the peer station
attempted to receive, but that failed to be received.

## Syntax

```cpp
typedef struct _DOT11_PEER_STATISTICS {
  ULONGLONG ullDecryptSuccessCount;
  ULONGLONG ullDecryptFailureCount;
  ULONGLONG ullTxPacketSuccessCount;
  ULONGLONG ullTxPacketFailureCount;
  ULONGLONG ullRxPacketSuccessCount;
  ULONGLONG ullRxPacketFailureCount;
} DOT11_PEER_STATISTICS, *PDOT11_PEER_STATISTICS;
```

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)