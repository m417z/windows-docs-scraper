# _IO_CONNECT_INTERRUPT_PARAMETERS structure

## Description

The **IO_CONNECT_INTERRUPT_PARAMETERS** structure contains the parameters that a driver supplies to the [IoConnectInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioconnectinterruptex) routine to register an interrupt service routine (ISR).

## Members

### `Version`

On input, specifies the particular operation to be performed by **IoConnectInterruptEx**, as follows.

| Version value | IoConnectInterruptEx operation |
| --- | --- |
| CONNECT_FULLY_SPECIFIED | Connects to a specific interrupt using information provided by the Plug and Play (PnP) manager. Use the **FullySpecified** member to provide the additional parameters of the operation. |
| CONNECT_LINE_BASED | Registers an [InterruptService](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-kservice_routine) routine for the device's line-based interrupts. Use the **LineBased** member to provide the additional parameters of the operation. |
| CONNECT_MESSAGE_BASED | Registers an [InterruptMessageService](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-kmessage_service_routine) routine for the device's message-signaled interrupts. The caller can also specify a fallback *InterruptService* routine if the device only has line-based interrupts. Use the **MessageBased** member to provide the additional parameters of the operation. |

On return, the routine provides information about the operation, as follows.

| Version value | Description |
| --- | --- |
| CONNECT_FULLY_SPECIFIED | The caller specified CONNECT_LINE_BASED or CONNECT_MESSAGE_BASED for **Version** on a platform that does not support it. Retry the operation using CONNECT_FULLY_SPECIFIED. |
| CONNECT_LINE_BASED | The caller specified CONNECT_MESSAGE_BASED and the caller's fallback *InterruptService* routine was registered. |
| CONNECT_MESSAGE_BASED | The caller specified CONNECT_MESSAGE_BASED and the caller's *InterruptMessageService* routine was registered. |

### `FullySpecified`

Specifies the additional parameters of the operation to be performed by [IoConnectInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioconnectinterruptex) when **Version** has a value of CONNECT_FULLY_SPECIFIED (or CONNECT_FULLY_SPECIFIED_GROUP if the **Group** member is used). For more information, see [Using the CONNECT_FULLY_SPECIFIED Version of IoConnectInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-the-connect-fully-specified-version-of-ioconnectinterruptex).

#### PhysicalDeviceObject

A pointer to the PDO for the device.

#### InterruptObject

A pointer to a location that receives a pointer to the set of interrupt objects for the device.

#### ServiceRoutine

A pointer to the [InterruptService](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-kservice_routine) routine to register as the ISR for the device's interrupts.

#### ServiceContext

Specifies the value to be passed as the *ServiceContext* parameter of the [InterruptService](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-kservice_routine) routine.

#### SpinLock

Either a pointer to a spin lock to serve as the interrupt spin lock for the set of interrupts, or **NULL**. If **NULL**, the system allocates a spin lock to serve as the interrupt spin lock. If non-**NULL**, you should have initialized the spin lock with [KeInitializeSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializespinlock).

#### SynchronizeIrql

Specifies the DIRQL at which the ISR will run. If the ISR handles more than one interrupt vector or the driver has more than one ISR, this value must be the maximum IRQL of the set of interrupts. The IRQL for an interrupt is passed in the **CmResourceTypeInterrupt** resource at the **u.Interrupt.Level** member of [CM_PARTIAL_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_partial_resource_descriptor). Otherwise, the **Irql** and **SynchronizeIrql** values are identical.

#### FloatingSave

Specifies if the system saves the processor's floating-point state when the interrupt occurs. If **TRUE**, the system saves the floating-point state.

#### ShareVector

Specifies whether the interrupt vector is sharable. Line-based PCI interrupts must be sharable. For message-signaled PCI interrupts, driver writers can choose whether their interrupts are sharable, but should choose to make them sharable by default.

#### Vector

Specifies the interrupt vector passed in the **CmResourceTypeInterrupt** resource at the **u.Interrupt.Vector** member of **CM_PARTIAL_RESOURCE_DESCRIPTOR**.

#### Irql

Specifies the DIRQL passed in the **CmResourceTypeInterrupt** resource at the **u.Interrupt.Level** member of [CM_PARTIAL_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_partial_resource_descriptor). Starting with Windows 8, a driver can register an ISR that runs at passive level by setting **Irql** and **SynchronizeIrql** to PASSIVE_LEVEL, and setting **SpinLock** to **NULL**. For more information, see [Using Passive-Level Interrupt Service Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-passive-level-interrupt-handling-routines).

#### InterruptMode

Specifies a [KINTERRUPT_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_kinterrupt_mode) that determines whether the interrupt is level-triggered (**InterruptMode** = **LevelSensitive**) or edge-triggered (**InterruptMode** = **Latched**). For shared interrupt lines from a PCI bus, specify **LevelSensitive**. For PCI message-signaled interrupts, specify **Latched**.

#### ProcessorEnableMask

