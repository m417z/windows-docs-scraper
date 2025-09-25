# IEmptyVolumeCache::Initialize

## Description

Initializes the disk cleanup handler, based on the information stored under the specified registry key.

## Parameters

### `hkRegKey` [in]

Type: **HKEY**

A handle to the registry key that holds the information about the handler object.

### `pcwszVolume` [in]

Type: **LPCWSTR**

A pointer to a null-terminated Unicode string with the volume root—for example, "C:\".

### `ppwszDisplayName` [out]

Type: **LPWSTR***

A pointer to a null-terminated Unicode string with the name that will be displayed in the disk cleanup manager's list of handlers. If no value is assigned, the registry value will be used.

### `ppwszDescription` [out]

Type: **LPWSTR***

A pointer to a null-terminated Unicode string that will be displayed when this object is selected from the disk cleanup manager's list of available disk cleanup handlers. If no value is assigned, the registry value will be used.

### `pdwFlags` [in, out]

Type: **DWORD***

The flags that are used to pass information to the handler and back to the disk cleanup manager.

#### These flags can be passed in to the object:

#### EVCF_OUTOFDISKSPACE

If this flag is set, the user is out of disk space on the drive. When this flag is received, the handler should be aggressive about freeing disk space, even if it results in a performance loss. The handler, however, should not delete files that would cause an application to fail, or the user to lose data.

#### EVCF_SETTINGSMODE

If the disk cleanup manager is being run on a schedule, it will set this flag. You must assign values to the *ppwszDisplayName* and *ppwszDescription* parameters. If this flag is set, the disk cleanup manager will not call [IEmptyVolumeCache::GetSpaceUsed](https://learn.microsoft.com/windows/desktop/api/emptyvc/nf-emptyvc-iemptyvolumecache-getspaceused), [IEmptyVolumeCache::Purge](https://learn.microsoft.com/windows/desktop/api/emptyvc/nf-emptyvc-iemptyvolumecache-purge), or [IEmptyVolumeCache::ShowProperties](https://learn.microsoft.com/windows/desktop/api/emptyvc/nf-emptyvc-iemptyvolumecache-showproperties). Because **IEmptyVolumeCache::Purge** will not be called, cleanup must be handled by **IEmptyVolumeCache::Initialize**. The handler should ignore the *pcwszVolume* parameter and clean up any unneeded files regardless of what drive they are on. Because there is no opportunity for user feedback, only those files that are extremely safe to clean up should be touched.

#### These flags can be passed by the handler back to the disk cleanup manager:

#### EVCF_DONTSHOWIFZERO

Set this flag when there are no files to delete. When [IEmptyVolumeCache::GetSpaceUsed](https://learn.microsoft.com/windows/desktop/api/emptyvc/nf-emptyvc-iemptyvolumecache-getspaceused) is called, set the *pdwSpaceUsed* parameter to zero, and the disk cleanup manager will omit the handler from its list.

#### EVCF_ENABLEBYDEFAULT

Set this flag to have the handler checked by default in the cleanup manager's list. It will run every time the Disk Cleanup utility runs, unless the user clears the handler's check box. Once the check box has been cleared, the handler will not be run until the user selects it again.

#### EVCF_ENABLEBYDEFAULT_AUTO

Set this flag to have the handler run automatically during scheduled cleanup. This flag should only be set when deletion of the files is low-risk. As with **EVCF_ENABLEBYDEFAULT**, the user can choose not to run the handler by clearing its check box in the disk cleanup manager's list.

#### EVCF_HASSETTINGS

Set this flag to indicate that the handler can display a UI. An example of a simple UI is a list box that displays the deletable files and allows the user to select which ones to delete. The disk cleanup manager will then display a button below the cleanup handler's description. The user clicks this button to request the UI. The default button text is "Settings", but the handler can specify a different text by setting the AdvancedButtonText value in its registry key.

#### EVCF_REMOVEFROMLIST

Set this flag to remove the handler from the disk cleanup manager's list. All registry information will be deleted, and the handler cannot be run again until the key and its values are restored. This flag is used primarily for one-time cleanup operations.

## Return value

Type: **HRESULT**

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **S_FALSE** | There are no files to delete. |
| **E_ABORT** | The cleanup operation was ended prematurely. |
| **E_FAIL** | The cleanup operation failed. |

## Remarks

This method is used by the Windows 98 disk cleanup manager. Windows 2000 uses the [InitializeEx](https://learn.microsoft.com/windows/desktop/api/emptyvc/nf-emptyvc-iemptyvolumecache2-initializeex) method exported by [IEmptyVolumeCache2](https://learn.microsoft.com/windows/desktop/api/emptyvc/nn-emptyvc-iemptyvolumecache2).

Use [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc) to allocate memory for the strings returned through *ppwszDisplayName* and *ppwszDescription*. The disk cleanup manager will free the memory when it is no longer needed.