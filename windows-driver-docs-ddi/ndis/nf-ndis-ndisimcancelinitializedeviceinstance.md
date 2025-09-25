# NdisIMCancelInitializeDeviceInstance function

## Description

The
**NdisIMCancelInitializeDeviceInstance** function cancels a preceding call to the
[NdisIMInitializeDeviceInstanceEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisiminitializedeviceinstanceex) function.

## Parameters

### `DriverHandle` [in]

The miniport driver handle that the
[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver) function returned at the
*NdisMiniportDriverHandle* parameter.

### `DeviceInstance` [in]

A pointer to an NDIS_STRING type that describes a caller-initialized counted string in the
system-default character set. The string contains the name of the registry key in which the driver
stores information about a virtual miniport and, possibly, binding-specific information. For Microsoft
Windows 2000 and later drivers, this string contains Unicode characters. That is, for Windows 2000 and
later, NDIS defines the NDIS_STRING type as a
[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) type.

## Return value

**NdisIMCancelInitializeDeviceInstance** returns NDIS_STATUS_SUCCESS if it canceled the preceding call
to
**NdisIMInitializeDeviceInstanceEx**. Otherwise, it returns NDIS_STATUS_FAILURE if there is no way to
stop the initialization operation for the virtual miniport.

## Remarks

An intermediate driver calls the
[NdisIMInitializeDeviceInstanceEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisiminitializedeviceinstanceex) function to initiate the initialization operation for a virtual
miniports.Before NDIS calls the driver's
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function, the
driver can call
**NdisIMCancelInitializeDeviceInstance** to cancel the initialization operation. For example, if an
underlying driver that the intermediate driver requires for normal operation is removed, the intermediate
driver can cancel the initialization for any virtual miniports that are associated with the removed
driver.

## See also

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NdisIMInitializeDeviceInstanceEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisiminitializedeviceinstanceex)

[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)