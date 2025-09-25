# MI_Instance_Clone function

## Description

Creates a copy of the specified instance on the heap.

## Parameters

### `self` [in]

Instance to be cloned.

### `newInstance`

Returned instance. This should be deleted via [MI_Instance_Delete](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_instance_delete).

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.