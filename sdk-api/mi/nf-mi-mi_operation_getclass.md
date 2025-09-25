# MI_Operation_GetClass function

## Description

Gets a synchronous result for a class operation.

## Parameters

### `operation` [in]

Operation handle returned from an instance session operation.

### `classResult`

Returned class. If the operation fails, this value may be **Null**. The returned class is valid until the next call to **MI_Operation_GetClass** or [MI_Operation_Close](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_operation_close). If the class needs to be stay active across these calls, then the class needs to be cloned via [MI_Class_Clone](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_class_clone).

### `moreResults` [out, optional]

Returned Boolean value indicating if more results are available. A value of **MI_TRUE** means that more results can be retrieved. This is accomplished by calling this function until **moreResults** has a value of **MI_FALSE** (even if the operation is canceled via [MI_Operation_Cancel](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_operation_cancel). Calling [MI_Operation_Close](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_operation_close) before retrieving the last result where **moreResults** is set to **MI_FALSE** will cause the **MI_Operation_Close** function to stop responding.

### `result` [out, optional]

Returned value indicating the success or failure of the function call. A value of **MI_RESULT_OK** indicates success. Otherwise, the returned **errorMessage** value should be used to determine the cause of failure.

### `errorMessage`

In the case of an error, this returned value provides additional debugging information as to the cause of failure. This error message has the same lifetime as the **classResult** value.

### `completionDetails`

In the case of an error, this returned value provides additional error information - typically in the form of a CIM_Error object (or a derived class). This returned instance has the same lifetime as the **classResult** value. If this value is needs to stay active longer, then the value needs to be cloned via [MI_Instance_Clone](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_instance_clone).

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.

## Remarks

This function will block until a result is available. It must be called until the **moreResults** parameter is returned with a value of **MI_FALSE**. It is an error to call this function if a class callback is registered.