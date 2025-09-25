# DebugCreateEx function

## Description

The **DebugCreateEx** function creates a new [client object](https://learn.microsoft.com/windows-hardware/drivers/debugger/client-objects) and returns an interface pointer to it.

## Parameters

### `InterfaceId` [in]

Specifies the interface identifier (IID) of the desired debugger engine client interface. This is the type of the interface that will be returned in *Interface*. For information about the interface identifier, see [Using Client Objects](https://learn.microsoft.com/windows-hardware/drivers/debugger/using-client-objects).

### `DbgEngOptions` [in]

Supplies debugger option flags.

### `Interface` [out]

Receives an interface pointer for the new client. The type of this interface is specified by *InterfaceId*.

## Return value

This method may also return other error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The function was successful. |
| **E_NOINTERFACE** | The client object doesn't implement the specified interface. |

## Remarks

The parameters passed to **DebugCreateEx** are the same as those passed to **IUnknown::QueryInterface**, and they are treated the same way.

As with **IUnknown::QueryInterface**, when the returned interface is no longer needed, its **IUnknown::Release** method should be called.

You don't need to call **CoInitialize**, **CoInitializeEx**, or **OleInitialize** to use this function and interfaces obtained by it.

The debugger engine client interfaces cannot be obtained by calling **CoCreateInstance**, **CoCreateInstanceEx**, or **CoGetClassObject**. Use **DebugCreate**, **DebugCreateEx**, **DebugConnect**, or **DebugConnectWide** to create such an interface, or call **IUnknown::QueryInterface** on another debugger engine client interface.

## See also

[Client Functions](https://learn.microsoft.com/windows-hardware/drivers/debugger/client-com-interfaces)

[Client Objects](https://learn.microsoft.com/windows-hardware/drivers/debugger/client-objects)