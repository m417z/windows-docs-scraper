# ITfFnLMProcessor::QueryLangID

## Description

Determines if the language model text service supports a particular language.

## Parameters

### `langid` [in]

Contains a **LANGID** that specifies the identifier of the language that the query applies to.

### `pfAccepted` [out]

Pointer to a **BOOL** value that receives nonzero if the language model text service supports the language identified by *langid* or zero otherwise.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | *pfAccepted* is invalid. |

## Remarks

If a client can possibly generate more than one language identifier of text, it should query all with this method.