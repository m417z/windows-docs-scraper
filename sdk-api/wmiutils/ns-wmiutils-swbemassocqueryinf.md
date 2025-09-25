# SWbemAssocQueryInf structure

## Description

The **SWbemAssocQueryInf** structure contains information from the [IWbemQuery::GetAnalysis](https://learn.microsoft.com/windows/desktop/api/wmiutils/nf-wmiutils-iwbemquery-getanalysis) method when you use the **WMIQ_ANALYSIS_ASSOC_QUERY** analysis type.

## Members

### `m_uVersion`

Value must be 2.

### `m_uAnalysisType`

Value must be 2.

### `m_uFeatureMask`

Bit values that indicate the features in a query.

#### WMIQ_ASSOCQ_ASSOCIATORS (1 (0x1))

Associators exist in the query.

#### WMIQ_ASSOCQ_REFERENCES (2 (0x2))

References exist in the query.

#### WMIQ_ASSOCQ_RESULTCLASS (4 (0x4))

A result class is specified in the query.

#### WMIQ_ASSOCQ_ASSOCCLASS (8 (0x8))

An association class is specified in the query.

#### WMIQ_ASSOCQ_ROLE (16 (0x10))

A role is specified in the query.

#### WMIQ_ASSOCQ_RESULTROLE (32 (0x20))

A result role is specified in the query.

#### WMIQ_ASSOCQ_REQUIREDQUALIFIER (64 (0x40))

Required qualifiers are specified in the query.

#### WMIQ_ASSOCQ_REQUIREDASSOCQUALIFIER (128 (0x80))

Required association qualifiers are specified in the query.

#### WMIQ_ASSOCQ_CLASSDEFONLY (256 (0x100))

The query specifies class definitions only.

#### WMIQ_ASSOCQ_KEYSONLY (512 (0x200))

The query contains the **KEYSONLY** keyword.

#### WMIQ_ASSOCQ_SCHEMAONLY (1024 (0x400))

The query returns only the schema.

#### WMIQ_ASSOCQ_CLASSREFSONLY (2048 (0x800))

The query returns only the class references.

### `m_pPath`

Pointer to an [IWbemPath](https://learn.microsoft.com/windows/desktop/api/wmiutils/nn-wmiutils-iwbempath) object.

### `m_pszPath`

String representation of the object path used in the query.

### `m_pszQueryText`

Text of the original query.

### `m_pszResultClass`

String representation of the result class. If there is no result class, this field is **NULL**.

### `m_pszAssocClass`

String representation of the association class. If there is no result class, this field is **NULL**.

### `m_pszRole`

String representation of the role. If there is no role, this field is **NULL**.

### `m_pszResultRole`

String representation of the result role. If there is no result role, this field is **NULL**.

### `m_pszRequiredQualifier`

String representation of the required qualifier. If no qualifiers are required, this field is **NULL**.

### `m_pszRequiredAssocQualifier`

Pointer to a list of required association qualifiers.

## See also

[IWbemQuery](https://learn.microsoft.com/windows/desktop/api/wmiutils/nn-wmiutils-iwbemquery)

[IWbemQuery::GetAnalysis](https://learn.microsoft.com/windows/desktop/api/wmiutils/nf-wmiutils-iwbemquery-getanalysis)