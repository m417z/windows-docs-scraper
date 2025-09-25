# IF_QUERY_OBJECT callback function

## Description

The
*ProviderQueryObject* function retrieves information about a network interface.

## Parameters

### `ProviderIfContext` [in]

A handle that identifies the interface provider's context area for the interface. The interface
provider passed this handle to NDIS in a call to the
[NdisIfRegisterInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisifregisterinterface) function.

### `ObjectId` [in]

An identifier for the object that is the target of the query request. For a list of object
identifiers (OIDs) that apply to interface providers, see
[NDIS Network Interface
OIDs](https://learn.microsoft.com/windows-hardware/drivers/network/mapping-of-ndis-network-interfaces-to-ndis-oids).

### `pOutputBufferLength` [in, out]

A pointer to an NDIS-supplied variable in which NDIS provides the length of the output buffer.
*ProviderQueryObject* writes the length of the data that it put in the output buffer.

### `pOutputBuffer` [out]

A pointer to an NDIS-supplied output buffer in which
*ProviderQueryObject* writes the response to the query request.

## Return value

*ProviderQueryObject* returns one of the following status values:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | The operation completed successfully. |
| **NDIS_STATUS_RESOURCES** | The operation failed because of insufficient resources. |
| **NDIS_STATUS_INVALID_PARAMETER** | The call failed because some of the input parameters were invalid. |
| **NDIS_STATUS_*Xxx*** | The call failed for some other reason. This function can propagate error codes from the functions that it calls or generate an appropriate error code. |

## Remarks

NDIS calls a network interface provider's
*ProviderQueryObject* function to obtain information about an interface that the provider registered.
For a list of OIDs that apply to interface providers, see
[NDIS Network Interface OIDs](https://learn.microsoft.com/windows-hardware/drivers/network/mapping-of-ndis-network-interfaces-to-ndis-oids).

NDIS calls
*ProviderQueryObject* at IRQL = PASSIVE_LEVEL.

## See also

[NdisIfRegisterInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisifregisterinterface)