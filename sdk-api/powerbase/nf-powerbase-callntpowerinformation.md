# CallNtPowerInformation function

## Description

Sets or retrieves power information.

## Parameters

### `InformationLevel` [in]

The information level requested. This value indicates the specific power information to be set or
retrieved. This parameter must be one of the following
**POWER_INFORMATION_LEVEL** enumeration type values.

| Value | Meaning |
| --- | --- |
| **AdministratorPowerPolicy**<br><br>9 | This information level is not supported. |
| **LastSleepTime**<br><br>15 | The *lpInBuffer* parameter must be **NULL**; otherwise, the function returns **ERROR_INVALID_PARAMETER**.<br><br>The *lpOutputBuffer* buffer receives a **ULONGLONG** that specifies the interrupt-time count, in 100-nanosecond units, at the last system sleep time. |
| **LastWakeTime**<br><br>14 | The *lpInBuffer* parameter must be **NULL**; otherwise, the function returns **ERROR_INVALID_PARAMETER**.<br><br>The *lpOutputBuffer* buffer receives a **ULONGLONG** that specifies the interrupt-time count, in 100-nanosecond units, at the last system wake time. |
| **ProcessorInformation**<br><br>11 | The *lpInBuffer* parameter must be **NULL**; otherwise the function returns **ERROR_INVALID_PARAMETER**.<br><br>The *lpOutputBuffer* buffer receives one [PROCESSOR_POWER_INFORMATION](https://learn.microsoft.com/windows/desktop/Power/processor-power-information-str) structure for each processor that is installed on the system. Use the [GetSystemInfo](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getsysteminfo) function to retrieve the number of processors. |
| **ProcessorPowerPolicyAc**<br><br>18 | This information level is not supported. |
| **ProcessorPowerPolicyCurrent**<br><br>22 | This information level is not supported. |
| **ProcessorPowerPolicyDc**<br><br>19 | This information level is not supported. |
| **SystemBatteryState**<br><br>5 | The *lpInBuffer* parameter must be **NULL**; otherwise, the function returns **ERROR_INVALID_PARAMETER**.<br><br>The *lpOutputBuffer* buffer receives a [SYSTEM_BATTERY_STATE structure](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-system_battery_state) containing information about the current system battery. |
| **SystemExecutionState**<br><br>16 | The *lpInBuffer* parameter must be **NULL**; otherwise the function returns **ERROR_INVALID_PARAMETER**.<br><br>The *lpOutputBuffer* buffer receives a **ULONG** value containing the system execution state buffer. This value may contain any combination of the following values: **ES_SYSTEM_REQUIRED**, **ES_DISPLAY_REQUIRED**, or **ES_USER_PRESENT**. For more information, see the [SetThreadExecutionState](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setthreadexecutionstate) function. |
| **SystemPowerCapabilities**<br><br>4 | The *lpInBuffer* parameter must be **NULL**, otherwise, the function returns **ERROR_INVALID_PARAMETER**.<br><br>The *lpOutputBuffer* buffer receives a [SYSTEM_POWER_CAPABILITIES](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-system_power_capabilities) structure containing the current system power capabilities.<br><br>This information represents the currently supported power capabilities. It may change as drivers are installed in the system. For example, installation of legacy device drivers that do not support power management disables all system sleep states. |
| **SystemPowerInformation**<br><br>12 | The *lpInBuffer* parameter must be **NULL**; otherwise, the function returns **ERROR_INVALID_PARAMETER**.<br><br>The *lpOutputBuffer* buffer receives a [SYSTEM_POWER_INFORMATION](https://learn.microsoft.com/windows/desktop/Power/system-power-information-str) structure.<br><br>Applications can use this level to retrieve information about the idleness of the system. |
| **SystemPowerPolicyAc**<br><br>0 | If *lpInBuffer* is not **NULL**, the function applies the [SYSTEM_POWER_POLICY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-system_power_policy) values passed in *lpInBuffer* to the current system power policy used while the system is running on AC (utility) power.<br><br>The *lpOutputBuffer* buffer receives a [SYSTEM_POWER_POLICY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-system_power_policy) structure containing the current system power policy used while the system is running on AC (utility) power. |
| **SystemPowerPolicyCurrent**<br><br>8 | The *lpInBuffer* parameter must be **NULL**; otherwise, the function returns **ERROR_INVALID_PARAMETER**.<br><br>The *lpOutputBuffer* buffer receives a [SYSTEM_POWER_POLICY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-system_power_policy) structure containing the current system power policy used while the system is running on AC (utility) power. |
| **SystemPowerPolicyDc**<br><br>1 | If *lpInBuffer* is not **NULL**, the function applies the [SYSTEM_POWER_POLICY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-system_power_policy) values passed in *lpInBuffer* to the current system power policy used while the system is running on battery power.<br><br>The *lpOutputBuffer* buffer receives a [SYSTEM_POWER_POLICY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-system_power_policy) structure containing the current system power policy used while the system is running on battery power. |
| **SystemReserveHiberFile**<br><br>10 | If *lpInBuffer* is not **NULL** and the current user has sufficient privileges, the function commits or decommits the storage required to hold the hibernation image on the boot volume.<br><br>The *lpInBuffer* parameter must point to a **BOOLEAN** value indicating the desired request. If the value is **TRUE**, the hibernation file is reserved; if the value is **FALSE**, the hibernation file is removed. |
| **VerifyProcessorPowerPolicyAc**<br><br>20 | This information level is not supported. |
| **VerifyProcessorPowerPolicyDc**<br><br>21 | This information level is not supported. |
| **VerifySystemPolicyAc**<br><br>2 | This information level is not supported. |
| **VerifySystemPolicyDc**<br><br>3 | This information level is not supported. |

### `InputBuffer` [in]

A pointer to an optional input buffer. The data type of this buffer depends on the information level
requested in the *InformationLevel* parameter.

### `InputBufferLength` [in]

The size of the input buffer, in bytes.

### `OutputBuffer` [out]

A pointer to an optional output buffer. The data type of this buffer depends on the information level
requested in the *InformationLevel* parameter. If the buffer is too small to contain the
information, the function returns STATUS_BUFFER_TOO_SMALL.

### `OutputBufferLength` [in]

The size of the output buffer, in bytes. Depending on the information level requested, this may be a
variably sized buffer.

## Return value

If the function succeeds, the return value is **STATUS_SUCCESS**.

If the function fails, the return value can be one the following status codes.

| Status | Meaning |
| --- | --- |
| **STATUS_BUFFER_TOO_SMALL** | The output buffer is of insufficient size to contain the data to be returned. |
| **STATUS_ACCESS_DENIED** | The caller had insufficient access rights to perform the requested action. |

## Remarks

Changes made to the current system power policy using
**CallNtPowerInformation** are immediate, but they
are not persistent; that is, the changes are not stored as part of a power scheme. Any changes to system power
policy made with **CallNtPowerInformation** may be
overwritten by changes to a policy scheme made by the user in the Power Options control panel program, or by
subsequent calls to [WritePwrScheme](https://learn.microsoft.com/windows/desktop/api/powrprof/nf-powrprof-writepwrscheme),
[SetActivePwrScheme](https://learn.microsoft.com/windows/desktop/api/powrprof/nf-powrprof-setactivepwrscheme), or other power scheme
functions.

For more information on using PowrProf.h, see [Power
Schemes](https://learn.microsoft.com/windows/desktop/Power/power-schemes).

## See also

[ADMINISTRATOR_POWER_POLICY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-administrator_power_policy)

[PROCESSOR_POWER_INFORMATION](https://learn.microsoft.com/windows/desktop/Power/processor-power-information-str)

[PROCESSOR_POWER_POLICY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-processor_power_policy)

[Power Management Functions](https://learn.microsoft.com/windows/desktop/Power/power-management-functions)

[SYSTEM_BATTERY_STATE structure](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-system_battery_state)

[SYSTEM_POWER_CAPABILITIES](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-system_power_capabilities)

[SYSTEM_POWER_INFORMATION](https://learn.microsoft.com/windows/desktop/Power/system-power-information-str)

[SYSTEM_POWER_POLICY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-system_power_policy)