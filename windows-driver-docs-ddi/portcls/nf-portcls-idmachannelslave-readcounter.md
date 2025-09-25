# IDmaChannelSlave::ReadCounter

## Description

The ReadCounter method reads the counter of a subordinate DMA object.

## Return value

ReadCounter returns the DMA object's counter value as ULONG, which specifies the current byte count. When the object is started, this value is set to the map size (the IDmaChannelSlave::Start method's MapSize parameter). The value decrements until it reaches zero, at which time it is reset to the map size. This process repeats until the DMA object is stopped (by calling the IDmaChannelSlave::Stop method).

## Remarks

> [!NOTE]
> Microsoft supports a diverse and inclusive environment. This article contains references to terminology that the [Microsoft style guide for bias-free communication](https://learn.microsoft.com/style-guide/bias-free-communication) recognizes as exclusionary. The word or phrase is used in this article for consistency because it currently appears in the software. When the software is updated to remove the language, this article will be updated to be in alignment.

## See also

[IDmaChannelSlave interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-idmachannelslave)