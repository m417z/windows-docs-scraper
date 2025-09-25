# ITfProperty::FindRange

## Description

Obtains a range that covers the text that contains a non-empty value for the property.

## Parameters

### `ec` [in]

Contains an edit cookie that identifies the edit context. This is obtained from [ITfDocumentMgr::CreateContext](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfdocumentmgr-createcontext) or [ITfEditSession::DoEditSession](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfeditsession-doeditsession).

### `pRange` [in]

Pointer to an [ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange) interface that contains the point to obtain the property range for. The point will either be the start anchor or end anchor of this range, based upon the value of *aPos*.

### `ppRange` [out]

Pointer to an **ITfRange** interface pointer that receives the requested range object.

### `aPos` [in]

Contains one of the [TfAnchor](https://learn.microsoft.com/windows/win32/api/msctf/ne-msctf-tfanchor) values which specifies which anchor of *pRange* is used as the point to obtain the property range for.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | *pRange* is not over, or adjacent to, the property. *ppRange* receives **NULL**. |
| **E_INVALIDARG** | One or more parameters are invalid. |
| **E_OUTOFMEMORY** | A memory allocation failure occurred. |
| **E_FAIL** | An unspecified error occurred. |
| **TF_E_NOLOCK** | The edit context identified by *ec* does not have a read-only or read/write lock. |

## Remarks

This method obtains a range of text that contains a non-empty value for the property. If the property has no value at the specified point, *ppRange* receives **NULL** and the method returns S_FALSE. In the following example, if *aPos* contains TF_ANCHOR_START, the returned range would contain "is". If *aPos* contains TF_ANCHOR_END, the method would return S_FALSE because the property does not exist at the end point of the range.

``` syntax

COLOR: RRRRR   RR          GGGGGGGG
TEXT:  this <a>is som</a>e colored text

```

If *aPos* contains TF_ANCHOR_START, this method ignores property ranges that end immediately before the start anchor. Likewise, if *aPos* contains TF_ANCHOR_END, this method ignores property ranges that start immediately after the end anchor. In the following example, if *aPos* contains TF_ANCHOR_START, the returned range would contain "colored " and not "some " because the R value property ends at the start anchor point and the G value property begins at the start anchor. If *aPos* contains TF_ANCHOR_END, the returned range would contain "colored " and not "text".

``` syntax

COLOR:         RRRRR   GGGGGGGG    BBBB
TEXT:  this is some <a>colored </a>text

```

## See also

[ITfDocumentMgr::CreateContext](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfdocumentmgr-createcontext)

[ITfEditSession::DoEditSession](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfeditsession-doeditsession)

[ITfProperty](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfproperty)

[ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange)

[TfAnchor](https://learn.microsoft.com/windows/win32/api/msctf/ne-msctf-tfanchor)