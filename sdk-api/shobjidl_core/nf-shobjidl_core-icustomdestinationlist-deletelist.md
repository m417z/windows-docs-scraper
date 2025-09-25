# ICustomDestinationList::DeleteList

## Description

Deletes a custom Jump List for a specified application.

## Parameters

### `pszAppID` [in]

Type: **LPCWSTR**

A pointer to the AppUserModelID of the process whose taskbar button representation displays the custom Jump List. In the beta release of Windows 7, this AppUserModelID must be explicitly provided because this method is intended to be called from an uninstaller, which runs in a separate process. Because it is in a separate process, the system cannot reliably deduce the AppUserModelID. This restriction is expected to be removed in later releases.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

There are several instances where this method should be called, including:

* When the application is uninstalled.
* When the user clears history from within the application.
* When the user disables destination tracking in the application's Settings or Options pages.

This method should not be called when an application is updating a custom destination list. It is used only to completely clear the list during an uninstall operation, or if the application provides an option for the user to turn off the list.

After the custom Jump List has been removed, a standard Jump List generated from system-generated data for recently used items is shown. If no such data has been collected or if the information has been cleared through [RemoveAllDestinations](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iapplicationdestinations-removealldestinations), the Jump List might contain only its minimum, always present content: standard tasks to pin or unpin, launch a new instance of the application, or close windows.

## See also

[Application User Model IDs (AppUserModelIDs)](https://learn.microsoft.com/windows/desktop/shell/appids)

[ICustomDestinationList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-icustomdestinationlist)

[ICustomDestinationList::SetAppID](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-icustomdestinationlist-setappid)

[Taskbar Extensions](https://learn.microsoft.com/windows/desktop/shell/taskbar-extensions)