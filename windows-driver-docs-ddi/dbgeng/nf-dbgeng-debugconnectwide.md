# DebugConnectWide function

## Description

The [DebugConnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-debugconnect) and **DebugConnectWide** functions create a new [client object](https://learn.microsoft.com/windows-hardware/drivers/debugger/client-objects) and return an interface pointer to it. The client object will be connected to a remote host.

## Parameters

### `RemoteOptions` [in]

Specifies how the debugger engine will connect to the remote host. These are the same options that get passed to the **-remote** option on the command line. For details on the syntax of this string, see [Activating a Debugging Client](https://learn.microsoft.com/windows-hardware/drivers/debugger/activating-a-debugging-client).

### `InterfaceId` [in]

Specifies the interface identifier (IID) of the desired debugger engine client interface. This is the type of the interface that will be returned in *Interface*. For information about the interface identifier, see [Using Client Objects](https://learn.microsoft.com/windows-hardware/drivers/debugger/using-client-objects).

### `Interface` [out]

Receives an interface pointer for the new client. The type of this interface is specified by *InterfaceId*.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

As with **IUnknown::QueryInterface**, when the returned interface is no longer needed, its **IUnknown::Release** method should be called.

You don't need to call **CoInitialize**, **CoInitializeEx**, or **OleInitialize** to use this function and interfaces obtained by it.

## See also

[Client Functions](https://learn.microsoft.com/windows-hardware/drivers/debugger/client-com-interfaces)

[Client Objects](https://learn.microsoft.com/windows-hardware/drivers/debugger/client-objects)