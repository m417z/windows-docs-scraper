# SWbemRpnEncodedQuery structure

## Description

The **SWbemRpnEncodedQuery** structure contains information from the [IWbemQuery::GetAnalysis](https://learn.microsoft.com/windows/desktop/api/wmiutils/nf-wmiutils-iwbemquery-getanalysis) method when you use the **WMIQ_ANALYSIS_RPN_SEQUENCE** analysis type. Not all the fields in the structure are used actively, because some are reserved for future use.

## Members

### `m_uVersion`

Unused. Value is always 1.

### `m_uTokenType`

Unused. Value is always 0 (zero).

### `m_uParsedFeatureMask`

Unused. Value is always 0 (zero).

### `m_uDetectedArraySize`

Unused. Value is always 0 (zero).

### `m_puDetectedFeatures`

Unused. Value is always **NULL**.

### `m_uSelectListSize`

Number of elements listed in a SELECT clause. For example, in the statement `SELECT a,b,c FROM d`, **m_uSelectListSize** is the value 3 (a, b and c).

### `m_ppSelectList`

Structure used to store property names. This field is used with the **m_uSelectListSize** field. For example, in the statement `SELECT a,b,c FROM d`, **m_uSelectListSize** is 3, and the **m_ppszNameList** field of the **m_ppSelectList** structure contains the strings "a", "b" and "c". For more information, see [SWbemQueryQualifiedName](https://learn.microsoft.com/windows/win32/api/wmiutils/ns-wmiutils-swbemqueryqualifiedname).

### `m_uFromTargetType`

Bitmap used to indicate the form of the FROM clause.

#### WMIQ_RPN_FROM_UNARY (1 (0x1))

FROM clause contains a single class.

#### WMIQ_RPN_FROM_PATH (2 (0x2))

FROM clause contains an object path.

#### WMIQ_RPN_FROM_CLASS_LIST (4 (0x4))

FROM clause contains a list of classes.

### `m_pszOptionalFromPath`

Optional FROM path. If not used this field is **NULL**.

### `m_uFromListSize`

Number of items in the FROM clause of the SELECT statement. For example, in the statement, `SELECT * FROM a, b`, the value of **m_uFromListSize** is 2.

### `m_ppszFromList`

Pointer to a list of strings. Each string is one element of the FROM clause of a SELECT statement. For example, in the statement `SELECT * FROM a, b`, the list contains the strings "a" and "b".

### `m_uWhereClauseSize`

Number of tokens in the WHERE clause. For example, in the statement `SELECT * FROM a, b WHERE c < 1000 AND d ISA e`, the value of **m_uWhereClauseSize** is 2 (the phrases `c < 1000` and `d ISA e`).

### `m_ppRpnWhereClause`

[SWbemRpnQueryToken](https://learn.microsoft.com/windows/win32/api/wmiutils/ns-wmiutils-swbemrpnquerytoken)
`SELECT * FROM a, b WHERE c < 1000 AND d ISA e`
`c < 1000`
`d ISA e`
`AND`

### `m_dblWithinPolling`

If there is a WITHIN clause, this field indicates the polling interval. If there is a GROUP WITHIN clause, this **m_dblWithinPolling** is unused.

### `m_dblWithinWindow`

Used if there is a GROUP WITHIN clause to indicate the interval over which to group results.

### `m_uOrderByListSize`

### `m_ppszOrderByList`

### `m_uOrderDirectionEl`

## See also

[IWbemQuery](https://learn.microsoft.com/windows/desktop/api/wmiutils/nn-wmiutils-iwbemquery)

[SWbemQueryQualifiedName](https://learn.microsoft.com/windows/win32/api/wmiutils/ns-wmiutils-swbemqueryqualifiedname)

[SWbemRpnQueryToken](https://learn.microsoft.com/windows/win32/api/wmiutils/ns-wmiutils-swbemrpnquerytoken)