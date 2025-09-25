# IAzClientContext::GetRoles

## Description

The **GetRoles** method returns the roles for the client context.

## Parameters

### `bstrScopeName` [in, optional]

Name of the [IAzScope](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazscope) object from which the roles returned in the *pvarRoleNames* parameter are applicable. If this property is **NULL**, the roles from the application scope are returned; otherwise, the roles from the specified scope are returned instead of the roles from the application scope.

### `pvarRoleNames` [out]

A pointer to a **VARIANT** used to return a [SAFEARRAY](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-safearray). Each element of the **SAFEARRAY** is a **VARIANT** of type **BSTR** that contains the name of a role to which the client belongs at the scope specified by the *bstrScopeName* parameter.

## Return value

The return value is an **HRESULT**. A value of S_OK indicates success. Any other value indicates that the operation failed.

## Remarks

In JScript, the returned [SAFEARRAY](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-safearray) must be converted to the JScript [Array](https://learn.microsoft.com/scripting/javascript/reference/array-object-javascript) object.