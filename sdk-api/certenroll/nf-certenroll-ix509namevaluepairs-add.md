# IX509NameValuePairs::Add

## Description

The **Add** method adds an [IX509NameValuePair](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509namevaluepair) object to the collection.

## Parameters

### `pVal` [in]

A pointer to an [IX509NameValuePair](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509namevaluepair) interface that represents the name-value pair to add.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[IX509NameValuePair](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509namevaluepair)

[IX509NameValuePairs](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509namevaluepairs)