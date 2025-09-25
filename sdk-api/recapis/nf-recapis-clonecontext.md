# CloneContext function

## Description

Creates a recognizer context that contains the same settings as the original. The new recognizer context does not include the ink or recognition results of the original.

## Parameters

### `hrc`

The handle to the recognizer context.

### `pCloneHrc`

The new recognizer context.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | The *pCloneHrc* parameter is invalid. |
| **E_OUTOFMEMORY** | Unable to allocate memory to complete the operation. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | An invalid argument was received. |

## Remarks

The settings for this context include the recognition guide, character Autocomplete mode, and any factoids that improve the recognition results. An example of a factoid may include whether the ink is a phone number, a name, or a URL. The TextContext and Wordlists are preserved in the new context.

## See also

[ResetContext Function](https://learn.microsoft.com/windows/desktop/api/recapis/nf-recapis-resetcontext)

[SetTextContext Function](https://learn.microsoft.com/windows/desktop/api/recapis/nf-recapis-settextcontext)