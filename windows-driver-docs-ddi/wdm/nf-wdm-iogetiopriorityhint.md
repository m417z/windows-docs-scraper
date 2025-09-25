# IoGetIoPriorityHint function

## Description

The **IoGetIoPriorityHint** routine gets the [priority hint value](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-irp-priority-hints) from an IRP.

## Parameters

### `Irp` [in]

Specifies the IRP to obtain the priority hint from.

## Return value

**IoGetIoPriorityHint** returns the [IO_PRIORITY_HINT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_io_priority_hint) value that indicates the current priority hint.

## Remarks

For more information about priority hints, see [Using IRP Priority Hints](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-irp-priority-hints).

## See also

[IO_PRIORITY_HINT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_io_priority_hint)

[IoSetIoPriorityHint](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iosetiopriorityhint)