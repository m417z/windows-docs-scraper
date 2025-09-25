# ICertView::SetResultColumn

## Description

The **SetResultColumn** method specifies a column for the result set of a customized view of the Certificate Services database.

## Parameters

### `ColumnIndex` [in]

A zero-based index of a column to include in the result set.

## Return value

### VB

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

Before calling the **SetResultColumn** method, the [SetResultColumnCount](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-icertview-setresultcolumncount) method must be called to specify how many columns will be in the result set. Calls to the **SetResultColumn** method will fail under the following conditions:

* The number of columns has not been specified.
* **SetResultColumn** is called more times than the number of columns specified by the call to [SetResultColumnCount](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-icertview-setresultcolumncount).
* [SetResultColumnCount](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-icertview-setresultcolumncount) specified a predefined set of columns. This method specifies a predefined set of columns when its *cResultColumnCount* parameter is one of the following values:
  + CV_COLUMN_LOG_DEFAULT
  + CV_COLUMN_LOG_FAILED_DEFAULT
  + CV_COLUMN_QUEUE_DEFAULT

After a column is specified, an optional call to the
[SetRestriction](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-icertview-setrestriction) method can be used to specify sorting and qualifying restrictions for the column.

The **SetResultColumn** method must be called for each column that is needed in the result set. On successful completion of these calls, the columns specified in each call will be included in the result set when the [OpenView](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-icertview-openview) method is called.

#### Examples

```cpp
    HRESULT    hr;
    LONG       nCount;
    LONG       i;

    // Determine the number of columns in the entire database.
    // pCertView is a pointer to ICertView.
    hr = pCertView->GetColumnCount(FALSE, &nCount);
    if (FAILED(hr))
    {
        printf("Failed GetColumnCount - %x\n", hr);
        goto error;
    }
    hr = pCertView->SetResultColumnCount( nCount );
    if (FAILED(hr))
    {
        printf("Failed SetResultColumnCount - %x\n", hr);
        goto error;
    }
    // Place each column in the view.
    for (i = 0; i < nCount; i++)
    {
        hr = pCertView->SetResultColumn(i);
        if (FAILED(hr))
        {
            printf("Failed SetResultColumn (%d) - %x\n", i, hr );
            goto error;
        }
    }
    // Call ICertView::OpenView, and so on.
    // ...

error:
	{
		 // Clean up resources, and so on.
	}
```

## See also

[ICertView](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-icertview)

[ICertView2](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-icertview2)

[ICertView::OpenView](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-icertview-openview)

[ICertView::SetRestriction](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-icertview-setrestriction)

[ICertView::SetResultColumnCount](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-icertview-setresultcolumncount)