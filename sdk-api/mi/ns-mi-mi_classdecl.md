# MI_ClassDecl structure

## Description

This structure outlines the class declaration. It contains class name and hierarchy, properties, qualifiers, and methods.

## Members

### `flags`

Flags can consist of values from following list.

#### MI_FLAG_CLASS ((1 << 0))

Indicates the structure describes a class.

#### MI_FLAG_ASSOCIATION ((1 << 4))

Indicates the class is also an association class.

#### MI_FLAG_INDICATION ((1 << 5))

Indicates the class is also an indication class.

#### MI_FLAG_ABSTRACT ((1 << 17))

Indicates the class is abstract.

#### MI_FLAG_TERMINAL ((1 << 18))

Indicates class cannot be derived from.

### `code`

Hash code: (name[0] << 16) | (name[len-1] << 8) | len

### `name`

Name of this feature.

### `qualifiers`

Describes extra metadata for classes, properties, methods, and parameters.

### `numQualifiers`

Length of **qualifiers** array.

### `properties`

The properties of this object.

### `numProperties`

The number of properties of this object.

### `size`

Size of structure described by **MI_ClassDecl**.

### `superClass`

Parent class name.

### `superClassDecl`

The classDecl for the parent class **superClass**.

### `methods`

The methods of this class.

### `numMethods`

Number of methods in this class.

### `schema`

Pointer to schema this class belongs to.

### `providerFT`

Provider functions.

### `owningClass`

Owning [MI_Class](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_class) object, if any.