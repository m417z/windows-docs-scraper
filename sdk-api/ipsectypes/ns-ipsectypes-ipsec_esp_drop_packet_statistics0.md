# IPSEC_ESP_DROP_PACKET_STATISTICS0 structure

## Description

The **IPSEC_ESP_DROP_PACKET_STATISTICS0** structure stores ESP drop packet statistics.

## Members

### `invalidSpisOnInbound`

Number of invalid SPIs on inbound.

### `decryptionFailuresOnInbound`

Number of decryption failures on inbound.

### `authenticationFailuresOnInbound`

Number of authentication failures on inbound.

### `replayCheckFailuresOnInbound`

Number of replay check failures on inbound.

### `saNotInitializedOnInbound`

Number of inbound drops for packets received on SAs that were not fully initialized.

## Remarks

**IPSEC_ESP_DROP_PACKET_STATISTICS0** is a specific implementation of IPSEC_ESP_DROP_PACKET_STATISTICS. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)