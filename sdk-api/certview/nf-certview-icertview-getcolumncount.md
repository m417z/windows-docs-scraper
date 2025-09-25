# ICertView::GetColumnCount

## Description

The **GetColumnCount** method retrieves the number of columns in the view of the Certificate Services database.

## Parameters

### `fResultColumn` [in]

Specifies the column. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CVRC_COLUMN_SCHEMA** | Schema column information. |
| **CVRC_COLUMN_RESULT** | Result column information. |
| **CVRC_COLUMN_VALUE** | Value column information. |
| **CVRC_COLUMN_MASK** | Column information mask. |

### `pcColumn` [out]

A pointer to a variable that contains the number of columns in the view. This function will fail if the *pcColumn* parameter is **NULL**.

## Return value

### C++

If the method succeeds, the method returns S_OK, and the *pcColumn* parameter is set to the number of columns in the view.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The return value is the number of columns in the view.

## Remarks

This method is used to determine the number of columns in the view. The returned number represents the count of a result set's columns if *fResultColumn* is **TRUE** or the count of the full database schema's columns if *fResultColumn* is **FALSE**.

## See also

[CCertView](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-icertview2)

[ICertView](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-icertview)

[ICertView::SetResultColumnCount](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-icertview-setresultcolumncount)