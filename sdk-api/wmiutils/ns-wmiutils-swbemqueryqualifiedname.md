# SWbemQueryQualifiedName structure

## Description

The **SWbemQueryQualifiedName** structure stores property names for the [IWbemQuery::GetAnalysis](https://learn.microsoft.com/windows/desktop/api/wmiutils/nf-wmiutils-iwbemquery-getanalysis) method.

## Members

### `m_uVersion`

Unused. Always 1 (one).

### `m_uTokenType`

Unused. Always 1 (one).

### `m_uNameListSize`

Number of elements in the list of names. For example, for the "propName" property, **m_uNameListSize** is 1 (one) and **m_ppszNameList** is "propName".

### `m_ppszNameList`

List of property names. For example, for the "propName" property, **m_uNameListSize** is 1 (one) and **m_ppszNameList** is "propName".

### `m_bArraysUsed`

Unused. Always **false**.

### `m_pbArrayElUsed`

Unused. Always **NULL**.

### `m_puArrayIndex`

Unused. Always **NULL**.

## See also

[IWbemQuery](https://learn.microsoft.com/windows/desktop/api/wmiutils/nn-wmiutils-iwbemquery)

[IWbemQuery::GetAnalysis](https://learn.microsoft.com/windows/desktop/api/wmiutils/nf-wmiutils-iwbemquery-getanalysis)

[SWbemRpnEncodedQuery](https://learn.microsoft.com/windows/win32/api/wmiutils/ns-wmiutils-swbemrpnencodedquery)