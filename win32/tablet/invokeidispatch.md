# InvokeIDispatch function

Invokes helper functionality for the IDispatch interface.

This function is not intended to be used by application code.

## Parameters

*pDispatch*

The instance of the IDispatch interface.

*dispid*

The method, property, or argument to pass in.

*pDisp*

The parameters to pass in.

*pVarResult* \[out\]

A structure that receives the retrieved values.

## Return value

If the method succeeds, it returns S\_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
|----------------------------------------------------------------------------------------------|--------------------------------------------------|
| **E\_INVALIDARG** | The value for *pDispatch* is invalid.<br> |

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP Tablet PC Edition \[desktop apps only\]<br> |
| Minimum supported server<br> | None supported<br> |
| Library<br> | InkObj.dll |

