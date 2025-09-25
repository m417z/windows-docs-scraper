# ICertView::SetRestriction

## Description

The **SetRestriction** method sets the sorting and qualifying restrictions on a column.

## Parameters

### `ColumnIndex` [in]

A valid column index number for the view or a predefined column specifier. If the *ColumnIndex* parameter is not negative, this value represents the zero-based index of the column that is receiving the restriction.

If the *ColumnIndex* parameter is negative, all other parameters are ignored, and this parameter must be one of the following values:

| Value | Meaning |
|-------|---------|
| **CV_COLUMN_QUEUE_DEFAULT**<br>`-1` | Restricts view to requests that have not been resolved; if a request has resulted in either an issued certificate or a failed request, it will not be part of the view. |
| **CV_COLUMN_LOG_DEFAULT**<br>`-2` | Restricts view to requests that have been resolved. A request is resolved if it has resulted in an issued certificate or a failed request; revoked certificates are considered resolved. |
| **CV_COLUMN_LOG_FAILED_DEFAULT**<br>`-3` | Restricts view to requests that have failed. |

### `SeekOperator` [in]

Specifies the logical operator of the data-query qualifier for the column. This parameter is used with the *pvarValue* parameter to define the data-query qualifier.

This parameter must be set to one of the following values:

| Value | Meaning |
|-------|---------|
| **CVR_SEEK_EQ**<br>`0x1` | Equal to |
| **CVR_SEEK_LT**<br>`0x2` | Less than |
| **CVR_SEEK_LE**<br>`0x4` | Less than or equal to |
| **CVR_SEEK_GE**<br>`0x8` | Greater than or equal to |
| **CVR_SEEK_GT**<br>`0x10` | Greater than |

### `SortOrder` [in]

Specifies the sort order for the column. Indexed columns with zero or one restriction can include a sort order of **CVR_SORT_ASCEND** or **CVR_SORT_DESCEND**. Non-indexed columns or columns with two or more restrictions must use **CVR_SORT_NONE**.

| Value | Meaning |
|-------|---------|
| **CVR_SORT_NONE**<br>`0` | No sort order |
| **CVR_SORT_ASCEND**<br>`0x1` | Ascending |
| **CVR_SORT_DESCEND**<br>`0x2` | Descending |

### `pvarValue` [in]

Specifies the data query qualifier applied to this column. This parameter, along with the *SeekOperator* parameter, determines which data is returned to the Certificate Services view.

## Return value

If the method succeeds, the method returns **S_OK**.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/win32/SecCrypto/common-hresult-values).

## Remarks

The [ICertView](https://learn.microsoft.com/windows/win32/api/certview/nn-certview-icertview) object maintains an array of restrictions, allowing each column to contain any number of restrictions. After the column restrictions are established, a call to the [ICertView::OpenView](https://learn.microsoft.com/windows/win32/api/certview/nf-certview-icertview-openview) method will retrieve the data, with each column's restrictions used as part of the database query.

Before the **SetRestriction** method is called, it is necessary to establish a connection with the Certificate Service server by calling the[ICertView::OpenConnection](https://learn.microsoft.com/windows/win32/api/certview/nf-certview-icertview-openconnection) method.

#### Examples

```cpp
    // This example restricts the data
    // to rows that have RequestIDs greater than five.
    // pCertView is a pointer to ICertView.
    HRESULT    hr;
    VARIANT    varRest;
    LONG       nIndex;
    BSTR       bstrCol = NULL;

    // Use one column in the result set.
    hr = pCertView->SetResultColumnCount(1);
    if (FAILED(hr))
    {
        printf("Failed SetResultColumnCount - %x\n", hr);
        goto error;
    }
    // Determine the column index for RequestID column.
    bstrCol = SysAllocString(TEXT("RequestID"));
    hr = pCertView->GetColumnIndex(FALSE, bstrCol, &nIndex);
    if (FAILED(hr))
    {
        printf("Failed GetColumnIndex - %x\n", hr);
        goto error;
    }
    // Place this column into the result set.
    pCertView->SetResultColumn(nIndex);
    // Set a restriction on this column.
    VariantInit(&varRest);
    varRest.vt = VT_I4;
    varRest.lVal = 5;
    // Restrict view to requests with ID greater than 5.
    hr = pCertView->SetRestriction(nIndex,
                                   CVR_SEEK_GT,
                                   CVR_SORT_NONE,
                                   &varRest);
    if (S_OK != hr)
        printf("Failed ICertView::SetRestriction - %x\n", hr);
    else
    {
        // Call OpenView, process rows, release resources, and so on.
        // ...
    }
error:
    // Done processing, clear resources.
    VariantClear(&varRest);
    if (NULL != bstrCol)
        SysFreeString(bstrCol);
```

## See also

[ICertView](https://learn.microsoft.com/windows/win32/api/certview/nn-certview-icertview)

[ICertView2](https://learn.microsoft.com/windows/win32/api/certview/nn-certview-icertview2)

[ICertView::OpenConnection](https://learn.microsoft.com/windows/win32/api/certview/nf-certview-icertview-openconnection)

[ICertView::OpenView](https://learn.microsoft.com/windows/win32/api/certview/nf-certview-icertview-openview)

[ICertView::SetResultColumn](https://learn.microsoft.com/windows/win32/api/certview/nf-certview-icertview-setresultcolumn)

[IEnumCertViewColumn::IsIndexed](https://learn.microsoft.com/windows/win32/api/certview/nf-certview-ienumcertviewcolumn-isindexed)