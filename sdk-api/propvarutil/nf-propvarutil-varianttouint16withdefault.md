# VariantToUInt16WithDefault function

## Description

Extracts an unsigned **Int16** property value of a variant structure. If no value exists, then the specified default value is returned.

## Parameters

### `varIn` [in]

Type: **REFVARIANT**

Reference to a source variant structure.

### `uiDefault` [in]

Type: **USHORT**

Specifies default property value, for use where no value currently exists.

## Return value

Type: **USHORT**

Returns extracted unsigned **Int16** value, or default.