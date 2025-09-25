# ITaskNamedValueCollection::Create

## Description

Creates a name-value pair in the collection.

## Parameters

### `name` [in]

The name associated with a value in a name-value pair.

### `value` [in]

The value associated with a name in a name-value pair.

### `ppPair` [out, retval]

The name-value pair created in the collection.

Pass in a reference to a **NULL** [ITaskNamedValuePair](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-itasknamedvaluepair) interface pointer. Referencing a non-**NULL** pointer can cause a memory leak because the pointer will be overwritten.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITaskNamedValueCollection](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-itasknamedvaluecollection)