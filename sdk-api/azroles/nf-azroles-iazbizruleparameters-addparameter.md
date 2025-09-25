# IAzBizRuleParameters::AddParameter

## Description

The **AddParameter** method adds a parameter to the list of parameters available to business rule (BizRule) scripts.

## Parameters

### `bstrParameterName` [in]

A string that contains the parameter name.

### `varParameterValue` [in]

The data type of the parameter value.

## Return value

 If the method succeeds, it returns **S_OK**.

If the method fails, it returns an error code. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[IAzBizRuleParameters](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazbizruleparameters)

[IAzClientContext3::BizRuleParameters](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazclientcontext3-get_bizruleparameters)