# NPOpenEnum function

## Description

Opens an enumeration of network resources or existing connections. The **NPOpenEnum** function must be called to obtain a valid handle for an enumeration.

## Parameters

### `dwScope` [in]

Determines the scope of the enumeration. This can be one of the following.

| Value | Meaning |
| --- | --- |
| **RESOURCE_CONNECTED** | All currently connected resources. |
| **RESOURCE_GLOBALNET** | All resources on the network. |
| **RESOURCE_CONTEXT** | The resources associated with the user's current and default network context (used for a "Network Neighborhood" view). The interpretation of this is left to the provider. |

### `dwType` [in]

Specifies the type of resources of interest. This is a bitmask, which may be any combination of the following flags.

| Value | Meaning |
| --- | --- |
| **RESOURCETYPE_DISK** | All disk resources. |
| **RESOURCETYPE_PRINT** | All print resources. |
| **RESOURCEUSAGE_ATTACHED** | Specifies that the function should fail if the caller is not authenticated (even if the network permits enumeration without authentication). |

If *dwType* is 0, or is just RESOURCEUSAGE_ATTACHED, all types of resources are returned. If a provider does not have the capability to distinguish between print and disk resources at the same level, it may return all resources.

### `dwUsage` [in]

Specifies the usage of resources of interested. This is a bitmask, which may be any combination of the following flags.

| Value | Meaning |
| --- | --- |
| **RESOURCEUSAGE_CONNECTABLE** | All connectable resources |
| **RESOURCEUSAGE_CONTAINER** | All container resources |

The bitmask may be zero to match all of the flags. This parameter may be ignored if *dwScope* is not set to RESOURCE_GLOBALNET.

### `lpNetResource` [in]

Pointer to the container to perform the enumeration. The
[NETRESOURCE](https://learn.microsoft.com/windows/desktop/api/winnetwk/ns-winnetwk-netresourcea) could have been obtained through a previous [NPEnumResource](https://learn.microsoft.com/windows/desktop/api/npapi/nf-npapi-npenumresource) call, or constructed by the caller, or it can be **NULL**. If it is **NULL** or if the **lpRemoteName** field of the **NETRESOURCE** is **NULL**, the provider should enumerate the top level of its network. Note that this means a provider cannot use an **lpRemoteName** of **NULL** to represent any network resource. A caller would normally start off by calling **NPOpenEnum** with this parameter set to **NULL** and then use the returned results for further enumeration. If the calling program knows exactly the provider and remote path to enumerate from, it may build its own **NETRESOURCE** structure to pass in, filling in the **lpProvider** and **lpRemoteName** fields. Note that if *dwScope* is RESOURCE_CONNECTED or RESOURCE_CONTEXT, this parameter will be **NULL**.

### `lphEnum` [out]

Pointer to a handle that can be used by the [NPEnumResource](https://learn.microsoft.com/windows/desktop/api/npapi/nf-npapi-npenumresource) function. When you have finished using the handle, release the handle by calling the [NPCloseEnum](https://learn.microsoft.com/windows/desktop/api/npapi/nf-npapi-npcloseenum) function.

## Return value

If the function succeeds, it should return WN_SUCCESS. Otherwise, it should return an error code which may include one of the following.

| Return code | Description |
| --- | --- |
| **WN_NOT_SUPPORTED** | The provider does not support the type of enumeration being requested, or the specific network resource cannot be browsed. |
| **WN_NOT_CONTAINER** | *lpNetResource* does not point to a container. |
| **WN_BAD_VALUE** | Invalid *dwScope*, *dwUsage*, or *dwType* or bad combination of parameters is specified. |
| **WN_NO_NETWORK** | The network is not present. |