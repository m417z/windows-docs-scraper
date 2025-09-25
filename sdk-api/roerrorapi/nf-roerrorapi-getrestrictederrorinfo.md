# GetRestrictedErrorInfo function

## Description

Gets the restricted error information object set by a previous call to [SetRestrictedErrorInfo](https://learn.microsoft.com/windows/desktop/api/roerrorapi/nf-roerrorapi-setrestrictederrorinfo) in the current logical thread.

## Parameters

### `ppRestrictedErrorInfo` [out]

The restricted error info object associated with the current thread.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The restricted error object was retrieved successfully. |
| **S_FALSE** | There is no restricted error object associated with the current thread. Any other error object is removed from the thread. |

## Remarks

Call the **GetRestrictedErrorInfo** function to get the most recently set [IRestrictedErrorInfo](https://learn.microsoft.com/windows/desktop/api/restrictederrorinfo/nn-restrictederrorinfo-irestrictederrorinfo) object on the current thread in a Windows Store app.

Call the [RoCaptureErrorContext](https://learn.microsoft.com/windows/desktop/api/roerrorapi/nf-roerrorapi-rocaptureerrorcontext) function to save error information for the current thread. Call the [RoFailFastWithErrorContext](https://learn.microsoft.com/windows/desktop/api/roerrorapi/nf-roerrorapi-rofailfastwitherrorcontext) function to raise an exception, terminate the current process, and report the error to the Windows Error Reporting service (WER).

**GetRestrictedErrorInfo** transfers ownership of the error object to the caller and clears the error state for the thread. If the most recently set error object doesn't support the [IRestrictedErrorInfo](https://learn.microsoft.com/windows/desktop/api/restrictederrorinfo/nn-restrictederrorinfo-irestrictederrorinfo) interface, the error state for the thread is cleared, but no interface is returned to the caller.

The **GetRestrictedErrorInfo** retrieves the error object from the current thread and calls [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) to find the [IRestrictedErrorInfo](https://learn.microsoft.com/windows/desktop/api/restrictederrorinfo/nn-restrictederrorinfo-irestrictederrorinfo) interface. If **IRestrictedErrorInfo** isn't found, **GetRestrictedErrorInfo** returns **S_FALSE**. In this case, the error object is removed from the thread. For more info, see [GetErrorInfo](https://learn.microsoft.com/windows/desktop/api/oleauto/nf-oleauto-geterrorinfo).

Calling the **GetRestrictedErrorInfo** function fails if [IRestrictedErrorInfo](https://learn.microsoft.com/windows/desktop/api/restrictederrorinfo/nn-restrictederrorinfo-irestrictederrorinfo) isn't the system implementation. To create an **IRestrictedErrorInfo** object, call the [OriginateError](https://learn.microsoft.com/windows/desktop/api/roerrorapi/nf-roerrorapi-rooriginateerror), [TransformError](https://learn.microsoft.com/windows/desktop/api/roerrorapi/nf-roerrorapi-rotransformerror), or [RoCaptureErrorContext](https://learn.microsoft.com/windows/desktop/api/roerrorapi/nf-roerrorapi-rocaptureerrorcontext) functions.

## See also

[GetErrorInfo](https://learn.microsoft.com/windows/desktop/api/oleauto/nf-oleauto-geterrorinfo)

[IRestrictedErrorInfo](https://learn.microsoft.com/windows/desktop/api/restrictederrorinfo/nn-restrictederrorinfo-irestrictederrorinfo)

[RO_ERROR_REPORTING_FLAGS](https://learn.microsoft.com/windows/desktop/api/roerrorapi/ne-roerrorapi-roerrorreportingflags)

[RoCaptureErrorContext](https://learn.microsoft.com/windows/desktop/api/roerrorapi/nf-roerrorapi-rocaptureerrorcontext)

[RoFailFastWithErrorContext](https://learn.microsoft.com/windows/desktop/api/roerrorapi/nf-roerrorapi-rofailfastwitherrorcontext)

[SetRestrictedErrorInfo](https://learn.microsoft.com/windows/desktop/api/roerrorapi/nf-roerrorapi-setrestrictederrorinfo)