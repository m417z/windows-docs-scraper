# IOleObject::SetColorScheme

## Description

Specifies the color palette that the object application should use when it edits the specified object.

## Parameters

### `pLogpal` [in]

Pointer to a [LOGPALETTE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logpalette) structure that specifies the recommended palette.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_NOTIMPL** | Object does not support setting palettes. |
| **OLE_E_PALETTE** | Invalid LOGPALETTE structure pointed to by *pLogPal*. |
| **OLE_E_NOTRUNNING** | Object must be running to perform this operation. |

## Remarks

The **IOleObject::SetColorScheme** method sends the container application's recommended color palette to the object application, which is not obliged to use it.

## See also

[IOleObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleobject)