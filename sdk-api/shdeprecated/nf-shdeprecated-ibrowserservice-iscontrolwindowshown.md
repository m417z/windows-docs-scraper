# IBrowserService::IsControlWindowShown

## Description

Deprecated. Retrieves a value that indicates whether a specified frame control is currently visible.

## Parameters

### `id` [in]

Type: **UINT**

The frame control to check.

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

### `pfShown` [out]

Type: **BOOL***

A value of type **BOOL** that indicates whether the specified frame control is visible.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.