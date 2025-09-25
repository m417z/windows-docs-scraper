# IF_SET_OBJECT callback function

## Description

The
*ProviderSetObject* function sets information that is associated with a network interface.

## Parameters

### `ProviderIfContext` [in]

A handle that identifies the interface provider's context area for the interface. The interface
provider passed this handle to NDIS in a call to the
[NdisIfRegisterInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisifregisterinterface) function.

### `ObjectId` [in]

An identifier for the object that is the target of the set request. For a list of object
identifiers (OIDs) that apply to interface providers, see
[NDIS Network Interface
OIDs](https://learn.microsoft.com/windows-hardware/drivers/network/mapping-of-ndis-network-interfaces-to-ndis-oids).

### `InputBufferLength` [in]

The length, in bytes, of the buffer that
*pInputBuffer* points to.

### `pInputBuffer` [in]

A pointer to an input buffer that specifies the information that the interface provider should use
to set the object data.

## Return value

*ProviderSetObject* returns one of the following status values:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | The operation completed successfully. |
| **NDIS_STATUS_RESOURCES** | The operation failed because of insufficient resources. |
| **NDIS_STATUS_INVALID_PARAMETER** | The call failed because some of the input parameters were invalid. |
| **NDIS_STATUS_Xxx** | The call failed for some other reason. This function can propagate error codes from the functions that it calls or generate an appropriate error code. |

## Remarks

NDIS calls a network interface provider's
*ProviderSetObject* function to set information that is associated with an interface that the
provider registered. For a list of OIDs that apply to interface providers, see
[NDIS Network Interface OIDs](https://learn.microsoft.com/windows-hardware/drivers/network/mapping-of-ndis-network-interfaces-to-ndis-oids).

Note that there are currently no set OIDs defined.

NDIS calls
*ProviderSetObject* at IRQL = PASSIVE_LEVEL.

## See also

[NdisIfRegisterInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisifregisterinterface)