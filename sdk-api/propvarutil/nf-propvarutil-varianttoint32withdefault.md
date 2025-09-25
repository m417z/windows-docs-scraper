# VariantToInt32WithDefault function

## Description

Extracts an **Int32** property value of a variant structure. If no value exists, then the specified default value is returned.

## Parameters

### `varIn` [in]

Type: **REFVARIANT**

Reference to a source variant structure.

### `lDefault` [in]

Type: **LONG**

Specifies default property value, for use where no value currently exists.

## Return value

Type: **LONG**

Returns the extracted Int32 value, or default.