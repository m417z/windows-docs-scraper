# PCONVERTTREETOSTREAM callback function

## Description

The Bluetooth
**SdpConvertTreeToStream** function is used to produce a raw bytestream representation of an SDP record
from a tree representation. The raw bytestream version is suitable for publication on a local SDP
server.

## Parameters

### `Root`

The root node of the tree-based representation of the SDP record to convert into a stream-based
representation.

### `Stream`

A pointer to the buffer that receives the converted SDP stream.

### `Size`

The address of an unsigned long integer to receive the length of the converted SDP stream.

### `tag`

Specifies a 4-byte
[pool tag](https://learn.microsoft.com/windows-hardware/drivers/) that uniquely identifies the driver that does the memory
allocation. For more information about pool tags, see
[ExAllocatePoolWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithtag).

## Return value

Possible return values include:

STATUS_SUCCESS

STATUS_INSUFFICIENT_RESOURCES

STATUS_INVALID_PARAMETER

## Remarks

The
**SdpConvertTreeToStream** function performs the opposite operation as the
[SdpConvertStreamToTree](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthsdpddi/nc-bthsdpddi-pconvertstreamtotree) function. It
generates a complete native SDP record from a Microsoft-specific tree structure. Driver developers might
find it more convenient to build a SDP record as a tree and then convert it to a stream prior to
publishing.

**SdpConvertTreeToStream** allocates the necessary memory to store the stream version of the SDP
record. When the memory is no longer needed, the caller is responsible for freeing the memory using the
[ExFreePool](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-exfreepool) driver support routine.

Bluetooth profile drivers can obtain a pointer to this function through the
[BTHDDI_SDP_PARSE_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthsdpddi/ns-bthsdpddi-_bthddi_sdp_parse_interface).

## See also

[BTHDDI_SDP_PARSE_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthsdpddi/ns-bthsdpddi-_bthddi_sdp_parse_interface)

[ExFreePool](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-exfreepool)

[SdpConvertStreamToTree](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthsdpddi/nc-bthsdpddi-pconvertstreamtotree)