# SetFlags function

## Description

Specifies how the recognizer interprets the ink and determines the result string.

Call this function before processing the ink for the first time. Therefore, call the **SetFlags** function before calling the [Process](https://learn.microsoft.com/windows/desktop/api/recapis/nf-recapis-process) function.

## Parameters

### `hrc` [in]

Handle to the recognizer context.

### `dwFlags` [in]

The following table lists the flags that you may set to specify how the recognizer interprets the ink and determines the result string. Use the **OR** operator (|) to combine flags as appropriate.

| Bit flag | Meaning |
| --- | --- |
| **RECOFLAG_AUTOSPACE** | Recognizer uses smart spacing based on language model rules. |
| **RECOFLAG_COERCE** | Recognizer coerces the result based on the factoid you specify for the context. For example, if you specify a phone number factoid and the user enters the word "hello", the recognizer may return a random phone number or an empty string. If you do not specify this flag, the recognizer returns "hello" as the result. |
| **RECOFLAG_PREFIXOK** | Recognizer supports the recognition of any prefix part of the strings that are defined in the default or specified (factoid) language model.<br><br>For example, without this flag, the user writes "handw" and the recognizer returns suggestions (such as "hander" or "handed") that are words that exist in the recognizer lexicon. With the flag, the recognizer may return "handw" as one of the suggestions since it is a valid prefix of the word "handwriting" that exists in the recognizer lexicon.<br><br>The Tablet PC Input Panel sets this flag in most cases, except when the input scope is IS_DEFAULT (or no input scope) or when there is no user word list or regular expression.<br><br>Recognizers of East Asian characters should return E_INVALIDARG when a caller passes in this flag. |
| **RECOFLAG_LINEMODE** | The recognizer does not split lines but must still do character and word separation. This is the same as lined mode, except that there is no guide, and all ink is assumed to be in a single line. When this flag is set, a guide, if set, is ignored. |
| **RECOFLAG_SINGLESEG** | Disables multiple segmentation. By default, the recognizer returns multiple segmentations (alternates) for the ink.<br><br>For example, if you write "together" as separate strokes, the recognizer may segment the ink as "to get her", "to gather", or "together". Set this flag if you do not need multiple segmentations of the ink when you query for alternates. This improves performance and reduces memory usage. |
| **RECOFLAG_WORDMODE** | Recognizer treats the ink as a single word. For example, if the context contains "to get her", the recognizer returns "together". |

## Return value

This function can return one of these values.

| HRESULT value | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | The flag is invalid. |
| **E_NOTIMPL** | The recognizer does not support this function. |
| **E_OUTOFMEMORY** | Unable to allocate memory to complete the operation. |
| **E_FAIL** | An unspecified error occurred. |
| **E_POINTER** | The context is invalid or one of the parameters is an invalid pointer. |

## Remarks

Prior to Microsoft Windows XP Tablet PC Edition Development Kit 1.7, Tablet PC Input Panel performed smart spacing. Starting with Tablet PC SDK 1.7, Input Panel continues to produce results with preliminary spacing recommendations. Tablet PC Input Panel's spacing results may however be changed by the recognizer's recommendations (results). The recognizer is able to do this by using text contextual information (based on the [SetTextContext](https://learn.microsoft.com/windows/desktop/api/recapis/nf-recapis-settextcontext) call made by Input Panel) and its internal language model rules.

Input Panel is able to determine whether the recognizer is capable of doing auto-spacing by calling this function with the RECOFLAG_AUTOSPACE flag set. If the recognizer does not support auto-spacing, E_INVALIDARG is returned.

**Note** Only line mode is supported in the **SetFlags** function. Boxed mode, free mode, and single-line mode are not supported.

## See also

[SetFactoid Function](https://learn.microsoft.com/windows/desktop/api/recapis/nf-recapis-setfactoid)

[SetTextContext Function](https://learn.microsoft.com/windows/desktop/api/recapis/nf-recapis-settextcontext)