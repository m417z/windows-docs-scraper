# IBindCtx::RevokeObjectParam

## Description

Removes the specified key and its associated pointer from the bind context's string-keyed table of objects. The key must have previously been inserted into the table with a call to [RegisterObjectParam](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ibindctx-registerobjectparam).

## Parameters

### `pszKey` [in]

The [bind context string key](https://learn.microsoft.com/windows/desktop/shell/str-constants) to be removed. Key string comparison is case-sensitive.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The specified key was removed successfully. |
| **S_FALSE** | The object was not previously registered. |

## Remarks

A bind context maintains a table of interface pointers, each associated with a string key. This enables communication between a moniker implementation and the caller that initiated the binding operation. One party can store an interface pointer under a string known to both parties so that the other party can later retrieve it from the bind context.

This method is used to remove an entry from the table. If the specified key is found, the bind context also releases its reference to the object.

## See also

[IBindCtx](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ibindctx)