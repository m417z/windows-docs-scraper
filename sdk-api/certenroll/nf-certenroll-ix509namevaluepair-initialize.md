# IX509NameValuePair::Initialize

## Description

The **Initialize** method initializes the object from strings that contain the name and associated value.

## Parameters

### `strName` [in]

A **BSTR** variable that contains the name.

### `strValue` [in]

A **BSTR** variable that contains the value.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

You can call the [Name](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509namevaluepair-get_name) and [Value](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509namevaluepair-get_value) properties to retrieve the values initialized by calling this method.

## See also

[IX509NameValuePair](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509namevaluepair)

[Name](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509namevaluepair-get_name)

[Value](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509namevaluepair-get_value)