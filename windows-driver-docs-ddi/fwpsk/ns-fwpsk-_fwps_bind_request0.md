# _FWPS_BIND_REQUEST0 structure

## Description

The **FWPS_BIND_REQUEST0** structure defines modifiable data for the FWPM_LAYER_ALE_AUTH_BIND_REDIRECT_V4
and FWPM_LAYER_ALE_AUTH_BIND_REDIRECT_V6 layers. The callout driver uses this data to inspect or modify the
connection information.

**Note** **FWPS_BIND_REQUEST0** is a specific version of **FWPS_BIND_REQUEST**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## Members

### `localAddressAndPort`

The local transport address of the bind request. This is an IPV4 or IPV6 address and TCP/UDP port
formatted as a
[SOCKADDR_STORAGE](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-sockaddr_storage_lh) structure.

### `portReservationToken`

A token used to reserve the appropriate port. The token is obtained when a port is reserved by
calling either
[CreatePersistentTcpPortReservation](https://learn.microsoft.com/windows/win32/api/iphlpapi/nf-iphlpapi-createpersistenttcpportreservation) or
[CreatePersistentUdpPortReservation](https://learn.microsoft.com/windows/win32/api/iphlpapi/nf-iphlpapi-createpersistentudpportreservation). Both reservation functions can be found in iphlpapi.h.

### `previousVersion`

The previous version of the bind request data. This read-only field records the modification history of the bind request. This member is preinitialized with a pointer to a singly linked list with the index set to the record for the current FWPS_BIND_REQUEST0 data.

### `modifierFilterId`

The value of the
**FilterId** member of the
[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) function's
*filter* parameter. For more information about the
**FilterId** member, see
[FWPS_FILTER1](https://learn.microsoft.com/windows/win32/api/fwpstypes/ns-fwpstypes-fwps_filter1).

## Remarks

The callout driver obtains this structure by calling the
[FwpsAcquireWritableLayerDataPointer0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsacquirewritablelayerdatapointer0) function, which returns a pointer to a **FWPS_BIND_REQUEST0**
structure through the
*writableLayerData* parameter.

The
[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) function can modify the bind
request's parameters, such as redirecting the local transport address or port to another address or port. If
it modifies the bind request's parameters, the
*classifyFn* function must do the following:

* Make all changes to the **FWPS_BIND_REQUEST0** structure that was returned by
  [FwpsAcquireWritableLayerDataPointer0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsacquirewritablelayerdatapointer0). Only the
  **localAddressAndPort** and
  **portReservationToken** members can be modified.
* Call
  [FwpsApplyModifiedLayerData0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsapplymodifiedlayerdata0) with the
  *modifiedLayerData* parameter set to the address of the **FWPS_BIND_REQUEST0** structure, even if the callout driver didn't modify any data. This value
  must be the same as the
  *modifiedLayerData* parameter value that was returned by
  [FwpsAcquireWritableLayerDataPointer0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsacquirewritablelayerdatapointer0).

This structure acts as a linked list that contains a record of all changes made by other callout
drivers. There is previous version information if the
**previousVersion** member is not **NULL**. To examine the complete version history, the callout driver
must continue to examine the
**previousVersion** member of each structure in the list until it is finds a node that has this member set to a value of **NULL**.

## See also

[FWPS_FILTER1](https://learn.microsoft.com/windows/win32/api/fwpstypes/ns-fwpstypes-fwps_filter1)

[FwpsAcquireWritableLayerDataPointer0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsacquirewritablelayerdatapointer0)

[FwpsApplyModifiedLayerData0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsapplymodifiedlayerdata0)

[SOCKADDR_STORAGE](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-sockaddr_storage_lh)

[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/)