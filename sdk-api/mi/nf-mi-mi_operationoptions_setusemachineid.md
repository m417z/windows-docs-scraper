# MI_OperationOptions_SetUseMachineID function

## Description

Enables or disables the sending of machine identification information in the operation request.

## Parameters

### `options` [in, out]

A pointer to a [MI_OperationOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_operationoptions) structure.

### `machineID` [in]

Boolean value where **MI_TRUE** means to add the source machine name to the operation request packet so that the server can identify it. **MI_FALSE** means to not add the information.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.

## See also

[MI_OperationOptions_GetUseMachineID](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_operationoptions_getusemachineid)