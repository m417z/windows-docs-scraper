# _AVC_IRB structure

## Description

The AVC_IRB structure is an I/O Request Block (IRB) header structure where a function number is stored.

## Members

### `Function`

Value from the AVC_FUNCTION enumeration specifying a function number.

## Remarks

This structure is included at the head of the AVC_COMMAND_IRB and AVC_MULTIFUNC_IRB structures. These structures represent the I/O request block (IRB) associated with specific types of AV/C functions. Each specific type of AV/C function is documented in IOCTL_AVC_CLASS.

## See also

[AVC_COMMAND_IRB](https://learn.microsoft.com/windows-hardware/drivers/ddi/avc/ns-avc-_avc_command_irb)

[AVC_FUNCTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/avc/ne-avc-_tagavc_function)

[AVC_MULTIFUNC_IRB](https://learn.microsoft.com/windows-hardware/drivers/ddi/avc/ns-avc-_avc_multifunc_irb)

[IOCTL_AVC_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/avc/ni-avc-ioctl_avc_class)