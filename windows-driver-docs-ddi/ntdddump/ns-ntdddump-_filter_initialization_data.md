# _FILTER_INITIALIZATION_DATA structure

## Description

The filter driver fills in a **FILTER_INITIALIZATION_DATA** structure and returns it to the crash dump driver.

## Members

### `MajorVersion`

Set to one of the following major version values:

#### DUMP_FILTER_MAJOR_VERSION_1 (0x1)

#### DUMP_FILTER_MAJOR_VERSION (0x2)

### `MinorVersion`

Set to **DUMP_FILTER_MINOR_VERSION**.

### `DumpStart`

A pointer to the dump initialization routine. This routine is called when the crash dump starts.

### `DumpWrite`

A pointer to the write routine. This routine is called before every crash dump write request.

### `DumpFinish`

A pointer to the dump finish routine. This routine is called when the crash dump is finished.

### `DumpUnload`

A pointer to the dump unload routine. This routine is called before the driver is unloaded.

### `DumpData`

The filter driver can pass a pointer to internal context data in this member. This pointer is passed back to the filter driver in a [FILTER_EXTENSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddump/ns-ntdddump-_filter_extension) structure during each callback.

### `MaxPagesPerWrite`

The maximum number of pages for each dump read or write request.

### `Flags`

A set of flags for dump filter initialization. This value is set to either 0 or the following:

| Value | Meaning |
| --- | --- |
| **DUMP_FILTER_FLAG_SYSTEM_SUPPORT_READ** | The dump filter supports filtering reads, and a read callback routine is set for **DumpRead**. This flag is supported starting in Windows 8. |
| **DUMP_FILTER_CRITICAL** | Fail the filter initialization immediately if the dump filter driver's **DriverEntry** routine does not return STATUS_SUCCESS. This flag is supported starting in Windows 8. |

### `DumpRead`

A pointer to the read routine. This routine is called after every crash dump read request. This member is available starting in Windows 8.

## Remarks

For a dump filter driver to support read filtering, the following settings are required:

* The **DUMP_FILTER_FLAG_SYSTEM_SUPPORT_READ** flag is set in **Flags**.
* **MajorVersion** is set to **DUMP_FILTER_MAJOR_VERSION** = 2.
* The **DumpRead** pointer is set to the dump filter driver's read routine.

If any of these members are not set, the dump filter driver will be marked as not supporting dump reads by the crashdump stack.

## See also

[Dump_Finish](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddump/nc-ntdddump-dump_finish)

[Dump_Read](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddump/nc-ntdddump-dump_read)

[Dump_Start](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddump/nc-ntdddump-dump_start)

[Dump_Unload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddump/nc-ntdddump-dump_unload)

[Dump_Write](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddump/nc-ntdddump-dump_write)

[FILTER_EXTENSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddump/ns-ntdddump-_filter_extension)