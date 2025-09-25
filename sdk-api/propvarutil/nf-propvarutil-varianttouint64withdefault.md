# VariantToUInt64WithDefault function

## Description

Extracts an unsigned **Int64** property value of a variant structure. If no value currently exists, then the specified default value is returned.

## Parameters

### `varIn` [in]

Type: **REFVARIANT**

Reference to a source variant structure.

### `ullDefault` [in]

Type: **ULONGLONG**

Specifies default property value, for use where no value currently exists.

## Return value

Type: **ULONGLONG**

Returns the extracted unsigned **Int64** value, or a default.