# IObjectContext::IsSecurityEnabled

## Description

Indicates whether security is enabled for the current object. COM+ security is enabled unless the object is running in the client's process.

## Return value

If security is enabled for this object, the return value is **TRUE**. Otherwise, it is **FALSE**.

## Remarks

In the COM+ environment, server and library applications can use role-based security. **IsSecurityEnabled** returns **TRUE** when an application uses role-based security, and role-based security is enabled both for the application and the specific component that called the method.

**MTS 2.0:** In MTS 2.0, this method always returns **FALSE** when the current object is running in a library application, because MTS library applications cannot use role-based security. However, in the COM+ environment, library applications optionally can use role-based security.

## See also

[IObjectContext](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iobjectcontext)