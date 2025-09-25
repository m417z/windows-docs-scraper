# ICallFrameEvents::OnCall

## Description

Informs the event sink if it receives a method call on the interceptor. The sink is provided with an [ICallFrame](https://learn.microsoft.com/windows/desktop/api/callobj/nn-callobj-icallframe) instance which is bound to the intercepted incoming method invocation. Through that sink the call frame can be manipulated in various ways.

## Parameters

### `pFrame` [in]

A call frame bound to the just-received invocation.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_UNEXPECTED** | An unexpected error has occurred. |

## Remarks

On return from **OnCall**, the interceptor assumes that by some means the out-values of the method have been appropriately initialized as needed, if any; the interceptor does not itself manipulate the call frame further in any way. Typically, the **OnCall** implementation will have set the out-values by some means, either by invoking the call frame on an object, successfully unmarshalling some previously marshaled out-values, or clearing them with [ICallFrame::Free](https://learn.microsoft.com/windows/desktop/api/callobj/nf-callobj-icallframe-free).

The return value should also have been appropriately set during the call in a similar manner. See [ICallFrame::SetReturnValue](https://learn.microsoft.com/windows/desktop/api/callobj/nf-callobj-icallframe-setreturnvalue).

## See also

[ICallFrame](https://learn.microsoft.com/windows/desktop/api/callobj/nn-callobj-icallframe)

[ICallFrameEvents](https://learn.microsoft.com/windows/desktop/api/callobj/nn-callobj-icallframeevents)