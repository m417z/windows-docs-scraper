# IActiveDesktop::AddDesktopItemWithUI

## Description

Adds a desktop item to the Active Desktop after displaying user interfaces that confirm the addition of the desktop item, verifying security zone permissions, and asking if the user wants to create a subscription.

## Parameters

### `hwnd` [in, optional]

Type: **HWND**

The handle of the parent window. If **NULL**, the desktop item is added without displaying any user interface, in accordance with the corresponding security zone permissions. For more information, see [About URL Security Zones](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/ms537183(v=vs.85)).

### `pcomp` [in]

Type: **LPCOMPONENT**

Address of the [COMPONENT](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-component) structure containing the details of the desktop item to be added.

### `dwReserved`

Type: **DWORD**

Unsigned long integer value that contains the flags that control how the desktop item is added. Can be one of the following values.

#### DTI_ADDUI_DEFAULT

Do default action. Identical to using zero.

#### DTI_ADDUI_DISPSUBWIZARD

Activate the subscription wizard to allow the user to subscribe to this desktop item.

#### DTI_ADDUI_POSITIONITEM

Instruct the system to look at the [COMPPOS](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-comppos) structure passed to the **cpPos** member of the [COMPONENT](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-component) structure to ensure that the values are within reasonable limits. This value was added for Internet Explorer 5.

## Return value

Type: **HRESULT**

Returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_FAIL** | Failed to add the desktop item, or an instance of the desktop item already exists on the Active Desktop. |
| **E_INVAILDARG** | One or more of the parameters were invalid. |
| **S_OK** | If the **ADDURL_SILENT** flag has been set, the desktop item has either been added successfully or it already exists on the Active Desktop. Otherwise, the desktop item has been added successfully. |

## Remarks

This method creates a second instance of the [Active Desktop](https://learn.microsoft.com/windows/desktop/lwef/active-desktop-interface) to add the desktop item, so the desktop item does not appear in the current instance. The application must call the [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method on this [IActiveDesktop](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-iactivedesktop) interface and then use the [CoCreateInstance](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cocreateinstance) function to retrieve the Active Desktop object with the newly added component.

## See also

[IActiveDesktop](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-iactivedesktop)

[Using the Active Desktop Object](https://learn.microsoft.com/windows/desktop/lwef/active-desktop-interface)