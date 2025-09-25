# MI_Operation_GetInstance function

## Description

Gets a synchronous result for an instance operation.

## Parameters

### `operation` [in]

The operation handle returned from instance session operations.

### `instance`

Returned instance. This value may be **Null** even if the operation succeeds. The
returned instance is valid until the next call to
**MI_Operation_GetInstance** or
[MI_Operation_Close](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_operation_close). If the instance needs to be
stay active across these calls, then the class needs to be cloned via
[MI_Instance_Clone](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_instance_clone).

### `moreResults` [out, optional]

Returned Boolean value indicating if more results are available. A value of
**MI_TRUE** means that more results can be retrieved. This function must be called until
**moreResults** has a value of **MI_FALSE** (even if the operation
is canceled via [MI_Operation_Cancel](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_operation_cancel)). Calling
[MI_Operation_Close](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_operation_close) before retrieving the last
result where **moreResults** is set to **MI_FALSE** will cause the
**MI_Operation_Close** function to stop
responding.

### `result` [out, optional]

Returned value indicating the success or failure of the function call. A value of
**MI_RESULT_OK** indicates success. Otherwise, the returned
**errorMessage** value should be used to determine the cause of failure.

### `errorMessage`

In the case of an error, this returned value provides additional debugging information as to the cause of
failure. This error message has the same lifetime as the **classResult** value.

### `completionDetails`

In the case of an error, this returned value provides additional error information - typically in the form
of a [CIM_Error](https://learn.microsoft.com/windows/desktop/hyperv_v2/cim-error) object (or a derived class). This returned
instance has the same lifetime as the **classResult** value. If this value is needs to
stay active longer, then the value needs to be cloned via
[MI_Instance_Clone](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_instance_clone).

## Remarks

This function is called to get all synchronous results for all instance operations except subscriptions, where
[MI_Operation_GetIndication](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_operation_getindication) should be
used. This function will block until a result is available. It should be called until the
**moreResults** parameter is returned with a value of **MI_FALSE**. It
is an error to call this function if an instance callback is registered.