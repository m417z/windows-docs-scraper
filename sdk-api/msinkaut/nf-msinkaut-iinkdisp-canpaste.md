# IInkDisp::CanPaste

## Description

Indicates whether the [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) can be converted to an [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object.

## Parameters

### `DataObject` [in, optional]

Optional. Specifies the [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) to inspect. The default value is **NULL**, which means the data object on the Clipboard is used.

### `CanPaste` [out, retval]

**VARIANT_TRUE** if the data object can be converted to an [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object; otherwise, **VARIANT_FALSE**.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |

## Remarks

If the supplied [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) is **NULL**, then the data object on the Clipboard is used.

## See also

[IInkDisp](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkdisp)

[InkDisp Class](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class)