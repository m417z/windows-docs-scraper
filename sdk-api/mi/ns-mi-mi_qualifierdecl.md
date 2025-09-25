# MI_QualifierDecl structure

## Description

Represents a CIM qualifier declaration.

## Members

### `name`

Name of this qualifier.

### `type`

Type of this qualifier.

### `scope`

Scope of this qualifier.

### `flavor`

Flavor of this qualifier. The flavor value may contain any combination of these bit flags:

#### MI_FLAG_ENABLEOVERRIDE (0x00000080)

Enables override.

#### MI_FLAG_DISABLEOVERRIDE (0x00000100)

Disables override.

#### MI_FLAG_RESTRICTED (0x00000200)

Applies only to the class in which it is declared.

#### MI_FLAG_TOSUBCLASS (0x00000400)

Allows inheritance to any subclass.

#### MI_FLAG_TRANSLATABLE (0x00000800)

Allows for string localization.

### `subscript`

Array subscript. If this is an array type with a fixed length, the subscript value represents the array length.

### `value`

Pointer to a qualifier value of a particular type.