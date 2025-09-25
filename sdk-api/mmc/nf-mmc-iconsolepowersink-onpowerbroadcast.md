# IConsolePowerSink::OnPowerBroadcast

## Description

The
**OnPowerBroadcast** method processes
[WM_POWERBROADCAST](https://learn.microsoft.com/windows/desktop/Power/wm-powerbroadcast) notification messages related to the computer's power management.

## Parameters

### `nEvent` [in]

The power broadcast event identifier. The identifier is one of the following values.

#### PBT_APMBATTERYLOW

Battery power is low.

#### PBT_APMOEMEVENT

OEM-defined event occurred.

#### PBT_APMPOWERSTATUSCHANGE

Power status has changed.

#### PBT_APMQUERYSUSPEND

Request for permission to suspend.

#### PBT_APMQUERYSUSPENDFAILED

Suspension request denied.

#### PBT_APMRESUMEAUTOMATIC

Operation resuming automatically after event.

#### PBT_APMRESUMECRITICAL

Operation resuming after critical suspension.

#### PBT_APMRESUMESUSPEND

Operation resuming after suspension.

#### PBT_APMSUSPEND

System is suspending operation.

### `lParam` [in]

Function-specific data. For most events, this parameter is reserved and not used. However, if *nEvent* is one of the resume events (PBT_APMRESUME*), the *lParam* parameter can specify the PBTF_APMRESUMEFROMFAILURE flag. This flag indicates that a suspend operation failed after the [PBT_APMSUSPEND](https://learn.microsoft.com/windows/desktop/Power/pbt-apmsuspend) event was broadcast.

### `plReturn` [out]

On return, the snap-in's response to the broadcast event. Generally, set **plReturn* to **TRUE**. The exception is when *nEvent* is
[PBT_APMQUERYSUSPEND](https://learn.microsoft.com/windows/desktop/Power/pbt-apmquerysuspend). To allow the computer suspension to continue in response to the PBT_APMQUERYSUSPEND event, set **plReturn* to **TRUE**; to deny the computer suspension, set **plReturn* to BROADCAST_QUERY_DENY. A snap-in that permits computer suspension should perform necessary suspension preparations before returning from this method.

## Return value

If successful, the return value is S_OK. Other return values indicate an error code.

## See also

[WM_POWERBROADCAST](https://learn.microsoft.com/windows/desktop/Power/wm-powerbroadcast)