# ITextStoreACP2::FindNextAttrTransition

## Description

Determines the character position where a transition occurs in an attribute value. The specified attribute to check is application-dependent.

## Parameters

### `acpStart` [in]

Specifies the character position to start the search for an attribute transition.

### `acpHalt` [in]

Specifies the character position to end the search for an attribute transition.

### `cFilterAttrs` [in]

Specifies the number of attributes to check.

### `paFilterAttrs` [in]

Pointer to the [TS_ATTRID](https://learn.microsoft.com/windows/desktop/TSF/ts-attrid) data type that specifies the attribute to check.

### `dwFlags` [in]

Specifies the direction to search for an attribute transition. By default, the method searches forward.

| Value | Meaning |
| --- | --- |
| **TS_ATTR_FIND_BACKWARDS** | The method searches backward. |
| **TS_ATTR_FIND_WANT_OFFSET** | The *plFoundOffset* parameter receives the character offset of the attribute transition from *acpStart*. |

### `pacpNext` [out]

Receives the next character position to check for an attribute transition.

### `pfFound` [out]

Receives a Boolean value of **TRUE** if an attribute transition was found, otherwise **FALSE** is returned.

### `plFoundOffset` [out]

Receives the character position of the attribute transition (not ACP positions). If TS_ATTR_FIND_WANT_OFFSET flag is set in *dwFlags*, receives the character offset of the attribute transition from *acpStart*.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **TS_E_INVALIDPOS** | The character positions specified are beyond the text in the document. |

## Remarks

**Note** If an application does not implement **FindNextAttrTransition**, [ITfReadOnlyProperty::EnumRanges](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfreadonlyproperty-enumranges) fails with **E_FAIL**.

## See also

[ITextStoreACP2](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreacp2)

[TS_ATTRID](https://learn.microsoft.com/windows/desktop/TSF/ts-attrid)

[TS_ATTR_* Constants](https://learn.microsoft.com/windows/desktop/TSF/ts-attr--constants)