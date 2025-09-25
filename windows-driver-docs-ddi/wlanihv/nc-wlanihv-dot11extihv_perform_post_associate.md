# DOT11EXTIHV_PERFORM_POST_ASSOCIATE callback

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The operating system calls the
*Dot11ExtIhvPerformPostAssociate* function to request that the IHV Extensions DLL initiate a
post-association operation with the basic service set (BSS) network.

## Parameters

### `hIhvExtAdapter` [in, optional]

The handle used by the IHV Extensions DLL to reference the wireless LAN (WLAN) adapter. This
handle value was specified through a previous call to the
[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter) IHV
Handler function.

### `hSecuritySessionID` [in, optional]

The handle of the security session. The IHV Extensions DLL must use this handle value when it
calls
[Dot11ExtPostAssociateCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_post_associate_completion) to asynchronously complete the post-association operation.

### `pPortState` [in]

A pointer to a
[DOT11_PORT_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlclient/ns-wlclient-_dot11_port_state) structure, which
specifies the current port state of the security session.

### `uDot11AssocParamsBytes` [in]

The length, in bytes, of the data referenced through the
*pDot11AssocParams* parameter.

### `pDot11AssocParams` [in]

A pointer to a
[DOT11_ASSOCIATION_COMPLETION_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_association_completion_parameters) structure, which specifies the result of the association
operation completed by the WLAN adapter. The Native 802.11 miniport driver, which manages the WLAN
adapter, includes a DOT11_ASSOCIATION_COMPLETION_PARAMETERS structure when it makes a media-specific
[NDIS_STATUS_DOT11_ASSOCIATION_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-dot11-association-completion) indication.

For more information about the association operation, see
[Association Operations](https://learn.microsoft.com/windows-hardware/drivers/network/association-operations).

## Return value

If the IHV Extension DLL can initiate the post-association operation, it must complete the operation
asynchronously. In this situation, the function returns ERROR_SUCCESS.

If the IHV Extensions DLL cannot initiate the post-association operation, it returns an error code
defined in
*Winerror.h*.

## Prototype

```cpp
DOT11EXTIHV_PERFORM_POST_ASSOCIATE Dot11ExtIhvPerformPostAssociate;

DWORD APIENTRY Dot11ExtIhvPerformPostAssociate(
  _In_opt_ HANDLE                                   hIhvExtAdapter,
  _In_opt_ HANDLE                                   hSecuritySessionID,
  _In_     PDOT11_PORT_STATE                        pPortState,
  _In_     ULONG                                    uDot11AssocParamsBytes,
  _In_     PDOT11_ASSOCIATION_COMPLETION_PARAMETERS pDot11AssocParams
)
{ ... }
```

## Remarks

The operating system calls the
*Dot11ExtIhvPerformPostAssociate* function to initiate a post-association operation with the IHV
Extensions DLL. The operating system initiates this operation after the WLAN adapter completes an
association operation with an access point (AP) in an infrastructure basic service set (BSS) network.

**Note** For Windows Vista, the IHV Extensions DLL supports only infrastructure basic
service set (BSS) networks.

For more information about the association operation, see
[Association Operations](https://learn.microsoft.com/windows-hardware/drivers/network/association-operations).

The post-association operation must be completed asynchronously from the call to
*Dot11ExtIhvPerformPostAssociate*. After the post-association operation completes, the DLL must call
[Dot11ExtPostAssociateCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_post_associate_completion).

If the IHV Extensions DLL can initiate the post-association operation, the
*Dot11ExtIhvPerformPostAssociate* function must return ERROR_SUCCESS and complete the operation
asynchronously.

For more information about the post-association operation, see
[Post-Association Operations](https://learn.microsoft.com/windows-hardware/drivers/network/post-association-operations).

## See also

[Dot11ExtPostAssociateCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_post_associate_completion)

[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter)

[DOT11_PORT_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlclient/ns-wlclient-_dot11_port_state)

[Dot11ExtIhvAdapterReset](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_adapter_reset)

[NDIS_STATUS_DOT11_ASSOCIATION_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-dot11-association-completion)