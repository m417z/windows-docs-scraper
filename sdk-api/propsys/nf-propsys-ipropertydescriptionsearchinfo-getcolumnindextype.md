# IPropertyDescriptionSearchInfo::GetColumnIndexType

## Description

Determines the how the current property is indexed.

## Parameters

### `ppdciType` [out]

Type: **[PROPDESC_COLUMNINDEX_TYPE](https://learn.microsoft.com/windows/desktop/api/propsys/ne-propsys-propdesc_columnindex_type)***

When this method returns successfully, contains a pointer to a [PROPDESC_COLUMNINDEX_TYPE](https://learn.microsoft.com/windows/desktop/api/propsys/ne-propsys-propdesc_columnindex_type) constant. This constant describes whether the property is indexed and if so, if it is indexed in memory or on disk.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IPropertyDescriptionSearchInfo](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertydescriptionsearchinfo)

[PROPDESC_COLUMNINDEX_TYPE](https://learn.microsoft.com/windows/desktop/api/propsys/ne-propsys-propdesc_columnindex_type)