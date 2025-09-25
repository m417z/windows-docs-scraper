# IPropertyStore::SetValue

## Description

This method sets a property value or replaces or removes an existing value.

## Parameters

### `key`

TBD

### `propvar`

TBD

### `Key`

A reference to the PROPERTYKEY structure that is retrieved through [IPropertyStore::GetAt](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-ipropertystore-getat). This structure contains a global unique identifier (GUID) for the property.

#### - pv

A pointer to a [PROPVARIANT](https://learn.microsoft.com/previous-versions/aa912007(v=msdn.10)) structure that contains the new property data.

## Return value

The `IPropertyStore::SetValue` method can return any one of the following:

| Return code | Description |
| --- | --- |
| **S_OK** | The property change was successful. |
| **INPLACE_S_TRUNCATED** | The value was set but truncated. |
| **STG_E_ACCESSDENIED** | This is an error code. The property store was read-only so the method was not able to set the value. |

## Remarks

`IPropertyStore::SetValue` affects the current property store instance only. A property handler implements `IPropertyStore::SetValue` by accumulating property changes in an in-memory data structure. Property changes are written to the stream only when [IPropertyStore::Commit](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-ipropertystore-commit) is called.

If **IPropertyStore::Commit** is called on a read-only property store, the property handler determines this and returns STG_E_ACCESSDENIED.

If a value was added or removed as a result of `SetValue`, subsequent enumerations by [IPropertyStore::GetCount](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-ipropertystore-getcount) and [IPropertyStore::GetAt](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-ipropertystore-getat) reflect that change and subsequent calls to `IPropertyStore::SetValue` reflect the changed value.

**Adding a New Property**

If the property value that was pointed to by key does not exist in the store, `IPropertyStore::SetValue` adds the value to the store.

**Replacing an Existing Property Value**

If the property value that was pointed to by key already exists in the store, the stored value is replaced.

**Removing an Existing Property**

To remove a value from the property store, set the vt member of the structure that is pointed to by pv to VT_EMPTY. If that value is not present, do nothing and the method returns S_OK.

## See also

[IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore)

[IPropertyStore::Commit](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-ipropertystore-commit)

[IPropertyStore::GetAt](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-ipropertystore-getat)

[IPropertyStore::GetCount](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-ipropertystore-getcount)