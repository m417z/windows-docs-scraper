# KsAddObjectCreateItemToDeviceHeader function

## Description

The **KsAddObjectCreateItemToDeviceHeader** function adds the specified create-item to an empty item in the previously allocated create item list for this device header. An empty item is signified by a **NULL** create dispatch function in the entry. This function assumes that the caller is serializing multiple changes to the create items list.

## Parameters

### `Header` [in]

Points to the device header that contains the previously allocated child create table.

### `Create` [in]

Specifies the create dispatch function.

### `Context` [in]

Specifies the context parameter.

### `ObjectClass` [in]

Specifies a pointer to a **NULL**-terminated character string that will be used for comparison on create requests. This pointer must remain valid while the device object is active.

### `SecurityDescriptor` [in, optional]

Specifies the security descriptor. This must remain valid while the device object is active. This parameter is optional.

## Return value

The **KsAddObjectCreateItemToDeviceHeader** function returns STATUS_SUCCESS if an empty create item slot was found and the item was added.If unsuccessful, it returns STATUS_ALLOTTED_SPACE_EXCEEDED.