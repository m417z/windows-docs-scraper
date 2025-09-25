# MI_PropertySet_Clone function

## Description

Creates a copy of the specified property set on the heap.

## Parameters

### `self` [in]

Property set to be cloned.

### `newPropertySet`

The returned property set clone. This clone will eventually need to be deleted by using the [MI_PropertySet_Delete](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_propertyset_delete) function.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.

## Remarks

The *newPropertySet* clone should be passed eventually to the [MI_PropertySet_Delete](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_propertyset_delete) function.

## See also

[MI_PropertySet_Delete](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_propertyset_delete)