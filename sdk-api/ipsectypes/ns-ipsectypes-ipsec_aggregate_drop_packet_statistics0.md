# IPSEC_AGGREGATE_DROP_PACKET_STATISTICS0 structure

## Description

The [IPSEC_AGGREGATE_DROP_PACKET_STATISTICS1](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_aggregate_drop_packet_statistics1) is available.

## Members

### `invalidSpisOnInbound`

Number of invalid SPIs on inbound.

### `decryptionFailuresOnInbound`

Number of decryption failures on inbound.

### `authenticationFailuresOnInbound`

Number of authentication failures on inbound.

### `udpEspValidationFailuresOnInbound`

Number of UDP ESP validation failures on inbound.

### `replayCheckFailuresOnInbound`

Number of replay check failures on inbound.

### `invalidClearTextInbound`

Number of invalid clear text instances on inbound.

### `saNotInitializedOnInbound`

Number of inbound drops for packets received on SAs that were not fully initialized.

### `receiveOverIncorrectSaInbound`

Number of inbound drops for packets received on SAs whose characteristics did not match the packet.

### `secureReceivesNotMatchingFilters`

Number of inbound IPsec secured packets that did not match any inbound IPsec transport layer filter.

## See also

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)