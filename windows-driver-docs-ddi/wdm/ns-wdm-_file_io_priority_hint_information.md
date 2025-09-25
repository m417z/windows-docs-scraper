# _FILE_IO_PRIORITY_HINT_INFORMATION structure

## Description

The **FILE_IO_PRIORITY_HINT_INFORMATION** structure is used by the [ZwQueryInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntqueryinformationfile) and [ZwSetInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntsetinformationfile) routines to query and set the default IRP [priority hint](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-irp-priority-hints) for requests on the specified file handle.

## Members

### `PriorityHint`

Specifies the [IO_PRIORITY_HINT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_io_priority_hint) value that indicates the priority hint for a file handle.

## Remarks

For more information about priority hints, see [Using IRP Priority Hints](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-irp-priority-hints).

## See also

[IO_PRIORITY_HINT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_io_priority_hint)

[ZwQueryInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntqueryinformationfile)

[ZwSetInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntsetinformationfile)