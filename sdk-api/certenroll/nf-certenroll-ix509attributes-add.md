# IX509Attributes::Add

## Description

The **Add** method adds an [IX509Attribute](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509attribute) object to the collection.

## Parameters

### `pVal` [in]

Pointer to an [IX509Attribute](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509attribute) interface that represents the attribute to add to the collection.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[IX509Attribute](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509attribute)

[IX509AttributeExtensions](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509attributeextensions)

[IX509Attributes](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509attributes)