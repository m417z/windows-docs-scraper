# IQueryForm::Initialize

## Description

The **IQueryForm::Initialize** method initializes the query form extension object.

## Parameters

### `hkForm` [in]

Contains a registry key that identifies where the query form object was obtained. This parameter may be **NULL**.

## Return value

This method returns **S_OK** to enable the form object within the query dialog, or a failure code, such as **E_FAIL**, to prevent the form from being added to the query dialog.

## See also

[IQueryForm](https://learn.microsoft.com/windows/desktop/api/cmnquery/nn-cmnquery-iqueryform)