Specifies the [**KAFFINITY**](https://learn.microsoft.com/windows-hardware/drivers/kernel/interrupt-affinity-and-priority#about-kaffinity) mask that represents the set of processors on which the device's interrupts can occur. This value is passed in the **CmResourceTypeInterrupt** resource at the **u.Interrupt.Affinity** member of **CM_PARTIAL_RESOURCE_DESCRIPTOR**.

#### Group

Specifies a group number that identifies the processor group to which the interrupt is to be delivered. Typically, a driver receives its group number as part of the translated resources that are included in an [IRP_MN_START_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-start-device) request. Starting with Windows 7, the **Group** member is used if the **Version** member of the **IO_CONNECT_INTERRUPT_PARAMETERS** structure is set to CONNECT_FULLY_SPECIFIED_GROUP. The **Group** member is ignored if **Version** is set to CONNECT_FULLY_SPECIFIED, in which case the group number for delivery of the interrupt is always 0.

### `LineBased`

Specifies the additional parameters of the operation to be performed by [IoConnectInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioconnectinterruptex) when **Version** has a value of CONNECT_LINE_BASED. For more information, see [Using the CONNECT_LINE_BASED Version of IoConnectInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-the-connect-line-based-version-of-ioconnectinterruptex).

#### PhysicalDeviceObject

A pointer to the physical device object (PDO) of the device.

#### InterruptObject

A pointer to a location that receives a pointer to the set of interrupt objects for the device.

#### ServiceRoutine

A pointer to the [InterruptService](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-kservice_routine) routine to register as the ISR for the device's interrupts.

#### ServiceContext

Specifies the value to be passed as the *ServiceContext* parameter of the *InterruptService* routine.

#### SpinLock

Either a pointer to a spin lock to serve as the interrupt spin lock for the set of interrupts, or **NULL**. If **NULL**, the system allocates a spin lock to serve as the interrupt spin lock. If non-**NULL**, you should have initialized the spin lock with [KeInitializeSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializespinlock).

#### SynchronizeIrql

Specifies the minimum device IRQL (DIRQL) at which the ISR runs. The system uses this value only if it is greater than the maximum IRQL of the set of interrupts; otherwise, the system uses the maximum IRQL. Drivers almost always specify PASSIVE_LEVEL for **SynchronizeIrql**. (A driver should specify a value other than PASSIVE_LEVEL only if the ISR must run above a certain IRQL.) Starting with Windows 8, a set of line-based interrupt resources that are assigned to a device can share an ISR that runs at IRQL = PASSIVE_LEVEL. If **SynchronizeIrql** = PASSIVE_LEVEL, and the maximum IRQL of this set of interrupts is PASSIVE_LEVEL, the *InterruptService* routine is called at PASSIVE_LEVEL. For more information, see [Using Passive-Level Interrupt Service Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-passive-level-interrupt-handling-routines).

#### FloatingSave

Specifies if the system saves the processor's floating-point state when the interrupt occurs. If **TRUE**, the system saves floating-point state. For x86-based and Itanium-based platforms, this value must be set to **FALSE**. For more information about saving floating-point and MMX state, see [Using Floating Point or MMX in a WDM Driver](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-floating-point-or-mmx-in-a-wdm-driver).

### `MessageBased`

Specifies the additional parameters of the operation to be performed by [IoConnectInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioconnectinterruptex) when **Version** has a value of CONNECT_MESSAGE_BASED. For more information, see [Using the CONNECT_MESSAGE_BASED Version of IoConnectInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-the-connect-message-based-version-of-ioconnectinterruptex).

#### PhysicalDeviceObject

A pointer to the PDO of the device.

#### ConnectionContext

A pointer to a location that receives a pointer to the connection context. If on return **Version** has a value of CONNECT_LINE_BASED, the routine provides a pointer to a [KINTERRUPT](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure. If on return **Version** has a value of CONNECT_MESSAGE_BASED, the routine provides a pointer to an [IO_INTERRUPT_MESSAGE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_interrupt_message_info) structure.

To minimize casting, **ConnectionContext** is defined as a union. Use **ConnectionContext.Generic** to treat the location as a PVOID. Use **ConnectionContext.InterruptObject** and **ConnectionContext.InterruptMessageTable** to treat the location as a PKINTERRUPT or PIO_INTERRUPT_MESSAGE_INFO variable respectively.

##### Generic

A pointer to a PVOID variable into which the **IoConnectInterruptEx** routine writes a pointer to the connection context.

##### InterruptMessageTable

A pointer to a PIO_INTERRUPT_MESSAGE_INFO variable into which the **IoConnectInterruptEx** routine writes a pointer to the connection context.

##### InterruptObject

A pointer to a PKINTERRUPT variable into which the **IoConnectInterruptEx** routine writes a pointer to the connection context.

#### MessageServiceRoutine

A pointer to the [InterruptMessageService](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-kmessage_service_routine) routine to register as the ISR for the device's interrupts.

#### ServiceContext

Specifies the value to be passed as the *ServiceContext* parameter of the [InterruptMessageService](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-kmessage_service_routine) or [InterruptService](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-kservice_routine) routine for the interrupt.

#### SpinLock

Either a pointer to a spin lock to serve as the interrupt spin lock for the set of interrupts, or **NULL**. If **NULL**, the system allocates a spin lock to serve as the interrupt spin lock. If non-**NULL**, you should have initialized the spin lock with [KeInitializeSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializespinlock).

#### SynchronizeIrql

Specifies the minimum device IRQL (DIRQL) at which the ISR runs. The system only uses this value if it is greater than the maximum IRQL of the set of interrupts; otherwise, the system uses the maximum IRQL. Drivers almost always specify PASSIVE_LEVEL for **SynchronizeIrql**.

#### FloatingSave

Specifies if the system saves the processor's floating-point state when the interrupt occurs. If **TRUE**, the system saves floating-point state.

#### FallBackServiceRoutine

A pointer to an [InterruptService](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-kservice_routine) routine to use as the ISR for line-based interrupts. If the device has no message-signaled interrupts, but has line-based interrupts, the system registers this routine to handle the line-based interrupts.

## Remarks

The [IoConnectInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioconnectinterruptex) routine takes a single *Parameters* parameter, which points to an **IO_CONNECT_INTERRUPT_PARAMETERS** structure that contains all of the parameters of the operation.

## See also

[IoConnectInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioconnectinterruptex)