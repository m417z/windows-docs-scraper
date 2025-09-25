# _tagAVC_FUNCTION enumeration

## Description

The AVC_FUNCTION enumeration type is used to specify AV/C subunit functions.

## Constants

### `AVC_FUNCTION_COMMAND`

This value is a function code used to send an AV/C request and receive a response as one operation. This function code uses the AVC_COMMAND_IRB structure.

This function code is available to both peer and virtual instances of *avc.sys*.

### `AVC_FUNCTION_GET_PIN_COUNT`

This value is a function code used to obtain the number of pins supported by the underlying subunit device. This function code uses the AVC_PIN_COUNT structure.

This function code is available only to peer instances of *avc.sys*.

### `AVC_FUNCTION_GET_PIN_DESCRIPTOR`

This value is a function code used to obtain the pin descriptor for each pin ID. This function code uses the AVC_PIN_DESCRIPTOR structure.

This function code is available only to peer instances of *avc.sys*.

### `AVC_FUNCTION_GET_CONNECTINFO`

This value is a function code used to obtain the AVCPRECONNECTINFO structure for each pin ID. This function code uses the AVC_PRE_CONNECTINFO structure.

This function code is available only to peer instances of *avc.sys*.

### `AVC_FUNCTION_SET_CONNECTINFO`

This value is a function code used to set the AVCCONNECTINFO structure for each pin ID. This function code uses the AVC_SET_CONNECTINFO structure.

This function code is available only to peer instances of *avc.sys*.

### `AVC_FUNCTION_ACQUIRE`

This value is a function code used to cause *avc.sys* to establish any connections suggested by cached AVCCONNECTINFO values. This function code uses the AVC_PIN_ID structure.

This function code is available only to peer instances of *avc.sys*.

### `AVC_FUNCTION_RELEASE`

This value is a function code used to cause *avc.sys* to release any connections suggested by cached AVCCONNECTINFO values. This function code uses the AVC_PIN_ID structure.

### `AVC_FUNCTION_CLR_CONNECTINFO`

This value is a function code used to cause *avc.sys* to remove any cached AVCCONNECTINFO values. This function code uses the AVC_PIN_ID structure.

This function code is available only to peer instances of *avc.sys*.

### `AVC_FUNCTION_GET_EXT_PLUG_COUNTS`

This value is a function code used to cause *avc.sys* to obtain the external input and output plug counts. This function code uses the AVC_EXT_PLUG_COUNTS structure.

This function code is available only to peer instances of *avc.sys*.

### `AVC_FUNCTION_GET_UNIQUE_ID`

This value is a function code used to obtain the unique ID of the AV/C unit. This function code uses the AVC_UNIQUE_ID structure.

This function code is available only to peer instances of *avc.sys*.

### `AVC_FUNCTION_GET_REQUEST`

This value is a function code used to register to receive AV/C unit and subunit requests. This function code uses the AVC_COMMAND_IRB structure.

This function code is available to both peer and virtual instances of *avc.sys*.

### `AVC_FUNCTION_SEND_RESPONSE`

This value is a function code used to cause *avc.sys* to respond to AV/C unit and subunit requests. This function code uses the AVC_COMMAND_IRB structure.

This function code is available to both peer and virtual instances of *avc.sys*.

### `AVC_FUNCTION_FIND_PEER_DO`

This value is a function code used to locate a nonvirtual *avc.sys* instance. This function code uses the AVC_PEER_DO_LOCATOR structure.

This function code is available to both peer and virtual instances of *avc.sys*.

### `AVC_FUNCTION_PEER_DO_LIST`

This value is a function code used to locate all nonvirtual *avc.sys* instances. This function code uses the AVC_PEER_DO_LIST structure.

This function code is available to both peer and virtual instances of *avc.sys*.

### `AVC_FUNCTION_GET_SUBUNIT_INFO`

This value is a function code used to obtain the subunit information of the target device. This function code uses the AVC_SUBUNIT_INFO_BLOCK structure.

This function code is available to both peer and virtual instances of *avc.sys*.

## See also

[AVC_COMMAND_IRB](https://learn.microsoft.com/windows-hardware/drivers/ddi/avc/ns-avc-_avc_command_irb)

[AVC_EXT_PLUG_COUNTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/avc/ns-avc-_avc_ext_plug_counts)

[AVC_IRB](https://learn.microsoft.com/windows-hardware/drivers/ddi/avc/ns-avc-_avc_irb)

[AVC_PEER_DO_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/avc/ns-avc-_avc_peer_do_list)

[AVC_PEER_DO_LOCATOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/avc/ns-avc-_avc_peer_do_locator)

[AVC_PIN_COUNT](https://learn.microsoft.com/windows-hardware/drivers/ddi/avc/ns-avc-_avc_pin_count)

[AVC_PIN_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/avc/ns-avc-_avc_pin_descriptor)

[AVC_PIN_ID](https://learn.microsoft.com/windows-hardware/drivers/ddi/avc/ns-avc-_avc_pin_id)

[AVC_PRECONNECT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/avc/ns-avc-_avc_preconnect_info)

[AVC_SETCONNECT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/avc/ns-avc-_avc_setconnect_info)

[AVC_SUBUNIT_INFO_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/avc/ns-avc-_avc_subunit_info_block)

[AVC_UNIQUE_ID](https://learn.microsoft.com/windows-hardware/drivers/ddi/avc/ns-avc-_avc_unique_id)