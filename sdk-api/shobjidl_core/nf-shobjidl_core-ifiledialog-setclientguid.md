# IFileDialog::SetClientGuid

## Description

Enables a calling application to associate a GUID with a dialog's persisted state.

## Parameters

### `guid` [in]

Type: **REFGUID**

The GUID to associate with this dialog state.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

A dialog's state can include factors such as the last visited folder and the position and size of the dialog.

Typically, this state is persisted based on the name of the executable file. By specifying a GUID, an application can have different persisted states for different versions of the dialog within the same application (for example, an import dialog and an open dialog).

**IFileDialog::SetClientGuid** should be called immediately after creation of the dialog object.