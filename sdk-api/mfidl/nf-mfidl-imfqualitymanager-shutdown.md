# IMFQualityManager::Shutdown

## Description

Called when the Media Session is shutting down.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The quality manager should release all references to the Media Session when this method is called.

## See also

[IMFQualityManager](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfqualitymanager)