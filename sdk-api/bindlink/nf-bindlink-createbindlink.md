## Description

This API allows admins to create a bind link between a virtual path and a backing path. The virtual path is always local while the backing path could be local or remote (a network share, for example). The parent of the *virtualPath* should be visible for the link creation to succeed. Both the virtual path and the backing path can represent files or directories. The *backingPath* for a prior link can be a *virtualPath* for a subsequent link as well. **CreateBindLink** can only be called by a user with Administrator privileges. Once created, a bind link exists system-wide, and it lasts until it is deleted by calling [RemoveBindLink](https://learn.microsoft.com/windows/win32/api/bindlink/nf-bindlink-removebindlink), or until the system is shut down.

## Parameters

### `virtualPath`

The virtual path to be used to create the bind link.

### `backingPath`

The backing path to be used to create the bind link.

### `createBindLinkFlags`

These flags can change the default bind link behavior to suit the needs of the user. See [CREATE_BIND_LINK_FLAGS](https://learn.microsoft.com/windows/win32/api/bindlink/ne-bindlink-create_bind_link_flags) for more details.

### `exceptionCount`

The number of exceptions provided in the *exceptionPaths* parameter.

### `exceptionPaths`

The exception paths to be excluded from the bind link. Note that exceptions do not apply to anchorless links since anchorless virtual paths have no descendants by definition and, therefore, have no paths that qualify. The API will return an error if there is an attempt to pass exceptions to anchorless link.

## Return value

## Remarks

For more information about creating bind links, see [Bindlink Overview - Creating bind links](https://learn.microsoft.com/windows/win32/bindlink/bindlink-overview#create-bind-links).

#### Examples

For a full example of how to use the **CreateBindLink** and **RemoveBindLink** APIs, see the [bind link example](https://learn.microsoft.com/windows/win32/bindlink/bindlink-example) page.

## See also

[RemoveBindLink](https://learn.microsoft.com/windows/win32/api/bindlink/nf-bindlink-removebindlink)