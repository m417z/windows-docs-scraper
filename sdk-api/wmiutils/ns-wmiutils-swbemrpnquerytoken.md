# SWbemRpnQueryToken structure

## Description

The **SWbemRpnQueryToken** structure represents the query tokens in a WMIQ_ANALYSIS_RPN_SEQUENCE type query. An example of a query token is the following: j > 4.

## Members

### `m_uVersion`

Unused. Always 1.

### `m_uTokenType`

Type of token this instance represents.

#### WMIQ_RPN_TOKEN_EXPRESSION (1)

This token is an expression, for example, J = 7.

#### WMIQ_RPN_TOKEN_AND (2)

This token is a logical AND.

#### WMIQ_RPN_TOKEN_OR (3)

This token is a logical OR.

#### WMIQ_RPN_TOKEN_NOT (4)

This token is a logical NOT.

### `m_uSubexpressionShape`

If the **m_uTokenType** member is **WMIQ_RPN_TOKEN_EXPRESSION**, **m_uSubexpressionShape** bitmask value specifies the shape of the expression.

#### WMIQ_RPN_LEFT_PROPERTY_NAME (1 (0x1))

Left argument is a property name.

#### WMIQ_RPN_RIGHT_PROPERTY_NAME (2 (0x2))

Right argument is a property name.

#### WMIQ_RPN_CONST2 (4 (0x4))

Has a second constant. Used with "BETWEEN" clauses.

#### WMIQ_RPN_CONST (8 (0x8))

Has a constant.

#### WMIQ_RPN_RELOP (16 (0x10))

The field **m_uOperator** is not 0 (zero).

#### WMIQ_RPN_LEFT_FUNCTION (32 (0x20))

Left argument is a function.

#### WMIQ_RPN_RIGHT_FUNCTION (64 (0x40))

Right argument is a function.

### `m_uOperator`

This field can have the value 0 (zero), or one of the following values.

#### WMIQ_RPN_OP_UNDEFINED (0 (0x0))

The operator is undefined or unknown.

#### WMIQ_RPN_OP_EQ (1 (0x1))

The operator is equal-to (=).

#### WMIQ_RPN_OP_NE (2 (0x2))

The operator is not-equal-to (<>).

#### WMIQ_RPN_OP_GE (3 (0x3))

The operator is greater-than-or-equal-to (>=).

#### WMIQ_RPN_OP_LE (4 (0x4))

The operator is less-than-or-equal-to (<=).

#### WMIQ_RPN_OP_LT (5 (0x5))

The operator is less-than (<) .

#### WMIQ_RPN_OP_GT (6 (0x6))

The operator is greater-than (>).

#### WMIQ_RPN_OP_LIKE (7 (0x7))

The operator is LIKE.

#### WMIQ_RPN_OP_ISA (8 (0x8))

The operator is ISA.

#### WMIQ_RPN_OP_ISNOTA (9 (0x9))

The operator is ISNOTA.

#### WMIQ_RPN_OP_ISNULL (10 (0xA))

The operator is ISNULL.

#### WMIQ_RPN_OP_ISNOTNULL (11 (0xB))

The operator is ISNOTNULL.

### `m_pRightIdent`

If there are two property names in a token, **m_pRightIdent** is used to identify the right property name.

### `m_pLeftIdent`

If there are two property names in a token **m_pLeftIdent** is used to identify the left property name. If only one property name is present, it appears in this member.

### `m_uConstApparentType`

Apparent data type of the constant.

#### VT_I4 (3 (0x3))

Long data type.

#### VT_R8 (5 (0x5))

Double precision floating-point data type.

#### VT_BOOL (11 (0xB))

Boolean data type

#### VT_UI4 (19 (0x13))

Unsigned long data type.

#### VT_I8 (20 (0x14))

Signed 64-bit integer.

#### VT_UI8 (21 (0x15))

Unsigned 64-bit integer.

#### VT_LPWSTR (31 (0x1F))

LPCWSTR data type.

### `m_Const`

Value of the first constant. For more information, see [SWbemRpnConst](https://learn.microsoft.com/windows/win32/api/wmiutils/ns-wmiutils-swbemrpnquerytoken).

### `m_uConst2ApparentType`

Type of second constant. The fields **m_uConst2ApparentType** and **m_uConst2** are used only for BETWEEN phrases.

#### VT_I4 (3 (0x3))

Long data type.

#### VT_R8 (5 (0x5))

Double precision floating-point data type.

#### VT_BOOL (11 (0xB))

Boolean data type.

#### VT_UI4 (19 (0x13))

Unsigned long data type.

#### VT_I8 (20 (0x14))

Signed 64-bit integer.

#### VT_UI8 (21 (0x15))

Unsigned 64-bit integer.

#### VT_LPWSTR (31 (0x1F))

LPCWSTR data type.

### `m_Const2`

Value of the second constant. The fields **m_uConst2ApparentType** and **m_uConst2** are used only for BETWEEN phrases. For more information, see [SWbemRpnConst](https://learn.microsoft.com/windows/win32/api/wmiutils/ns-wmiutils-swbemrpnquerytoken).

### `m_pszRightFunc`

Specifies a function on the right of the operator in a WHERE clause. If there is no function on the right of the operator in this token, this field is **NULL**.

### `m_pszLeftFunc`

Specifies a function on the left of the operator in a WHERE clause. If there is no function on the left of the operator in this token, this field is **NULL**.

## See also

[IWbemQuery](https://learn.microsoft.com/windows/desktop/api/wmiutils/nn-wmiutils-iwbemquery)

[IWbemQuery::GetAnalysis](https://learn.microsoft.com/windows/desktop/api/wmiutils/nf-wmiutils-iwbemquery-getanalysis)

[SWbemRpnConst](https://learn.microsoft.com/windows/win32/api/wmiutils/ns-wmiutils-swbemrpnquerytoken)

[SWbemrpnEncodedQuery](https://learn.microsoft.com/windows/win32/api/wmiutils/ns-wmiutils-swbemrpnencodedquery)