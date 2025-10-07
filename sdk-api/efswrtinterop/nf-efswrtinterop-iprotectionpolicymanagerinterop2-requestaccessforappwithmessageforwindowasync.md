# IProtectionPolicyManagerInterop2::RequestAccessForAppWithMessageForWindowAsync

## Description

**Note** Windows Information Protection (WIP) policy can be applied on Windows 10, version 1607.

Request access to enterprise-protected content for a specific target app.

## Parameters

### `appWindow` [in]

 A handle to the current window.

### `sourceIdentity` [in]

 The enterprise identity to which the content is protected. This is an email address or domain that is managed.

### `appPackageFamilyName` [in]

The enterprise identity to which the content is being disclosed. This is an email address or domain.

### `auditInfoUnk` [in]

An audit info object; an instance of [ProtectionPolicyAuditInfo](https://learn.microsoft.com/uwp/api/Windows.Security.EnterpriseData.ProtectionPolicyAuditInfo).

### `messageFromApp` [in]

A message that will be displayed in the consent dialog so that the user can make a consent decision.

### `riid` [iid_is] [out, retval]

 Reference to the identifier of the interface describing the type of interface pointer to return in *asyncOperation*.

### `asyncOperation`

An [IAsyncOperation\<ProtectionPolicyEvaluationResult>](https://learn.microsoft.com/uwp/api/Windows.Foundation.IAsyncOperation_TResult_) with a value of the [ProtectionPolicyEvaluationResult](https://learn.microsoft.com/uwp/api/windows.security.enterprisedata.protectionpolicyevaluationresult) enumeration that is the result of the request.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IProtectionPolicyManagerInterop2](https://learn.microsoft.com/previous-versions/windows/desktop/api/efswrtinterop/nn-efswrtinterop-iprotectionpolicymanagerinterop2)