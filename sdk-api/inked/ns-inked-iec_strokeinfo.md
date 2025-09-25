# IEC_STROKEINFO structure

## Description

Contains information about a [Stroke](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-stroke) event.

## Members

### `nmhdr`

Specifies the NMHDR structure that contains standard information about the WM_NOTIFY message. The NMHDR structure contains the handle and identifier of the control that is sending the message and the notification code, which in this case is [IECN_STROKE](https://learn.microsoft.com/windows/desktop/tablet/inkedit-messages--win32-only-). The format of the NMHDR structure is:

```cpp
typedef struct tagNMHDR {
      HWND hwndFrom;
      UINT idFrom;
      UINT code;
  } NMHDR;
```

### `Cursor`

The [IInkCursor](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkcursor) object that was used to create the [IInkStrokeDisp](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp) object.

### `Stroke`

The [IInkStrokeDisp](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp) object that was created.

## See also

[IInkStrokeDisp Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp)

[InkEdit](https://learn.microsoft.com/windows/desktop/tablet/inkedit-control-reference)

[Stroke Event [InkEdit Control]](https://learn.microsoft.com/windows/desktop/tablet/inkedit-stroke)

[Using the COM Library](https://learn.microsoft.com/windows/desktop/tablet/using-the-com-library)