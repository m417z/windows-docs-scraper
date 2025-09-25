# MI_Instance_SetElementAt function

## Description

Set the value of the element at the given index of an instance.

## Parameters

### `self` [in, out]

A pointer to an instance.

### `index`

The position of the element.

### `value` [in, optional]

The new value of the element.

### `type`

The CIM type of the element that will be set.

### `flags`

The bit flags indicates memory management policy and can be any of the following values.

#### MI_FLAG_BORROW

Used while adding and setting properties on an **MI_Instance** to indicate that the instance will not copy the value. The value must stay valid until the instance is deleted.

#### MI_FLAG_ADOPT

Used while adding and setting properties on an **MI_Instance** to indicate that the instance will adopt the pointer and will be responsible for deleting it.

#### MI_FLAG_NULL

Element value is **Null**.

## Return value

This function returns MI_INLINE MI_Result MI_INLINE_CALL.