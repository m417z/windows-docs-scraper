# MINIDUMP_MISC_INFO_2 structure

## Description

Represents information in the miscellaneous information stream.

## Members

### `SizeOfInfo`

The size of the structure, in bytes.

### `Flags1`

The flags that indicate the valid members of this structure. This member can be one or more of the
following values.

| Value | Meaning |
| --- | --- |
| **MINIDUMP_MISC1_PROCESS_ID**<br><br>0x00000001 | **ProcessId** is used. |
| **MINIDUMP_MISC1_PROCESS_TIMES**<br><br>0x00000002 | **ProcessCreateTime**, **ProcessKernelTime**, and **ProcessUserTime** are used. |
| **MINIDUMP_MISC1_PROCESSOR_POWER_INFO**<br><br>0x00000004 | **ProcessorMaxMhz**, **ProcessorCurrentMhz**, **ProcessorMhzLimit**, **ProcessorMaxIdleState**, and **ProcessorCurrentIdleState** are used. |

### `ProcessId`

The identifier of the process. If **Flags1** does not specify
**MINIDUMP_MISC1_PROCESS_ID**, this member is unused.

### `ProcessCreateTime`

The creation time of the process, in **time_t** format. If
**Flags1** does not specify **MINIDUMP_MISC1_PROCESS_TIMES**, this
member is unused.

### `ProcessUserTime`

The time the process has executed in user mode, in seconds. The time that each of the threads of the
process has executed in user mode is determined, then all these times are summed to obtain this value. If
**Flags1** does not specify **MINIDUMP_MISC1_PROCESS_TIMES**, this
member is unused.

### `ProcessKernelTime`

The time the process has executed in kernel mode, in seconds. The time that each of the threads of the
process has executed in kernel mode is determined, then all these times are summed to obtain this value. If
**Flags1** does not specify **MINIDUMP_MISC1_PROCESS_TIMES**, this
member is unused.

### `ProcessorMaxMhz`

The maximum specified clock frequency of the system processor, in MHz. If **Flags1**
does not specify **MINIDUMP_MISC1_PROCESSOR_POWER_INFO**, this member is unused.

### `ProcessorCurrentMhz`

The processor clock frequency, in MHz. This number is the maximum specified processor clock frequency
multiplied by the current processor throttle. If **Flags1** does not specify
**MINIDUMP_MISC1_PROCESSOR_POWER_INFO**, this member is unused.

### `ProcessorMhzLimit`

The limit on the processor clock frequency, in MHz. This number is the maximum specified processor clock
frequency multiplied by the current processor thermal throttle limit. If **Flags1** does
not specify **MINIDUMP_MISC1_PROCESSOR_POWER_INFO**, this member is unused.

### `ProcessorMaxIdleState`

The maximum idle state of the processor. If **Flags1** does not specify
**MINIDUMP_MISC1_PROCESSOR_POWER_INFO**, this member is unused.

### `ProcessorCurrentIdleState`

The current idle state of the processor. If **Flags1** does not specify
**MINIDUMP_MISC1_PROCESSOR_POWER_INFO**, this member is unused.

## See also

[MINIDUMP_STREAM_TYPE](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/ne-minidumpapiset-minidump_stream_type)