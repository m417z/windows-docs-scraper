# ITraceDataProvider::get_Level

## Description

Retrieves the level of information used to enable the provider.

This property is read-only.

## Parameters

## Remarks

The *ppLevel* parameter is a provider-defined value that specifies the level of information that the event generates. For example, you can use this value to indicate the severity level of the events (informational, warning, error) that you want the provider to generate.

You use the [IValueMap](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-ivaluemap) interface to retrieve or set the level value. The [IValueMap::Value](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-ivaluemap-get_value) property contains the level value.

You can also use the [IValueMap::Add](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-ivaluemap-add) method to add one or more level values. You need to use the [IValueMapItem](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-ivaluemapitem) interface only when you want to name the level, or you want to enable or disable levels without having to add or remove them. Only one level can be enabled.

The [IValueMapItem::Key](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-ivaluemapitem-get_key) property contains the string representation of the level, for example, Information. The [IValueMapItem::Value](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-ivaluemapitem-get_value) property contains the level value. The [IValueMapItem::Enabled](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-ivaluemapitem-get_enabled) property indicates whether the level is enabled.

If you use [IValueMap::Value](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-ivaluemap-get_value) to set the level and the value map collection contains one or more items, PLA searches the collection for a matching value and enables it and disables the others. If the value does not exist in the list, PLA adds the level (the item is not named).

## See also

[ITraceDataProvider](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-itracedataprovider)