# IPhotoAcquireSettings::SetSequenceZeroPadding

## Description

The `SetSequenceZeroPadding` method sets a value indicating whether zeros or spaces are used to pad sequential file names.

## Parameters

### `fZeroPad` [in]

Flag that, if set to **TRUE**, indicates that zeros pad sequential file names.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

A file name padded with zeros might appear as

``` syntax
"IMG0001.JPG"
```

The same file name without zero padding might appear as

``` syntax
"IMG   1.JPG"
```

## See also

[GetSequenceZeroPadding](https://learn.microsoft.com/windows/desktop/api/photoacquire/nf-photoacquire-iphotoacquiresettings-getsequencezeropadding)

[IPhotoAcquireSettings Interface](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoacquiresettings)

[SetSequencePaddingWidth](https://learn.microsoft.com/windows/desktop/api/photoacquire/nf-photoacquire-iphotoacquiresettings-setsequencepaddingwidth)