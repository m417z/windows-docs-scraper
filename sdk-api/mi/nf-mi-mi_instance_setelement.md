# MI_Instance_SetElement function

## Description

Set the value of the element with the given name in the given instance.

## Parameters

### `self` [out]

A pointer to an instance.

### `name`

A null-terminated string that represents the name of the element that will be set.

### `value` [in, optional]

The new value for the element.

### `type`

The CIM type of the element that will be set.

### `flags`

Bit flags indicating memory management policy.

#### MI_FLAG_BORROW

Used while adding and setting properties on an **MI_Instance** to indicate that the instance will not copy the value. The value must stay valid until the instance is deleted.

#### MI_FLAG_ADOPT

Used while adding and setting properties on an **MI_Instance** to indicate that the instance will adopt the pointer and will be responsible for deleting it.

#### MI_FLAG_NULL

Element value is **Null**.

## Return value

This function returns MI_INLINE MI_Result MI_INLINE_CALL.

## Remarks

By default, all memory referred to by the value parameter is copied. By passing the flag MI_FLAG_BORROW, memory pointers within the value structure are stored directly in the instance's element. The caller must guarantee that the memory outlives the instance.