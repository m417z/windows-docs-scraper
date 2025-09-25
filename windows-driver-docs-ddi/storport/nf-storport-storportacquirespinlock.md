# StorPortAcquireSpinLock function

## Description

The **StorPortAcquireSpinLock** routine acquires the specified spin lock.

## Parameters

### `DeviceExtension` [in]

A pointer to the miniport driver per-adapter device extension.

### `SpinLock` [in]

Specifies an enumerator value of type [**STOR_SPINLOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ne-storport-_stor_spinlock) that specifies the spin lock to acquire. For this function, **SpinLock** must be one of: **DpcLock**, **StartIoLock**, or **InterruptLock**. Call [**StorportAcquireSpinLockEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportacquirespinlockex) to acquire other types of spin locks.

### `LockContext` [in]

A pointer to the DPC object for which the lock is held if **SpinLock** is set to **DpcLock**. This member should be NULL if **SpinLock** indicates a type of either **InterruptLock** or **StartIoLock**.

### `LockHandle` [in/out]

A pointer to a buffer that, on return, will contain a lock handle. To release the lock, the caller must pass this handle to the [**StorPortReleaseSpinLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportreleasespinlock) routine.

## Remarks

Miniport drivers must ensure that they do not attempt to acquire a lock that is already held or acquire locks in an incorrect order. Either of these mistakes will result in system deadlock.

Certain locks are held automatically by the port driver before it calls the miniport driver callback routines. For each miniport driver callback routine, the following table indicates which locks the port driver acquires automatically before calling the callback routine.

| Miniport driver routine | Spin lock held by port driver |
| ----------------------- | ----------------------------- |
| [**HwStorFindAdapter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_find_adapter) | None |
| [**HwStorInitialize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_initialize) | Interrupt (physical miniports), None (virtual miniports) |
| [**HwStorInterrupt**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_interrupt) | Interrupt |
| [**HwMSIInterruptRoutine**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_message_signaled_interrupt_routine) | Interrupt |
| [**HwStorStartIo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_startio) | StartIo (physical miniports only when requested concurrent channels <= 1) |
| [**HwStorBuildIo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_buildio) | None |
| [**HwStorTimer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_timer) | Startio, Interrupt (when **SynchronizationModel** member of [**PORT_CONFIGURATION_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_port_configuration_information) is set to **StorSynchronizeHalfDuplex**) |
| [**HwStorResetBus**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_reset_bus) | Startio, Interrupt (when **SynchronizationModel** member of [**PORT_CONFIGURATION_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_port_configuration_information) is set to **StorSynchronizeHalfDuplex**) |
| [**HwStorAdapterControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_adapter_control) | None. (In Windows Server 2003, the StartIo spin lock was held when control type is ScsiStopAdapter.) |
| [**HwStorUnitControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_unit_control) | None |
| [**HwStorTracingEnabled**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_tracing_enabled) | None |
| [**HwStorPassiveInitializeRoutine**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_passive_initialize_routine) | None |
| [**HwStorDpcRoutine**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_dpc_routine) | None |
| [**HwStorStateChange**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_state_change) | Startio, Interrupt (when **SynchronizationModel** member of [**PORT_CONFIGURATION_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_port_configuration_information) is set to **StorSynchronizeHalfDuplex**) |

The locks held by the port driver influence which locks the callback routines are allowed to acquire, because spin locks must be acquired in the following order:

* DPC or StartIo
* Interrupt

For instance, if the port driver acquires the *Interrupt* spin lock before calling a callback routine, that callback routine can no longer acquire the *DPC* or *StartIo* spin lock because the *DPC* and *StartIo* spin locks are of a lower order than the *Interrupt* spin lock. On the other hand, if the port driver acquires the *StartIo* spin lock before calling a callback routine, that callback routine, when executed, could still acquire an *Interrupt* or a *DPC* spin lock.

The following table indicates which spin locks each miniport driver routine can acquire. In those cases where the miniport driver routine must obtain both the *StartIo* spin lock and the *Interrupt* spin lock, the routine must always acquire the *StartIo* spin lock first.

| Miniport driver routine | Allowed spin locks |
| ----------------------- | ------------------ |
| [**HwStorFindAdapter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_find_adapter) | None |
| [**HwStorInitialize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_initialize) | None |
| [**HwStorInterrupt**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_interrupt) | None |
| [**HwMSIInterruptRoutine**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_message_signaled_interrupt_routine) | None |
| [**HwStorStartIo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_startio) | DPC, Interrupt. Note that StartIo can be acquired in a virtual miniport driver or from a physical miniport driver that uses multiple concurrent channels. |
| [**HwStorBuildIo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_buildio) |DPC, StartIo, Interrupt |
| [**HwStorTimer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_timer) | Interrupt (when **SynchronizationModel** member of [**PORT_CONFIGURATION_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_port_configuration_information) is not set to **StorSynchronizeHalfDuplex**) |
| [**HwStorResetBus**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_reset_bus) | Interrupt (when **SynchronizationModel** member of [**PORT_CONFIGURATION_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_port_configuration_information) is not set to **StorSynchronizeHalfDuplex**) |
| [**HwStorAdapterControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_adapter_control) | DPC, StartIo, Interrupt. (In Windows Server 2003, the no spin lock is allowed when control type is ScsiStopAdapter.) |
| [**HwStorUnitControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_unit_control) | DPC, StartIo, Interrupt |
| [**HwStorTracingEnabled**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_tracing_enabled) | DPC, StartIo, Interrupt |
| [**HwStorPassiveInitializeRoutine**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_passive_initialize_routine) | None |
| [**HwStorDpcRoutine**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_dpc_routine) | DPC, StartIo, Interrupt |
| [**HwStorStateChange**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_state_change) | Interrupt (when **SynchronizationModel** member of [**PORT_CONFIGURATION_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_port_configuration_information) is not set to **StorSynchronizeHalfDuplex**) |

## See also

[**STOR_SPINLOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ne-storport-_stor_spinlock)

[**StorPortReleaseSpinLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportreleasespinlock)