# IPropertyDescription::GetViewFlags

## Description

Gets the current set of flags governing the property's view.

## Parameters

### `ppdvFlags` [out]

Type: **[PROPDESC_VIEW_FLAGS](https://learn.microsoft.com/windows/desktop/api/propsys/ne-propsys-propdesc_view_flags)***

When this method returns, contains a pointer to a value that includes one or more of the following flags. See [PROPDESC_VIEW_FLAGS](https://learn.microsoft.com/windows/desktop/api/propsys/ne-propsys-propdesc_view_flags) for valid values.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IPropertyDescription](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertydescription)

[Property Description Schema](https://learn.microsoft.com/windows/desktop/properties/propdesc-schema-entry)