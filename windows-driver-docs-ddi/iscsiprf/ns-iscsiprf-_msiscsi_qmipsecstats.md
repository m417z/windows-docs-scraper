# _MSiSCSI_QMIPSECStats structure

## Description

The MSiSCSI_QMIPSECStats structure can be used by an iSCSI initiator to report IPsec statistics for an HBA.

## Members

### `ActiveSA`

The number of active IPsec security associations (SAs).

### `PendingKeyOperations`

The number of IPsec key operations that are in progress.

### `KeyAdditions`

The number of successful IPsec SA negotiations.

### `KeyDeletions`

The number of IPsec SA key deletions.

### `ReKeys`

The number of re-key operations for IPsec SAs.

### `ActiveTunnels`

The number of active IPsec tunnels.

### `BadSPIPackets`

The number of packets for which the security parameters index (SPI) was incorrect.

### `PacketsNotDecrypted`

The number of failed decryption packets.

### `PacketsNotAuthenticated`

The number of packets for which data could not be verified.

### `PacketsWithReplayDetection`

The number of packets that contained a valid sequence number field.

### `ConfidentialBytesSent`

The number of bytes that are sent by using the encapsulating security payload (ESP) protocol.

### `ConfidentialBytesReceived`

The number of bytes that are received by using the ESP protocol.

### `AuthenticatedBytesSent`

The number of bytes that are sent by using the authentication header (AH) protocol.

### `AuthenticatedBytesReceived`

The number of bytes that are received by using the AH protocol.

### `TransportBytesSent`

The number of bytes that are sent by using the IPsec protocol.

### `TransportBytesReceived`

The number of bytes that are received by using the IPsec protocol.

### `TunnelBytesSent`

The number of bytes that are sent by using the IPsec tunnel mode.

### `TunnelBytesReceived`

The number of bytes that are received by using the IPsec tunnel mode.

## Remarks

It is optional that you implement this class.

## See also

[MSiSCSI_QMIPSECStats WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msiscsi-qmipsecstats-wmi-class)