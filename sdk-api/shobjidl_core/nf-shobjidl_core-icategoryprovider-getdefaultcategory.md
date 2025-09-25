# ICategoryProvider::GetDefaultCategory

## Description

Enables the folder to override the default grouping.

## Parameters

### `pguid` [out]

Type: **GUID***

Not used.

### `pscid` [out]

Type: **[SHCOLUMNID](https://learn.microsoft.com/windows/desktop/shell/objects)***

When this method returns, contains a pointer to a [SHCOLUMNID](https://learn.microsoft.com/windows/desktop/shell/objects) structure.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or an error value otherwise, including the following:

| Return code | Description |
| --- | --- |
| **S_FALSE** | There is no default group. |

## Remarks

**ICategoryProvider::GetDefaultCategory** returns an [SHCOLUMNID](https://learn.microsoft.com/windows/desktop/shell/objects) structure that is used by the default categorizer. The method returns S_FALSE if a default group is not supported.

**ICategoryProvider::GetDefaultCategory** is called only when a folder is first opened. After that, the user's grouping choice is cached in the [property bag](https://learn.microsoft.com/windows/win32/api/oaidl/nn-oaidl-ipropertybag) storing the state of the view. To force a call to **ICategoryProvider::GetDefaultCategory** after the folder is first opened, the **Shell** and **ShellNoRoam** registry keys must be deleted. They are found in the following location.

```
HKEY_CURRENT_USER
   Software
      Microsoft
         Windows
            Shell
            ShellNoRoam
```