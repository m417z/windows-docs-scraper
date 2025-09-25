# CoSwitchCallContext function

## Description

Switches the call context object used by [CoGetCallContext](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cogetcallcontext).

## Parameters

### `pNewObject` [in, optional]

A pointer to an interface on the new call context object. COM stores this pointer without adding a reference to the pointer until **CoSwitchCallContext** is called with another object. This parameter may be **NULL** if you are calling **CoSwitchCallContext** to switch back to the original call context but there was no original call context.

### `ppOldObject` [out]

The address of pointer variable that receives a pointer to the call context object of the call currently in progress. This value is returned so that the original call context can be restored by the custom marshaller. The returned pointer will be **NULL** if there was no call in progress.

## Return value

This function can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The function was successful. |
| **E_OUT_OF_MEMORY** | Out of memory. |

## Remarks

Custom marshallers call **CoSwitchCallContext** to change the call context object used by the [CoGetCallContext](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cogetcallcontext) function. Before dispatching an arriving call, custom marshallers call **CoSwitchCallContext**, specifying the new context object. After sending a reply, they must restore the original call context by calling **CoSwitchCallContext** again, this time passing a pointer to the original context object.

**CoSwitchCallContext** does not add a reference to the new context object. Custom marshallers must ensure that the lifetime of their context object continues throughout their call and until the call to restore the original context. Custom marshallers should not release the value that they placed into the *ppOldObject* parameter when they set their context.

Call context objects provided by custom marshallers should support the [IServerSecurity](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iserversecurity) interface.

## See also

[CoGetCallContext](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cogetcallcontext)

[IServerSecurity](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iserversecurity)

[Security in COM](https://learn.microsoft.com/windows/desktop/com/security-in-com)