# FVSHOWINFO structure

## Description

Contains information that the file viewer uses to display a file.

## Members

### `cbSize`

Type: **DWORD**

The size of the structure, in bytes.

### `hwndOwner`

Type: **HWND**

A window handle to the owner of the window where the file will be displayed.

### `iShow`

Type: **int**

The show command for the window. This parameter is one of the **SW_** values detailed in [ShowWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-showwindow).

### `dwFlags`

Type: **DWORD**

Flags that determine what the file viewer displays. This member can be one or more of the following values.

#### FVSIF_CANVIEWIT

The file viewer can display the file.

#### FVSIF_NEWFAILED

The file viewer specified a new file to display, but no viewer could display the file. The file viewer should either continue to display the previous file or terminate.

#### FVSIF_NEWFILE

A drag-and-drop operation has dropped a file on the file viewer window. The file viewer passes the name of the file to the Shell by copying the name to the **strNewFile** member. The Shell attempts to load a file viewer that can display the new file.

#### FVSIF_PINNED

A pinned window exists. A file viewer should either use the pinned window to display the file or set a new pinned window and display the file in it.

#### FVSIF_RECT

The **rect** member contains valid data.

### `rect`

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)**

The [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that specifies the size and position of the file viewer's window. This member is valid only if the **dwFlags** member includes the **FVSIF_RECT** value.

### `punkRel`

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

The address of an interface that has its [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method called by a new file viewer to release the previous file viewer. This member is used when a drag-and-drop operation drops a file on the file viewer's window.

### `strNewFile`

Type: **OLECHAR[MAX_PATH]**

The address of a string that specifies the name of a new file to display. A file viewer sets this member when a drag-and-drop operation drops a file on the file viewer's window.