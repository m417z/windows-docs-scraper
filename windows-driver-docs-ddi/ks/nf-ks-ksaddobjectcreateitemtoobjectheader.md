# KsAddObjectCreateItemToObjectHeader function

## Description

The **KsAddObjectCreateItemToObjectHeader** function adds the specified create-item to an empty item in the previously allocated create item list for this object header. An empty item is signified by a **NULL** create dispatch function in the entry. This function assumes that the caller is serializing multiple changes to the create items list.

## Parameters

### `Header` [in]

Points to the object header that contains the previously allocated child- create table.

### `Create` [in]

Specifies the create dispatch function to use.

### `Context` [in]

Specifies the context parameter.

### `ObjectClass` [in]

Specifies a pointer to a **NULL**-terminated character string that is used for comparison on create requests. This pointer must remain valid while the object is active.

### `SecurityDescriptor` [in, optional]

Specifies the security descriptor. This must remain valid while the object is active.

## Return value

The **KsAddObjectCreateItemToObjectHeader** function returns STATUS_SUCCESS if an empty create item slot was found and the item was added. If unsuccessful, it returns STATUS_ALLOTTED_SPACE_EXCEEDED.