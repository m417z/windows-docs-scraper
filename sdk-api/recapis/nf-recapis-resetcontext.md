# ResetContext function

## Description

Deletes the current ink and recognition results from the context.

The current settings of the recognizer context are preserved. The settings can include the recognition guide, character Autocomplete mode, and any recognition hints that improve recognition results. An example of a recognition hint may include whether a factoid is set indicating that the ink is a phone number, a name, or a URL. The TextContext and Wordlists are preserved in the context.

## Parameters

### `hrc`

The handle to the recognizer context.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | An invalid argument was received. |

## See also

[CloneContext Function](https://learn.microsoft.com/windows/desktop/api/recapis/nf-recapis-clonecontext)