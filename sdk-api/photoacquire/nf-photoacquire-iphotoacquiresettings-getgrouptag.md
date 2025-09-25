# IPhotoAcquireSettings::GetGroupTag

## Description

The `GetGroupTag` method retrieves a tag string for the group of files being downloaded from the device.

## Parameters

### `pbstrGroupTag` [out]

Pointer to a string containing the group tag.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The group tag is stored as a keyword in each file's metadata. It is also used in the file name if the `$(GroupTag)` token is present in the format string passed to [SetOutputFileNameTemplate](https://learn.microsoft.com/windows/desktop/api/photoacquire/nf-photoacquire-iphotoacquiresettings-getoutputfilenametemplate).

## See also

[IPhotoAcquireSettings Interface](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoacquiresettings)

[SetGroupTag](https://learn.microsoft.com/windows/desktop/api/photoacquire/nf-photoacquire-iphotoacquiresettings-setgrouptag)