# _WDF_INTERRUPT_CONFIG structure

## Description

[Applies to KMDF and UMDF]

The **WDF_INTERRUPT_CONFIG** structure contains configuration information for a device interrupt.

## Members

### `Size`

The size, in bytes, of this structure.

### `SpinLock`

The handle to a framework spin-lock object, obtained by a previous call to [WdfSpinLockCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfsync/nf-wdfsync-wdfspinlockcreate), or **NULL**. If this parameter is **NULL**, the framework uses an internal spin-lock object. The framework acquires the spin lock before it calls the driver's [EvtInterruptSynchronize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_synchronize) event callback function and when the driver calls [WdfInterruptAcquireLock](https://learn.microsoft.com/previous-versions/ff547340(v=vs.85)). For passive-level interrupt handling, set to NULL.

Starting with UMDF version 2.0, UMDF always uses passive-level interrupt handling. In this case, set this member to NULL.

### `ShareVector`

A [WDF_TRI_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftypes/ne-wdftypes-_wdf_tri_state)-typed value. If this value is **WdfTrue**, the interrupt vector can be shared. If the value is **WdfFalse**, the interrupt vector cannot be shared. If the value is **WdfDefault**, the PnP manager uses the bus driver's value.

### `FloatingSave`

A Boolean value that, if **TRUE**, indicates that the system will save the processor's floating point and MMX state when the device interrupts. If **FALSE**, the system does not save the floating point and MMX state. A driver should set this value to **TRUE** only if its [EvtInterruptIsr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_isr) callback function must use floating point or MMX registers. For more information about saving floating point and MMX state, see [Using Floating Point or MMX in a WDM Driver](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-floating-point-or-mmx-in-a-wdm-driver).

This member is ignored starting in UMDF version 2.0.

### `AutomaticSerialization`

A Boolean value that, if **TRUE**, indicates that the framework will synchronize execution of the interrupt object's [EvtInterruptDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_dpc) or [EvtInterruptWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_workitem) callback function with callback functions from other objects that are underneath the interrupt's parent object. For more information, see the following Remarks section.

### `EvtInterruptIsr`

A pointer to the driver's [EvtInterruptIsr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_isr) callback function. This pointer cannot be **NULL**.

### `EvtInterruptDpc`

A pointer to the driver's [EvtInterruptDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_dpc) callback function, or **NULL**. The driver can provide [EvtInterruptWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_workitem) or *EvtInterruptDpc*, but not both.

### `EvtInterruptEnable`

A pointer to the driver's [EvtInterruptEnable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_enable) callback function, or **NULL**.

### `EvtInterruptDisable`

A pointer to the driver's [EvtInterruptDisable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_disable) callback function, or **NULL**.

### `EvtInterruptWorkItem`

A pointer to the driver's [EvtInterruptWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_workitem) callback function, or **NULL**. The driver can provide *EvtInterruptWorkItem* or [EvtInterruptDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_dpc), but not both. The **EvtInterruptWorkItem** member is available in version 1.11 and later versions of KMDF.

### `InterruptRaw`

A pointer to the [CM_PARTIAL_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_partial_resource_descriptor) structure that describes the [raw resources](https://learn.microsoft.com/windows-hardware/drivers/wdf/raw-and-translated-resources) that the system assigned to the interrupt. This member is only used if the interrupt is created in the [EvtDevicePrepareHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware) callback. The **InterruptRaw** member is available in version 1.11 and later versions of KMDF.

### `InterruptTranslated`

A pointer to the [CM_PARTIAL_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_partial_resource_descriptor) structure that describes the [translated resources](https://learn.microsoft.com/windows-hardware/drivers/wdf/raw-and-translated-resources) that the system assigned to the interrupt. This member is only used if the interrupt is created in the [EvtDevicePrepareHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware) callback. The **InterruptTranslated** member is available in version 1.11 and later versions of KMDF.

### `WaitLock`

A handle to a framework wait-lock object, obtained by a previous call to [WdfWaitLockCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfsync/nf-wdfsync-wdfwaitlockcreate), or **NULL**. If **WaitLock** is non-**NULL**, **PassiveHandling** must be set to **TRUE**. The **WaitLock** member is available in version 1.11 and later versions of KMDF. For more information about **WaitLock**, see **Remarks**.

### `PassiveHandling`

Set to **FALSE** for interrupt handling at the device's IRQL (DIRQL).
Set to **TRUE** for passive-level interrupt handling.
The **PassiveHandling** member is available in version 1.11 and later versions of KMDF. Starting in UMDF version 2.0, [WDF_INTERRUPT_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdf_interrupt_config_init) always sets this member to TRUE.

### `ReportInactiveOnPowerDown`

This member applies to KMDF only.

 A [WDF_TRI_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftypes/ne-wdftypes-_wdf_tri_state)-typed value that applies only if the driver has not called [WdfDeviceInitSetPowerNotPageable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetpowernotpageable). This member can have one of the following values:

**WdfTrue** - KMDF reports the interrupt inactive when the device transitions to a low-power (Dx) state. In operating systems prior to Windows 8, the framework's behavior matches that described for **WdfFalse**.

**Note** If **CanWakeDevice** is set to **TRUE** and **ReportInactiveOnPowerDown** is set to **WdfTrue**, the framework does not report the interrupt inactive when the device transitions to a low-power state.

**WdfFalse** - KMDF disconnects the interrupt when the device transitions to a low-power (Dx) state.

**WdfDefault** - On ARM-based platforms, the framework's behavior matches that described for **WdfTrue**. On other platforms, the framework's behavior matches that described for **WdfFalse**.

The **ReportInactiveOnPowerDown** member is available in version 1.11 and later versions of KMDF. It is not available in UMDF version 2.0.

For more information about reporting an interrupt inactive, see [Making an ISR Active or Inactive](https://learn.microsoft.com/windows-hardware/drivers/kernel/making-an-isr-active-or-inactive).

### `CanWakeDevice`

A Boolean value that indicates whether the interrupt is used to wake the device from a low-power state.
If **FALSE**, the interrupt is not used to wake the device. If **TRUE**, the interrupt is used to wake the device.
The **CanWakeDevice** member is available starting in KMDF version 1.13 and UMDF version 2.0.

## Remarks

The **WDF_INTERRUPT_CONFIG** structure is used as input to [WdfInterruptCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdfinterruptcreate).

To initialize a **WDF_INTERRUPT_CONFIG** structure, your driver must first call [WDF_INTERRUPT_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdf_interrupt_config_init) and then fill in structure members that **WDF_INTERRUPT_CONFIG_INIT** does not initialize.

If **AutomaticSerialization** is TRUE, the following rules apply:

* If the execution level of the interrupt's parent object is **WdfExecutionLevelPassive**, the driver can supply [EvtInterruptWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_workitem), but should not supply [EvtInterruptDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_dpc) in this configuration structure.
* If the execution level of the interrupt's parent object is **WdfExecutionLevelDispatch**, the driver can supply [EvtInterruptDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_dpc), but should not supply [EvtInterruptWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_workitem) in this configuration structure. In this second case, the interrupt object itself can still be passive.

The driver can use this structure's **WaitLock** member to provide its own interrupt lock for [passive-level interrupt handling](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-passive-level-interrupts). If the driver sets **PassiveHandling** to TRUE but not does provide a **WaitLock**, the framework creates an interrupt lock internally. The framework acquires the passive-level interrupt lock before calling the following callback functions:

[EvtInterruptEnable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_enable)

[EvtInterruptDisable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_disable)

[EvtInterruptSynchronize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_synchronize)

[EvtInterruptIsr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_isr)

For more information about **AutomaticSerialization** and synchronizing driver callback functions, see [Synchronization Techniques for Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/synchronization-techniques-for-wdf-drivers).

By default, KMDF function drivers are power pageable. A driver calls [WdfDeviceInitSetPowerNotPageable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetpowernotpageable)
to specify that it is non-power pageable.

In KMDF versions earlier than 1.11, the framework always disconnects interrupts of power pageable drivers when the device transitions into a low-power (Dx) state. Starting in KMDF version 1.11, you can change this behavior by setting the **ReportInactiveOnPowerDown** member of this structure. For non-power pageable drivers, interrupts remain connected when Dx state transitions occur, regardless of the value set in **ReportInactiveOnPowerDown**.

If a UMDF driver sets **ReportInactiveOnPowerDown**, the value is ignored.

For more information about handling interrupts in framework-based drivers, see [Handling Hardware Interrupts](https://learn.microsoft.com/windows-hardware/drivers/wdf/handling-hardware-interrupts).

The driver can use this structure's **CanWakeDevice** member to create an interrupt that can be used to bring the device from a low-power Dx state back to D0. The driver's [EvtInterruptIsr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_isr) callback routine is scheduled to run at IRQL = PASSIVE_LEVEL after the device enters D0.

For more information, see [Using an Interrupt to Wake a Device](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-an-interrupt-to-wake-a-device).

## See also

[EvtInterruptDisable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_disable)

[EvtInterruptDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_dpc)

[EvtInterruptEnable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_enable)

[EvtInterruptIsr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_isr)

[WDF_INTERRUPT_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdf_interrupt_config_init)

[WDF_TRI_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftypes/ne-wdftypes-_wdf_tri_state)

[WdfDeviceInitSetPowerNotPageable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetpowernotpageable)

[WdfDeviceInitSetPowerPageable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetpowerpageable)

[WdfInterruptCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdfinterruptcreate)

[WdfInterruptQueueDpcForIsr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdfinterruptqueuedpcforisr)

[WdfSpinLockCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfsync/nf-wdfsync-wdfspinlockcreate)