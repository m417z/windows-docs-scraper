# WMIQ_RPN_TOKEN_FLAGS enumeration

## Description

Contains flags that describe query tokens used in the [GetAnalysis](https://learn.microsoft.com/windows/desktop/api/wmiutils/nf-wmiutils-iwbemquery-getanalysis) method.

## Constants

### `WMIQ_RPN_TOKEN_EXPRESSION:1`

This token is an expression, for example, J = 7.

### `WMIQ_RPN_TOKEN_AND:2`

This token is a logical AND.

### `WMIQ_RPN_TOKEN_OR:3`

This token is a logical OR.

### `WMIQ_RPN_TOKEN_NOT:4`

This token is a logical NOT.

### `WMIQ_RPN_OP_UNDEFINED:0`

The operator is undefined or unknown.

### `WMIQ_RPN_OP_EQ:1`

The operator is equal-to (=).

### `WMIQ_RPN_OP_NE:2`

The operator is not-equal-to (<>).

### `WMIQ_RPN_OP_GE:3`

The operator is greater-than-or-equal-to (>=).

### `WMIQ_RPN_OP_LE:4`

The operator is less-than-or-equal-to (<=).

### `WMIQ_RPN_OP_LT:5`

The operator is less-than (<) .

### `WMIQ_RPN_OP_GT:6`

The operator is greater-than (>).

### `WMIQ_RPN_OP_LIKE:7`

The operator is LIKE.

### `WMIQ_RPN_OP_ISA:8`

The operator is ISA.

### `WMIQ_RPN_OP_ISNOTA:9`

The operator is ISNOTA.

### `WMIQ_RPN_OP_ISNULL:10`

The operator is ISNULL.

### `WMIQ_RPN_OP_ISNOTNULL:11`

The operator is ISNOTNULL.

### `WMIQ_RPN_LEFT_PROPERTY_NAME:0x1`

Left argument is a property name.

### `WMIQ_RPN_RIGHT_PROPERTY_NAME:0x2`

Right argument is a property name.

### `WMIQ_RPN_CONST2:0x4`

Has a second constant. Used with "BETWEEN" clauses.

### `WMIQ_RPN_CONST:0x8`

Has a constant.

### `WMIQ_RPN_RELOP:0x10`

The field **m_uOperator** is not 0 (zero).

### `WMIQ_RPN_LEFT_FUNCTION:0x20`

Left argument is a function.

### `WMIQ_RPN_RIGHT_FUNCTION:0x40`

Right argument is a function.

### `WMIQ_RPN_GET_TOKEN_TYPE:1`

Reserved for future use.

### `WMIQ_RPN_GET_EXPR_SHAPE:2`

Reserved for future use.

### `WMIQ_RPN_GET_LEFT_FUNCTION:3`

Reserved for future use.

### `WMIQ_RPN_GET_RIGHT_FUNCTION:4`

Reserved for future use.

### `WMIQ_RPN_GET_RELOP:5`

Reserved for future use.

### `WMIQ_RPN_NEXT_TOKEN:1`

Reserved for future use.

### `WMIQ_RPN_FROM_UNARY:0x1`

FROM clause contains a single class.

### `WMIQ_RPN_FROM_PATH:0x2`

FROM clause contains an object path.

### `WMIQ_RPN_FROM_CLASS_LIST:0x4`

FROM clause contains a list of classes.

### `WMIQ_RPN_FROM_MULTIPLE:0x8`

Reserved for future use.