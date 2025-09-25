# MI_Sint16AField structure

## Description

Represents a property inside an [MI_Instance](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_instance) structure.

## Members

### `value`

A field of type [MI_Sint16A](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_sint16a).

### `exists`

Indicates whether the field is non-null. Can be set to **MI_TRUE** or **MI_FALSE**.

### `flags`

Bit flags indicating memory management policy.

#### MI_FLAG_NOT_MODIFIED ((1 << 25))

Indicates that the property is not modified.

#### MI_FLAG_NULL ((1 << 29))

Element value is **Null**.

#### MI_FLAG_BORROW ((1 << 30))

Used while adding and setting properties on an **MI_Instance** to indicate that the instance will not copy the value. The value must stay valid until the instance is deleted.

#### MI_FLAG_ADOPT ((1 << 31))

Used while adding and setting properties on an **MI_Instance** to indicate that the instance will adopt the pointer and will be responsible for deleting it.