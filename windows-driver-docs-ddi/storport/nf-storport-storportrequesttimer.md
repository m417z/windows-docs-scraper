# StorPortRequestTimer function

## Description

Schedules a callback event for a Storport timer context object.

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension for the host bus adapter (HBA).

### `TimerHandle` [in]

A pointer to an opaque buffer for the timer context returned by [StorPortInitializeTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitializetimer).

### `TimerCallback` [in]

A pointer to a timer callback routine supplied by the miniport. The following is the prototype defined for **PHW_TIMER_EX**:

```
typedef
VOID
(*PHW_TIMER_EX) (
  _In_ PVOID  DeviceExtension,
  _In_opt_ PVOID Context
  );
```

### `CallbackContext` [in, optional]

A pointer to a miniport provided context for the timer callback.

### `TimerValue` [in]

The timeout value for the timer, in microseconds. Setting *TimerValue* to 0 will cancel the timer.

### `TolerableDelay` [in]

The allowable delay for the timer in microseconds. Values less than 32 microseconds are ignored and *TolerableDelay* defaults to 0.

## Return value

The **StorPortRequestTimer** routine returns one of these status codes:

| Return code | Description |
| --- | --- |
| **STOR_STATUS_INSUFFICIENT_RESOURCES** | Not enough resources available to defer scheduling of the timer. |
| **STOR_STATUS_INVALID_PARAMETER** | *HwDeviceExtension*, *TimerHandle*, or *TimerCallback* is NULL.<br><br>The timer context object, *TimerHandle*, is invalid. |
| **STOR_STATUS_BUSY** | A previous timer request is active. *TimerValue* > 0 and *TimerCallback* has not been called. |
| **STOR_STATUS_SUCCESS** | The timer request was successfully scheduled. |

## Remarks

The **StorPortRequestTimer** routine is callable at any IRQL. However, if the routine is called when IRQL > DISPATCH_LEVEL, the timer's scheduling is deferred until IRQL <= DISPATCH_LEVEL.

## See also

[HwStorTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_timer)

[StorPortFreeTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportfreetimer)

[StorPortInitializeTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitializetimer)

[StorPortNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportnotification)