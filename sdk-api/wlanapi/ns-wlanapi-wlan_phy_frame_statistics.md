# WLAN_PHY_FRAME_STATISTICS structure

## Description

The **WLAN_PHY_FRAME_STATISTICS** structure contains information about sent and received PHY frames

## Members

### `ullTransmittedFrameCount`

Contains the number of successfully transmitted MSDU/MMPDUs.

### `ullMulticastTransmittedFrameCount`

Contains the number of successfully transmitted MSDU/MMPDUs in which the multicast bit is set as the destination MAC address.

### `ullFailedCount`

Contains the number of MSDU/MMPDUs transmission failures due to the number of transmit attempts exceeding the retry limit.

### `ullRetryCount`

Contains the number of MSDU/MMPDUs successfully transmitted after one or more retransmissions.

### `ullMultipleRetryCount`

Contains the number of MSDU/MMPDUs successfully transmitted after more than one retransmission.

### `ullMaxTXLifetimeExceededCount`

Contains the number of fragmented MSDU/MMPDUs that failed to send due to timeout.

### `ullTransmittedFragmentCount`

Contains the number of MPDUs with an individual address in the address 1 field and MPDUs that have a multicast address with types Data or Management.

### `ullRTSSuccessCount`

Contains the number of times a CTS has been received in response to an RTS.

### `ullRTSFailureCount`

Contains the number of times a CTS has not been received in response to an RTS.

### `ullACKFailureCount`

Contains the number of times an expected ACK has not been received.

### `ullReceivedFrameCount`

Contains the number of MSDU/MMPDUs successfully received.

### `ullMulticastReceivedFrameCount`

Contains the number of successfully received MSDU/MMPDUs with the multicast bit set in the MAC address.

### `ullPromiscuousReceivedFrameCount`

Contains the number of MSDU/MMPDUs successfully received only because promiscuous mode is enabled.

### `ullMaxRXLifetimeExceededCount`

Contains the number of fragmented MSDU/MMPDUs dropped due to timeout.

### `ullFrameDuplicateCount`

Contains the number of frames received that the Sequence Control field indicates as a duplicate.

### `ullReceivedFragmentCount`

Contains the number of successfully received Data or Management MPDUs.

### `ullPromiscuousReceivedFragmentCount`

Contains the number of MPDUs successfully received only because promiscuous mode is enabled.

### `ullFCSErrorCount`

Contains the number of times an FCS error has been detected in a received MPDU.

## See also

[WLAN_STATISTICS](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_statistics)