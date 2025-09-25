# NdisClDeregisterSap function

## Description

**NdisClDeregisterSap** releases a previously registered SAP.

## Parameters

### `NdisSapHandle` [in]

Specifies the handle returned by
**NdisClRegisterSap**.

## Return value

**NdisClDeregisterSap** can return one of the following:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_PENDING** | The call manager's [ProtocolCmDeregisterSap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_deregister_sap) function has been called to complete the requested operation. NDIS calls the client's [ProtocolClDeregisterSapComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_deregister_sap_complete) function when this operation is completed. |
| **NDIS_STATUS_FAILURE** | The SAP already is being closed, so this is a redundant call. If **NdisClRegisterSap** returns anything other than NDIS_STATUS_PENDING, the client should make an internal call to its *ProtocolClRegisterSapComplete* function. |

## Remarks

**NdisClDeregisterSap** releases a SAP on which the client previously registered itself to receive
incoming calls with
**NdisClRegisterSap**.

The client should consider the given
*NdisSapHandle* invalid as soon as it calls
**NdisClDeregisterSap**.

## See also

[NdisClRegisterSap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclregistersap)

[NdisCmRegisterSapComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmregistersapcomplete)

[ProtocolClDeregisterSapComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_deregister_sap_complete)

[ProtocolCmDeregisterSap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_deregister_sap)

[ProtocolUnbindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_unbind_adapter_ex)