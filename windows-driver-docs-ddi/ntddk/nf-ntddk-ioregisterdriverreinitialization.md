# IoRegisterDriverReinitialization function

## Description

The **IoRegisterDriverReinitialization** routine is called by a driver during its initialization or reinitialization to register its [Reinitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-driver_reinitialize) routine to be called again before the driver's and, possibly the system's, initialization is complete.

## Parameters

### `DriverObject` [in]

Pointer to the driver object that was input to the [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routine.

### `DriverReinitializationRoutine` [in]

Pointer to the driver's [Reinitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-driver_reinitialize) routine.

### `Context` [in, optional]

Pointer to the context to be passed to the driver's *Reinitialize* routine.

## Remarks

A driver can call this routine only if its *DriverEntry* routine will return STATUS_SUCCESS. If the driver-supplied [Reinitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-driver_reinitialize) routine must use the registry, the *DriverEntry* routine should include a copy of the string to which *RegistryPath* points as part of the context passed to the *Reinitialize* routine in this call.

If the driver is loaded dynamically, it is possible for this to occur during a normally running system, so all references to the reinitialization queue must be synchronized.

The *Count* input to a *DriverReinitializationRoutine* indicates how many times this routine has been called, including the current call.

The *DriverEntry* routine can call **IoRegisterDriverReinitialization** only once. If the *Reinitialize* routine should be run again after any other drivers' *Reinitialize* routines have returned control, the *Reinitialize* routine also can call **IoRegisterDriverReinitialization** as many times as the driver's *Reinitialize* routine should be run.

Usually, a driver with a *Reinitialize* routine is a higher-level driver that controls both PnP and legacy devices. Such a driver must not only create device objects for the devices that the PnP manager detects (and for which the PnP manager calls the driver's [AddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_add_device) routine), the driver must also create device objects for legacy devices that the PnP manager does not detect. A driver can use a *Reinitialize* routine to create those device objects and layer the driver over the next-lower driver for the underlying device.

## See also

[DRIVER_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_driver_object)

[IoRegisterBootDriverReinitialization](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-ioregisterbootdriverreinitialization)