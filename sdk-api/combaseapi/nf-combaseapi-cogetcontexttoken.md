# CoGetContextToken function

## Description

Returns a pointer to an implementation of [IObjContext](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iobjcontext) for the current context.

## Parameters

### `pToken` [out]

A pointer to an implementation of [IObjContext](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iobjcontext) for the current context.

## Return value

This function can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The token was retrieved successfully. |
| **E_POINTER** | The caller did not pass a valid token pointer variable. |
| **CO_E_NOTINITIALIZED** | The caller is not in an initialized apartment. |

## See also

[IContext](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-icontext)

[IObjContext](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iobjcontext)