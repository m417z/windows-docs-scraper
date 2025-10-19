# ICertProperties::Add

## Description

The **Add** method adds a property to the collection. This method is web enabled.

## Parameters

### `pVal` [in]

Pointer to an [ICertProperty](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertproperty) interface that represents the property to add to the collection.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code/value | Description |
| --- | --- |
| **HRESULT_FROM_WIN32(ERROR_FILE_EXISTS)** | An item in the collection has the same ID as the property you specified. |

## See also

[ICertProperties](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertproperties)

[ICertProperty](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertproperty)