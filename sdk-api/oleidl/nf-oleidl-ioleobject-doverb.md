# IOleObject::DoVerb

## Description

Requests that an object perform an action in response to an end-user's action. The possible actions are enumerated for the object in [IOleObject::EnumVerbs](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-enumverbs).

## Parameters

### `iVerb` [in]

Number assigned to the verb in the [OLEVERB](https://learn.microsoft.com/windows/desktop/api/oleidl/ns-oleidl-oleverb) structure returned by [IOleObject::EnumVerbs](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-enumverbs).

### `lpmsg` [in]

Pointer to the [MSG](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-msg) structure describing the event (such as a double-click) that invoked the verb. The caller should pass the **MSG** structure unmodified, without attempting to interpret or alter the values of any of the structure members.

### `pActiveSite` [in]

Pointer to the [IOleClientSite](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleclientsite) interface on the object's active client site, where the event occurred that invoked the verb.

### `lindex` [in]

This parameter is reserved and must be zero.

### `hwndParent` [in]

Handle of the document window containing the object. This and *lprcPosRect* together make it possible to open a temporary window for an object, where *hwndParent* is the parent window in which the object's window is to be displayed, and *lprcPosRect* defines the area available for displaying the object window within that parent. A temporary window is useful, for example, to a multimedia object that opens itself for playback but not for editing.

### `lprcPosRect` [in]

Pointer to the [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure containing the coordinates, in pixels, that define an object's bounding rectangle in *hwndParent*. This and *hwndParent* together enable opening multimedia objects for playback but not for editing.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **OLE_E_NOT_INPLACEACTIVE** | iVerb set to OLEIVERB_UIACTIVATE or OLEIVERB_INPLACEACTIVATE and object is not already visible. |
| **OLE_E_CANT_BINDTOSOURCE** | The object handler or link object cannot connect to the link source. |
| **DV_E_LINDEX** | Invalid lindex. |
| **OLEOBJ_S_CANNOT_DOVERB_NOW** | The verb is valid, but in the object's current state it cannot carry out the corresponding action. |
| **OLEOBJ_S_INVALIDHWND** | DoVerb was successful but *hwndParent* is invalid. |
| **OLEOBJ_E_NOVERBS** | The object does not support any verbs. |
| **OLEOBJ_S_INVALIDVERB** | Link source is across a network that is not connected to a drive on this computer. |
| **MK_E_CONNECT** | Link source is across a network that is not connected to a drive on this computer. |
| **OLE_E_CLASSDIFF** | Class for source of link has undergone a conversion. |
| **E_NOTIMPL** | Object does not support in-place activation or does not recognize a negative verb number. |

## Remarks

A "verb" is an action that an OLE object takes in response to a message from its container. An object's container, or a client linked to the object, normally calls **IOleObject::DoVerb** in response to some end-user action, such as double-clicking on the object. The various actions that are available for a given object are enumerated in an [OLEVERB](https://learn.microsoft.com/windows/desktop/api/oleidl/ns-oleidl-oleverb) structure, which the container obtains by calling [IOleObject::EnumVerbs](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-enumverbs). **IOleObject::DoVerb** matches the value of iVerb against the iVerb member of the structure to determine which verb to invoke.

Through [IOleObject::EnumVerbs](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-enumverbs), an object, rather than its container, determines which verbs (i.e., actions) it supports. OLE 2 defines seven verbs that are available, but not necessarily useful, to all objects. In addition, each object can define additional verbs that are unique to it. The following table describes the verbs defined by OLE.

| Verb | Description |
| --- | --- |
| OLEIVERB_PRIMARY (0L) | Specifies the action that occurs when an end user double-clicks the object in its container. The object, not the container, determines this action. If the object supports in-place activation, the primary verb usually activates the object in place. |
| OLEIVERB_SHOW (-1) | Instructs an object to show itself for editing or viewing. Called to display newly inserted objects for initial editing and to show link sources. Usually an alias for some other object-defined verb. |
| OLEIVERB_OPEN (-2) | Instructs an object, including one that otherwise supports in-place activation, to open itself for editing in a window separate from that of its container. If the object does not support in-place activation, this verb has the same semantics as OLEIVERB_SHOW. |
| OLEIVERB_HIDE (-3) | Causes an object to remove its user interface from the view. Applies only to objects that are activated in-place. |
| OLEIVERB_UIACTIVATE (-4) | Activates an object in place, along with its full set of user-interface tools, including menus, toolbars, and its name in the title bar of the container window. If the object does not support in-place activation, it should return E_NOTIMPL. |
| OLEIVERB_INPLACEACTIVATE (-5) | Activates an object in place without displaying tools, such as menus and toolbars, that end users need to change the behavior or appearance of the object. Single-clicking such an object causes it to negotiate the display of its user-interface tools with its container. If the container refuses, the object remains active but without its tools displayed. |
| OLEIVERB_DISCARDUNDOSTATE (-6) | Used to tell objects to discard any undo state that they may be maintaining without deactivating the object. |

### Notes to Callers

Containers call **IOleObject::DoVerb** as part of initializing a newly created object. Before making the call, containers should first call [IOleObject::SetClientSite](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-setclientsite) to inform the object of its display location and [IOleObject::SetHostNames](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-sethostnames) to alert the object that it is an embedded object and to trigger appropriate changes to the user interface of the object application in preparation for opening an editing window.

**IOleObject::DoVerb** automatically runs the OLE server application. If an error occurs during verb execution, the object application is shut down.

If an end user invokes a verb by some means other than selecting a command from a menu (say, by double-clicking or, more rarely, single-clicking an object), the object's container should pass a pointer to a Windows [MSG](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-msg) structure containing the appropriate message. For example, if the end user invokes a verb by double-clicking the object, the container should pass a **MSG** structure containing WM_LBUTTONDBLCLK, WM_MBUTTONDBLCLK, or WM_RBUTTONDBLCLK. If the container passes no message, lpmsg should be set to **NULL**. The object should ignore the **hwnd** member of the passed **MSG** structure, but can use all the other MSG members.

If the object's embedding container calls **IOleObject::DoVerb**, the client-site pointer (*pClientSite*) passed to **IOleObject::DoVerb** is the same as that of the embedding site. If the embedded object is a link source, the pointer passed to **IOleObject::DoVerb** is that of the linking client's client site.

When **IOleObject::DoVerb** is invoked on an OLE link, it may return OLE_E_CLASSDIFF or MK_CONNECTMANUALLY. The link object returns the former error when the link source has been subjected to some sort of conversion while the link was passive. The link object returns the latter error when the link source is located on a network drive that is not currently connected to the caller's computer. The only way to connect a link under these conditions is to first call [IUnknown::QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)), ask for [IOleLink](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iolelink), allocate a bind context, and run the link source by calling [IOleLink::BindToSource](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolelink-bindtosource).

Container applications that do not support general in-place activation can still use the *hwndParent* and *lprcPosRect* parameters to support in-place playback of multimedia files. Containers must pass valid *hwndParent* and *lprcPosRect* parameters to **IOleObject::DoVerb**.

Some code samples pass a lindex value of -1 instead of zero. The value -1 works but should be avoided in favor of zero. The *lindex* parameter is a reserved parameter, and for reasons of consistency Microsoft recommends assigning a zero value to all reserved parameters.

### Notes to Implementers

In addition to the above verbs, an object can define in its [OLEVERB](https://learn.microsoft.com/windows/desktop/api/oleidl/ns-oleidl-oleverb) structure additional verbs that are specific to itself. Positive numbers designate these object-specific verbs. An object should treat any unknown positive verb number as if it were the primary verb and return OLEOBJ_S_INVALIDVERB to the calling function. The object should ignore verbs with negative numbers that it does not recognize and return E_NOTIMPL.

If the verb being executed places the object in the running state, you should register the object in the running object table (ROT) even if its server application doesn't support linking. Registration is important because the object at some point may serve as the source of a link in a container that supports links to embeddings. Registering the object with the ROT enables the link client to get a pointer to the object directly, instead of having to go through the object's container. To perform the registration, call [IOleClientSite::GetMoniker](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleclientsite-getmoniker) to get the full moniker of the object, call the [GetRunningObjectTable](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-getrunningobjecttable) function to get a pointer to the ROT, and then call [IRunningObjectTable::Register](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-irunningobjecttable-register).

**Note** When the object leaves the running state, remember to revoke the object's registration with the ROT by calling [IOleObject::Close](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-close). If the object's container document is renamed while the object is running, you should revoke the object's registration and re-register it with the ROT, using its new name. The container should inform the object of its new moniker either by calling [IOleObject::SetMoniker](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-setmoniker) or by responding to the object's calling [IOleClientSite::GetMoniker](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleclientsite-getmoniker).

When showing a window as a result of **IOleObject::DoVerb**, it is very important for the object to explicitly call [SetForegroundWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setforegroundwindow) on its editing window. This ensures that the object's window will be visible to the user even if another process originally obscured it. For more information see **SetForegroundWindow** and [SetActiveWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setactivewindow).

## See also

[GetRunningObjectTable](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-getrunningobjecttable)

[IOleClientSite::GetMoniker](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleclientsite-getmoniker)

[IOleLink::BindToSource](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolelink-bindtosource)

[IOleObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleobject)

[IOleObject::Close](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-close)

[IOleObject::EnumVerbs](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-enumverbs)

[IOleObject::GetMoniker](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-getmoniker)

[IOleObject::SetMoniker](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-setmoniker)

[IRunningObjectTable::Register](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-irunningobjecttable-register)

[OleRun](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olerun)