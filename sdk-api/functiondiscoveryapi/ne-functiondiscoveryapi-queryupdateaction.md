# QueryUpdateAction enumeration

## Description

[Function Discovery is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Represents the type of action Function Discovery is performing on the specified function instance. This information is used by the client program's change notification handler.

## Constants

### `QUA_ADD:0`

Function Discovery is adding the specified function instance.

### `QUA_REMOVE:1`

Function Discovery is removing the specified function instance.

### `QUA_CHANGE:2`

Function Discovery is modifying the specified function instance.

## Remarks

When a client program implements the [IFunctionDiscoveryNotification](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctiondiscoverynotification) interface and passes the address of the interface to one of the Query methods, Function Discovery calls the client program's [IFunctionDiscoveryNotification::OnUpdate](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nf-functiondiscoveryapi-ifunctiondiscoverynotification-onupdate) method to notify the client program when a function instance which meets the query parameters has been added, removed, or modified.