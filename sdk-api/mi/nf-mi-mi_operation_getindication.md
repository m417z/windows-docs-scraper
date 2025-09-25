# MI_Operation_GetIndication function

## Description

Get the synchronous results from a subscription.

## Parameters

### `operation` [in]

Operation handle returned from an instance session operation.

### `instance`

Returned indication instance. If the operation fails, this value may be **Null**. The returned class is valid until the next call to **MI_Operation_GetIndication** or [MI_Operation_Close](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_operation_close). If the class needs to be stay active across these calls, then the class needs to be cloned via [MI_Instance_Clone](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_instance_clone).

### `bookmark`

Some providers allow a subscription to resume from a particular indication result should the subscription fail or get shut down. If the provider supports this, then a bookmark is optionally returned with the instance. This bookmark can then be passed in to a future subscription to attempt to resume the subscription from that point. Most providers do not support this functionality.

### `machineID`

Returned machine identification indicating the origin of the event.

### `moreResults` [out, optional]

Returned Boolean value indicating if more results are available. A value of **MI_TRUE** means that more results can be retrieved. This function must be called until **moreResults** has a value of **MI_FALSE** (even if the operation is canceled via [MI_Operation_Cancel](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_operation_cancel)). Calling [MI_Operation_Close](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_operation_close) before retrieving the last result where **moreResults** is set to **MI_FALSE** will cause the **MI_Operation_Close** function to stop responding.

### `result` [out, optional]

Returned value indicating the success or failure of the function call. A value of **MI_RESULT_OK** indicates success. Otherwise, the returned **errorMessage** value should be used to determine the cause of failure.

### `errorMessage`

In the case of an error, this returned value provides additional debugging information as to the cause of failure. This error message has the same lifetime as the **classResult** value.

### `completionDetails`

In the case of an error, this returned value provides additional error information - typically in the form of a CIM_Error object (or a derived class). This returned instance has the same lifetime as the **classResult** value. If this value is needs to stay active longer, then the value needs to be cloned via [MI_Instance_Clone](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_instance_clone).

## Remarks

This function will block until a new indication arrives. This function should not be called on non-subscription calls or a non-subscription operation.