# IPhotoProgressDialog::SetPercentComplete

## Description

The `SetPercentComplete` method sets a value indicating the completed portion of the current operation.

## Parameters

### `nPercent` [in]

Integer value indicating the percentage of the operation that has completed. This value may be between 0 and 100 only.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

If you pass PROGRESS_INDETERMINATE to `SetPercentComplete`, the progress bar will not progress from left to right (from 0 to 100%), but will instead animate to indicate that an operation with an indeterminate end is taking place.

## See also

[IPhotoProgressDialog Interface](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoprogressdialog)