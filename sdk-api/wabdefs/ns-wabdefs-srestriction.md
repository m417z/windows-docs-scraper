# SRestriction structure

## Description

Do not use. Describes a filter for limiting the view of a table to particular rows.

## Members

### `rt`

Type: **ULONG**

Variable of type **ULONG** that specifies the restriction type. The possible values are as follows.

#### RES_AND

**SRestriction** structure describes an AND restriction, which applies a bitwise AND operation to a restriction.

#### RES_BITMASK

**SRestriction** structure describes a bitmask restriction, which applies a bitmask to a property value.

#### RES_COMMENT

**SRestriction** structure describes a comment restriction, which associates a comment with a restriction.

#### RES_COMPAREPROPS

**SRestriction** structure describes a compare properties restriction, which compares two property values.

#### RES_CONTENT

**SRestriction** structure describes a content restriction, which searches a property value for specific content.

#### RES_EXIST

**SRestriction** structure describes an exist restriction, which determines if a property is supported.

#### RES_NOT

**SRestriction** structure describes a NOT restriction, which applies a logical NOT operation to a restriction.

#### RES_OR

**SRestriction** structure describes an OR restriction, which applies a logical OR operation to a restriction.

#### RES_PROPERTY

**SRestriction** structure describes a property restriction, which determines if a property value matches a particular value.

#### RES_SIZE

**SRestriction** structure describes a size restriction, which determines if a property value is a particular size.

#### RES_SUBRESTRICTION

**SRestriction** structure describes a subobject restriction, which applies a restriction to a message's attachments or recipients.

### `res`

Union of restriction structures describing the filter to be applied. The specific structure included in the **res** member depends on the value of the **rt** member. The following list gives the mapping between the structure and the restriction type.

### `res.resCompareProps`

Type: **SComparePropsRestriction**

RES_COMPAREPROPS

### `res.resAnd`

Type: **SAndRestriction**

RES_AND

### `res.resOr`

Type: **SOrRestriction**

RES_OR

### `res.resNot`

Type: **SNotRestriction**

RES_NOT

### `res.resContent`

Type: **SContentRestriction**

RES_CONTENT

### `res.resProperty`

Type: **SPropertyRestriction**

RES_PROPERTY

### `res.resBitMask`

Type: **SBitMaskRestriction**

RES_BITMASK

### `res.resSize`

Type: **SSizeRestriction**

RES_SIZE

### `res.resExist`

Type: **SExistRestriction**

RES_EXIST

### `res.resSub`

Type: **SSubRestriction**

RES_SUBRESTRICTION

### `res.resComment`

Type: **SCommentRestriction**

RES_COMMENT