# ITEMPROP structure

## Description

[**ITEMPROP** and [IItemPropertyBag](https://learn.microsoft.com/windows/desktop/search/iitempropertybag) are supported only on Windows XP and Windows Server 2003, and should no longer be used.]

Stores information about properties in the [Windows Property System](https://learn.microsoft.com/windows/desktop/properties/windows-properties-system), and is used by the [IItemPropertyBag](https://learn.microsoft.com/windows/desktop/search/iitempropertybag) interface.

## Members

### `variantValue`

### `pwszName`

#### - bstrIndexProp

The name of a property in the [Windows Property System](https://learn.microsoft.com/windows/desktop/properties/windows-properties-system). For example, the [System.ItemUrl](https://learn.microsoft.com/windows/desktop/properties/props-system-itemurl) property.

#### - bstrName

For internal use only.

#### - ds

For internal use only.

#### - dwHint

For internal use only.

#### - dwUID

For internal use only.

#### - vt

The type of the property value. For example, the type of the string property [System.ItemUrl](https://learn.microsoft.com/windows/desktop/properties/props-system-itemurl) is **VT_BSTR**.

## Remarks

To preview attachments with a third-party protocol handler on computers running Windows XP or Windows Server 2003, it may be necessary to use the [IItemPropertyBag](https://learn.microsoft.com/windows/desktop/search/iitempropertybag) interface and the following APIs: the [ISearchProtocolUI](https://learn.microsoft.com/windows/desktop/search/-search-isearchprotocolui), [IItemPreviewerExt](https://learn.microsoft.com/windows/desktop/search/-search-iitempreviewerext) and [ISearchItem](https://learn.microsoft.com/windows/desktop/search/-search-isearchitem) interfaces, the [LINKINFO](https://learn.microsoft.com/windows/desktop/search/-search-linkinfo) and **ITEMPROP** structures, and the [LINKTYPE](https://learn.microsoft.com/windows/desktop/search/-search-linktype) enumeration.

## See also

[IItemPropertyBag](https://learn.microsoft.com/windows/desktop/search/iitempropertybag)