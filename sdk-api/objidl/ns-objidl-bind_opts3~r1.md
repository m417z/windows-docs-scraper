# BIND_OPTS3 structure

## Description

Contains parameters used during a moniker-binding operation.

## Members

### `cbStruct`

The size of this structure, in bytes.

### `grfFlags`

Flags that control aspects of moniker binding operations. This value is any combination of the bit flags in the [BIND_FLAGS](https://learn.microsoft.com/windows/desktop/api/objidl/ne-objidl-bind_flags) enumeration. The [CreateBindCtx](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-createbindctx) function initializes this member to zero.

### `grfMode`

Flags that should be used when opening the file that contains the object identified by the moniker. Possible values are the [STGM constants](https://learn.microsoft.com/windows/desktop/Stg/stgm-constants). The binding operation uses these flags in the call to [IPersistFile::Load](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersistfile-load) when loading the file. If the object is already running, these flags are ignored by the binding operation. The [CreateBindCtx](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-createbindctx) function initializes this field to STGM_READWRITE.

### `dwTickCountDeadline`

The clock time by which the caller would like the binding operation to be completed, in milliseconds. This member lets the caller limit the execution time of an operation when speed is of primary importance. A value of zero indicates that there is no deadline. Callers most often use this capability when calling the [IMoniker::GetTimeOfLastChange](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-gettimeoflastchange) method, though it can be usefully applied to other operations as well. The [CreateBindCtx](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-createbindctx) function initializes this field to zero.

Typical deadlines allow for a few hundred milliseconds of execution. This deadline is a recommendation, not a requirement; however, operations that exceed their deadline by a large amount may cause delays for the end user. Each moniker implementation should try to complete its operation by the deadline, or fail with the error MK_E_EXCEEDEDDEADLINE.

If a binding operation exceeds its deadline because one or more objects that it needs are not running, the moniker implementation should register the objects responsible in the bind context using the [IBindCtx::RegisterObjectParam](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ibindctx-registerobjectparam). The objects should be registered under the parameter names "ExceededDeadline", "ExceededDeadline1", "ExceededDeadline2", and so on. If the caller later finds the object in the running object table, the caller can retry the binding operation.

The [GetTickCount](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-gettickcount) function indicates the number of milliseconds since system startup, and wraps back to zero after 2^31 milliseconds. Consequently, callers should be careful not to inadvertently pass a zero value (which indicates no deadline), and moniker implementations should be aware of clock wrapping problems.

### `dwTrackFlags`

A moniker can use this value during link tracking. If the original persisted data that the moniker is referencing has been moved, the moniker can attempt to reestablish the link by searching for the original data though some adequate mechanism. This member provides additional information on how the link should be resolved. See the documentation of the *fFlags* parameter in [IShellLink::Resolve](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllinka-resolve).

COM's file moniker implementation uses the shell link mechanism to reestablish links and passes these flags to [IShellLink::Resolve](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllinka-resolve).

### `dwClassContext`

The class context, taken from the [CLSCTX](https://learn.microsoft.com/windows/desktop/api/wtypesbase/ne-wtypesbase-clsctx) enumeration, that is to be used for instantiating the object. Monikers typically pass this value to the *dwClsContext* parameter of [CoCreateInstance](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cocreateinstance).

### `locale`

The [LCID value](https://learn.microsoft.com/windows/desktop/Intl/language-identifier-constants-and-strings) indicating the client's preference for the locale to be used by the object to which they are binding. A moniker passes this value to [IClassActivator::GetClassObject](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iclassactivator-getclassobject).

### `pServerInfo`

A pointer to a [COSERVERINFO](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-coserverinfo) structure. This member allows clients calling [IMoniker::BindToObject](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-bindtoobject) to specify server information. Clients may pass a [BIND_OPTS2](https://learn.microsoft.com/windows/win32/api/objidl/ns-objidl-bind_opts2~r1) structure to the [IBindCtx::SetBindOptions](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ibindctx-setbindoptions) method. If a server name is specified in the **COSERVERINFO** structure, the moniker bind will be forwarded to the specified computer. **SetBindOptions** only copies the struct members of **BIND_OPTS2**, not the **COSERVERINFO** structure and the pointers it contains. Callers may not free any of these pointers until the bind context is released. COM's new class moniker does not currently honor the **pServerInfo** flag.

### `hwnd`

A handle to the window that becomes the owner of the elevation UI, if applicable. If **hwnd** is **NULL**, COM will call the [GetActiveWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getactivewindow) function to find a window handle associated with the current thread. This case might occur if the client is a script, which cannot fill in a **BIND_OPTS3** structure. In this case, COM will try to use the window associated with the script thread.

## Remarks

A **BIND_OPTS3** structure is stored in a bind context; the same bind context is used by each component of a composite moniker during binding, allowing the same parameters to be passed to all components of a composite moniker. See [IBindCtx](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ibindctx) for more information about bind contexts.

Moniker clients (use a moniker to acquire an interface pointer to an object) typically do not need to specify values for the members of this structure. The [CreateBindCtx](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-createbindctx) function creates a bind context with the bind options set to default values that are suitable for most situations; the [BindMoniker](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-bindmoniker) function does the same thing when creating a bind context for use in binding a moniker. If you want to modify the values of these bind options, you can do so by passing a **BIND_OPTS3** structure to the [IBindCtx::SetBindOptions](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ibindctx-setbindoptions) method. Moniker implementers can pass a **BIND_OPTS3** structure to the [IBindCtx::GetBindOptions](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ibindctx-getbindoptions) method to retrieve the values of these bind options.

## See also

[CreateBindCtx](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-createbindctx)

[IBindCtx](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ibindctx)

[IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker)