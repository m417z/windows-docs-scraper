# ITraceDataProvider::get_KeywordsAll

## Description

Retrieves the list of keywords that restricts the category of events that you want the provider to write. The restrictions are in addition to those provided by the [ITraceDataProvider::KeywordsAny](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-itracedataprovider-get_keywordsany) property.

This property is read-only.

## Parameters

## Remarks

The provider writes an event if any of the event's keyword bits match any of the bits set in the [KeywordsAny](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-itracedataprovider-get_keywordsany) property.
The keywords specified in the **KeywordsAll** property further restrict the category of events that you want the provider to write. If the event's keyword meets the **KeywordsAny** condition, the provider will write the event only if all of the bits in the **KeywordsAll** mask exist in the event's keyword. The **KeywordsAll** mask is not used if **KeywordsAny** is zero.

For more information about how the **KeywordsAll** and [KeywordsAny](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-itracedataprovider-get_keywordsany) conditions relate, see the Remarks section of [KeywordsAny](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-itracedataprovider-get_keywordsany).

You use the [IValueMap](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-ivaluemap) interface to retrieve or set the keywords value. You can use the [IValueMap::Value](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-ivaluemap-get_value) property to retrieve the keywords value (the value of all of the items in the map when combined with the **OR** operator), or you can enumerate each item in the map to retrieve the individual keyword values.

Likewise, when you set the keywords value, you call the [IValueMap::Value](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-ivaluemap-get_value) property to set the keywords value, or you can call the [IValueMap::Add](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-ivaluemap-add) method to add each individual keyword value.

If you use [IValueMap::Value](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-ivaluemap-get_value) to set the keywords and the value map contains one or more items, PLA searches the collection for matching values and enables them and disables the others. If the value does not exist in the list, PLA adds the keyword (the item is not named).

The [IValueMapItem::Key](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-ivaluemapitem-get_key) property contains the string representation of the keyword. The [IValueMapItem::Value](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-ivaluemapitem-get_value) property contains the keyword value. The [IValueMapItem::Enabled](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-ivaluemapitem-get_enabled) property indicates if the keyword is enabled. You need to use [IValueMapItem](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-ivaluemapitem) interface only when you want to name the keyword or you want to enable or disable keywords without having to add or remove them.

## See also

[ITraceDataProvider](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-itracedataprovider)

[ITraceDataProvider::KeywordsAny](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-itracedataprovider-get_keywordsany)