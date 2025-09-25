# AutoSelectionMode enumeration

## Description

Defines the types of logic that is used to determine whether a particular update will be automatically selected when the user views available updates in the Windows Update user interface.

## Constants

### `asLetWindowsUpdateDecide:0`

Use the standard logic. The update will be automatically selected if it is important, or if it is recommended and Windows Update has been configured to treat recommended updates as important. Otherwise, the update will not be automatically selected.

### `asAutoSelectIfDownloaded:1`

The update will be automatically selected only if it has been completely downloaded.

### `asNeverAutoSelect:2`

The update will never be automatically selected.

### `asAlwaysAutoSelect:3`

The update will always be automatically selected.

## Remarks

In versions of the Windows Update Agent (WUA) in which [IUpdate5](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdate5) is not available, all updates are processed by using the standard logic.