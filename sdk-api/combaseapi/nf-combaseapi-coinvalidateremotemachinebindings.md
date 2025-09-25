# CoInvalidateRemoteMachineBindings function

## Description

Tells the [service control manager](https://learn.microsoft.com/windows/desktop/Services/service-control-manager) to flush any cached RPC binding handles for the specified computer.

Only administrators may call this function.

## Parameters

### `pszMachineName` [in]

The computer name for which binding handles should be flushed, or an empty string to signify that all handles in the cache should be flushed.

## Return value

This function can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | Indicates success. |
| **CO_S_MACHINENAMENOTFOUND** | Indicates that the specified computer name was not found or that the binding handle cache was empty, indicating that an empty string was passed instead of a specific computer name. |
| **E_ACCESSDENIED** | Indicates the caller was not an administrator for this computer. |
| **E_INVALIDARG** | Indicates that a **NULL** value was passed for *pszMachineName*. |

## Remarks

The OLE Service Control Manager is used by COM to send component activation requests to other machines. To do this, the OLE Service Control Manager maintains a cache of RPC binding handles to send activation requests to computer, keyed by computer name. Under normal circumstances, this works well, but in some scenarios, such as Web farms and load-balancing situations, the ability to purge this cache of specific handles might be needed in order to facilitate rebinding to a different physical server by the same name. **CoInvalidateRemoteMachineBindings** is used for this purpose.

The OLE Service Control Manager will flush unused binding handles over time. It is not necessary to call **CoInvalidateRemoteMachineBindings** to do this.