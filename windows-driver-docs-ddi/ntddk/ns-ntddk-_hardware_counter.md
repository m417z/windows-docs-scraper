# _HARDWARE_COUNTER structure

## Description

The **HARDWARE_COUNTER** structure contains information about a hardware counter.

## Members

### `Type`

Specifies the type of the hardware counter. Set this member to the following [HARDWARE_COUNTER_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ne-ntddk-_hardware_counter_type) enumeration value:

* **PMCCounter**

### `Reserved`

Reserved for use by the operating system. Initialize this member to zero.

### `Index`

Specifies the hardware counter index. Each hardware counter in a performance monitoring unit (PMU) for a processor is identified by an index.

## Remarks

This structure is used by the [KeQueryHardwareCounterConfiguration](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kequeryhardwarecounterconfiguration) and [KeSetHardwareCounterConfiguration](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kesethardwarecounterconfiguration) routines.

The **Type** member specifies the type of hardware counter that is described by the structure. In Windows 7, the only defined hardware counter type is **PMCCounter**, which is a performance monitor counter. This type of counter is used by thread-profiling applications.

## See also

[HARDWARE_COUNTER_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ne-ntddk-_hardware_counter_type)

[KeQueryHardwareCounterConfiguration](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kequeryhardwarecounterconfiguration)

[KeSetHardwareCounterConfiguration](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kesethardwarecounterconfiguration)