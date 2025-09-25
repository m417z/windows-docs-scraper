# IDiscRecorder::GetDisplayNames

## Description

Retrieves a formatted name for the recorder that can be displayed. The name consists of the manufacturer and product identifier of the device.

## Parameters

### `pbstrVendorID` [out]

Vendor of the disc recorder. This parameter can be **NULL**.

### `pbstrProductID` [out]

Product name of the disc recorder. This parameter can be **NULL**.

### `pbstrRevision` [out]

Revision of the disc recorder. This is typically the revision of the recorder firmware, but it can be a revision for the entire device. This parameter can be **NULL**.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

## Remarks

The display names are typically combined into a string that is displayed in recorder selection list boxes or other GUI components.

The combination of these three strings does not produce a unique identifier for this specific recorder. Combine these strings with the string returned from
[GetPath](https://learn.microsoft.com/windows/desktop/api/imapi/nf-imapi-idiscrecorder-getpath) to create a unique value.

## See also

[IDiscRecorder](https://learn.microsoft.com/windows/desktop/api/imapi/nn-imapi-idiscrecorder)