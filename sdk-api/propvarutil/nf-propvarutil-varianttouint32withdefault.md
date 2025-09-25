# VariantToUInt32WithDefault function

## Description

Extracts an unsigned **Int32** property value of a variant structure. If no value currently exists, then the specified default value is returned.

## Parameters

### `varIn` [in]

Type: **REFVARIANT**

Reference to a source variant structure.

### `ulDefault` [in]

Type: **ULONG**

Specifies default property value, for use where no value currently exists.

## Return value

Type: **ULONG**

Returns extracted unsigned **Int32** value, or default.