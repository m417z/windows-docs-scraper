# ITextStoreACP::RequestAttrsTransitioningAtPosition

## Description

Gets text attributes transitioning at the specified character position.

## Parameters

### `acpPos` [in]

Specifies the application character position in the document.

### `cFilterAttrs` [in]

Specifies the number of attributes to obtain.

### `paFilterAttrs` [in]

Pointer to the [TS_ATTRID](https://learn.microsoft.com/windows/desktop/TSF/ts-attrid) data type that specifies the attribute to verify.

### `dwFlags` [in]

Specifies attributes for the call to the [ITextStoreACP::RetrieveRequestedAttrs](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreacp-retrieverequestedattrs) method. If this parameter is not set, the method returns the attributes that start at the specified position. Other possible values for this parameter are the following.

| Value | Meaning |
| --- | --- |
| **TS_ATTR_FIND_WANT_END** | Obtains the attributes that end at the specified application character position. |
| **TS_ATTR_FIND_WANT_VALUE** | Obtains the value of the attribute in addition to the attribute. The attribute value is put into the **varValue** member of the [TS_ATTRVAL](https://learn.microsoft.com/windows/desktop/api/textstor/ns-textstor-ts_attrval) structure during the **ITextStoreACP::RetrieveRequestedAttrs** method call. |

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

In the sentence, "This is *italic text*.", the italic attribute starts before the word *italic* and ends after the word *text*.

If the flag TS_ATTR_FIND_WANT_END is set in *dwFlags*, the method would return the italic attribute for the text "*italic* <anchor>normal", because there is an end transition at the anchor location.

## See also

[ITextStoreACP](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreacp)

[ITextStoreACP::RetrieveRequestedAttrs](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreacp-retrieverequestedattrs)

[TS_ATTRID](https://learn.microsoft.com/windows/desktop/TSF/ts-attrid)

[TS_ATTRVAL](https://learn.microsoft.com/windows/desktop/api/textstor/ns-textstor-ts_attrval)

[TS_ATTR_* Constants](https://learn.microsoft.com/windows/desktop/TSF/ts-attr--constants)