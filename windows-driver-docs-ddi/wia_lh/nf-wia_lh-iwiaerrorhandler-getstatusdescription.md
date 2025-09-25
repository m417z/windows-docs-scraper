## Description

 The system UI calls the **GetStatusDescription** method to provide the user with extra information about an error, if the user requests this information. This method is implemented by a driver's UI extension.

## Parameters

### `lFlags` [in]

Currently unused. Should be set to zero.

### `pWiaItem2` [in]

Pointer to the [**IWiaItem2**](https://learn.microsoft.com/windows/win32/wia/-wia-iwiaitem2) item being transferred.

### `hrStatus` [in]

HRESULT variable that contains the status code received by the WIA transfer method, for example the [**IWiaDataCallback::BandedDataCallback**](https://learn.microsoft.com/windows/win32/api/wia_xp/nf-wia_xp-iwiadatacallback-bandeddatacallback).

### `pbstrDescription` [out]

Pointer to a BSTR that receives a description of the status or error encountered during the transfer. This parameter cannot be **NULL**. The driver must allocate the string using the [**SysAllocString**](https://learn.microsoft.com/windows/win32/api/oleauto/nf-oleauto-sysallocstring) function and the caller must free the string using the [**SysFreeString**](https://learn.microsoft.com/windows/win32/api/oleauto/nf-oleauto-sysfreestring) function.

## Return value

Returns a standard COM error code if an error occurs, or one of the following:

| Return code | Description |
|---|---|
| **S_OK** | The *pbstrDescription* parameter contains a valid BSTR pointer. |
| **WIA_STATUS_NOT_HANDLED** | The value in the *hrStatus* parameter is unknown to the extension and no description is available. |

## Remarks

In order for an application to call **IWiaErrorHandler::GetStatusDescription**, the application must call **IWiaItem2::GetExtension** first to receive an interface pointer to the error handling extension. An application must pass "ErrorHandler" as bstrName and IID_IWiaErrorHandler as riidExtensionInterface. An application should pass 0 as lFlags to ensure upward compatibility.

The implementation of **IWiaErrorHandler::GetStatusDescription** should return S_OK for all the device status codes (*hrStatus*) that the implementation of [**IWiaErrorHandler::ReportStatus**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wia_lh/nf-wia_lh-iwiaerrorhandler-reportstatus) handles, and WIA_STATUS_NOT_HANDLED for those that **IWiaErrorHandler::ReportStatus** does not handle.

## See also

[**IWiaErrorHandler**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wia_lh/nn-wia_lh-iwiaerrorhandler)

[**IWiaErrorHandler::ReportStatus**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wia_lh/nf-wia_lh-iwiaerrorhandler-reportstatus)