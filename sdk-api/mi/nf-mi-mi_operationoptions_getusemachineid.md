# MI_OperationOptions_GetUseMachineID function

## Description

Gets the value that indicates whether to use machine identification information in the operation request.

## Parameters

### `options` [in]

[MI_OperationOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_operationoptions) structure.

### `machineID` [out]

Returned Boolean value where **MI_TRUE** means that the source machine name is being added to the operation request packet so that the server can identify it. **MI_FALSE** means that the information is not being added.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.