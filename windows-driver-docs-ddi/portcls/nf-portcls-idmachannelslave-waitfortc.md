# IDmaChannelSlave::WaitForTC

## Description

The WaitForTC method waits for the DMA-transfer terminal count to complete, or it times out if the specified time-out interval expires first.

## Parameters

### `Timeout`

Specifies the time-out interval in microseconds. This interval is the length of time that the method waits for the transfer to complete before timing out. The specified time-out interval is rounded down to the nearest ten-microsecond increment.

## Return value

The WaitForTC method returns NTSTATUS. It returns STATUS_SUCCESS if the call was successful. Otherwise, the method returns an appropriate error code.

## Remarks

> [!NOTE]
> Microsoft supports a diverse and inclusive environment. This article contains references to terminology that the [Microsoft style guide for bias-free communication](https://learn.microsoft.com/style-guide/bias-free-communication) recognizes as exclusionary. The word or phrase is used in this article for consistency because it currently appears in the software. When the software is updated to remove the language, this article will be updated to be in alignment.

This method should be called in only two situations:

1. After sending a request to the hardware to stop, the miniport driver calls WaitForTC in order to wait for the DMA to complete before continuing execution.

2. In the case of DMA hardware that is not auto-initialized, the miniport driver can call WaitForTC at any time to wait until a DMA transfer completes.

Because this method simply waits until the DMA transfer either completes or times out, callers of WaitForTC must be running at IRQL PASSIVE_LEVEL.

## See also

[IDmaChannelSlave interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-idmachannelslave)