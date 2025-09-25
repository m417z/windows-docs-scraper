# _MAILSLOT_CREATE_PARAMETERS structure

## Description

 The MAILSLOT_CREATE_PARAMETERS is used by the Windows subsystem to create a mailslot.

## Members

### `MailslotQuota`

Pool quota that is reserved for writes to this mailslot.

### `MaximumMessageSize`

Size, in bytes, of the largest message that can be written to this mailslot.

### `ReadTimeout`

The timeout period for the read operation, specified as a relative time.

### `TimeoutSpecified`

Boolean value that specifies whether a timeout period was provided in the *ReadTimeout* member.

## Remarks

For an [IRP_MJ_CREATE_MAILSLOT](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-create-mailslot) operation, [FLT_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_parameters) is a *CreateMailslot* structure, and *CreateMailslot.Parameters* points to a MAILSLOT_CREATE_PARAMETERS structure that describes the mailslot to create or open.

## See also

[FLT_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_parameters)

[IRP_MJ_CREATE_MAILSLOT](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-create-mailslot)