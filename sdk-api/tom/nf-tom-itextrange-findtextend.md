# ITextRange::FindTextEnd

## Description

Searches up to *Count* characters for the string, *bstr*, starting from the range's End *cp*. The search is subject to the comparison parameter, *Flags*. If the string is found, the End *cp* is changed to be the end of the matched string, and *pLength* is set equal to the length of the string. If the string is not found, the range is unchanged and *pLength* is set equal to zero.

## Parameters

### `bstr`

Type: **BSTR**

String to search for.

### `Count`

Type: **long**

Maximum number of characters to search. It can be one of the following.

|  |  |
| --- | --- |
| *tomForward* | Search to the end of the story. This is the default value. |
| *n* (greater than 0) | Search forward for *n* chars, starting from *cpLim.* |
| *n* (less than 0) | Search backward for *n* chars, starting from *cpLim.* |

### `Flags`

Type: **long**

Flags governing comparisons. It can be zero (the default) or any combination of the following values.

|  |  |  |
| --- | --- | --- |
| *tomMatchWord* | 2 | Matches whole words. |
| *tomMatchCase* | 4 | Matches case. |
| *tomMatchPattern* | 8 | Matches regular expressions. |

### `pLength`

Type: **long***

The length of string matched.

## Return value

Type: **HRESULT**

The method returns an **HRESULT** value. If the method succeeds, it returns **S_OK**. If the method fails, it returns S_FALSE.

## See also

**Conceptual**

[FindText](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-findtext)

[FindTextStart](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-findtextstart)

[ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)