# MI_ReferenceAField structure

## Description

Represents a property inside an [MI_Instance](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_instance) structure.

## Members

### `value`

A field of type [MI_ReferenceA](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_referencea).

### `exists`

Indicates whether the field is non-null. This member can be set to **MI_TRUE** or **MI_FALSE**.

### `flags`

Bit flags that indicate the memory management policy.

#### MI_FLAG_NOT_MODIFIED ((1 << 25))

Indicates that the property is not modified.

#### MI_FLAG_NULL ((1 << 29))

The element value is **NULL**.

#### MI_FLAG_BORROW ((1 << 30))

Used while adding and setting properties on an [MI_Instance](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_instance) to indicate that the instance will not copy the value. The value must stay valid until the instance is deleted.

#### MI_FLAG_ADOPT ((1 << 31))

Used while adding and setting properties on an [MI_Instance](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_instance) to indicate that the instance will adopt the pointer and will be responsible for deleting it.