# ICertView::EnumCertViewColumn

## Description

The **EnumCertViewColumn** method obtains an instance of a column-enumeration sequence for the database schema.

Note that this enumeration sequence cannot be used to enumerate the column values, only the database schema. Use
[IEnumCERTVIEWROW::EnumCertViewColumn](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewrow-enumcertviewcolumn) if you need to enumerate the data values of the columns.

## Parameters

### `fResultColumn` [in]

Specifies the column. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CVRC_COLUMN_SCHEMA** | Schema column information. |
| **CVRC_COLUMN_RESULT** | Result column information. |
| **CVRC_COLUMN_VALUE** | Value column information. |
| **CVRC_COLUMN_MASK** | Column information mask. |

### `ppenum` [out]

A pointer to a pointer of [IEnumCERTVIEWCOLUMN](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-ienumcertviewcolumn) type. This method fails if the *ppenum* parameter is **NULL**.

## Return value

### C++

If the method succeeds, the method returns S_OK, and **ppenum* is set to a pointer of [IEnumCERTVIEWCOLUMN](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-ienumcertviewcolumn) type.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The return value is an [IEnumCERTVIEWCOLUMN](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-ienumcertviewcolumn) object.

## Remarks

The
[IEnumCERTVIEWCOLUMN](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-ienumcertviewcolumn) object can be used to enumerate the view's columns and retrieve each column's information.

## See also

[EnumCERTVIEWCOLUMN](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-ienumcertviewcolumn)

[ICertView](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-icertview)

[ICertView2](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-icertview2)