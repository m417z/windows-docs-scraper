# ID2D1PrintControl::Close

## Description

Passes all remaining resources to the print sub-system, then clean up and close the current print job.

## Return value

Type: **HRESULT**

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| HRESULT | Description |
| --- | --- |
| S_OK | No error occurred. |
| E_OUTOFMEMORY | Direct2D could not allocate sufficient memory to complete the call. |
| E_INVALIDARG | An invalid parameter was passed to the returning function. |
| D2DERR_PRINT_JOB_CLOSED | The print job is already finished. |

## See also

[ID2D1PrintControl](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1printcontrol)