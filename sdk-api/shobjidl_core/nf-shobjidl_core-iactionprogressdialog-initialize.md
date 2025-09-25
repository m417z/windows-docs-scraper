# IActionProgressDialog::Initialize

## Description

Provides details about the action progress dialog.

## Parameters

### `flags` [in]

Type: **SPINITF**

One of the following values.

#### SPINITF_NORMAL (0x01)

Use the default progress dialog behavior.

#### SPINITF_MODAL (0x01)

Use a modal window for the dialog.

#### SPINITF_NOMINIMIZE (0x08)

Do not display a minimize button.

### `pszTitle` [in]

Type: **LPCWSTR**

The title of the progress dialog.

### `pszCancel` [in]

Type: **LPCWSTR**

The string displayed when a user closes the dialog before completion.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.