# MFCreateSystemTimeSource function

## Description

Creates a presentation time source that is based on the system time.

## Parameters

### `ppSystemTimeSource`

Receives a pointer to the object's [IMFPresentationTimeSource](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfpresentationtimesource) interface. The caller must release the interface.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The function succeeded. |

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)