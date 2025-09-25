# IDmaChannelSlave::Stop

## Description

The Stop method stops a subordinate DMA object that was started by a previous call to [IDmaChannelSlave::Start](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-idmachannelslave-start).

## Return value

The stop method returns NTSTATUS. It returns STATUS_SUCCESS if the call was successful. Otherwise, the method returns an appropriate error code.

## Remarks

> [!NOTE]
> Microsoft supports a diverse and inclusive environment. This article contains references to terminology that the [Microsoft style guide for bias-free communication](https://learn.microsoft.com/style-guide/bias-free-communication) recognizes as exclusionary. The word or phrase is used in this article for consistency because it currently appears in the software. When the software is updated to remove the language, this article will be updated to be in alignment.

This call flushes any data remaining in the DMA controller's internal cache at the time that the DMA transfer operation is stopped.

## See also

[IDmaChannelSlave::Start](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-idmachannelslave-start)

[IDmaChannelSlave interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-idmachannelslave)