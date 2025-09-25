# StorPortInitializeTimer function

## Description

Creates a Storport timer context object.

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension for the host bus adapter (HBA).

### `TimerHandle` [out]

A pointer to an opaque buffer that holds context information for the timer.

## Return value

The **StorPortInitializeTimer** routine returns one of these status codes:

| Return code | Description |
| --- | --- |
| **STOR_STATUS_INVALID_IRQL** | Current IRQL > DISPATCH_LEVEL. |
| **STOR_STATUS_INVALID_PARAMETER** | Either *HwDeviceExtension* or *TimerHandle* is NULL. |
| **STOR_STATUS_INSUFFICIENT_RESOURCES** | Insufficient resources are available to initialize the timer context. |
| **STOR_STATUS_SUCCESS** | The timer context was successfully initialized. |
| **STOR_STATUS_UNSUCCESSFUL** | The number of supported timers is exceeded. |

## Remarks

Storport provides a single timer to a miniport driver by using the **RequestTimerCall** notification type in [StorPortNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportnotification). If a miniport requires more than one timer, additional timers are created with **StorPortInitializeTimer**.

It is recommended that miniports call **StorPortInitializeTimer** in the [HwStorFindAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_find_adapter) function to ensure that the additional timer resources are available.

Miniports can use this routine to set coalescing timers to create a delay period after an initial timeout.

Prior to Windows 8, a maximum of 4 timers can be created with **StorPortInitializeTimer**.
Starting with Windows 8, there is no maximum timers limitation.

## See also

[HwStorFindAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_find_adapter)

[StorPortFreeTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportfreetimer)

[StorPortNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportnotification)

[StorPortRequestTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportrequesttimer)