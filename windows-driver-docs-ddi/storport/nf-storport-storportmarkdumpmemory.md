# StorPortMarkDumpMemory function

## Description

A miniport should mark memory used for the dump file or the hibernation file. Marked memory is retained and remains valid after a resume from hibernation operation. The memory to mark is specified by an address and range length in a call to **StorPortMarkDumpMemory**.

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension for the host bus adapter (HBA).

### `Address` [in]

The starting address of the memory range to mark.

### `Length` [in]

The length of the marked memory range.

### `Flags` [in]

Dump memory marking flags. The *Flags* parameter must be 0 or contain only the following value.

| Value | Meaning |
| ----- | ------- |
| **MARK_DUMP_MEMORY_FLAG_PHYSICAL_ADDRESS** | The address provided in *Address* is a physical address and not a system virtual address.

## Return value

**StorPortMarkDumpMemory** returns one of the following status codes:

| Return code | Description |
| ----------- | ----------- |
| **STOR_STATUS_SUCCESS** | Indicates that the routine set the unit attributes successfully. |
| **STOR_STATUS_INVALID_PARAMETER** | An invalid flag value was specified in the *Flags* parameter. |

## Remarks

The **StorPortMarkDumpMemory** routine must only be called by a miniport driver in its [**DriverEntry**](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) or [**HwStorFindAdapter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_find_adapter) routines.

If *Length* = 0, the entire section containing *Address* is marked.

Miniport drivers should call **StorPortMarkDumpMemory** to ensure that the memory used by the miniport to generate either the dump file or the hibernation file is identified. At a minimum, miniports should call **StorPortMarkDumpMemory** when the **DumpMode** member of [**PORT_CONFIGURATION_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_port_configuration_information) is set to either **DUMP_MODE_MARK_MEMORY** or **DUMP_MODE_HIBER**.

## See also

[**DriverEntry**](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver)

[**HwStorFindAdapter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_find_adapter)

[**PORT_CONFIGURATION_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_port_configuration_information)