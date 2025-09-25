# IOleUIObjInfoA::ConvertObject

## Description

Converts the object to the type of the specified CLSID.

## Parameters

### `dwObject` [in]

A unique identifier for the object.

### `clsidNew` [in]

The CLSID.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | Insufficient access permissions. |
| **E_FAIL** | The operation failed. |
| **E_INVALIDARG** | The specified identifier is not valid. |
| **E_OUTOFMEMORY** | There is insufficient memory available for this operation. |

## Remarks

### Notes to Implementers

Your implementation of **IOleUIObjInfo::ConvertObject** needs to convert the object to the CLSID specified. The actions taken by the convert operation are similar to the actions taken after calling [OleUIConvert](https://learn.microsoft.com/windows/desktop/api/oledlg/nf-oledlg-oleuiconverta).

## See also

[IOleUIObjInfo](https://learn.microsoft.com/windows/desktop/api/oledlg/nn-oledlg-ioleuiobjinfoa)

[OleUIConvert](https://learn.microsoft.com/windows/desktop/api/oledlg/nf-oledlg-oleuiconverta)