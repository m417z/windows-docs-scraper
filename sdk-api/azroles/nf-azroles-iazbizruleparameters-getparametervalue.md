# IAzBizRuleParameters::GetParameterValue

## Description

The **GetParameterValue** method gets the value type of the business rule (BizRule) parameter with the specified name.

## Parameters

### `bstrParameterName` [in]

A string that contains the parameter name.

### `pvarParameterValue` [out]

A pointer to the data type of the parameter value.

## Return value

 If the method succeeds, it returns **S_OK**.

If the method fails, it returns an error code. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[IAzBizRuleParameters](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazbizruleparameters)

[IAzClientContext3::BizRuleParameters](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazclientcontext3-get_bizruleparameters)