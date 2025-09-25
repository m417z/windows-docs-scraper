# ITextStoreACP::RequestSupportedAttrs

## Description

Get the attributes that are supported in the document.

## Parameters

### `dwFlags` [in]

Specifies whether a subsequent call to the [ITextStoreAnchor::RetrieveRequestedAttrs](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreanchor-retrieverequestedattrs) method will contain the supported attributes. If the TS_ATTR_FIND_WANT_VALUE flag is specified, the default attribute values will be those in the [TS_ATTRVAL](https://learn.microsoft.com/windows/desktop/api/textstor/ns-textstor-ts_attrval) structure after the subsequent call to **ITextStoreAnchor::RetrieveRequestedAttrs**. If any other flag is specified for this parameter, the method only verifies that the attribute is supported and that the **varValue** member of the **TS_ATTRVAL** structure is set to VT_EMPTY.

### `cFilterAttrs` [in]

Specifies the number of supported attributes to obtain.

### `paFilterAttrs` [in]

Pointer to the [TS_ATTRID](https://learn.microsoft.com/windows/desktop/TSF/ts-attrid) data type that specifies the attribute to verify. The method returns only the attributes specified by **TS_ATTRID**, even though other attributes can be supported.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |
| **E_OUTOFMEMORY** | The method was unable to allocate sufficient memory to complete the operation. |

## See also

[ITextStoreACP](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreacp)

[ITextStoreACP::RetrieveRequestededAttrs](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreacp-retrieverequestedattrs)

[TS_ATTRID](https://learn.microsoft.com/windows/desktop/TSF/ts-attrid)

[TS_ATTRVAL](https://learn.microsoft.com/windows/desktop/api/textstor/ns-textstor-ts_attrval)