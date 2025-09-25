# IPhotoAcquireSettings::GetSequenceZeroPadding

## Description

The `GetSequenceZeroPadding` method retrieves a value that indicates whether zeros or spaces will be used to pad sequential file names.

## Parameters

### `pfZeroPad` [out]

Pointer to a flag that, if set to **TRUE**, indicates that zeros will pad sequential file names.

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

[IPhotoAcquireSettings Interface](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoacquiresettings)

[SetSequenceZeroPadding](https://learn.microsoft.com/windows/desktop/api/photoacquire/nf-photoacquire-iphotoacquiresettings-setsequencezeropadding)