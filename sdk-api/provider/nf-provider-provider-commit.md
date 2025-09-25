# Provider::Commit

## Description

[The [Provider](https://learn.microsoft.com/windows/desktop/api/provider/nl-provider-provider) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **Commit** method is used to send an instance to WMI. This method is a helper function and should not be overridden.

## Parameters

### `pInstance`

Pointer to the instance to be stored by WMI.

### `bCache`

Indicates whether a cache is implemented. This value must be set to **FALSE** in the current version of the provider framework.

## Return value

Use the **SUCCEEDED** or **FAILED** macros on the returned HRESULT to determine if the method was successful.

## Remarks

If the client cancels the query, the **Commit** method returns an error. A provider writer can use this fact to terminate an enumeration.

Also, this method calls CInstance::Release on the *pInstance* pointer. Because of this, the framework provider must be careful not to call CInstance::Release again. This means that a *pInstance* smart pointer is incompatible with this method because the smart pointer calls CInstance::Release in its destructor.

This method should only be used when the framework provider does not call CInstance::Release on the *pInstance* pointer separately and if the *pInstance* pointer is not, and will never be, a smart pointer.