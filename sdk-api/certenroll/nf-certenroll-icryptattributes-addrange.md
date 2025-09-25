# ICryptAttributes::AddRange

## Description

The **AddRange** method adds a range of [ICryptAttribute](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icryptattribute) objects to the collection. The attributes are contained in another [ICryptAttributes](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icryptattributes) collection.

## Parameters

### `pValue` [in]

Pointer to an [ICryptAttributes](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icryptattributes) interface that contains the attribute collection to add.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[ICryptAttribute](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icryptattribute)

[ICryptAttributes](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icryptattributes)

[IX509Attribute](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509attribute)

[IX509AttributeExtensions](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509attributeextensions)

[IX509Attributes](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509attributes)