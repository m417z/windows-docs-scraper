# PdhConnectMachineW function

## Description

Connects to the specified computer.

## Parameters

### `szMachineName` [in]

**Null**-terminated string that specifies the name of the computer to connect to. If **NULL**, PDH connects to the local computer.

## Return value

If the function succeeds, it returns ERROR_SUCCESS.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) or a
[PDH error code](https://learn.microsoft.com/windows/desktop/PerfCtrs/pdh-error-codes). The following are possible values.

| Return code | Description |
| --- | --- |
| **PDH_CSTATUS_NO_MACHINE** | Unable to connect to the specified computer. Could be caused by the computer not being on, not supporting PDH, not being connected to the network, or having the permissions set on the registry that prevent remote connections or remote performance monitoring by the user. |
| **PDH_MEMORY_ALLOCATION_FAILURE** | Unable to allocate a dynamic memory block. Occurs when there is a serious memory shortage in the system due to too many applications running on the system or an insufficient memory paging file. |

## Remarks

Typically, applications do not call this function and instead the connection is made when the application adds the counter to the query.

However, you can use this function if you want to include more than the local computer in the **Select counters from computer** list on the **Browse Counters** dialog box. For details, see the [PDH_BROWSE_DLG_CONFIG](https://learn.microsoft.com/windows/win32/api/pdh/ns-pdh-pdh_browse_dlg_config_a) structure.

> [!NOTE]
> The pdh.h header defines PdhConnectMachine as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[PdhEnumMachines](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhenummachinesa)