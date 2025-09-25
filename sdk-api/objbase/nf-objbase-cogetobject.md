# CoGetObject function

## Description

Converts a display name into a moniker that identifies the object named, and then binds to the object identified by the moniker.

## Parameters

### `pszName` [in]

The display name of the object to be created.

### `pBindOptions` [in, optional]

The binding options used to create a moniker that creates the actual object. For details, see [BIND_OPTS](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-bind_opts). This parameter can be **NULL**.

### `riid` [in]

A reference to the identifier of an interface that is implemented on the object to be created.

### `ppv` [out]

The address of a pointer to the interface specified by *riid* on the object that is created.

## Return value

This function can return the standard return values E_FAIL, E_OUTOFMEMORY, and E_UNEXPECTED, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The object was created successfully. |
| **MK_E_SYNTAX** | The *pszName* parameter is not a properly formed display name. |
| **MK_E_NOOBJECT** | The object identified by this moniker, or some object identified by the composite moniker of which this moniker is a part, could not be found. |
| **MK_E_EXCEEDEDDEADLINE** | The binding operation could not be completed within the time limit specified by the [BIND_OPTS](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-bind_opts) structure passed in *pBindOptions*. |
| **MK_E_CONNECTMANUALLY** | The binding operation requires assistance from the end user. The most common reasons for returning this value are that a password is needed or that a floppy needs to be mounted. |
| **MK_E_INTERMEDIATEINTERFACENOTSUPPORTED** | An intermediate object was found but it did not support an interface required to complete the binding operation. For example, an item moniker returns this value if its container does not support the [IOleItemContainer](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleitemcontainer) interface. |

## Remarks

**CoGetObject** encapsulates calls to the COM library functions [CreateBindCtx](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-createbindctx), [MkParseDisplayName](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-mkparsedisplayname), and [IMoniker::BindToObject](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-bindtoobject).

## See also

[BIND_OPTS](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-bind_opts)