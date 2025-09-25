# _IO_PRIORITY_HINT enumeration

## Description

The **IO_PRIORITY_HINT** enumeration type specifies the [priority hint](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-irp-priority-hints) for an IRP.

## Constants

### `IoPriorityVeryLow`

Specifies the lowest possible priority hint level. The system uses this value for background I/O operations.

### `IoPriorityLow`

Specifies a low-priority hint level.

### `IoPriorityNormal`

Specifies a normal-priority hint level. This value is the default setting for an IRP.

### `IoPriorityHigh`

Specifies a high-priority hint level. This value is reserved for use by the system.

### `IoPriorityCritical`

Specifies the highest-priority hint level. This value is reserved for use by the system.

### `MaxIoPriorityTypes`

Marks the limit for priority hints. Any priority hint value must be less than **MaxIoPriorityTypes**.

## Remarks

For more information about priority hints, see [Using IRP Priority Hints](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-irp-priority-hints).

## See also

[IoGetIoPriorityHint](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetiopriorityhint)

[IoSetIoPriorityHint](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iosetiopriorityhint)