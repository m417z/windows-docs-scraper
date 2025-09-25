# VariantToInt64WithDefault function

## Description

Extracts an **Int64** property value of a variant structure. If no value exists, then the specified default value is returned.

## Parameters

### `varIn` [in]

Type: **REFVARIANT**

Reference to a source variant structure.

### `llDefault` [in]

Type: **LONGLONG**

Specifies default property value, for use where no value currently exists.

## Return value

Type: **LONGLONG**

Returns extracted **Int64** value, or default.