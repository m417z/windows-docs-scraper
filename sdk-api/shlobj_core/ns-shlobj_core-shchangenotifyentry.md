# SHChangeNotifyEntry structure

## Description

Contains and receives information for change notifications. This structure is used with the [SHChangeNotifyRegister](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shchangenotifyregister) function and the [SFVM_QUERYFSNOTIFY](https://learn.microsoft.com/windows/desktop/shell/sfvm-queryfsnotify) notification.

## Members

### `pidl`

Type: **PCIDLIST_ABSOLUTE**

PIDL for which to receive notifications.

### `fRecursive`

Type: **BOOL**

A flag indicating whether to post notifications for children of this PIDL. For example, if the PIDL points to a folder, then file notifications would come from the folder's children if this flag was **TRUE**.