# IAzBizRuleParameters::AddParameters

## Description

The **AddParameters** method adds parameters to the list of parameters available to business rule (BizRule) scripts.

## Parameters

### `varParameterNames` [in]

The parameter names. This is a variant that contains either a [SAFEARRAY](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-safearray) or the JScript [Array](https://learn.microsoft.com/scripting/javascript/reference/array-object-javascript) object. Each element of the array holds a **VT_BSTR** that contains a parameter name. This array must be sorted alphabetically; the sort order is as defined by a case-sensitive [VarCmp](https://learn.microsoft.com/windows/desktop/api/oleauto/nf-oleauto-varcmp). The order of the *varParameterValues* array must match the order of this array.

### `varParameterValues` [in]

The values of the parameters that are available to BizRule scripts. This is a variant that contains either a [SAFEARRAY](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-safearray) or the JScript [Array](https://learn.microsoft.com/scripting/javascript/reference/array-object-javascript) object. Each element of the array holds a value that corresponds to an element in the *varParameterNames* array. The default value is **VT_NULL**. The entries in the array can hold any type except **VT_UNKNOWN** and **VT_DISPATCH**.

## Return value

 If the method succeeds, it returns **S_OK**.

If the method fails, it returns an error code. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[IAzBizRuleParameters](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazbizruleparameters)

[IAzClientContext3::BizRuleParameters](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazclientcontext3-get_bizruleparameters)