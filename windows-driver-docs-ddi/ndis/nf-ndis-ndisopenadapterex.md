# NdisOpenAdapterEx function

## Description

A protocol driver calls the
**NdisOpenAdapterEx** function from its
[ProtocolBindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_bind_adapter_ex) function to
set up a binding between the protocol driver and an underlying driver.

## Parameters

### `NdisProtocolHandle` [in]

The handle returned by the
[NdisRegisterProtocolDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisregisterprotocoldriver) function.

### `ProtocolBindingContext` [in]

The handle for a caller-supplied context area in which the protocol driver maintains state
information for this binding.

### `OpenParameters` [in]

A pointer to an
[NDIS_OPEN_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_open_parameters) structure that is
set up by the caller.

### `BindContext` [in]

The handle that identifies the NDIS context area for the bind operation. NDIS passed this handle
to the
*BindContext* parameter of the
*ProtocolBindAdapterEx* function.

### `NdisBindingHandle` [out]

A pointer to a caller-supplied variable. NDIS writes a handle at
*NdisBindingHandle* that identifies the binding between the caller and the miniport adapter
specified in the
**AdapterName** member at
*OpenParameters* . The caller uses this handle in subsequent calls to
**Ndis*Xxx*** functions.

## Return value

**NdisOpenAdapterEx** returns one of the following status values:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | **NdisOpenAdapterEx** successfully completed the open operation. |
| **NDIS_STATUS_PENDING** | **NdisOpenAdapterEx** did not complete the open operation. NDIS later calls the protocol driver's [ProtocolOpenAdapterCompleteEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_open_adapter_complete_ex) function to complete the open operation. |
| **NDIS_STATUS_RESOURCES** | **NdisOpenAdapterEx** failed due to insufficient resources. |
| **NDIS_STATUS_ADAPTER_NOT_FOUND** | **NdisOpenAdapterEx** failed because a miniport adapter specified in the **AdapterName** member at *OpenParameters* could not be found. |
| **NDIS_STATUS_UNSUPPORTED_MEDIA** | **NdisOpenAdapterEx** failed because the array specified in the **MediumArray** member at *OpenParameters* did not include a medium type that NDIS or the underlying driver supports. |
| **NDIS_STATUS_FAILURE** | **NdisOpenAdapterEx** failed for reasons other than those in the preceding list. |

## Remarks

A protocol driver must call
**NdisOpenAdapterEx** from its
[ProtocolBindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_bind_adapter_ex) function.
NDIS fails any attempt to call
**NdisOpenAdapterEx** outside the context of
*ProtocolBindAdapterEx*.

If
**NdisOpenAdapterEx** returns NDIS_STATUS_PENDING, the caller must not use the values at
*NdisBindingHandle* and the
**SelectedMediumIndex** member at
*OpenParameters* until NDIS calls the
[ProtocolOpenAdapterCompleteEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_open_adapter_complete_ex) function.

The string at
**AdapterName** must remain valid only until
**NdisOpenAdapterEx** returns. Therefore, in the case that
**NdisOpenAdapterEx** returns NDIS_STATUS_PENDING, the driver is not required to continue to retain
this string after
**NdisOpenAdapterEx** returns.

After the open operation completes successfully, the caller can use the value that NDIS returned in
the
*NdisBindingHandle* in subsequent calls to
**Ndis*Xxx*** functions. The caller can use the
**SelectedMediumIndex** member of the
*OpenParameters* parameter to determine how it should interact with the underlying driver.

## See also

[NDIS_OPEN_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_open_parameters)

[NdisRegisterProtocolDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisregisterprotocoldriver)

[ProtocolBindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_bind_adapter_ex)

[ProtocolOpenAdapterCompleteEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_open_adapter_complete_ex)