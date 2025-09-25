# WdfRequestImpersonate function

## Description

[Applies to UMDF only]

The **WdfRequestImpersonate** method registers a driver-supplied event callback function that the framework should call for impersonation.

## Parameters

### `Request` [in]

A handle to the framework request object that represents the I/O request that is being completed.

### `ImpersonationLevel` [in]

A [SECURITY_IMPERSONATION_LEVEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_security_impersonation_level)-typed value that identifies the level of impersonation.

### `EvtRequestImpersonate` [in]

A pointer to the driver's [EvtRequestImpersonate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_impersonate) event callback function.

### `Context` [in, optional]

A pointer to a buffer that contains context information that is related to the impersonation call. The framework passes this context information in a call to the [EvtRequestImpersonate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_impersonate) event callback function. This parameter is optional and can be **NULL**

## Return value

If the **WdfRequestImpersonate** method encounters no errors, it returns STATUS_SUCCESS.

The method might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

The **WdfRequestImpersonate** method does not return until the [EvtRequestImpersonate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_impersonate) event callback function completes.

For more information, see [Handling Client Impersonation in UMDF Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/handling-client-impersonation-in-umdf-drivers).

## See also

[EvtRequestImpersonate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_impersonate)

[IWDFIoRequest::Impersonate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-impersonate)