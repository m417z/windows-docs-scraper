# SHChangeNotifyRegister function

## Description

Registers a window to receive notifications from the file system or Shell, if the file system supports notifications.

## Parameters

### `hwnd` [in]

Type: **HWND**

A handle to the window that receives the change or notification messages.

### `fSources`

Type: **int**

One or more of the following values that indicate the type of events for which to receive notifications.

**Note** In earlier versions of the SDK, these flags are not defined in a header file and implementers must define these values themselves or use their numeric values directly. As of Windows Vista, these flags are defined in Shlobj.h.

#### SHCNRF_InterruptLevel (0x0001)

Interrupt level notifications from the file system.

#### SHCNRF_ShellLevel (0x0002)

Shell-level notifications from the shell.

#### SHCNRF_RecursiveInterrupt (0x1000)

Interrupt events on the whole subtree. This flag must be combined with the **SHCNRF_InterruptLevel** flag. When using this flag, notifications must also be made recursive by setting the **fRecursive** member of the corresponding [SHChangeNotifyEntry](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-shchangenotifyentry) structure referenced by *pshcne* to **TRUE**. Use of **SHCNRF_RecursiveInterrupt** on a single level view—for example, a PIDL that is relative and contains only one [SHITEMID](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-shitemid)—will block event notification at the highest level and thereby prevent a recursive, child update. Thus, an icon dragged into the lowest level of a folder hierarchy may fail to appear in the view as expected.

#### SHCNRF_NewDelivery (0x8000)

Messages received use shared memory. Call [SHChangeNotification_Lock](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shchangenotification_lock) to access the actual data. Call [SHChangeNotification_Unlock](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shchangenotification_unlock) to release the memory when done.

**Note** We recommend this flag because it provides a more robust delivery method. All clients should specify this flag.

### `fEvents`

Type: **LONG**

Change notification events for which to receive notification. See the SHCNE flags listed in [SHChangeNotify](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shchangenotify) for possible values.

### `wMsg`

Type: **UINT**

Message to be posted to the window procedure.

### `cEntries`

Type: **int**

Number of entries in the *pshcne* array.

### `pshcne` [in]

Type: **const [SHChangeNotifyEntry](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-shchangenotifyentry)***

Array of [SHChangeNotifyEntry](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-shchangenotifyentry) structures that contain the notifications. This array should always be set to one when calling **SHChangeNotifyRegister** or [SHChangeNotifyDeregister](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shchangenotifyderegister) will not work properly.

## Return value

Type: **ULONG**

Returns a positive integer registration ID. Returns 0 if out of memory or in response to invalid parameters.

## Remarks

See the [Change Notify Watcher Sample](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd940348(v=vs.85)) in the Windows Software Development Kit (SDK) for a full example that demonstrates the use of this function.

When a change notification event is raised, the message indicated by *wMsg* is delivered to the window specified by the *hwnd* parameter.

* If SHCNRF_NewDelivery is specified, the *wParam* and *lParam* values in the message should be passed to [SHChangeNotification_Lock](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shchangenotification_lock) as the *hChange* and *dwProcID* parameters respectively.
* If SHCNRF_NewDelivery is not specified, *wParam* is a pointer to two PIDLIST_ABSOLUTE pointers, and *lParam* specifies the event. The two PIDLIST_ABSOLUTE pointers can be **NULL**, depending on the event being sent.

When a relevant file system event takes place and the *hwnd* parameter is not **NULL**, then the message indicated by *wMsg* is posted to the specified window. Otherwise, if the *pshcne* parameter is not **NULL**, then that notification entry is used.

For performance reasons, multiple notifications can be combined into a single notification. For example, if a large number of [SHCNE_UPDATEITEM](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shchangenotify) notifications are generated for files in the same folder, they can be joined into a single [SHCNE_UPDATEDIR](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shchangenotify) notification.

The **NTSHChangeNotifyRegister** function, which is no longer available as of Windows Vista, was equivalent to **SHChangeNotifyRegister** with the SHCNRF_NewDelivery flag.