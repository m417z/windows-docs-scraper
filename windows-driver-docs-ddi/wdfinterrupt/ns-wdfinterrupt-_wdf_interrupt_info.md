# _WDF_INTERRUPT_INFO structure (wdfinterrupt.h)

## Description

[Applies to KMDF and UMDF]

The **WDF_INTERRUPT_INFO** structure contains information about a device's interrupt resource.

## Members

### `Size`

The size, in bytes, of this structure.

### `Reserved1`

This member is reserved for future use.

### `TargetProcessorSet`

A [**KAFFINITY**](https://learn.microsoft.com/windows-hardware/drivers/kernel/interrupt-affinity-and-priority#about-kaffinity)-typed value that specifies the interrupt's processor affinity.

### `Reserved2`

This member is reserved for future use.

### `MessageNumber`

If the **MessageSignaled** member is **TRUE**, this is the interrupt's message number.

### `Vector`

The interrupt vector.

### `Irql`

The IRQL at which the device interrupts.

### `Mode`

A [KINTERRUPT_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_kinterrupt_mode)-typed enumerator that indicates whether the interrupt is level-triggered or edge-triggered.

### `Polarity`

A [WDF_INTERRUPT_POLARITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/ne-wdfinterrupt-_wdf_interrupt_polarity)-typed enumerator that identifies the interrupt signal's polarity.

### `MessageSignaled`

A Boolean value that, if **TRUE**, indicates that the interrupt is message-signaled. If **FALSE**, the interrupt is not message-signaled.

### `ShareDisposition`

A CM_SHARE_DISPOSITION-typed enumerator that indicates whether the interrupt is being shared. The value is **CmResourceShareShared** if the interrupt is being shared or **CmResourceShareDeviceExclusive** if the interrupt is not being shared. The CM_SHARE_DISPOSITION enumeration type is defined in *Wdm.h*.

### `Group`

A value that identifies the processor group that the **TargetProcessorSet** member applies to. This value is zero if the computer has only one processor group or if the operating system does not support processor groups. The **Group** member is available in version 1.9 and later versions of KMDF.

## Remarks

The **WDF_INTERRUPT_INFO** structure is used as input to the [WdfInterruptGetInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdfinterruptgetinfo) method. To initialize a **WDF_INTERRUPT_INFO** structure, your driver should call [WDF_INTERRUPT_INFO_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdf_interrupt_info_init) before calling **WdfInterruptGetInfo**.

## See also

[**KAFFINITY**](https://learn.microsoft.com/windows-hardware/drivers/kernel/interrupt-affinity-and-priority#about-kaffinity)

[KINTERRUPT_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_kinterrupt_mode)

[WDF_INTERRUPT_INFO_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdf_interrupt_info_init)

[WDF_INTERRUPT_POLARITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/ne-wdfinterrupt-_wdf_interrupt_polarity)

[WdfInterruptGetInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdfinterruptgetinfo)