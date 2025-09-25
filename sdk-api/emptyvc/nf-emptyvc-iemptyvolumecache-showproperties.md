# IEmptyVolumeCache::ShowProperties

## Description

Notifies the handler to display its UI.

## Parameters

### `hwnd` [in]

Type: **HWND**

The parent window to be used when displaying the UI.

## Return value

Type: **HRESULT**

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The user changed one or more settings. |
| **S_FALSE** | No settings were changed. |

## Remarks

A handler can display a UI, which is typically used to allow the user to select which files are to be cleaned up and how. To do so, the handler sets the **EVCF_HASSETTINGS** flag in the *pdwFlags* parameter when [Initialize](https://learn.microsoft.com/windows/desktop/api/emptyvc/nf-emptyvc-iemptyvolumecache-initialize) is called. The disk cleanup manager will then display a **Settings** button. When that button is clicked, the disk cleanup manager calls **ShowProperties** to notify the handler to display its UI.