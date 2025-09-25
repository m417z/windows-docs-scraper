# ISharedPropertyGroupManager::CreatePropertyGroup

## Description

Creates a new shared property group. If a property group with the specified name already exists, **CreatePropertyGroup** returns a reference to the existing group.

## Parameters

### `Name` [in]

The name of the shared property group to be created.

### `dwIsoMode` [in, out]

The isolation mode for the properties in the new shared property group. See the table of constants in Remarks below. If the value of the *fExists* parameter is set to VARIANT_TRUE on return from this method, the input value is ignored and the value returned in this parameter is the isolation mode that was assigned when the property group was created.

### `dwRelMode` [in, out]

The release mode for the properties in the new shared property group. See the table of constants in Remarks below. If the value of the *fExists* parameter is set to VARIANT_TRUE on return from this method, the input value is ignored and the value returned in this parameter is the release mode that was assigned when the property group was created.

### `fExists` [out]

VARIANT_TRUE on return from this method if the shared property group specified in the name parameter existed prior to this call, and VARIANT_FALSE if the property group was created by this call.

### `ppGroup` [out]

A reference to [ISharedPropertyGroup](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-isharedpropertygroup), which is a shared property group identified by the *Name* parameter, or **NULL** if an error is encountered.

## Return value

This method can return the standard return values E_OUTOFMEMORY, E_UNEXPECTED, and E_FAIL, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | A reference to the shared property group specified in the *Name* parameter is returned in the *ppGroup* parameter. |
| **CONTEXT_E_NOCONTEXT** | The caller is not executing under COM+. A caller must be executing under COM+ to use the Shared Property Manager. |
| **E_INVALIDARG** | At least one of the parameters is not valid, or the same object is attempting to create the same property group more than once. |

## Remarks

The following constants are used to specify the effective isolation mode for a shared property group.

| Constant | Value | Description |
| --- | --- | --- |
| LockSetGet | 0 | The default value. It assures that every get or set operation on a shared property is atomic by locking the property during the call. This ensures that two clients cannot read or write to the same property at the same time, but it does not prevent other clients from concurrently accessing other properties in the same group. |
| LockMethod | 1 | This value locks all the properties in the shared property group for exclusive use by the caller as long as the caller's current method is executing. This is the appropriate mode to use when there are interdependencies among properties, or in cases where a client may have to update a property immediately after reading it before it can be accessed again. |

**Note** When you set the isolation mode to LockMethod, the Shared Property Manager requires access to the calling object's object context. You cannot use this isolation mode to create a shared property group from within an object's constructor or from a non-COM+ object because the object context is not available during object construction and a base client does not have an object context.

The following constants are used to specify the effective release mode for a shared property group.

| Constant | Value | Description |
| --- | --- | --- |
| Standard | 0 | The default value. When all clients have released their references on the property group, the property group is automatically destroyed. |
| Process | 1 | The property group is not destroyed until the process in which it was created has terminated. Objects that hold references on a property group must still call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on their references. |

**Note** An object should never attempt to pass a shared property group reference to another object. If the reference is passed outside of the object that acquired it, it is no longer a valid reference.

## See also

[ISharedPropertyGroupManager](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-isharedpropertygroupmanager)