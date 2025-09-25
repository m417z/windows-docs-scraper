# ITraceDataProvider::get_KeywordsAny

## Description

Retrieves the list of keywords that determine the category of events that you want the provider to write.

This property is read-only.

## Parameters

## Remarks

Keywords determine the category of events that you want the provider to write. The provider writes an event if any of the event's keyword bits match any of the bits set in this **KeywordsAny** mask.

To include all events that a provider provides, set this property to zero. To include only specific events, set this keyword mask to those specific events. For example, if the provider defines an event for its initialization and clean-up routines (bit 0), an event for its file operations (bit 1), and an event for its calculation operations (bit 2), you can choose to include only two of these events by setting this mask to 5 (set bits 0 and 2) to receive initialization and clean-up events and calculation events.

To further restrict the category of events that you want the provider to write, also set the [ITraceDataProvider::KeywordsAll](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-itracedataprovider-get_keywordsall) property.

If the provider defines more complex event keywords (for example, the provider defines an event that sets bit 0 for read and bit 1 for local access and a second event that sets bit 0 for read and bit 2 for remote access), you could set this mask to 1 to receive all read events, or you could set this mask to 1 and the [KeywordsAll](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-itracedataprovider-get_keywordsall) mask to 3 to receive local reads only.

If an event's keyword is zero, the provider will write the event to the session, regardless of this mask or the [KeywordsAll](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-itracedataprovider-get_keywordsall) mask.

For providers that were written on an operating system prior to Windows Vista, the keyword value will be mapped to the enable flags.

You use the [IValueMap](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-ivaluemap) interface to retrieve or set the keywords value. You can use the [IValueMap::Value](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-ivaluemap-get_value) property to retrieve the keywords value (the value of all of the items in the map when combined with the **OR** operator), or you can enumerate each item in the map to retrieve the individual keyword values.

Likewise, when you set the keywords value, you call the [IValueMap::Value](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-ivaluemap-get_value) property to set the keywords value, or you can call the [IValueMap::Add](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-ivaluemap-add) method to add each individual keyword value.

If you use [IValueMap::Value](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-ivaluemap-get_value) to set the keywords and the value map contains one or more items, PLA searches the collection for matching values and enables them and disables the others. If the value does not exist in the list, PLA adds the keyword (the item is not named).

The [IValueMapItem::Key](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-ivaluemapitem-get_key) property contains the string representation of the keyword. The [IValueMapItem::Value](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-ivaluemapitem-get_value) property contains the keyword value. The [IValueMapItem::Enabled](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-ivaluemapitem-get_enabled) property indicates if the keyword is enabled. You need to use the [IValueMapItem](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-ivaluemapitem) interface only when you want to name the keyword or you want to enable or disable keywords without having to add or remove them.

## See also

[ITraceDataProvider](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-itracedataprovider)

[ITraceDataProvider::KeywordsAll](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-itracedataprovider-get_keywordsall)