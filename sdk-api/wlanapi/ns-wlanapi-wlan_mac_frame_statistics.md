# WLAN_MAC_FRAME_STATISTICS structure

## Description

The **WLAN_MAC_FRAME_STATISTICS** structure contains information about sent and received MAC frames.

## Members

### `ullTransmittedFrameCount`

Contains the number of successfully transmitted MSDU/MMPDUs.

### `ullReceivedFrameCount`

Contains the number of successfully received MSDU/MMPDUs.

### `ullWEPExcludedCount`

Contains the number of frames discarded due to having a "Protected" status indicated in the frame control field.

### `ullTKIPLocalMICFailures`

Contains the number of MIC failures encountered while checking the integrity of packets received from the AP or peer station.

### `ullTKIPReplays`

Contains the number of TKIP replay errors detected.

### `ullTKIPICVErrorCount`

Contains the number of TKIP protected packets that the NIC failed to decrypt.

### `ullCCMPReplays`

Contains the number of received unicast fragments discarded by the replay mechanism.

### `ullCCMPDecryptErrors`

Contains the number of received fragments discarded by the CCMP decryption algorithm.

### `ullWEPUndecryptableCount`

Contains the number of WEP protected packets received for which a decryption key was not available on the NIC.

### `ullWEPICVErrorCount`

Contains the number of WEP protected packets the NIC failed to decrypt.

### `ullDecryptSuccessCount`

Contains the number of encrypted packets that the NIC has successfully decrypted.

### `ullDecryptFailureCount`

Contains the number of encrypted packets that the NIC has failed to decrypt.

## See also

[WLAN_STATISTICS](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_statistics)