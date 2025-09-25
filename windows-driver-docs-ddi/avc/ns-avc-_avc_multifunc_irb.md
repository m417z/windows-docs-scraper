# _AVC_MULTIFUNC_IRB structure

## Description

The AVC_MULTIFUNC_IRB structure contains other AV/C related structures in a union.

## Members

### `Common`

 I/O Request Block (IRB) header structure where a function number is stored.

### `PinCount`

Used with AVC_FUNCTION_GET_PIN_COUNT.

### `PinDescriptor`

Used with AVC_FUNCTION_GET_PIN_DESCRIPTOR.

### `PreConnectInfo`

Used with AVC_FUNCTION_GET_CONNECT_INFO.

### `SetConnectInfo`

Used with AVC_FUNCTION_SET_CONNECT_INFO.

### `PinId`

Used with AVC_FUNCTION_ACQUIRE, **AVC_FUNCTION_RELEASE** and AVC_FUNCTION_CLR_CONNECTINFO.

### `ExtPlugCounts`

Used with AVC_FUNCTION_GET_EXT_PLUG_COUNTS.

### `UniqueID`

Used with AVC_FUNCTION_GET_UNIQUE_ID.

### `PeerLocator`

Used with AVC_FUNCTION_PEER_DO_LOCATOR.

### `PeerList`

Used with AVC_FUNCTION_PEER_DO_LIST.

### `Subunits`

Used with AVC_FUNCTION_GET_SUBUNIT_INFO.

## Remarks

The AVC_MULTIFUNC_IRB structure used with a variety of AV/C functionality. Depending on the functionality described in the AVC_IRB header, the matching, respective structure in the union is used.

## See also

[AVC_EXT_PLUG_COUNTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/avc/ns-avc-_avc_ext_plug_counts)

[AVC_FUNCTION_ACQUIRE](https://learn.microsoft.com/windows-hardware/drivers/stream/avc-function-acquire)

[AVC_FUNCTION_CLR_CONNECTINFO](https://learn.microsoft.com/windows-hardware/drivers/stream/avc-function-clr-connectinfo)

[AVC_FUNCTION_FIND_PEER_DO](https://learn.microsoft.com/windows-hardware/drivers/stream/avc-function-find-peer-do)

[AVC_FUNCTION_GET_CONNECTINFO](https://learn.microsoft.com/windows-hardware/drivers/stream/avc-function-get-connectinfo)

[AVC_FUNCTION_GET_EXT_PLUG_COUNTS](https://learn.microsoft.com/windows-hardware/drivers/stream/avc-function-get-ext-plug-counts)

[AVC_FUNCTION_GET_PIN_COUNT](https://learn.microsoft.com/windows-hardware/drivers/stream/avc-function-get-pin-count)

[AVC_FUNCTION_GET_PIN_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/stream/avc-function-get-pin-descriptor)

[AVC_FUNCTION_GET_SUBUNIT_INFO](https://learn.microsoft.com/windows-hardware/drivers/stream/avc-function-get-subunit-info)

[AVC_FUNCTION_GET_UNIQUE_ID](https://learn.microsoft.com/windows-hardware/drivers/stream/avc-function-get-unique-id)

[AVC_FUNCTION_PEER_DO_LIST](https://learn.microsoft.com/windows-hardware/drivers/stream/avc-function-peer-do-list)

[AVC_FUNCTION_RELEASE](https://learn.microsoft.com/windows-hardware/drivers/stream/avc-function-release)

[AVC_FUNCTION_SET_CONNECTINFO](https://learn.microsoft.com/windows-hardware/drivers/stream/avc-function-set-connectinfo)

[AVC_PEER_DO_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/avc/ns-avc-_avc_peer_do_list)

[AVC_PEER_DO_LOCATOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/avc/ns-avc-_avc_peer_do_locator)

[AVC_PIN_COUNT](https://learn.microsoft.com/windows-hardware/drivers/ddi/avc/ns-avc-_avc_pin_count)

[AVC_PIN_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/avc/ns-avc-_avc_pin_descriptor)

[AVC_PIN_ID](https://learn.microsoft.com/windows-hardware/drivers/ddi/avc/ns-avc-_avc_pin_id)

[AVC_PRECONNECT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/avc/ns-avc-_avc_preconnect_info)

[AVC_SETCONNECT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/avc/ns-avc-_avc_setconnect_info)

[AVC_SUBUNIT_INFO_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/avc/ns-avc-_avc_subunit_info_block)

[AVC_UNIQUE_ID](https://learn.microsoft.com/windows-hardware/drivers/ddi/avc/ns-avc-_avc_unique_id)