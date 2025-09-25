# IFsrmFileScreenTemplate::put_Name

## Description

[This property is supported for compatibility but it's recommended to use the
[FSRM WMI Classes](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-wmi-classes) to manage FSRM. Please see the
[MSFT_FSRMFileScreenTemplate](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmfilescreentemplate) class.]

Retrieves and sets the name of the file screen template.

This property is read/write.

## Parameters

## Remarks

If a template with the specified name exists, the template fails with
**FSRM_E_ALREADY_EXISTS** when you call the
[IFsrmFileScreen::Commit](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nf-fsrm-ifsrmobject-commit) method.

#### Examples

For an example, see
[Using Templates to Define File Screens](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/using-templates-to-define-file-screens).

## See also

[IFsrmFileScreenTemplate](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmscreen/nn-fsrmscreen-ifsrmfilescreentemplate)

[MSFT_FSRMFileScreenTemplate](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmfilescreentemplate)