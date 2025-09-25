# IBindCtx::RevokeObjectBound

## Description

Removes the object from the bind context, undoing a previous call to [RegisterObjectBound](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ibindctx-registerobjectbound).

## Parameters

### `punk` [in]

A pointer to the [IUnknown](https://learn.microsoft.com/windows/desktop/com/iunknown-and-interface-inheritance) interface on the object to be removed.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The object was released successfully. |
| **MK_E_NOTBOUND** | The object was not previously registered. |

## Remarks

You would rarely call this method. It is documented primarily for completeness.

## See also

[IBindCtx](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ibindctx)