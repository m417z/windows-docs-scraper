# LINKTYPE enumeration

\[The **LINKTYPE** enumeration is supported only on Windows XP and Windows Server 2003, and should no longer be used.\]

Specifies the type of link when crawling or indexing.

## Constants

**LINKTYPE\_URL**

Specifies whether the URLs link type should be indexed.

**LINKTYPE\_CONTENT**

Specifies whether the link content should be indexed.

**LINKTYPE\_RELATED**

Specifies a related link.

## Remarks

To preview attachments with a third-party protocol handler on computers running Windows XP or Windows Server 2003, it may be necessary to use the **LINKTYPE** flags, and the following other APIs: the [**IItemPreviewerExt::GetLinkedContent**](https://learn.microsoft.com/windows/win32/search/-search-iitempreviewerext-getlinkedcontent) and [**IItemPreviewerExt::GetRelatedPart**](https://learn.microsoft.com/windows/win32/search/-search-iitempreviewerext-getrelatedpart) methods, and the [**LINKINFO**](https://learn.microsoft.com/windows/win32/search/-search-linkinfo) structure.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------|
| Minimum supported client<br> | Windows XP with SP2 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |

