# IFileIsInUse::GetCapabilities

## Description

Determines whether the file can be closed and whether the UI is capable of switching to the window of the application that is using the file.

## Parameters

### `pdwCapFlags` [out]

Type: **DWORD***

A pointer to a value that, when this method returns successfully, receives the capability flags. One or both of the following values:

#### OF_CAP_CANSWITCHTO (0x0001)

0x0001. The UI can switch to the top-level window of the application that is using the file.

#### OF_CAP_CANCLOSE (0x0002)

0x0002. The file can be closed.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The capabilities returned by this method can be used in the composition of the dialog box presented to the user that informs them of the sharing conflict. For instance, if the OF_CAP_CANSWITCHTO flag is retrieved, a button can be added to the dialog box that will switch the user to the conflicting application window (based on the **HWND** information retrieved by [IFileIsInUse::GetSwitchToHWND](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifileisinuse-getswitchtohwnd)) so that the user can address the situation as they see fit. If the OF_CAP_CANCLOSE flag is retrieved, the dialog box can present a **Close** button that calls the [CloseFile](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifileisinuse-closefile) method.