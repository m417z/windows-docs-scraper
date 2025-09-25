# IoSetIoPriorityHint function

## Description

The **IoSetIoPriorityHint** routine sets the [priority hint value](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-irp-priority-hints) for an IRP.

## Parameters

### `Irp` [in]

Specifies the IRP to set the priority hint value for.

### `PriorityHint` [in]

Specifies the [IO_PRIORITY_HINT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_io_priority_hint) value that indicates the new priority hint.

## Return value

**IoSetIoPriorityHint** returns STATUS_SUCCESS if the operation succeeds and the appropriate NTSTATUS value if the operation fails.

## Remarks

For more information about priority hints, see [Using IRP Priority Hints](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-irp-priority-hints).

## See also

[IO_PRIORITY_HINT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_io_priority_hint)

[IoGetIoPriorityHint](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetiopriorityhint)