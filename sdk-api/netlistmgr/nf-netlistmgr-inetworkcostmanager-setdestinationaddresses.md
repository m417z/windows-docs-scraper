# INetworkCostManager::SetDestinationAddresses

## Description

The **SetDestinationAddresses** method registers specified destination IPv4/IPv6 addresses to receive cost or data plan status change notifications.

## Parameters

### `length` [in]

The number of destination IPv4/IPv6 addresses in the list.

### `pDestIPAddrList` [in]

A [NLM_SOCKADDR](https://learn.microsoft.com/windows/desktop/api/netlistmgr/ns-netlistmgr-nlm_sockaddr) structure containing a list of destination IPv4/IPv6 addresses to register for cost or data plan status change notification.

### `bAppend`

If true, *pDestIPAddrList* will be appended to the existing address list; otherwise the existing list will be overwritten.

## Return value

Returns S_OK on success, otherwise an HRESULT error code is returned.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Returned if one of the following occurs:<br><br>* *length* is 0.<br>* *length* is larger than NLM_MAX_ADDRESS_LIST_SIZE(10)<br>* *bAppend* is VARIANT_TRUE, but including the number of subscribed destinations in the existing list with the value of *length* exceeds NLM_MAX_ADDRESS_SIZE.<br>* A destination address in the supplied list is invalid. |
| **E_POINTER** | *destIPAddrList* is NULL. |
| **HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED)** | The request is not supported. This error is returned if either an IPv4 or IPv6 stack is not present on the local computer but either an IPv4 or IPv6 address was specified by *destIPAddr*. |
| **HRESULT_FROM_WIN32(ERROR_ALREADY_INITIALIZED)** | This method was called after registering for [INetworkCostManagerEvents](https://learn.microsoft.com/windows/desktop/api/netlistmgr/nn-netlistmgr-inetworkcostmanagerevents) by calling [IConnectionPoint::Advise](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iconnectionpoint-advise). See Remark for more information. |

## Remarks

This method must be called before [IConnectionPoint::Advise](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iconnectionpoint-advise). Once **IConnectionPoint::Advise** is called, this method will not complete successfully until last sink calls [IConnectionPoint::UnAdvise](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iconnectionpoint-unadvise). However, this method can be called multiple times prior to the call to **IConnectionPoint::Advise**.

 If a list of destination addresses indicated by *pDestIPAddrList* contains duplicate addresses, only one of each will be used to notify cost changes. Callers can clear a list of destinations by calling this function with *length* set to 0, *destIPAddrList* set NULL, and *bAppend* set FALSE.

## See also

[IConnectionPoint::Advise](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iconnectionpoint-advise)

[IConnectionPoint::UnAdvise](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iconnectionpoint-unadvise)

[INetworkCostManager](https://learn.microsoft.com/windows/desktop/api/netlistmgr/nn-netlistmgr-inetworkcostmanager)