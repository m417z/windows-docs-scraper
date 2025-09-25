# IOCSPPropertyCollection::GetAllProperties

## Description

The **GetAllProperties** method gets all properties in a property set.

## Parameters

### `pVarProperties` [out]

A pointer to a safe array that contains the properties as name-value pairs.

This array is a two-dimensional array of elements, each of type **VARIANT**. The array contains one row for each named property in the collection. Each row contains two columns: the property name and the property value.

## Return value

### C++

If the method succeeds, it returns **S_OK**.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

A safe array that contains the properties as name-value pairs.

This array is a two-dimensional array of elements, each of type **Variant**. The array contains one row for each named property in the collection. Each row contains two columns: the property name and the property value.

## See also

[IOCSPPropertyCollection](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-iocsppropertycollection)