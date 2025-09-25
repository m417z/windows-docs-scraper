# IBrowserService::ShowControlWindow

## Description

Deprecated. Shows or hides various frame controls.

## Parameters

### `id` [in]

Type: **UINT**

A value that indicates the frame control to show or hide. One of the following values as defined in Shobjidl.h or -1 for fullscreen/kiosk mode.

**Note** These frame controls may not be supported in future versions of Windows.

#### FCW_STATUS (0x0001)

The browser's status bar.

#### FCW_TOOLBAR (0x0002)

The browser's toolbar.

#### FCW_TREE (0x0003)

The browser's tree view.

#### FCW_INTERNETBAR (0x0006)

The browser's Media Bar.

#### FCW_PROGRESS (0x0008)

The browser's progress bar.

### `fShow` [in]

Type: **BOOL**

A value that indicates whether to show or hide the frame control.

#### TRUE

Show the control.

#### FALSE

Hide the control.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.