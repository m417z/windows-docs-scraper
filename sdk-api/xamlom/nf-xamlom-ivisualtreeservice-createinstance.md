# IVisualTreeService::CreateInstance

## Description

Creates an instance of any XAML runtime, enum, or primitive type.

## Parameters

### `typeName` [in]

The type name. (Should be from [PropertyChainValue.Type](https://learn.microsoft.com/previous-versions/windows/desktop/api/xamlom/ns-xamlom-propertychainvalue).)

### `value` [in]

The value to set on a primitive or enum type. **null** if creating a XAML runtime type.

### `pInstanceHandle` [out, retval]

An instance handle to newly created instance.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

 For primitives and enums, *value* should be
set to desired value. For XAML runtime types, *value* should be **null**.

## See also

[IVisualTreeService](https://learn.microsoft.com/previous-versions/windows/desktop/api/xamlom/nn-xamlom-ivisualtreeservice)