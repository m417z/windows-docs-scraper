# IExplorerPaneVisibility::GetPaneState

## Description

Gets the visibility state of the given Windows Explorer pane.

## Parameters

### `ep` [in]

Type: **REFEXPLORERPANE**

A reference to a GUID that uniquely identifies a Windows Explorer pane. One of the following constants as defined in Shlguid.h.

#### EP_NavPane (cb316b22-25f7-42b8-8a09-540d23a43c2f)

The pane on the left side of the Windows Explorer window that hosts the folders tree and **Favorites**.

#### EP_Commands (d9745868-ca5f-4a76-91cd-f5a129fbb076)

**Commands** module along the top of the Windows Explorer window.

#### EP_Commands_Organize (72e81700-e3ec-4660-bf24-3c3b7b648806)

**Organize** menu within the commands module.

#### EP_Commands_View (21f7c32d-eeaa-439b-bb51-37b96fd6a943)

**View** menu within the commands module.

#### EP_DetailsPane (43abf98b-89b8-472d-b9ce-e69b8229f019)

Pane showing metadata along the bottom of the Windows Explorer window.

#### EP_PreviewPane (893c63d1-45c8-4d17-be19-223be71be365)

Pane on the right of the Windows Explorer window that shows a large reading preview of the file.

#### EP_QueryPane (65bcde4f-4f07-4f27-83a7-1afca4df7ddd)

Quick filter buttons to aid in a search.

#### EP_AdvQueryPane (b4e9db8b-34ba-4c39-b5cc-16a1bd2c411c)

Additional fields and options to aid in a search.

#### EP_StatusBar (65fe56ce-5cfe-4bc4-ad8a-7ae3fe7e8f7c)

**Introduced in Windows 8**: A status bar that indicates the progress of some process, such as copying or downloading.

#### EP_Ribbon (d27524a8-c9f2-4834-a106-df8889fd4f37)

**Introduced in Windows 8**: The ribbon, which is the control that replaced menus and toolbars at the top of many Microsoft applications.

### `peps` [out]

Type: **[EXPLORERPANESTATE](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_explorerpanestate)***

When this method returns, contains the visibility state of the given Windows Explorer pane as one of the [EXPLORERPANESTATE](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_explorerpanestate) constants.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If the implementer does not care about the state of a given pane and therefore does not want to change it, then the implementer should return a success code for the method and EPS_DONTCARE for the *peps* parameter. If the method fails, it is treated as if EPS_DONTCARE was returned for the *peps* parameter.