# SHChangeNotify function

## Description

Notifies the system of an event that an application has performed. An application should use this function if it performs an action that may affect the Shell.

## Parameters

### `wEventId`

Type: **LONG**

Describes the event that has occurred. Typically, only one event is specified at a time. If more than one event is specified, the values contained in the *dwItem1* and *dwItem2* parameters must be the same, respectively, for all specified events. This parameter can be one or more of the following values:

#### SHCNE_ALLEVENTS

All events have occurred.

#### SHCNE_ASSOCCHANGED

A file type association has changed. **SHCNF_IDLIST** must be specified in the *uFlags* parameter. *dwItem1* and *dwItem2* are not used and must be **NULL**. This event should also be sent for registered protocols.

#### SHCNE_ATTRIBUTES

The attributes of an item or folder have changed. **SHCNF_IDLIST** or **SHCNF_PATH** must be specified in *uFlags*. *dwItem1* contains the item or folder that has changed. *dwItem2* is not used and should be **NULL**.

#### SHCNE_CREATE

A nonfolder item has been created. **SHCNF_IDLIST** or **SHCNF_PATH** must be specified in *uFlags*. *dwItem1* contains the item that was created. *dwItem2* is not used and should be **NULL**.

#### SHCNE_DELETE

A nonfolder item has been deleted. **SHCNF_IDLIST** or **SHCNF_PATH** must be specified in *uFlags*. *dwItem1* contains the item that was deleted. *dwItem2* is not used and should be **NULL**.

#### SHCNE_DRIVEADD

A drive has been added. **SHCNF_IDLIST** or **SHCNF_PATH** must be specified in *uFlags*. *dwItem1* contains the root of the drive that was added. *dwItem2* is not used and should be **NULL**.

#### SHCNE_DRIVEADDGUI

**Windows XP and later**: Not used.

#### SHCNE_DRIVEREMOVED

A drive has been removed. **SHCNF_IDLIST** or **SHCNF_PATH** must be specified in *uFlags*. *dwItem1* contains the root of the drive that was removed. *dwItem2* is not used and should be **NULL**.

#### SHCNE_EXTENDED_EVENT

Not currently used.

#### SHCNE_FREESPACE

The amount of free space on a drive has changed. **SHCNF_IDLIST** or **SHCNF_PATH** must be specified in *uFlags*. *dwItem1* contains the root of the drive on which the free space changed. *dwItem2* is not used and should be **NULL**.

#### SHCNE_MEDIAINSERTED

Storage media has been inserted into a drive. **SHCNF_IDLIST** or **SHCNF_PATH** must be specified in *uFlags*. *dwItem1* contains the root of the drive that contains the new media. *dwItem2* is not used and should be **NULL**.

#### SHCNE_MEDIAREMOVED

Storage media has been removed from a drive. **SHCNF_IDLIST** or **SHCNF_PATH** must be specified in *uFlags*. *dwItem1* contains the root of the drive from which the media was removed. *dwItem2* is not used and should be **NULL**.

#### SHCNE_MKDIR

A folder has been created. **SHCNF_IDLIST** or **SHCNF_PATH** must be specified in *uFlags*. *dwItem1* contains the folder that was created. *dwItem2* is not used and should be **NULL**.

#### SHCNE_NETSHARE

A folder on the local computer is being shared via the network. **SHCNF_IDLIST** or **SHCNF_PATH** must be specified in *uFlags*. *dwItem1* contains the folder that is being shared. *dwItem2* is not used and should be **NULL**.

#### SHCNE_NETUNSHARE

A folder on the local computer is no longer being shared via the network. **SHCNF_IDLIST** or **SHCNF_PATH** must be specified in *uFlags*. *dwItem1* contains the folder that is no longer being shared. *dwItem2* is not used and should be **NULL**.

#### SHCNE_RENAMEFOLDER

The name of a folder has changed. **SHCNF_IDLIST** or **SHCNF_PATH** must be specified in *uFlags*. *dwItem1* contains the previous PIDL or name of the folder. *dwItem2* contains the new PIDL or name of the folder.

#### SHCNE_RENAMEITEM

