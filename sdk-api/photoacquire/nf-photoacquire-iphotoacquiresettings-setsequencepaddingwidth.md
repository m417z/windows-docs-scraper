# IPhotoAcquireSettings::SetSequencePaddingWidth

## Description

The `SetSequencePaddingWidth` method sets a value indicating how wide sequential fields in filenames will be.

## Parameters

### `dwWidth` [in]

Double word value containing the width of sequential fields.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

If the value passed to `SetSequencePaddingWidth` is nonzero and the format string specified in [SetOutputFileNameTemplate](https://learn.microsoft.com/windows/desktop/api/photoacquire/nf-photoacquire-iphotoacquiresettings-setoutputfilenametemplate) contains a sequential token, this method sets the width allotted for the sequential token. For example, given the template `$(GroupTag)$(AcquisitionSequence).$(OriginalExtension)`, if padding is set to 0, a file name might appear as
``` syntax
"Image1.jpg"
```
If padding is set to 3, the file name may appear as
``` syntax
"Image   1.jpg"
```

## See also

[GetSequencePaddingWidth](https://learn.microsoft.com/windows/desktop/api/photoacquire/nf-photoacquire-iphotoacquiresettings-getsequencepaddingwidth)

[IPhotoAcquireSettings Interface](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoacquiresettings)

[SetSequenceZeroPadding](https://learn.microsoft.com/windows/desktop/api/photoacquire/nf-photoacquire-iphotoacquiresettings-setsequencezeropadding)