# TimeProvCommand function

## Description

A callback function that is called by the time provider manager to send commands to the time provider.

## Parameters

### `hTimeProv` [in]

A handle to the time provider. The
[TimeProvOpen](https://learn.microsoft.com/windows/desktop/api/timeprov/nf-timeprov-timeprovopen) function receives this handle.

### `eCmd` [in]

The command to be sent. This parameter can be one of the following values.

| Command | Meaning |
| --- | --- |
| **TPC_GetSamples** | The time provider should return the time samples it has collected. If there is no data available, the provider should return no samples. For more details, see Remarks. <br><br>The *pvArgs* parameter is pointer to a [TpcGetSamplesArgs](https://learn.microsoft.com/windows/desktop/api/timeprov/ns-timeprov-tpcgetsamplesargs) structure. The time provider manager provides the buffer for the samples. If the *pvArgs* buffer if too small, the provider should provide as many samples as is can and return ERROR_INSUFFICIENT_BUFFER. Any other error codes returned by the provider are ignored. |
| **TPC_NetTopoChange** | The network topology has changed. Network providers must redetect the network settings and verify that they can reach their sources. <br><br>The *pvArgs* parameter indicates whether the change was requested by the user (NTC_UserRequested) or the system (NTC_Default). |
| **TPC_Query** | Reserved for future use. |
| **TPC_PollIntervalChanged** | The polling interval has changed. The time provider should call the [GetTimeSysInfo](https://learn.microsoft.com/windows/desktop/api/timeprov/nc-timeprov-gettimesysinfofunc) function to retrieve the new value. <br><br>The *pvArgs* parameter is not used. Any error returned by the provider is ignored. |
| **TPC_Shutdown** | The system is shutting down. The time provider should exit within five seconds. <br><br>The *pvArgs* parameter is not used. |
| **TPC_TimeJumped** | The system clock was adjusted abruptly, so the time provider should discard any time stamps it has saved. <br><br>The *pvArgs* parameter indicates whether the time jump was requested by the user (TJF_UserRequested) or the system (TJF_Default). |
| **TPC_UpdateConfig** | The time provider should verify whether its application-specific configuration data stored in the registry has changed. <br><br>The *pvArgs* parameter is not used. Any error returned by the provider is ignored. |

### `pvArgs` [in]

A pointer to a buffer that specifies command information. The format of this data depends on the value of *eCmd*.

## Return value

If the function succeeds, the return value is S_OK. Otherwise, the return value is one of the error codes defined in WinError.h.

## Remarks

The time provider should never take longer than half a second to return from this call.

When processing the TPC_GetSamples command, the provider should return one sample for each source it is monitoring. Therefore, a hardware provider should return one sample, while a network provider like NTP can return multiple samples. The provider should not return multiple samples from a single source; it should return the best sample from its cache of samples for the source. The provider can return the same sample on subsequent calls, provided that the data has not changed.

#### Examples

For an example, see [Sample Time Provider](https://learn.microsoft.com/windows/desktop/SysInfo/sample-time-provider).

## See also

[GetTimeSysInfoFunc](https://learn.microsoft.com/windows/desktop/api/timeprov/nc-timeprov-gettimesysinfofunc)

[TimeProvOpen](https://learn.microsoft.com/windows/desktop/api/timeprov/nf-timeprov-timeprovopen)

[TpcGetSamplesArgs](https://learn.microsoft.com/windows/desktop/api/timeprov/ns-timeprov-tpcgetsamplesargs)