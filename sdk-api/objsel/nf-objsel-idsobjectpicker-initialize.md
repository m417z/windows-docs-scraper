# IDsObjectPicker::Initialize

## Description

The **IDsObjectPicker::Initialize** method initializes the object picker dialog box with data about the scopes, filters, and options used by the object picker dialog box.

## Parameters

### `pInitInfo`

Pointer to a
[DSOP_INIT_INFO](https://learn.microsoft.com/windows/desktop/api/objsel/ns-objsel-dsop_init_info) structure that contains the initialization data.

## Return value

Returns a standard error code or one of the following values.

## Remarks

**IDsObjectPicker::Initialize** can be called more than once and the last call takes precedence. The [IDsObjectPicker](https://learn.microsoft.com/windows/desktop/api/objsel/nn-objsel-idsobjectpicker) object will completely re-initialize itself in response to this method.

## See also

[DSOP_INIT_INFO](https://learn.microsoft.com/windows/desktop/api/objsel/ns-objsel-dsop_init_info)

[Directory Object Picker](https://learn.microsoft.com/windows/desktop/AD/directory-object-picker)

[IDsObjectPicker](https://learn.microsoft.com/windows/desktop/api/objsel/nn-objsel-idsobjectpicker)