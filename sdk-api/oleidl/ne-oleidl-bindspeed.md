# BINDSPEED enumeration

## Description

Indicates approximately how long the caller will wait to bind to an object.

## Constants

### `BINDSPEED_INDEFINITE:1`

There is no time limit on the binding operation.

### `BINDSPEED_MODERATE:2`

The binding operation must be completed in a moderate amount of time.

If this flag is specified, the implementation of [IOleItemContainer::GetObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleitemcontainer-getobject) should return MK_E_EXCEEEDEDDEADLINE unless tone of the following is true:

* The object is already in the running state.
* The object is a pseudo-object (an object internal to the item container, such as a cell-range in a spreadsheet or a character-range in a word processor).
* The object is supported by an in-process server (so it is always in the running state when it is loaded). In this case, [GetObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleitemcontainer-getobject) should load the designated object, and, if the [OleIsRunning](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleisrunning) function indicates that the object is running, return successfully.

### `BINDSPEED_IMMEDIATE:3`

The caller will wait only a short time. In this case, the binding operation should return MK_E_EXCEEEDEDDEADLINE unless the object is already in the running state or is a pseudo-object.

## Remarks

The system-supplied item moniker implementation is the primary caller of [IOleItemContainer::GetObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleitemcontainer-getobject). The **BINDSPEED** value that it specifies depends on the deadline specified by the caller of the moniker operation.

The deadline is stored in the **dwTickCountDeadline** field of the [BIND_OPTS](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-bind_opts) structure in the bind context passed to the moniker operation. This value is based on the return value of the [GetTickCount](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-gettickcount) function. If *dwTickCountDeadline* is zero, indicating no deadline, the item moniker implementation specifies BINDSPEED_INDEFINITE. (This is the default *dwTickCountDeadline* value for a bind context returned by the [CreateBindCtx](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-createbindctx) function.) If the difference between *dwTickCountDeadline* and the value returned by **GetTickCount** is greater than 2500, the item moniker implementation specifies BINDSPEED_MODERATE. If the difference is less than 2500, the item moniker implementation specifies BINDSPEED_IMMEDIATE.

Implementations of [GetObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleitemcontainer-getobject) can use the **BINDSPEED** value as a shortcut approximation of the binding deadline, or they can use the [IBindCtx](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ibindctx) instance parameter to determine the exact deadline.

## See also

[BIND_OPTS](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-bind_opts)

[IBindCtx](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ibindctx)

[IOleItemContainer::GetObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleitemcontainer-getobject)