The name of a nonfolder item has changed. **SHCNF_IDLIST** or **SHCNF_PATH** must be specified in *uFlags*. *dwItem1* contains the previous PIDL or name of the item. *dwItem2* contains the new PIDL or name of the item.

#### SHCNE_RMDIR

A folder has been removed. **SHCNF_IDLIST** or **SHCNF_PATH** must be specified in *uFlags*. *dwItem1* contains the folder that was removed. *dwItem2* is not used and should be **NULL**.

#### SHCNE_SERVERDISCONNECT

The computer has disconnected from a server. **SHCNF_IDLIST** or **SHCNF_PATH** must be specified in *uFlags*. *dwItem1* contains the server from which the computer was disconnected. *dwItem2* is not used and should be **NULL**.

#### SHCNE_UPDATEDIR

The contents of an existing folder have changed, but the folder still exists and has not been renamed. **SHCNF_IDLIST** or **SHCNF_PATH** must be specified in *uFlags*. *dwItem1* contains the folder that has changed. *dwItem2* is not used and should be **NULL**. If a folder has been created, deleted, or renamed, use **SHCNE_MKDIR**, **SHCNE_RMDIR**, or **SHCNE_RENAMEFOLDER**, respectively.

#### SHCNE_UPDATEIMAGE

An image in the system image list has changed. **SHCNF_DWORD** must be specified in *uFlags*.

*dwItem2* contains the index in the system image list that has changed. *dwItem1* is not used and should be **NULL**.

#### SHCNE_UPDATEITEM

An existing item (a folder or a nonfolder) has changed, but the item still exists and has not been renamed. **SHCNF_IDLIST** or **SHCNF_PATH** must be specified in *uFlags*. *dwItem1* contains the item that has changed. *dwItem2* is not used and should be **NULL**. If a nonfolder item has been created, deleted, or renamed, use **SHCNE_CREATE**, **SHCNE_DELETE**, or **SHCNE_RENAMEITEM**, respectively, instead.

#### SHCNE_DISKEVENTS

Specifies a combination of all of the disk event identifiers.

#### SHCNE_GLOBALEVENTS

Specifies a combination of all of the global event identifiers.

#### SHCNE_INTERRUPT

The specified event occurred as a result of a system interrupt. As this value modifies other event values, it cannot be used alone.

### `uFlags`

Type: **UINT**

Flags that, when combined bitwise with **SHCNF_TYPE**, indicate the meaning of the *dwItem1* and *dwItem2* parameters. The *uFlags* parameter must be one of the following values.

#### SHCNF_DWORD

The *dwItem1* and *dwItem2* parameters are **DWORD** values.

#### SHCNF_IDLIST

*dwItem1* and *dwItem2* are the addresses of [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structures that represent the item(s) affected by the change. Each **ITEMIDLIST** must be relative to the desktop folder.

#### SHCNF_PATH

*dwItem1* and *dwItem2* are the addresses of null-terminated strings of maximum length **MAX_PATH** that contain the full path names of the items affected by the change.

#### SHCNF_PRINTER

*dwItem1* and *dwItem2* are the addresses of null-terminated strings that represent the friendly names of the printer(s) affected by the change.

#### SHCNF_FLUSH

The function should not return until the notification has been delivered to all affected components. As this flag modifies other data-type flags, it cannot be used by itself.

#### SHCNF_FLUSHNOWAIT

The function should begin delivering notifications to all affected components but should return as soon as the notification process has begun. As this flag modifies other data-type flags, it cannot by used by itself. This flag includes **SHCNF_FLUSH**.

#### SHCNF_NOTIFYRECURSIVE

Notify clients registered for all children.

### `dwItem1` [in, optional]

Type: **LPCVOID**

Optional. First event-dependent value.

### `dwItem2` [in, optional]

Type: **LPCVOID**

Optional. Second event-dependent value.

## Remarks

Applications that register new handlers of any type must call **SHChangeNotify** with the **SHCNE_ASSOCCHANGED** flag to instruct the Shell to invalidate the icon and thumbnail cache. This will also load new icon and thumbnail handlers that have been registered. Note, however, that icon overlay handlers are not reloaded.

The strings pointed to by *dwItem1* and *dwItem2* can be either ANSI or Unicode.