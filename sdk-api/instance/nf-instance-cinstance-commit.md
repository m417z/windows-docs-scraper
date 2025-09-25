# CInstance::Commit

## Description

[The [CInstance](https://learn.microsoft.com/windows/desktop/api/instance/nl-instance-cinstance) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **Commit** method returns the current instance to WMI.

## Return value

Use the **SUCCEEDED** or **FAILED** macro on the returned **HRESULT** to determine success or failure of the method.

## Remarks

If the client cancels the query, the **Commit** method returns an error. A provider writer can use this fact to terminate an enumeration.

Also, framework providers should call this method to commit rather than [Provider::Commit](https://learn.microsoft.com/windows/desktop/api/provider/nf-provider-provider-commit). **Provider::Commit** calls **CInstance::Release** automatically. Smart [CInstance](https://learn.microsoft.com/windows/desktop/api/instance/nl-instance-cinstance) pointers cannot be used in this case because the smart **CInstance** pointer would call **CInstance::Release** in its destructor. If the release has already occurred, an exception will result. Issues of this type are best resolved by allowing the **CInstance** instance, or a smart pointer to it, to call **CInstance::Release** when it is appropriate.