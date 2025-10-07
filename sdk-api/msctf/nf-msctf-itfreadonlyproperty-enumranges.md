# ITfReadOnlyProperty::EnumRanges

## Description

Obtains an enumeration of ranges that contain unique values of the property within the given range.

## Parameters

### `ec` [in]

Contains an edit cookie that identifies the edit context. This is obtained from [ITfDocumentMgr::CreateContext](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfdocumentmgr-createcontext) or [ITfEditSession::DoEditSession](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfeditsession-doeditsession).

### `ppEnum` [out]

Pointer to an [IEnumTfRanges](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-ienumtfranges) interface pointer that receives the enumerator object. The caller must release this object when it is no longer required.

### `pTargetRange` [in]

Pointer to an [ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange) interface that specifies the range to scan for unique property values. This parameter is optional and can be **NULL**. For more information, see the Remarks section.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | One or more parameters are invalid. |
| **E_OUTOFMEMORY** | A memory allocation failure occurred. |
| **E_FAIL** | An unspecified error occurred. <br><br>**Note** If an application does not implement [ITextStoreACP::FindNextAttrTransition](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreacp-findnextattrtransition), ITfReadOnlyProperty::EnumRanges fails with E_FAIL. |
| **TF_E_NOLOCK** | The edit context identified by *ec* does not have a read-only or read/write lock. |

## Remarks

**Note:** If an application does not implement [ITextStoreACP::FindNextAttrTransition](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreacp-findnextattrtransition), **ITfReadOnlyProperty::EnumRanges** fails with E_FAIL.

The enumerator obtained by this method will contain a range for each unique value, including empty values, of the specified property. For example, a hypothetical color property can be applied to the following marked up text:

``` syntax

COLOR:      RR      GGGGGGGG
TEXT:  this is some colored text

```

When **ITfReadOnlyProperty::EnumRanges** is called with *pTargetRange* set to this range, the enumerator will contain five ranges.

| Range Index | Color Property Value | Range Text |
| --- | --- | --- |
| 0 | \<empty> | "this " |
| 1 | R | "is" |
| 2 | \<empty> | " some " |
| 3 | G | "colored " |
| 4 | \<empty> | "text" |

If *pTargetRange* is **NULL**, then the enumerator will begin and end with the first and last range that contains a non-empty property value in the context. Specifying **NULL** for *pTargetRange* in the above example would result in an enumerator with three ranges.

| Range Index | Color Property Value | Text Within Range |
| --- | --- | --- |
| 0 | R | "is" |
| 1 | \<empty> | " some " |
| 2 | G | "colored " |

The enumerated ranges will begin and end with the start and end anchors of *pTargetRange*, even if either anchor is positioned in the middle of a property.

## See also

[IEnumTfRanges](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-ienumtfranges)

[ITfDocumentMgr::CreateContext](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfdocumentmgr-createcontext)

[ITfEditSession::DoEditSession](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfeditsession-doeditsession)

[ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange)

[ITfReadOnlyProperty](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfreadonlyproperty)