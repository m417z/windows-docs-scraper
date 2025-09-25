# IFileDialog::ClearClientData

## Description

Instructs the dialog to clear all persisted state information.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Persisted information can be associated with an application or a GUID. If a GUID was set by using [IFileDialog::SetClientGuid](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifiledialog-setclientguid), that GUID is used to clear persisted information.