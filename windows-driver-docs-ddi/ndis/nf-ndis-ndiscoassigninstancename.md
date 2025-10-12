# NdisCoAssignInstanceName function

## Description

**NdisCoAssignInstanceName** assigns an instance name to a VC and causes NDIS to register a GUID
(globally unique identifier) for the assigned name with Windows Management Instrumentation (WMI).

## Parameters

### `NdisVcHandle` [in]

Specifies the handle to the VC being named. This handle was supplied by NDIS when the VC was
originally created with
[NdisCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscocreatevc), whether by the client in
preparation for making an outgoing call or by the call manager in preparation for dispatching an
incoming call to the client.

### `BaseInstanceName` [in]

Pointer to an NDIS_STRING type that describes a caller-supplied Unicode string that specifies the
base name of the VC. The base name can be any localizable Unicode string that uniquely identifies the VC
with respect to the other named VCs within the scope of the miniport driver. For Windows Vista and
later, NDIS defines the NDIS_STRING type as a
[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) type.

### `VcInstanceName` [out, optional]

Pointer to a caller-allocated NDIS_STRING type in which this routine returns a Unicode string that
specifies the NDIS-assigned instance name assigned for the VC.

## Return value

**NdisCoAssignInstanceName** can return any of the following:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | NDIS assigned an instance name to the specified VC and registered a GUID for the instance name with WMI. |
| **NDIS_STATUS_FAILURE** | The attempt to assign an instance name to the VC failed. |
| **NDIS_STATUS_RESOURCES** | NDIS could not allocate a buffer for the instance name. |

## Remarks

After initiating the setup of a VC with
[NdisCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscocreatevc), a call manager or
connection-oriented client can name the VC with
**NdisCoAssignInstanceName**. Calling
**NdisCoAssignInstanceName**, causes NDIS to assign the VC an instance name and register the instance
name with WMI. WMI clients can then enumerate the VC and query or set OIDs relative to the VC.

An integrated miniport call manager (MCM) driver cannot use
**NdisCoAssignInstanceName** to name its VCs. Instead, an MCM driver should create a custom GUID and
OID for the VC and register the GUID-to-OID mapping with NDIS.

NDIS creates an instance name for the specified VC by appending an index to the base name pointed to
by the caller. NDIS returns the complete instance name (base name + index) to the caller and then
registers a GUID for the instance name with WMI. Only named VCs can be enumerated and queried by WMI
clients. Unnamed VCs are not visible to WMI clients.

If the specified VC already has an instance name (assigned in a previous call to
**NdisCoAssignInstanceName**), NDIS returns NDIS_STATUS_SUCCESS and the
*original* instance name assigned to the VC. An instance name remains assigned to a VC until that VC
is deleted.

The caller can associate the returned instance name with the handle for the named VC that NDIS
previously returned to the caller from
**NdisCoCreateVc**. NDIS, however, will continue to use the VC handle--not the instance name--to refer
to the VC in subsequent calls. The caller of
**NdisCoAssignInstanceName** might find the need to return the instance name to some other management
entity.

The caller is responsible for freeing the buffer containing the returned instance name. After deleting
the named VC with
[NdisCoDeleteVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscodeletevc), the caller must free the
buffer with
[NdisFreeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreestring).

## See also

[MiniportCoOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_co_oid_request)

[MiniportOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_oid_request)

[NdisCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscocreatevc)

[NdisCoDeleteVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscodeletevc)

[NdisFreeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreestring)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)