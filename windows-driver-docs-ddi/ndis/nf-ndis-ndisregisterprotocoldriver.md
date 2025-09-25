# NdisRegisterProtocolDriver function

## Description

A protocol driver calls the
**NdisRegisterProtocolDriver** function to register its
*ProtocolXxx* functions with NDIS.

## Parameters

### `ProtocolDriverContext` [in, optional]

A handle to a driver-allocated context area where the driver maintains state and configuration
information.

### `ProtocolCharacteristics` [in]

A pointer to an
[NDIS_PROTOCOL_DRIVER_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_protocol_driver_characteristics) structure that the protocol driver created and initialized
with its
*ProtocolXxx* function entry points.

### `NdisProtocolHandle` [out]

A pointer to a caller-supplied handle variable. NDIS writes a handle to this variable that
uniquely identifies the driver that is registering. The driver must save this handle for use in
subsequent
**Ndis*Xxx*** function calls.

## Return value

**NdisRegisterProtocolDriver** returns one of the following status values:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | [NdisRegisterProtocolDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisregisterprotocoldriver) returns NDIS_STATUS_SUCCESS if it registered the protocol driver. |
| **NDIS_STATUS_BAD_VERSION** | The version specified in the **MajorNdisVersion** member of the structure at *ProtocolCharacteristics* is invalid. |
| **NDIS_STATUS_BAD_CHARACTERISTICS** | Some members of the structure at the *ProtocolCharacteristics* parameter are invalid. |
| **NDIS_STATUS_RESOURCES** | [NdisRegisterProtocolDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisregisterprotocoldriver) failed due to insufficient resources. |
| **NDIS_STATUS_FAILURE** | [NdisRegisterProtocolDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisregisterprotocoldriver) returns NDIS_STATUS_FAILURE if none of the preceding values applies. |

## Remarks

A protocol driver calls the
**NdisRegisterProtocolDriver** function from its
[DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routine. For more information about
**DriverEntry**, see
[DriverEntry of NDIS
Protocol Drivers](https://learn.microsoft.com/previous-versions/windows/embedded/gg156036(v=winembedded.80)).

Drivers that call **NdisRegisterProtocolDriver** must be prepared for an immediate call to any of their *ProtocolXxx* functions.

Every protocol driver exports a set of
*ProtocolXxx* functions by setting up the
[NDIS_PROTOCOL_DRIVER_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_protocol_driver_characteristics) structure and calling
**NdisRegisterProtocolDriver**. NDIS copies this structure to the NDIS library's internal storage.

To allow protocol drivers to register optional services, NDIS calls the
[ProtocolSetOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-set_options) function within
the context of
**NdisRegisterProtocolDriver**.

Protocol drivers call the
[NdisDeregisterProtocolDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisderegisterprotocoldriver) function to release resources that were previously allocated with
**NdisRegisterProtocolDriver**.

## See also

[DriverEntry of NDIS Protocol
Drivers](https://learn.microsoft.com/previous-versions/windows/embedded/gg156036(v=winembedded.80))

[NDIS_PROTOCOL_DRIVER_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_protocol_driver_characteristics)

[NdisDeregisterProtocolDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisderegisterprotocoldriver)

[NdisSetOptionalHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissetoptionalhandlers)