# _AVC_SUBUNIT_INFO_BLOCK structure

## Description

The AVC_SUBUNIT_INFO_BLOCK structure describes subunit information.

## Members

### `Info`

Ignored on input. On output, this contains up to eight contiguous pages of subunit information in the format of the AV/C SUBUNIT_INFO unit command. The subunit information pages are terminated with 0xff. See Section 9.11 of the AV/C Digital Interface Command Set General Specification, Rev 3.0.

## Remarks

This structure is used with the [AVC_FUNCTION_GET_SUBUNIT_INFO](https://learn.microsoft.com/windows-hardware/drivers/stream/avc-function-get-subunit-info) function code.

This structure is used only as a member inside the AVC_MULTIFUNC_IRB structure. It is not used by itself.

See [How to Use Avc.sys](https://learn.microsoft.com/windows-hardware/drivers/stream/using-avc-sys) For information about building and sending an AV/C command.

## See also

[AVC_FUNCTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/avc/ne-avc-_tagavc_function)

[AVC_FUNCTION_GET_SUBUNIT_INFO](https://learn.microsoft.com/windows-hardware/drivers/stream/avc-function-get-subunit-info)

[AVC_MULTIFUNC_IRB](https://learn.microsoft.com/windows-hardware/drivers/ddi/avc/ns-avc-_avc_multifunc_irb)