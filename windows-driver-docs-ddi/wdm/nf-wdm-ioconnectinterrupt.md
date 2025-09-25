# IoConnectInterrupt function

## Description

The **IoConnectInterrupt** routine registers a device driver's [InterruptService](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-kservice_routine) routine (ISR), so that it will be called when a device interrupts on any of a specified set of processors.

## Parameters

### `InterruptObject` [out]

Pointer to the address of driver-supplied storage for a pointer to a set of interrupt objects. This pointer must be passed in subsequent calls to [KeSynchronizeExecution](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesynchronizeexecution).

### `ServiceRoutine` [in]

Pointer to the entry point for the driver-supplied [InterruptService](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-kservice_routine) routine.

### `ServiceContext` [in, optional]

Pointer to the driver-determined context that will be supplied to the *InterruptService* routine when it is called. The *ServiceContext* area must be in resident memory: in the device extension of a driver-created device object, in the controller extension of a driver-created controller object, or in nonpaged pool allocated by the device driver. See [Providing ISR Context Information](https://learn.microsoft.com/windows-hardware/drivers/kernel/providing-isr-context-information) for details.

### `SpinLock` [in, optional]

Pointer to an initialized spin lock, for which the driver supplies the storage, that will be used to synchronize access to driver-determined data shared by other driver routines. This parameter is required if the ISR handles more than one vector or if the driver has more than one ISR. Otherwise, the driver need not allocate storage for an interrupt spin lock and the input pointer is **NULL**.

### `Vector` [in]

Specifies the interrupt vector passed in the interrupt resource at the **u.Interrupt.Vector** member of [CM_PARTIAL_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_partial_resource_descriptor).

### `Irql` [in]

Specifies the DIRQL passed in the interrupt resource at the **u.Interrupt.Level** member of **CM_PARTIAL_RESOURCE_DESCRIPTOR**.

### `SynchronizeIrql` [in]

Specifies the DIRQL at which the ISR will run. If the ISR handles more than one interrupt vector or the driver has more than one ISR, this value must be the highest of the *Irql* values passed at **u.Interrupt.Level** in each interrupt resource. Otherwise, the *Irql* and *SynchronizeIrql* values are identical.

### `InterruptMode` [in]

Specifies whether the device interrupt is **LevelSensitive** or **Latched**.

### `ShareVector` [in]

Specifies whether the interrupt vector is sharable.

### `ProcessorEnableMask` [in]

Specifies a [**KAFFINITY**](https://learn.microsoft.com/windows-hardware/drivers/kernel/interrupt-affinity-and-priority#about-kaffinity) value representing the set of processors on which device interrupts can occur in this platform. This value is passed in the interrupt resource at **u.Interrupt.Affinity**.

### `FloatingSave` [in]

Specifies whether to save the floating-point stack when the driver's device interrupts. For x86-based and Itanium-based platforms, this value must be set to **FALSE**. For more information about saving floating-point and MMX state, see [Using Floating Point or MMX in a WDM Driver](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-floating-point-or-mmx-in-a-wdm-driver).

## Return value

**IoConnectInterrupt** can return one of the following NTSTATUS values:

**STATUS_SUCCESS**

**STATUS_INVALID_PARAMETER**: No processors were specified.

**STATUS_INSUFFICIENT_RESOURCES**: There was not enough nonpaged pool.

## Remarks

New drivers should use the [IoConnectInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioconnectinterruptex) routine, which is easier to use. Drivers for devices that support message-signaled interrupts (MSI) must use **IoConnectInterruptEx**.

A PnP driver should call **IoConnectInterrupt** as part of device start-up, before it completes the PnP [IRP_MN_START_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-start-device) request.

When a driver receives an **IRP_MN_START_DEVICE** request, the driver receives raw and translated hardware resources in the **Parameters.StartDevice.AllocatedResources** and **Parameters.StartDevice.AllocatedResourcesTranslated** members of the IRP's [IO_STACK_LOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_stack_location) structure, respectively. To connect its interrupt, the driver uses the resources at **AllocatedResourcesTranslated.List.PartialResourceList.PartialDescriptors[]**. The driver must scan the array of partial descriptors for resources of type **CmResourceTypeInterrupt**.

If the driver supplies the storage for the *SpinLock*, it must call [KeInitializeSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializespinlock) before passing its interrupt spin lock to **IoConnectInterrupt**.

On return from a successful call to **IoConnectInterrupt**, the caller's ISR can be called if interrupts are enabled on the driver's device or if *ShareVector* was set to **TRUE**. Drivers must not enable interrupts until after **IoConnectInterrupt** returns.

## See also

[CM_PARTIAL_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_partial_resource_descriptor)

[IO_STACK_LOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_stack_location)

[IoDisconnectInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iodisconnectinterrupt)

[KeInitializeSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializespinlock)

[KeSynchronizeExecution](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesynchronizeexecution)