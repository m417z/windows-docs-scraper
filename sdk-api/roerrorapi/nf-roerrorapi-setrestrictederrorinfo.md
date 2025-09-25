# SetRestrictedErrorInfo function

## Description

Sets the restricted error information object for the current thread.

## Parameters

### `pRestrictedErrorInfo` [in]

The restricted error information object associated with the current thread.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Call the [RoCaptureErrorContext](https://learn.microsoft.com/windows/desktop/api/roerrorapi/nf-roerrorapi-rocaptureerrorcontext) function to save error information for the current thread in a Windows Store app. Call the [RoFailFastWithErrorContext](https://learn.microsoft.com/windows/desktop/api/roerrorapi/nf-roerrorapi-rofailfastwitherrorcontext) function to raise an exception, terminate the current process, and report the error to the Windows Error Reporting service (WER).

The **SetRestrictedErrorInfo** function calls [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) to find the [IErrorInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-ierrorinfo) object, and then it calls [SetErrorInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-seterrorinfo). The call fails if [IRestrictedErrorInfo](https://learn.microsoft.com/windows/desktop/api/restrictederrorinfo/nn-restrictederrorinfo-irestrictederrorinfo) isn't the system implementation. To create an **IRestrictedErrorInfo** object, call the [OriginateError](https://learn.microsoft.com/windows/desktop/api/roerrorapi/nf-roerrorapi-rooriginateerror), [TransformError](https://learn.microsoft.com/windows/desktop/api/roerrorapi/nf-roerrorapi-rotransformerror), or [RoCaptureErrorContext](https://learn.microsoft.com/windows/desktop/api/roerrorapi/nf-roerrorapi-rocaptureerrorcontext) functions.

The **SetRestrictedErrorInfo** function releases the existing restricted error information object, if one exists, and sets *pRestrictedErrorInfo*. For more info, see the [SetErrorInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-seterrorinfo) function.

## See also

[IRestrictedErrorInfo](https://learn.microsoft.com/windows/desktop/api/restrictederrorinfo/nn-restrictederrorinfo-irestrictederrorinfo)

[RO_ERROR_REPORTING_FLAGS](https://learn.microsoft.com/windows/desktop/api/roerrorapi/ne-roerrorapi-roerrorreportingflags)

[RoCaptureErrorContext](https://learn.microsoft.com/windows/desktop/api/roerrorapi/nf-roerrorapi-rocaptureerrorcontext)

[RoFailFastWithErrorContext](https://learn.microsoft.com/windows/desktop/api/roerrorapi/nf-roerrorapi-rofailfastwitherrorcontext)

[SetErrorInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-seterrorinfo)