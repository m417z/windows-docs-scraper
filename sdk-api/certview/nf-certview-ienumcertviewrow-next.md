# IEnumCERTVIEWROW::Next

## Description

The **Next** method moves to the next row in the row-enumeration sequence.

## Parameters

### `pIndex` [out]

A pointer to a variable that contains the index value of the next row being referenced. If there are no more rows to enumerate, this variable will be set to –1. This method fails if *pIndex* is **NULL**.

## Return value

### C++

If the method succeeds, the method returns S_OK and the next row is now being referenced by the row-enumeration sequence. If there are no more rows to enumerate, S_FALSE is returned, and *pIndex* is set to a value of –1.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The return value is the index value of the row that is now being referenced by the row-enumeration sequence. If there are no more rows to enumerate, the return value is –1.

## Remarks

Upon successful completion of this method, the
columns, attributes, and extensions associated with the certificate in the row can be enumerated using the methods of the following interfaces:

* [IEnumCERTVIEWCOLUMN](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-ienumcertviewcolumn)
* [IEnumCERTVIEWATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-ienumcertviewattribute)
* [IEnumCERTVIEWEXTENSION](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-ienumcertviewextension)

Looping through all the rows in the enumeration sequence can be resource-intensive to compute, depending of the query involved and the size of the sequence.

#### Examples

```cpp
// pEnumRow is previously instantiated pointer to IEnumCERTVIEWROW.
LONG  Index;
LONG  nCount;

// Ensure enumerator is at first row.
if (FAILED(pEnumRow->Reset()))
    printf("Failed to Reset\n");
else
{
    nCount = 0;
    // Count the database records by enumerating the rows.
    while (S_OK == pEnumRow->Next(&Index))
        nCount++;
    // Display number of records.
    printf("Number of records is %d\n", nCount);
}
```

## See also

[IEnumCERTVIEWATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-ienumcertviewattribute)

[IEnumCERTVIEWCOLUMN](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-ienumcertviewcolumn)

[IEnumCERTVIEWEXTENSION](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-ienumcertviewextension)

[IEnumCERTVIEWROW](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-ienumcertviewrow)