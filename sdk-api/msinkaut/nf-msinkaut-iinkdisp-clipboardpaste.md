# IInkDisp::ClipboardPaste

## Description

Copies the [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) from the Clipboard to the [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object.

## Parameters

### `x` [in, optional]

Optional. Specifies the x-coordinate to paste to in **ink space** coordinates. The default value is 0.

### `y` [in, optional]

Optional. Specifies the y-coordinate to paste to in ink space coordinates. The default value is 0.

### `DataObject` [in, optional]

Optional. Specifies the [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) to be used. To paste from the Clipboard, set to **NULL**. The default value is **NULL**.

### `Strokes` [out, retval]

When this method returns, contains a pointer to the [InkStrokes](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85)) collection in the [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |

## Remarks

An error is returned if an unexpected error occurs while accessing the [Clipboard](https://learn.microsoft.com/windows/desktop/dataxchg/clipboard). If no error occurs but the Clipboard does not contain a format that can be pasted into **ink** -either **ink serialized format (ISF)** or a **text ink object (tInk)** -then **NULL** is returned and no exception is thrown.

## See also

[IInkDisp](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkdisp)

[InkDisp Class](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class)

[InkStrokes Collection](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85))