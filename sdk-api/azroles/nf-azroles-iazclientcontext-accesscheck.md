# IAzClientContext::AccessCheck

## Description

The **AccessCheck** method determines whether the current client context is allowed to perform the specified operations.

## Parameters

### `bstrObjectName` [in]

The name of the accessed object. This string is used in audits.

### `varScopeNames` [in]

A variant that contains either a [SAFEARRAY](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-safearray) or the JScript [Array](https://learn.microsoft.com/scripting/javascript/reference/array-object-javascript) object. Each element of the array holds a **VT_BSTR** that contains the name of a scope that the object specified by the *bstrObjectName* parameter matches. The array can contain only one element. To use the default application level scope, set the first entry in the array to an empty string ("") or **VT_EMPTY**, or pass **VT_EMPTY** in to this parameter.

### `varOperations` [in]

The operations for which access by the client context is checked. This is a variant that contains either a [SAFEARRAY](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-safearray) or the JScript [Array](https://learn.microsoft.com/scripting/javascript/reference/array-object-javascript) object. Each element of the array holds a **VT_I2** or **VT_I4** that represents the [OperationID](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazoperation-get_operationid) property of an [IAzOperation](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazoperation) object in the [IAzApplication](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazapplication) policy.

### `varParameterNames` [in, optional]

The names of the parameters available to business rules (BizRules) through the [AzBizRuleContext::GetParameter](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazbizrulecontext-getparameter) method. This is a variant that contains either a [SAFEARRAY](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-safearray) or the JScript [Array](https://learn.microsoft.com/scripting/javascript/reference/array-object-javascript) object. Each element of the array holds a **VT_BSTR** that contains a parameter name. This array must be sorted alphabetically by the caller; the sort order is as defined by a case-sensitive [VarCmp](https://learn.microsoft.com/windows/desktop/api/oleauto/nf-oleauto-varcmp). The order of the *varParameterValues* array must match the order of this array. The default value is **VT_NULL**.

### `varParameterValues` [in, optional]

The values of the parameters that are available to business rules (BizRules) through the [AzBizRuleContext::GetParameter](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazbizrulecontext-getparameter) method. This is a variant that contains either a [SAFEARRAY](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-safearray) or the JScript [Array](https://learn.microsoft.com/scripting/javascript/reference/array-object-javascript) object. Each element of the array holds a value that corresponds to an element in the *varParameterNames* array. The default value is **VT_NULL**. The entries in the array can hold any type except **VT_UNKNOWN** and **VT_DISPATCH**.

### `varInterfaceNames` [in, optional]

The names by which the interfaces in the *varInterfaces* array will be known in a BizRule script. This is a variant that contains either a [SAFEARRAY](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-safearray) or the JScript [Array](https://learn.microsoft.com/scripting/javascript/reference/array-object-javascript) object. Each element of the array holds a string variant that contains an interface name. This method calls the [IActiveScript::AddNamedItem](https://learn.microsoft.com/scripting/winscript/reference/iactivescript-addnameditem) method for each entry in the array. The default value is **VT_NULL**.

### `varInterfaceFlags` [in, optional]

Flags that will be passed in the call to [IActiveScript::AddNamedItem](https://learn.microsoft.com/scripting/winscript/reference/iactivescript-addnameditem). This is a variant that contains either a [SAFEARRAY](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-safearray) or the JScript [Array](https://learn.microsoft.com/scripting/javascript/reference/array-object-javascript) object. Each element of the array holds a **VT_I4**. The SCRIPTITEM_ISVISIBLE flag is implied; the SCRIPTITEM_ISPERSISTENT flag is ignored. Each entry in the array must match the corresponding element in the *varInterfaceNames* array. The default value is **VT_NULL**.

### `varInterfaces` [in, optional]

The [IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch) interfaces that will be made available to the BizRule script. This is a variant that contains either a [SAFEARRAY](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-safearray) or the JScript [Array](https://learn.microsoft.com/scripting/javascript/reference/array-object-javascript) object. Each element of the array holds an **IDispatch** interface. Each entry in the array must match the corresponding element in the *varInterfaceNames* array. The default value is **VT_NULL**.

### `pvarResults` [out]

A pointer to a **VARIANT** used to return a [SAFEARRAY](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-safearray) that contains the results of the access check. Each element of the **SAFEARRAY** is a **VARIANT** of type **VT_I4**. Each entry in the array matches the corresponding element in the *varOperations* array. If access to an operation is granted to the client context, a value of NO_ERROR is returned in the corresponding element in the *pvarResults* array. Any other value indicates that access to that operation is not granted. A typical value that indicates failure is ERROR_ACCESS_DENIED.

In JScript, the returned [SAFEARRAY](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-safearray) must be converted to the JScript [Array](https://learn.microsoft.com/scripting/javascript/reference/array-object-javascript) object.

## Return value

If the method succeeds, the method returns NO_ERROR.

If the method fails, it returns an **HRESULT** value that indicates the status of the method, not the result of the access check. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code/value | Description |
| --- | --- |
| **ERROR_FILE_CORRUPT** | This error code can be returned if an Active Directory authorization store is used and the administration of the scope has been delegated. The task and role definitions within a delegated scope cannot have BizRules. If a task or role definition within a delegated scope contains a BizRule (this is possible if the store is corrupted), the [AccessCheck](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazclientcontext-accesscheck) method will fail. |
| **OLESCRIPT_E_SYNTAX** | The BizRule used to evaluate access contains a syntax error. |

## Remarks

If the [RoleForAccessCheck](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazclientcontext-get_roleforaccesscheck) property is defined in the client context, the **AccessCheck** method will be performed only on that role.

When this method is called, the application group membership is added to the client context so that it does not need to be recomputed for subsequent access checks on the same client context.

This method cannot be called by a BizRule.