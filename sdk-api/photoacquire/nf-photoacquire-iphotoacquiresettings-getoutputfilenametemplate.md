# IPhotoAcquireSettings::GetOutputFilenameTemplate

## Description

The `GetOutputFilenameTemplate` method retrieves a format string (template) that specifies the format of file names.

## Parameters

### `pbstrTemplate` [out]

Pointer to a string containing the format string.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

Format strings contain a mix of path literals and tokens. A format string looks like the following:

``` syntax

$(MyPicturesFolder)\$(DateAcquired), $(EventName)\$(EventName) $(SequenceNumber).$(OriginalExtension)

```

## See also

[IPhotoAcquireSettings Interface](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoacquiresettings)

[SetOutputFilenameTemplate](https://learn.microsoft.com/windows/desktop/api/photoacquire/nf-photoacquire-iphotoacquiresettings-setoutputfilenametemplate)