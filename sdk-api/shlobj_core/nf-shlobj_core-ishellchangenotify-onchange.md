# IShellChangeNotify::OnChange

## Description

Informs a namespace extension that an event has taken place that affects its items.

## Parameters

### `lEvent`

Type: **LONG**

A value that describes the event that has occurred. Typically, only one event is specified at a time. If more than one event is specified, the values contained in the *pidl1* and *pidl2* parameters must be the same, respectively, for all specified events.The *lEvent* parameter may contain one or more of the following flags.

#### SHCNE_ALLEVENTS (0x7FFFFFFFL)

All events have occurred.

#### SHCNE_ASSOCCHANGED (0x08000000L)

A file type association has changed. The *pidl1* and *pidl2* parameters are not used and must be **NULL**.

#### SHCNE_ATTRIBUTES (0x00000800L)

The attributes of an item or folder have changed. The *pidl1* parameter contains the item or folder that has changed. The *pidl2* parameter is not used and should be **NULL**.

#### SHCNE_CREATE (0x00000002L)

A nonfolder item has been created. The *pidl1* parameter contains the item that was created. The *pidl2* parameter is not used and should be **NULL**.

#### SHCNE_DELETE (0x00000004L)

A nonfolder item has been deleted. The *pidl1* parameter contains the item that was deleted. The *pidl2* parameter is not used and should be **NULL**.

#### SHCNE_DRIVEADD (0x00000100L)

A drive has been added. The *pidl1* parameter contains the root of the drive that was added. The *pidl2* parameter is not used and should be **NULL**.

#### SHCNE_DRIVEADDGUI (0x00010000L)

**Windows XP and later**: Not used.

#### SHCNE_DRIVEREMOVED (0x00000080L)

A drive has been removed. The *pidl1* parameter contains the root of the drive that was removed. The *pidl2* parameter is not used and should be **NULL**.

#### SHCNE_FREESPACE (0x00040000L)

The amount of free space on a drive has changed. The *pidl1* parameter contains the root of the drive on which the free space changed. The *pidl2* parameter is not used and should be **NULL**.

#### SHCNE_MEDIAINSERTED (0x00000020L)

Storage media has been inserted into a drive. The *pidl1* parameter contains the root of the drive that contains the new media. The *pidl2* parameter is not used and should be **NULL**.

#### SHCNE_MEDIAREMOVED (0x00000040L)

Storage media has been removed from a drive. The *pidl1* parameter contains the root of the drive from which the media was removed. The *pidl2* parameter is not used and should be **NULL**.

#### SHCNE_MKDIR (0x00000008L)

A folder has been created. The *pidl1* parameter contains the folder that was created. The *pidl2* parameter is not used and should be **NULL**.

#### SHCNE_NETSHARE (0x00000200L)

A folder on the local computer is being shared through the network. The *pidl1* parameter contains the folder that is being shared. The *pidl2* parameter is not used and should be **NULL**.

#### SHCNE_NETUNSHARE (0x00000400L)

A folder on the local computer is no longer being shared through the network. The *pidl1* parameter contains the folder that is no longer being shared. The *pidl2* parameter is not used and should be **NULL**.

#### SHCNE_RENAMEFOLDER (0x00020000L)

The name of a folder has changed. The *pidl1* parameter contains the previous PIDL or name of the folder. The *pidl2* parameter contains the new PIDL or name of the folder.

#### SHCNE_RENAMEITEM (0x00000001L)

The name of a nonfolder item has changed. The *pidl1* parameter contains the previous PIDL or name of the item. The *pidl2* parameter contains the new PIDL or name of the item.

#### SHCNE_RMDIR (0x00000010L)

A folder has been removed. The *pidl1* parameter contains the folder that was removed. The *pidl2* parameter is not used and should be **NULL**.

#### SHCNE_SERVERDISCONNECT (0x00004000L)

The computer has disconnected from a server. The *pidl1* parameter contains the server from which the computer was disconnected. The *pidl2* parameter is not used and should be **NULL**.

#### SHCNE_UPDATEDIR (0x00001000L)

The contents of an existing folder have changed, but the folder still exists and has not been renamed. The *pidl1* parameter contains the folder that has changed. The *pidl2* parameter is not used and should be **NULL**. If a folder has been created, deleted, or renamed, use **SHCNE_MKDIR**, **SHCNE_RMDIR**, or **SHCNE_RENAMEFOLDER**, respectively, instead.

#### SHCNE_UPDATEIMAGE (0x00008000L)

An image in the system image list has changed. The *pidl2* parameter contains the index in the system image list that has changed.

#### SHCNE_UPDATEITEM (0x00002000L)

An existing item (a folder or a nonfolder) has changed, but the item still exists and has not been renamed. The *pidl1* parameter contains the item that has changed. The *pidl2* parameter is not used and should be **NULL**. If a nonfolder item has been created, deleted, or renamed, use **SHCNE_CREATE**, **SHCNE_DELETE**, or **SHCNE_RENAMEITEM**, respectively, instead.

The following values specify combinations of other events.

#### SHCNE_DISKEVENTS (0x0002381FL)

Specifies a combination of all of the disk event identifiers.

#### SHCNE_GLOBALEVENTS (0x0C0581E0L)

Specifies a combination of all of the global event identifiers.

The following value modifies other event values and cannot be used alone.

#### SHCNE_INTERRUPT (0x80000000L)

The specified event occurred as a result of a system interrupt.

### `pidl1` [in, optional]

Type: **PCIDLIST_ABSOLUTE**

The first event-dependent item identifier.

### `pidl2` [in, optional]

Type: **PCIDLIST_ABSOLUTE**

The second event-dependent item identifier.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is similar in function and usage to [SHChangeNotify](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shchangenotify).