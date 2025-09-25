# NdisGetProcessorInformationEx function

## Description

The
**NdisGetProcessorInformationEx** function retrieves information about the CPU topology of the local
computer.

## Parameters

### `NdisHandle` [in, optional]

An NDIS driver or instance handle that was obtained during caller initialization. For example, a
miniport driver can use the NDIS handle that it obtained from the
[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver) or
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) functions.
Other NDIS drivers can use the handles from the following functions:

[NdisRegisterProtocolDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisregisterprotocoldriver)

[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex)

[NdisFRegisterFilterDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfregisterfilterdriver)

[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach)

### `SystemProcessorInfo` [out, optional]

A pointer to a caller-allocated buffer where NDIS puts the
[NDIS_SYSTEM_PROCESSOR_INFO_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_system_processor_info_ex) structure and an array of
[NDIS_PROCESSOR_INFO_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_processor_info_ex) structures
that contain information about the CPU topology of the local computer. The caller provides the length of
the buffer in the
*Size* parameter.

### `Size` [in, out]

A pointer to a value that is the size, in bytes, of the buffer that the caller provided. When the
function returns, this value contains either the amount of data that NDIS put in the buffer or the
required size of the buffer if the buffer was too short.

## Return value

**NdisGetProcessorInformationEx** can return one of the following status values:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | The operation completed successfully. |
| **NDIS_STATUS_BUFFER_TOO_SHORT** | The size of the buffer at the *Size* parameter was too small. In this case, NDIS provides the required buffer size in the *Size* member. |

## Remarks

NDIS drivers call the
**NdisGetProcessorInformationEx** function to retrieve information about the processors on the local
computer.

## See also

[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach)

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NDIS_SYSTEM_PROCESSOR_INFO_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_system_processor_info_ex)

[NdisFRegisterFilterDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfregisterfilterdriver)

[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver)

[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex)

[NdisRegisterProtocolDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisregisterprotocoldriver)