# IWDFIoRequest::Impersonate

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **Impersonate** method registers the interface for the method that the framework should call for impersonation.

## Parameters

### `ImpersonationLevel` [in]

A [SECURITY_IMPERSONATION_LEVEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_security_impersonation_level)-typed value that identifies the level of impersonation.

### `pCallback` [in]

A pointer to the [IImpersonateCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iimpersonatecallback) interface whose method the framework calls for impersonation.

### `pvCallbackContext` [in, optional]

A pointer to a buffer that contains context information that is related to the impersonation call. The framework passes this context information in a call to the [IImpersonateCallback::OnImpersonate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iimpersonatecallback-onimpersonate) method. This parameter is optional. The driver can pass **NULL** if the driver does not have to supply a context.

## Return value

**Impersonate** returns S_OK if the operation succeeds. Otherwise, this method returns one of the error codes that are defined in Winerror.h.

## Remarks

For information about how UMDF and UMDF drivers handle impersonation, see [Handling Impersonation](https://learn.microsoft.com/windows-hardware/drivers/wdf/handling-client-impersonation-in-umdf-drivers).

## See also

[IImpersonateCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iimpersonatecallback)

[IImpersonateCallback::OnImpersonate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iimpersonatecallback-onimpersonate)

[IWDFIoRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiorequest)

[SECURITY_IMPERSONATION_LEVEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_security_impersonation_level)