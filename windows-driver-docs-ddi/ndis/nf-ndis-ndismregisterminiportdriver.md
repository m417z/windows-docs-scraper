# NdisMRegisterMiniportDriver function

## Description

A miniport driver calls the
**NdisMRegisterMiniportDriver** function to register
*MiniportXxx* entry points with NDIS as the first step in initialization.

## Parameters

### `DriverObject` [in]

A pointer to an opaque driver object that the miniport driver received in its
[DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routine at the
*Argument1* parameter (see
[DriverEntry of NDIS
Miniport Drivers](https://learn.microsoft.com/windows-hardware/drivers/network/initializing-a-miniport-driver)).

### `RegistryPath` [in]

A pointer to an opaque registry path that the miniport driver received in its
[DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routine at the
*Argument2* parameter.

### `MiniportDriverContext` [in, optional]

A handle to a driver-allocated context area where the driver maintains state and configuration
information.

### `MiniportDriverCharacteristics` [in]

A pointer to an
[NDIS_MINIPORT_DRIVER_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_driver_characteristics) structure that the caller initialized.

### `NdisMiniportDriverHandle` [out]

A pointer to a caller-supplied handle variable. NDIS writes a handle to this variable that
uniquely identifies this driver. The driver must save this handle for use in subsequent
**Ndis*Xxx*** function calls.

## Return value

**NdisMRegisterMiniportDriver** returns one of the following status values:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | [NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver) registered the miniport driver successfully. |
| **NDIS_STATUS_BAD_CHARACTERISTICS** | The *CharacteristicsLength* parameter is incorrect for the NDIS version that is specified at the **MajorNdisVersion** member in the structure at *MiniportDriverCharacteristics* . |
| **NDIS_STATUS_BAD_VERSION** | The **MajorNdisVersion** or **MinorNdisVersion** specified in the characteristics structure is invalid. |
| **NDIS_STATUS_RESOURCES** | A shortage of resources, possibly memory, prevented NDIS from registering the caller. |
| **NDIS_STATUS_FAILURE** | This is a default error status, returned when none of the preceding errors caused the registration to fail. |

## Remarks

An NDIS driver calls
**NdisMRegisterMiniportDriver** from its
[DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routine. For more information, see
[DriverEntry of NDIS
Miniport Drivers](https://learn.microsoft.com/windows-hardware/drivers/network/initializing-a-miniport-driver).

Every miniport driver exports a set of standard
*MiniportXxx* functions by setting up the characteristics structure and calling
**NdisMRegisterMiniportDriver**. NDIS copies the characteristics structure to NDIS internal storage.
Therefore, after it has registered, a driver cannot change its
*MiniportXxx* entry points.

To register its virtual miniport interface, an NDIS intermediate drivers must call
**NdisMRegisterMiniportDriver** with the NDIS_INTERMEDIATE_DRIVER flag set in the structure at
*MiniportDriverCharacteristics* . NDIS drivers that have a WDM lower edge must call
**NdisMRegisterMiniportDriver** with the NDIS_WDM_DRIVER flag set in the structure at
*MiniportDriverCharacteristics* .

Drivers can register as a combined miniport driver and intermediate driver. To register its physical
miniport driver, a miniport-intermediate driver calls
**NdisMRegisterMiniportDriver** with appropriate parameters just as for any miniport driver. To
register its virtual miniport interface, the driver calls
**NdisMRegisterMiniportDriver** again, but with the NDIS_INTERMEDIATE_DRIVER flag set in the
*MiniportDriverCharacteristics* parameter.

To enable miniport drivers to register optional services, NDIS calls the
[MiniportSetOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-set_options) function within
the context of
**NdisMRegisterMiniportDriver**.

After a driver calls
**NdisMRegisterMiniportDriver**, the driver should be prepared to be called back at the
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function that
is specified in the
*MiniportDriverCharacteristics* parameter any time after DriverEntry returns.

If an error occurs in
[DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) after
**NdisMRegisterMiniportDriver** returns successfully, the driver must call the
[NdisMDeregisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismderegisterminiportdriver) function before
**DriverEntry** returns. If
**DriverEntry** succeeds, the driver must call
**NdisMDeregisterMiniportDriver** from its
[MiniportDriverUnload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_unload) function.

## See also

[Initializing a Miniport Driver](https://learn.microsoft.com/windows-hardware/drivers/network/initializing-a-miniport-driver)

[DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver)

[MiniportDriverUnload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_unload)

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[MiniportSetOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-set_options)

[NDIS_MINIPORT_DRIVER_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_driver_characteristics)

[NdisMDeregisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismderegisterminiportdriver)