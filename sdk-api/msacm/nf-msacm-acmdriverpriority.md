# acmDriverPriority function

## Description

The **acmDriverPriority** function modifies the priority and state of an ACM driver.

## Parameters

### `hadid`

Handle to the driver identifier of an installed ACM driver. If the ACM_DRIVERPRIORITYF_BEGIN and ACM_DRIVERPRIORITYF_END flags are specified, this parameter must be **NULL**.

### `dwPriority`

New priority for a global ACM driver identifier. A zero value specifies that the priority of the driver identifier should remain unchanged. A value of 1 specifies that the driver should be placed as the highest search priority driver. A value of –1 specifies that the driver should be placed as the lowest search priority driver. Priorities are used only for global drivers.

### `fdwPriority`

Flags for setting priorities of ACM drivers. The following values are defined.

| Value | Meaning |
| --- | --- |
| ACM_DRIVERPRIORITYF_BEGIN | Change notification broadcasts should be deferred. An application must reenable notification broadcasts as soon as possible with the ACM_DRIVERPRIORITYF_END flag. Note that *hadid* must be **NULL**, *dwPriority* must be zero, and only the ACM_DRIVERPRIORITYF_BEGIN flag can be set. |
| ACM_DRIVERPRIORITYF_DISABLE | ACM driver should be disabled if it is currently enabled. Disabling a disabled driver does nothing. |
| ACM_DRIVERPRIORITYF_ENABLE | ACM driver should be enabled if it is currently disabled. Enabling an enabled driver does nothing. |
| ACM_DRIVERPRIORITYF_END | Calling task wants to reenable change notification broadcasts. An application must call **acmDriverPriority** with ACM_DRIVERPRIORITYF_END for each successful call with the ACM_DRIVERPRIORITYF_BEGIN flag. Note that *hadid* must be **NULL**, *dwPriority* must be zero, and only the ACM_DRIVERPRIORITYF_END flag can be set. |

## Return value

Returns zero if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **MMSYSERR_ALLOCATED** | The deferred broadcast lock is owned by a different task. |
| **MMSYSERR_INVALFLAG** | At least one flag is invalid. |
| **MMSYSERR_INVALHANDLE** | The specified handle is invalid. |
| **MMSYSERR_INVALPARAM** | At least one parameter is invalid. |
| **MMSYSERR_NOTSUPPORTED** | The requested operation is not supported for the specified driver. For example, local and notify driver identifiers do not support priorities (but can be enabled and disabled). If an application specifies a nonzero value for *dwPriority* for local and notify driver identifiers, this error will be returned. |

## Remarks

All driver identifiers can be enabled and disabled, including global, local and notification driver identifiers.

If more than one global driver identifier needs to be enabled, disabled or shifted in priority, an application should defer change notification broadcasts by using the ACM_DRIVERPRIORITYF_BEGIN flag. A single change notification will be broadcast when the ACM_DRIVERPRIORITYF_END flag is specified.

An application can use the function with the **acmMetrics** ACM_METRIC_DRIVER_PRIORITY metric index to retrieve the current priority of a global driver. Drivers are always enumerated from highest to lowest priority by the **acmDriverEnum** function.

All enabled driver identifiers will receive change notifications. An application can register a notification message by using the **acmDriverAdd** function in conjunction with the ACM_DRIVERADDF_NOTIFYHWND flag. Changes to nonglobal driver identifiers will not be broadcast.

Priorities are simply used for the search order when an application does not specify a driver. Boosting the priority of a driver will have no effect on the performance of a driver.

## See also

[Audio Compression Functions](https://learn.microsoft.com/windows/desktop/Multimedia/audio-compression-functions)

[Audio Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/audio-compression-manager)