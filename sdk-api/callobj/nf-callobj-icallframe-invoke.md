# ICallFrame::Invoke

## Description

Applies this activation record to an object.
In a marshalling situation, typically this is carried out on the server side, and is the means by which the work of the actual object is accomplished.

## Parameters

### `pvReceiver` [in]

The interface on which the invocation is to occur. The caller is responsible for ensuring that this interface is of the appropriate IID; the implementation will simply do a cast and assume that is the case.

### `...`

Additional parameters.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **CALLFRAME_E_ALREADYINVOKED** | An invocation has already been made from this frame. |
| **E_UNEXPECTED** | An unexpected error has occurred. |

## Remarks

Generally speaking, carrying out the invocation involves allocating a new stack frame, shallow-copying down the data in the original frame, then calling the appropriate method in the indicated object. The object invoked may then choose to modify [out] parameters, which are reachable from the copied frame, according to the appropriate semantics of the invocation. When the invocation returns from the object, the call frame automatically captures the return value from [ICallFrame::SetReturnValue](https://learn.microsoft.com/windows/desktop/api/callobj/nf-callobj-icallframe-setreturnvalue).

## See also

[ICallFrame](https://learn.microsoft.com/windows/desktop/api/callobj/nn-callobj-icallframe)