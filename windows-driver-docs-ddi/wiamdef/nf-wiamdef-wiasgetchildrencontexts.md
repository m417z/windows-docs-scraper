# wiasGetChildrenContexts function

## Description

The **wiasGetChildrenContexts** function retrieves an array of item contexts belonging to the current item's children.

## Parameters

### `pParentContext` [in]

Pointer to the parent item.

### `pulNumChildren` [out]

Pointer to a memory location that receives the number of children contexts.

### `pppChildren` [out]

Pointer to a memory location that points to an array whose elements are addresses of [IWiaItem](https://learn.microsoft.com/windows/win32/api/wia_xp/nn-wia_xp-iwiaitem) objects. Each **IWiaItem** object represents one child context.

## Return value

On success, the function returns S_OK.

If the function fails, it returns a standard COM error or one of the [WIA error codes](https://learn.microsoft.com/windows/win32/wia/-wia-error-codes).