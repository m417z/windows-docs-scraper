# IoRegisterBootDriverReinitialization function

## Description

The **IoRegisterBootDriverReinitialization** routine is called by a boot driver to register the driver's reinitialization routine with the I/O manager to be called after all devices have been enumerated and started.

## Parameters

### `DriverObject` [in]

Pointer to the driver object for the boot driver to be reinitialized.

### `DriverReinitializationRoutine` [in]

Pointer to the driver's [Reinitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-driver_reinitialize) routine.

### `Context` [in, optional]

Optional context pointer to be passed to the driver's reinitialization routine.

## Remarks

A boot driver normally calls **IoRegisterBootDriverReinitialization** from its [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routine, which is run during boot driver initialization. **IoRegisterBootDriverReinitialization** registers the driver's reinitialization callback routine to be called by the I/O manager after all devices have been enumerated and started. The *DriverReinitializationRoutine* is run in a system thread at IRQL = PASSIVE_LEVEL.

A driver should call **IoRegisterBootDriverReinitialization** only if its *DriverEntry* routine will return STATUS_SUCCESS.

If the *DriverReinitializationRoutine* uses the registry, the *DriverEntry* routine must include in **IoRegisterBootDriverReinitialization**'s *Context* parameter a copy of the string to which *DriverEntry*'s own *RegistryPath* parameter points.

The *DriverEntry* routine can call **IoRegisterBootDriverReinitialization** only once. If the reinitialization routine needs to be run more than once, the *DriverReinitializationRoutine* can call **IoRegisterBootDriverReinitialization** as many additional times as needed, using the *Count* parameter to keep track of the number of times the *DriverReinitializationRoutine* has been called.

## See also

[DRIVER_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_driver_object)

[IoRegisterDriverReinitialization](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-ioregisterdriverreinitialization)

[Reinitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-driver_reinitialize)