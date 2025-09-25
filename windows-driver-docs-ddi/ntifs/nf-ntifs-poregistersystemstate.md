# PoRegisterSystemState function (ntifs.h)

## Description

The **PoRegisterSystemState** routine registers the system as busy due to certain activity.

## Parameters

### `StateHandle` [in, out]

A pointer to a caller-supplied buffer for a registration state handle. The size, in bytes, of the buffer is ```sizeof(ULONG)```. If NULL, this is a new registration. If non-NULL, this parameter points to a handle that was returned by a previous call to **PoRegisterSystemState**.

### `Flags` [in]

Indicates the type of activity, as specified by a bitwise OR of one or more of the following values:

| Value | Meaning |
| ----- | ------- |
| ES_SYSTEM_REQUIRED | The system is not idle, regardless of apparent load. |
| ES_DISPLAY_REQUIRED | Use of the display is required. |
| ES_USER_PRESENT | A user is present. |
| ES_CONTINUOUS | The settings are continuous and should remain in effect until explicitly changed. |

## Return value

**PoRegisterSystemState** returns a handle to be used later to change or unregister the system busy state. It returns NULL if the handle could not be allocated.

## Remarks

**PoRegisterSystemState** registers the system busy state as indicated by the flags. The registration persists until the caller explicitly changes it with another call to **PoRegisterSystemState** or cancels it with a call to [**PoUnregisterSystemState**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-pounregistersystemstate).

The **Flags** parameter specifies the type of activity in progress. Drivers can specify any combination of the flags.

Setting ES_CONTINUOUS makes the busy state persist until a driver explicitly changes or cancels it by calling **PoRegisterSystemState** or **PoUnregisterSystemState**.

A driver can set the system busy state to request that the [power manager](https://learn.microsoft.com/windows-hardware/drivers/kernel/power-manager) avoid system power state transitions out of the system working state (S0) while driver activity is occurring. Note, however, that under some circumstances (such as a critically low battery) the power manager may override this request and put the system to sleep anyway.

To set the system power state, call [**PoSetSystemState**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-posetsystemstate).

## See also

[**PoSetSystemState**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-posetsystemstate)

[**PoUnregisterSystemState**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-pounregistersystemstate)