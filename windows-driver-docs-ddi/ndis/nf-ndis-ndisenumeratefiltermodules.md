# NdisEnumerateFilterModules function

## Description

The
**NdisEnumerateFilterModules** function enumerates all the filters modules and filter intermediate driver
instances in a filter stack.

## Parameters

### `NdisHandle` [in]

An NDIS handle that was obtained during caller initialization. For more information about this
handle, see
[Obtaining Pool Handles](https://learn.microsoft.com/windows-hardware/drivers/network/obtaining-pool-handles).

If the handle is an NDIS miniport adapter handle, NDIS returns information about all the interface
modules that are currently attached to the miniport adapter, starting with the top-most filter
module.

If the handle is an NDIS binding handle, NDIS returns information about all the filter modules that
are currently attached to the underlying miniport adapter, starting with the top-most filter module.

If the handle is an NDIS filter module handle, NDIS returns information about all the filter modules
that are currently attached to the underlying miniport adapter to which the specified filter module is
attached, starting with the top-most filter module.

### `InterfaceBuffer` [in]

A pointer to a caller-allocated memory block in which NDIS returns the information for all the
filter modules in a filter stack, starting with top-most filter. This buffer contains an
[NDIS_ENUM_FILTERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_enum_filters) structure that is
followed by zero or more
[NDIS_FILTER_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_filter_interface) structures, one
for each filter module in the stack.

### `InterfaceBufferLength` [in]

The length, in bytes, of the caller-supplied memory block at the
**InterfaceBuffer** member.

### `BytesNeeded` [in, out]

A pointer to a caller-supplied variable where NDIS writes the total number of bytes that NDIS
requires to successfully return the interface information for all the filters in the filter
stack.

### `BytesWritten` [in, out]

A pointer to a caller-supplied variable where NDIS writes the total bytes that NDIS wrote in the
memory at
**InterfaceBuffer**.

## Return value

**NdisEnumerateFilterModules** returns one of the following status values:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | The operation completed successfully. |
| **NDIS_STATUS_INVALID_PARAMETER** | **NdisEnumerateFilterModules** failed because the *NdisHandle* parameter was not a valid NDIS miniport adapter, protocol binding, or filter module handle. |
| **NDIS_STATUS_BUFFER_TOO_SHORT** | **NdisEnumerateFilterModules** failed because the buffer that was supplied at the *InterfaceBuffer* parameter was too short for NDIS to return all the information. If a partial result was written at *InterfaceBuffer*, the value at the *BytesWritten* parameter contains the length of the partial results. |

## Remarks

An NDIS miniport driver, protocol driver, or filter driver can call the
**NdisEnumerateFilterModules** function to enumerate all the filters in a filter stack.

**NdisEnumerateFilterModules** returns the list of filter modules and filter intermediate drivers from
the top to the bottom of the driver stack. For example, if filter modules (F1 and F2) are attached to
miniport adapter (M1) and if F2 is above F1,
**NdisEnumerateFilterModules** returns the list in the following order: F2, F1. If there is also a
filter intermediate driver (M2) that is bound to M1, if M2 is above F2, and if another filter (F3) is
attached to M2,
**NdisEnumerateFilterModules** returns the filter list in the following order: F3, M2, F2, F1.

## See also

[NDIS_ENUM_FILTERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_enum_filters)

[NDIS_FILTER_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_filter_interface)