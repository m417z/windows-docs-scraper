# ICertView::GetColumnIndex

## Description

The **GetColumnIndex** method retrieves the zero-based index of a column.

## Parameters

### `fResultColumn` [in]

Specifies the column. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CVRC_COLUMN_SCHEMA** | Schema column information. |
| **CVRC_COLUMN_RESULT** | Result column information. |
| **CVRC_COLUMN_VALUE** | Value column information. |
| **CVRC_COLUMN_MASK** | Column information mask. |

### `strColumnName` [in]

A string that contains the nonlocalized name of a column in the view.

### `pColumnIndex` [out, retval]

The address of a variable that will contain the index of the column specified in the *strColumnName* parameter. This method fails if *pColumnIndex* is **NULL**.

## Return value

### C++

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The return value is the zero-based index of the column.

## Remarks

This method is used to determine the index of the column specified by the *strColumnName* parameter. The column indices are zero-based (the first column is index zero).

## See also

[ICertView](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-icertview)

[ICertView2](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-icertview2)

[ICertView::SetRestriction](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-icertview-setrestriction)