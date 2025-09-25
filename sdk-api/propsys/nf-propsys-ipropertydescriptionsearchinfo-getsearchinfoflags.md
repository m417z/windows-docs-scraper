# IPropertyDescriptionSearchInfo::GetSearchInfoFlags

## Description

Gets the [PROPDESC_SEARCHINFO_FLAGS](https://learn.microsoft.com/windows/desktop/api/propsys/ne-propsys-propdesc_searchinfo_flags) associated with the property.

## Parameters

### `ppdsiFlags` [out]

Type: **[PROPDESC_SEARCHINFO_FLAGS](https://learn.microsoft.com/windows/desktop/api/propsys/ne-propsys-propdesc_searchinfo_flags)***

When this method returns successfully, contains a pointer to the [PROPDESC_SEARCHINFO_FLAGS](https://learn.microsoft.com/windows/desktop/api/propsys/ne-propsys-propdesc_searchinfo_flags) associated with the property.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IPropertyDescriptionSearchInfo](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertydescriptionsearchinfo)

[PROPDESC_SEARCHINFO_FLAGS](https://learn.microsoft.com/windows/desktop/api/propsys/ne-propsys-propdesc_searchinfo_flags)