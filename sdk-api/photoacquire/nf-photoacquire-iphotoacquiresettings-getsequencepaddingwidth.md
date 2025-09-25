# IPhotoAcquireSettings::GetSequencePaddingWidth

## Description

The `GetSequencePaddingWidth` method retrieves a value indicating how wide sequential fields in file names will be.

## Parameters

### `pdwWidth` [out]

Pointer to a double word value containing the width of sequential fields.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | A non-NULL value was expected. |

## Remarks

If the format string specified in [SetOutputFileNameTemplate](https://learn.microsoft.com/windows/desktop/api/photoacquire/nf-photoacquire-iphotoacquiresettings-setoutputfilenametemplate) contains a sequential token, this method gets the width allotted for the sequential token.

If the format string does not contain a sequential token, the value returned by this method is not defined.

## See also

[IPhotoAcquireSettings Interface](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoacquiresettings)

[SetSequencePaddingWidth](https://learn.microsoft.com/windows/desktop/api/photoacquire/nf-photoacquire-iphotoacquiresettings-setsequencepaddingwidth)