# Provider::Flush

## Description

[The [Provider](https://learn.microsoft.com/windows/desktop/api/provider/nl-provider-provider) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **Flush** method is called by the provider framework to delete all unnecessary memory in use by the provider. Because your provider may be called again after a call to **Flush**, you must re-create any objects released by **Flush**. If you override this method, you should call the parent object's **Flush** method to release any framework memory associated with your provider.

## Remarks

Override this method only if your framework provider allocates memory that can be flushed. If your provider chooses to override, include a call to **Provider::Flush** in the provider's implementation.

**Note** Because your provider may be called after a call to **Flush**, you must be prepared to re-create any items released by the call to **Flush**.