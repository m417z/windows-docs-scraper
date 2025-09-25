# NdisIfRegisterProvider function

## Description

The
**NdisIfRegisterProvider** function registers an NDIS network interface provider.

## Parameters

### `ProviderCharacteristics` [in]

A pointer to a caller-provided
[NDIS_IF_PROVIDER_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_if_provider_characteristics) structure. This structure defines the characteristics of the
provider, including the entry points for its provider callback functions.

### `IfProviderContext` [in]

A handle to a caller-provided context area for this network interface provider. Set this parameter
to **NULL** if there is no context area.

### `pNdisIfProviderHandle`

A pointer to a caller-provided handle variable. If the registration operation succeeds, NDIS
writes a handle to this variable that identifies the network interface provider. The interface provider
should retain this handle for use in subsequent calls that require an interface provider handle.

## Return value

**NdisIfRegisterProvider** returns one of the following status values:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | The operation completed successfully. |
| **NDIS_STATUS_RESOURCES** | The operation failed because of insufficient resources. |
| **NDIS_STATUS_INVALID_PARAMETER** | **NdisIfRegisterProvider** failed to register the provider because the [NDIS_IF_PROVIDER_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_if_provider_characteristics) structure at the *ProviderCharacteristics* parameter contained invalid member data. |
| **NDIS_STATUS_NOT_SUPPORTED** | **NdisIfRegisterProvider** failed to register the provider because the **Header** member in NDIS_IF_PROVIDER_CHARACTERISTICS specifies a structure version that is not supported. |

## Remarks

NDIS drivers call the
**NdisIfRegisterProvider** function once during initialization to register as an NDIS interface
provider. For example, the driver can call
**NdisIfRegisterProvider** from its
[DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routine. An interface provider is a
software component that manages network interfaces to support the MIB (
[RFC 2863](https://learn.microsoft.com/windows-hardware/drivers/network/overview-of-ndis-network-interfaces)).

To handle interface provider OID requests, interface providers provide entry points for callback
functions in the
[NDIS_IF_PROVIDER_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_if_provider_characteristics) structure at the
*ProviderCharacteristics* parameter of
**NdisIfRegisterProvider**.

NDIS interface providers call the
[NdisIfRegisterInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisifregisterinterface) function
to register a network interface. A provider can register multiple interfaces.

If
**NdisIfRegisterProvider** succeeds, it returns a handle at the location that the
*pNdisProviderHandle* parameter points to. The interface provider should retain this handle for use
in subsequent calls that require an interface provider handle. For example, a driver must call
[NdisIfDeregisterProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisifderegisterprovider) before
the driver unloads.

A component that is no longer an interface provider can call the
**NdisIfDeregisterProvider** function at any time to release the interface provider resources that NDIS
allocated when the driver called
**NdisIfRegisterProvider**.

## See also

[DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver)

[NDIS_IF_PROVIDER_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_if_provider_characteristics)

[NdisIfDeregisterProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisifderegisterprovider)

[NdisIfRegisterInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisifregisterinterface)