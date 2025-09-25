# IFsrmFileScreen::ApplyTemplate

## Description

[This method is supported for compatibility but it's recommended to use the
[FSRM WMI Classes](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-wmi-classes) to manage FSRM. Please see the
[MSFT_FSRMFileScreen](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmfilescreen) class.]

Applies the property values of the specified file screen template to this file screen
object.

## Parameters

### `fileScreenTemplateName` [in]

The name of the file screen template. The string is limited to 4,000 characters.

## Return value

The method returns the following return values.

## Remarks

To save the changes, call the
[IFsrmFileScreen::Commit](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nf-fsrm-ifsrmobject-commit) method.

The specified template must be a committed template; you cannot apply a newly created template that has not
been committed.

#### Examples

For an example, see
[Defining a File Screen](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/defining-a-file-screen).

## See also

[IFsrmFileScreen](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmscreen/nn-fsrmscreen-ifsrmfilescreen)

[MSFT_FSRMFileScreen](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmfilescreen)