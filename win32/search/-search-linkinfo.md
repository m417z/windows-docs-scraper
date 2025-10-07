# LINKINFO structure

\[**LINKINFO** and [**IItemPreviewerExt**](https://learn.microsoft.com/windows/win32/search/-search-iitempreviewerext) are supported only on Windows XP and Windows Server 2003, and should no longer be used.\]

Stores information about link types, and is used by the [**IItemPreviewerExt**](https://learn.microsoft.com/windows/win32/search/-search-iitempreviewerext) interface.

## Members

**type**

Type: **[**LINKTYPE**](https://learn.microsoft.com/windows/win32/search/-search-linktype)**

The type of link specified when crawling or indexing indicated by a [**LINKTYPE**](https://learn.microsoft.com/windows/win32/search/-search-linktype) constant.

**bstrContentType**

Type: **BSTR**

A **BSTR** value that specifies the content type.

**bstrEncoding**

Type: **BSTR**

An EncodingStyle attribute specified in the Web Services Description Language (WSDL) file.

**bstrFileExt**

Type: **BSTR**

A **BSTR** value that specifies the file name extension.

**varData**

Type: **VARIANT**

A variant that specifies the variable value.

**dwRelatedParts**

Type: **DWORD**

A **DWORD** that specifies the related parts.

**bstrRelatedCid**

Type: **BSTR**

A **BSTR** value that specifies a Cid property, a non-padded, signed decimal string.

**lCodePage**

Type: **Long**

The code page to use for encoding the string.

## Remarks

To preview attachments with a third-party protocol handler on computers running Windows XP or Windows Server 2003, it may be necessary to use the **LINKINFO** structure, and the following APIs: the [**IItemPreviewerExt::GetLinkedContent**](https://learn.microsoft.com/windows/win32/search/-search-iitempreviewerext-getlinkedcontent) and [**IItemPreviewerExt::GetRelatedPart**](https://learn.microsoft.com/windows/win32/search/-search-iitempreviewerext-getrelatedpart) methods, and the [**LINKTYPE**](https://learn.microsoft.com/windows/win32/search/-search-linktype) enumeration.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------|
| Minimum supported client<br> | Windows XP with SP2 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| Redistributable<br> | Windows Desktop Search (WDS) 3.0<br> |

