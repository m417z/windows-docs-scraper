# _FWPS_CONNECT_REQUEST0 structure

## Description

The **FWPS_CONNECT_REQUEST0** structure defines modifiable data for the
**FWPM_LAYER_ALE_AUTH_CONNECT_REDIRECT_V4** and **FWPM_LAYER_ALE_AUTH_CONNECT_REDIRECT_V6** layers. The callout
driver uses this data to inspect or modify the connection information.

**Note** **FWPS_CONNECT_REQUEST0** is a specific version of **FWPS_CONNECT_REQUEST**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## Members

### `localAddressAndPort`

The local transport address of the connect request. This is an IPV4 or IPV6 address and TCP port
formatted as a
[SOCKADDR_STORAGE](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-sockaddr_storage_lh) structure.

### `remoteAddressAndPort`

The remote transport address of the connect request. This is an IPV4 or IPV6 address and TCP/UDP
port formatted as a
[SOCKADDR_STORAGE](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-sockaddr_storage_lh) structure.

### `portReservationToken`

A token used to reserve the appropriate port. The token is obtained when a port is reserved by
calling either
[CreatePersistentTcpPortReservation](https://learn.microsoft.com/windows/win32/api/iphlpapi/nf-iphlpapi-createpersistenttcpportreservation) or
[CreatePersistentUdpPortReservation](https://learn.microsoft.com/windows/win32/api/iphlpapi/nf-iphlpapi-createpersistentudpportreservation).

### `localRedirectTargetPID`

The process identifier of the local host process that will be handling traffic to the address
specified in
**localAddressAndPort**. This value must be set for loopback redirect changes to be accepted by the
engine.

### `previousVersion`

The previous version of the connect request data. This read-only field records the modification history of the connect request. If the connect
request data has not been previously modified by another WFP filter,
*previousVersion* will be set to **NULL**.

### `modifierFilterId`

The value of the
**FilterId** member of the
[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) function's
*filter* parameter. For more information about the
**FilterId** member, see
[FWPS_FILTER1](https://learn.microsoft.com/windows/win32/api/fwpstypes/ns-fwpstypes-fwps_filter1).

### `localRedirectHandle`

 The redirect handle that the callout driver created by calling the [FwpsRedirectHandleCreate0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsredirecthandlecreate0) function.

**Note** Starting with Windows 8, the **localRedirectHandle** must be populated for redirection to work.

### `localRedirectContext`

A callout driver context area that the callout driver allocated by calling the
[ExAllocatePoolWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithtag) function.

**Note** Starting with Windows 8, memory allocated for **localRedirectContext** will have its ownership taken by WFP, and will be freed when the proxied flow is removed.

### `localRedirectContextSize`

The size, in bytes, of the callout-supplied context area.

**Note** Supported starting with Windows 8.

## Remarks

The callout driver obtains this structure by calling the
[FwpsAcquireWritableLayerDataPointer0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsacquirewritablelayerdatapointer0) function, which returns a pointer to a **FWPS_CONNECT_REQUEST0**
structure through the
*writableLayerData* parameter. The
[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) function can modify the connect
request's parameters, such as redirecting the local or remote transport address or port to another
address or port. If it modifies the connect request's parameters, the *classifyFn* function must do the
following:

* Make all changes to the **FWPS_CONNECT_REQUEST0** structure that was returned by
  [FwpsAcquireWritableLayerDataPointer0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsacquirewritablelayerdatapointer0). Only the
  **remoteAddressAndPort**,
  **portReservationToken**, **localRedirectTargetPID**, **localRedirectHandle**, **localRedirectContext**, and **localRedirectContextSize** members can be modified.
* Call
  [FwpsApplyModifiedLayerData0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsapplymodifiedlayerdata0) with the
  *modifiedLayerData* parameter set to the address of the **FWPS_CONNECT_REQUEST0** structure, even if the callout driver didn't modify any data. This value
  must be the same as the
  *modifiedLayerData* parameter value returned through
  [FwpsAcquireWritableLayerDataPointer0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsacquirewritablelayerdatapointer0).

This structure acts as a linked list that contains a record of all the changes made by other callout
drivers. There is previous version information if the
**previousVersion** member is not **NULL**. To examine the complete version history, the callout driver
must continue to examine the
**previousVersion** member of each structure in the list until it is set to **NULL**.

## See also

[ExAllocatePoolWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithtag)

[FWPS_FILTER1](https://learn.microsoft.com/windows/win32/api/fwpstypes/ns-fwpstypes-fwps_filter1)

[FwpsAcquireWritableLayerDataPointer0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsacquirewritablelayerdatapointer0)

[FwpsApplyModifiedLayerData0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsapplymodifiedlayerdata0)

[FwpsRedirectHandleCreate0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsredirecthandlecreate0)

[SOCKADDR_STORAGE](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-sockaddr_storage_lh)

[Using Bind or Connect
Redirection](https://learn.microsoft.com/windows-hardware/drivers/network/using-bind-or-connect-redirection)

[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/)