# IWABObject::Import

## Description

Imports a .wab file into the user's Address Book.

## Parameters

### `lpWIP`

Type: **LPSTR**

Pointer to a [WABIMPORTPARAM](https://learn.microsoft.com/windows/desktop/api/wabapi/ns-wabapi-wabimportparam)
structure.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or an error value otherwise.

## Remarks

When calling this method, pass a pointer to a
[WABIMPORTPARAM](https://learn.microsoft.com/windows/desktop/api/wabapi/ns-wabapi-wabimportparam) structure. If the caller specifies
**MAPI_DIALOG** in the
**ulFlags** member of the structure,
the Windows Address Book (WAB) shows a dialog box with a progress bar indicating
the progress of the import process. The caller can specify a file name
to import. If the caller specifies a **NULL** file name, the
WAB opens a [GetOpenFileName](https://learn.microsoft.com/windows/desktop/api/commdlg/nf-commdlg-getopenfilenamea)
dialog box to prompt the user to select a .wab file for importing.

For compatibility with previously released versions of the
WAB that expose this method, the pointer to the
[WABIMPORTPARAM](https://learn.microsoft.com/windows/desktop/api/wabapi/ns-wabapi-wabimportparam) structure needs to be cast to an
**LPSTR** prior to passing it into this method.