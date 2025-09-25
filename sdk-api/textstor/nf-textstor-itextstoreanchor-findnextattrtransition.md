# ITextStoreAnchor::FindNextAttrTransition

## Description

The **ITextStoreAnchor::FindNextAttrTransition** method finds the location in the text stream where a transition occurs in an attribute value. The specified attribute to check is application-dependent.

## Parameters

### `paStart` [in]

Pointer to the anchor position at the start of a range to search for an attribute transition.

### `paHalt` [in]

Pointer to the anchor position at the end of a range to search for an attribute transition.

### `cFilterAttrs` [in]

Specifies the number of attributes to check.

### `paFilterAttrs` [in]

Pointer to the [TS_ATTRID](https://learn.microsoft.com/windows/desktop/TSF/ts-attrid) data type that specifies the attribute to check. Pre-defined attributes are given in tsattrs.h.

### `dwFlags` [in]

Specifies the direction to search for an attribute transition. By default, the method searches forward.

| Value | Meaning |
| --- | --- |
| **TS_ATTR_FIND_BACKWARDS** | The method searches backward in the text stream. |
| **TS_ATTR_FIND_UPDATESTART** | The method positions the input anchor *paStart* at the next attribute transition, if one is found. Otherwise the input anchor is not modified. |
| **TS_ATTR_FIND_WANT_OFFSET** | The *plFoundOffset* parameter receives the character offset of the attribute transition from *paStart*. |

### `pfFound` [out]

Receives a Boolean value of **TRUE** if an attribute transition was found, otherwise **FALSE** is returned.

### `plFoundOffset` [out]

Receives the character offset of the attribute transition from the start anchor *paStart*.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | *paStart* and/or *paHalt* are invalid. |
| **TS_E_INVALIDPOS** | The character positions specified are beyond the text in the document. |

## See also

[ITextStoreAnchor](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreanchor)

[TS_ATTRID](https://learn.microsoft.com/windows/desktop/TSF/ts-attrid)

[TS_ATTR_* Constants](https://learn.microsoft.com/windows/desktop/TSF/ts-attr--constants)