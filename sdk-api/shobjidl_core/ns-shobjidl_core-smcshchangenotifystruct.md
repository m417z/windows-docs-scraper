# SMCSHCHANGENOTIFYSTRUCT structure

## Description

Contains information about change notification. It is used by [IShellMenuCallback::CallbackSM](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellmenucallback-callbacksm).

## Members

### `lEvent`

Type: **long**

An SHCNE value that specifies the type of change that took place. See [SHChangeNotify](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shchangenotify) for a complete list of these values.

### `pidl1`

Type: **PCIDLIST_ABSOLUTE**

PIDL provided by the change notification. The target of this PIDL varies depending on the value of **lEvent**.

### `pidl2`

Type: **PCIDLIST_ABSOLUTE**

A second PIDL provided by the change notification. Not all **lEvent** values make use of this parameter, in which case its value is **NULL**.