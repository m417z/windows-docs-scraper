# OleIsCurrentClipboard function

## Description

Determines whether the data object pointer previously placed on the clipboard by the [OleSetClipboard](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olesetclipboard) function is still on the clipboard.

## Parameters

### `pDataObj` [in]

Pointer to the [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) interface on the data object containing clipboard data of interest, which the caller previously placed on the clipboard.

## Return value

This function returns S_OK on success. Other possible values include the following.

| Return code | Description |
| --- | --- |
| **S_FALSE** | The specified pointer is not on the clipboard. |

## Remarks

**OleIsCurrentClipboard** only works for the data object used in the [OleSetClipboard](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olesetclipboard) function. It cannot be called by the consumer of the data object to determine if the object that was on the clipboard at the previous [OleGetClipboard](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olegetclipboard) call is still on the clipboard.

## See also

[OleFlushClipboard](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleflushclipboard)

[OleSetClipboard](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olesetclipboard)