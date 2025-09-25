# INamespaceWalkCB::InitializeProgressDialog

## Description

Initializes the window title and cancel button text of the progress dialog box displayed during the namespace walk.

## Parameters

### `ppszTitle` [out]

Type: **LPWSTR***

When this method returns, contains a pointer to a null-terminated string that contains the title to be used for the dialog box.

### `ppszCancel` [out]

Type: **LPWSTR***

When this method returns, contains a pointer to a null-terminated string that contains the text displayed on the button that cancels the namespace walk.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.