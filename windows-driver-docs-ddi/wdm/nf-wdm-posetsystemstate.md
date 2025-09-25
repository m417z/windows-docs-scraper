# PoSetSystemState function

## Description

Drivers call the **PoSetSystemState** routine to indicate that the system is active.

## Parameters

### `Flags` [in]

Indicates the system activity, as specified by a bitwise OR of one or more of the following values:

#### ES_SYSTEM_REQUIRED

The system is not idle, regardless of apparent load.

#### ES_DISPLAY_REQUIRED

Use of the display is required.

#### ES_USER_PRESENT

A user is present.

## Remarks

A driver calls **PoSetSystemState** to set flags indicating that system activity is occurring. Unlike [PoRegisterSystemState](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-poregistersystemstate), this routine does not allow the driver to set a persistent busy state.

The *Flags* parameter specifies the type of activity occurring. Drivers can specify any combination of the flags.

Drivers can set the system busy state to request that the system avoid leaving of the working state while driver activity is occurring. Note, however, that under some circumstances (such as a critically low battery) the [power manager](https://learn.microsoft.com/windows-hardware/drivers/kernel/power-manager) may override this request and put the system to sleep anyway.

## See also

[PoRegisterSystemState](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-poregistersystemstate)

[PoUnregisterSystemState](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-pounregistersystemstate)