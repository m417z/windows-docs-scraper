# ICryptAttribute::InitializeFromValues

## Description

The **InitializeFromValues** method initializes a cryptographic attribute by using an [IX509Attributes](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509attributes) object.

## Parameters

### `pAttributes` [in]

Pointer to an [IX509Attributes](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509attributes) interface that contains the attribute collection.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

The **InitializeFromValues** method uses the first [IX509Attribute](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509attribute) object in the collection.

## See also

[ICryptAttribute](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icryptattribute)

[ICryptAttributes](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icryptattributes)

[IX509Attribute](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509attribute)

[IX509Attributes](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509attributes)