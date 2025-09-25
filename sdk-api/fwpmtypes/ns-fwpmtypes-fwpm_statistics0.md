# FWPM_STATISTICS0 structure

## Description

The **FWPM_STATISTICS0** structure stores statistics related to connections at specific layers.

## Members

### `numLayerStatistics`

Type: **UINT32**

Number of [FWPM_LAYER_STATISTICS0](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_layer_statistics0) structures in the **layerStatistics** member.

### `layerStatistics`

Type: [FWPM_LAYER_STATISTICS0](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_layer_statistics0)*

Statistics related to the layer.

### `inboundAllowedConnectionsV4`

Type: **UINT32**

Number of allowed IPv4 inbound connections.

### `inboundBlockedConnectionsV4`

Type: **UINT32**

Number of blocked IPv4 inbound connections.

### `outboundAllowedConnectionsV4`

Type: **UINT32**

Number of allowed IPv4 outbound connections.

### `outboundBlockedConnectionsV4`

Type: **UINT32**

Number of blocked IPv4 outbound connections.

### `inboundAllowedConnectionsV6`

Type: **UINT32**

Number of allowed IPv6 inbound connections.

### `inboundBlockedConnectionsV6`

Type: **UINT32**

Number of blocked IPv6 inbound connections.

### `outboundAllowedConnectionsV6`

Type: **UINT32**

Number of allowed IPv6 outbound connections.

### `outboundBlockedConnectionsV6`

Type: **UINT32**

Number of blocked IPv6 outbound connections.

### `inboundActiveConnectionsV4`

Type: **UINT32**

Number of active IPv4 inbound connections.

### `outboundActiveConnectionsV4`

Type: **UINT32**

Number of active IPv4 outbound connections.

### `inboundActiveConnectionsV6`

Type: **UINT32**

Number of active IPv6 inbound connections.

### `outboundActiveConnectionsV6`

Type: **UINT32**

Number of active IPv6 outbound connections.

### `reauthDirInbound`

### `reauthDirOutbound`

### `reauthFamilyV4`

### `reauthFamilyV6`

### `reauthProtoOther`

### `reauthProtoIPv4`

### `reauthProtoIPv6`

### `reauthProtoICMP`

### `reauthProtoICMP6`

### `reauthProtoUDP`

### `reauthProtoTCP`

### `reauthReasonPolicyChange`

### `reauthReasonNewArrivalInterface`

### `reauthReasonNewNextHopInterface`

### `reauthReasonProfileCrossing`

### `reauthReasonClassifyCompletion`

### `reauthReasonIPSecPropertiesChanged`

### `reauthReasonMidStreamInspection`

### `reauthReasonSocketPropertyChanged`

### `reauthReasonNewInboundMCastBCastPacket`

### `reauthReasonEDPPolicyChanged`

### `reauthReasonPreclassifyLocalAddrLayerChange`

### `reauthReasonPreclassifyRemoteAddrLayerChange`

### `reauthReasonPreclassifyLocalPortLayerChange`

### `reauthReasonPreclassifyRemotePortLayerChange`

### `reauthReasonProxyHandleChanged`

## Remarks

**FWPM_STATISTICS0** is a specific implementation of FWPM_STATISTICS. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[FWPM_LAYER_STATISTICS0](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_layer_statistics0)