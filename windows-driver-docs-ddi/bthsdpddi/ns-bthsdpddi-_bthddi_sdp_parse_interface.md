# _BTHDDI_SDP_PARSE_INTERFACE structure

## Description

The BTHDDI_SDP_PARSE_INTERFACE structure provides functions for parsing SDP records.

## Members

### `Interface`

A structure that describes the
**BTHDDI_SDP_NODE_INTERFACE** interface for use by profile drivers. For more information about this
structure, see
[INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_interface).

### `SdpValidateStream`

A pointer to the
[SdpValidateStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthsdpddi/nc-bthsdpddi-pvalidatestream) function.

### `SdpConvertStreamToTree`

A pointer to the
[SdpConvertStreamToTree](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthsdpddi/nc-bthsdpddi-pconvertstreamtotree) function.

### `SdpConvertTreeToStream`

A pointer to the
[SdpConvertTreeToStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthsdpddi/nc-bthsdpddi-pconverttreetostream) function.

### `SdpFreeTree`

A pointer to the
[SdpFreeTree](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdplib/nf-sdplib-sdpfreetree) function.

### `SdpByteSwapUuid128`

A pointer to the
[SdpByteSwapUuid128](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthsdpddi/nc-bthsdpddi-pbyteswapuuid128) function.

### `SdpByteSwapUint128`

A pointer to the
[SdpByteSwapUint128](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthsdpddi/nc-bthsdpddi-pbyteswapuint128) function.

### `SdpByteSwapUint64`

A pointer to the
[SdpByteSwapUint64](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthsdpddi/nc-bthsdpddi-pbyteswapuint64) function.

### `SdpRetrieveUuid128`

A pointer to the
[SdpRetrieveUuid128](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthsdpddi/nc-bthsdpddi-pretrieveuuid128) function.

### `SdpRetrieveUint128`

A pointer to the
[SdpRetrieveUint128](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthsdpddi/nc-bthsdpddi-pretrieveuint64) function.

### `SdpRetrieveUint64`

A pointer to the
[SdpRetrieveUint64](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff536845(v=vs.85)) function.

### `SdpFindAttributeInTree`

A pointer to the
[SdpFindAttributeInTree](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdplib/nf-sdplib-sdpfindattributeintree) function.

### `SdpGetNextElement`

A pointer to the
[SdpGetNextElement](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthsdpddi/nc-bthsdpddi-pgetnextelement) function.

### `Reserved1`

Reserved for future use. Do not use.

### `Reserved2`

Reserved for future use. Do not use.

### `Reserved3`

Reserved for future use. Do not use.

### `Reserved4`

Reserved for future use. Do not use.

## Remarks

Profile drivers should specify the
**GUID_BTHDDI_SDP_PARSE_INTERFACE** GUID to query for an instance of the BTHDDI_SDP_PARSE_INTERFACE
structure from the Bluetooth driver stack.

All the members of this structure, other than the
**Interface** member, are function pointers.

## See also

[INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_interface)

[SdpByteSwapUint128](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthsdpddi/nc-bthsdpddi-pbyteswapuint128)

[SdpByteSwapUint64](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthsdpddi/nc-bthsdpddi-pbyteswapuint64)

[SdpByteSwapUuid128](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthsdpddi/nc-bthsdpddi-pbyteswapuuid128)

[SdpConvertStreamToTree](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthsdpddi/nc-bthsdpddi-pconvertstreamtotree)

[SdpConvertTreeToStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthsdpddi/nc-bthsdpddi-pconverttreetostream)

[SdpFindAttributeInTree](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdplib/nf-sdplib-sdpfindattributeintree)

[SdpFreeTree](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdplib/nf-sdplib-sdpfreetree)

[SdpGetNextElement](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthsdpddi/nc-bthsdpddi-pgetnextelement)

[SdpRetrieveUint128](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthsdpddi/nc-bthsdpddi-pretrieveuint64)

[SdpRetrieveUint64](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff536845(v=vs.85))

[SdpRetrieveUuid128](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthsdpddi/nc-bthsdpddi-pretrieveuuid128)

[SdpValidateStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthsdpddi/nc-bthsdpddi-pvalidatestream)