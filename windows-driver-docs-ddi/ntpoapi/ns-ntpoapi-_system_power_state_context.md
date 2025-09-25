# _SYSTEM_POWER_STATE_CONTEXT structure (ntpoapi.h)

## Description

The **SYSTEM_POWER_STATE_CONTEXT** structure is a partially opaque system structure that contains information about the previous system power states of a computer.

## Members

### `DUMMYUNIONNAME`

Unnamed union.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME`

Unnamed structure.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.Reserved1`

Opaque member. Reserved for system use.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.TargetSystemState`

The target system power state of the previous [system power IRP](https://learn.microsoft.com/windows-hardware/drivers/kernel/power-irps-for-the-system) that the driver received. This member is set to a [SYSTEM_POWER_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_system_power_state) enumeration value. Drivers should treat this member as read-only.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.EffectiveSystemState`

The effective previous system power state, as perceived by the user. This member is set to a **SYSTEM_POWER_STATE** enumeration value. Drivers should treat this member as read-only. This member value might not match the **TargetSystemState** member if, for example, the previous system power IRP indicated that the computer was about to enter hibernation, but a hybrid shutdown instead occurred to prepare the computer for a fast startup. For more information, see Remarks.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.CurrentSystemState`

Opaque member. Reserved for system use.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.IgnoreHibernationPath`

Opaque member. Reserved for system use.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.PseudoTransition`

Opaque member. Reserved for system use.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.KernelSoftReboot`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.DirectedDripsTransition`

a Directed DRIPS transition.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.Reserved2`

Opaque member. Reserved for system use.

### `DUMMYUNIONNAME.ContextAsUlong`

Opaque member. Reserved for system use.

## Remarks

Starting with Windows Vista, the [I/O stack location](https://learn.microsoft.com/windows-hardware/drivers/kernel/i-o-stack-locations) in a [system power IRP](https://learn.microsoft.com/windows-hardware/drivers/kernel/power-irps-for-the-system) contains a **SYSTEM_POWER_STATE_CONTEXT** structure. The **Power** member of the **IO_STACK_LOCATION** structure contains a **SystemPowerStateContext** member, which is a **SYSTEM_POWER_STATE_CONTEXT** structure. For more information, see [IO_STACK_LOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_stack_location).

The size of the **SYSTEM_POWER_STATE_CONTEXT** structure is four bytes. This structure is divided into bit fields, most of which are opaque to drivers and reserved exclusively for use by the operating system. However, two of these bit fields, **TargetSystemState** and **EffectiveSystemState**, can be read by kernel-mode drivers to distinguish a fast startup from a wake-from-hibernation startup. For more information, see [Distinguishing Fast Startup from Wake-from-Hibernation](https://learn.microsoft.com/windows-hardware/drivers/kernel/distinguishing-fast-startup-from-wake-from-hibernation).

## See also

[IO_STACK_LOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_stack_location)

[SYSTEM_POWER_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_system_power_state)