# _WDI_TXRX_TARGET_CAPABILITIES structure

## Description

The
WDI_TXRX_CAPABILITIES structure defines the target capabilities.

## Members

### `InterconnectType`

Interconnect type of the target.

### `TransmitCapabilities`

Transmit capabilities.

#### MaxMemBlocksPerFrame

Maximum number of Scatter Gather elements in a frame. WDI coalesces frames as necessary so that the IHV miniport does not receive a frame that requires more scatter gather elements than specified by this capability. For best performance, it is suggested that this capability is set higher than the typical frame as the coalescing requires a memory copy. If this capability is not greater than the maximum frame size divided by page size, WDI may be unable to successfully coalesce the frame and it may be dropped.

### `TransmitCapabilities.TargetPriorityQueueing`

If true, WDI does not classify Tx frames by Peer and TID, and only provides queuing at a port level. WDI schedules backlogged port queues using a global DRR.

If false, WDI classifies Tx frames by Peer and TID and utilizes the full scheduler to select TX queues to transfer.

Setting this to false is recommended unless the target is capable of classification and Peer-TID queueing.

### `TransmitCapabilities.MaxScatterGatherElementsPerFrame`

### `TransmitCapabilities.ExplicitSendCompleteFlagRequired`

If true, the target/TAL generates a TX send completion indication only for frames that have this flag set in the frame's metadata.

If false, the target/TAL generates a TX send completion indication for all frames

### `TransmitCapabilities.bPad`

Reserved.

### `TransmitCapabilities.MinEffectiveSize`

When dequeuing frames, the TxMgr treats frames smaller than **MinEffectiveSize** as having an effective size of **MinEffectiveSize**.

### `TransmitCapabilities.FrameSizeGranularity`

This value is equal to the granularity of memory allocation per frame. For the purposes of dequeuing, the TxMgr treats a frame as having an effective size equal to the frame size plus the least amount of padding such that the effective size is an integer multiple of the **FrameSizeGranularity**.

This value must be set to a power of two.

### `ReceiveCapabilities`

Receive capabilities.

### `ReceiveCapabilities.RxTxForwarding`

Reserved.

### `ReceiveCapabilities.MaxThroughput`

Specifies the maximum throughput of the device in units of 0.5 Mbps.