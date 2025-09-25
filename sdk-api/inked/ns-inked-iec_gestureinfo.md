# IEC_GESTUREINFO structure

## Description

Contains information about a specific gesture.

## Members

### `nmhdr`

The NMHDR structure that contains standard information about the WM_NOTIFY message. The NMHDR structure contains the handle and identifier of the control that is sending the message and the notification code, which in this case is [IECN_GESTURE](https://learn.microsoft.com/windows/desktop/tablet/inkedit-messages--win32-only-). The format of the NMHDR structure is:

```cpp
typedef struct tagNMHDR {
      HWND hwndFrom;
      UINT idFrom;
      UINT code;
  } NMHDR;
```

### `Cursor`

The [IInkCursor](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkcursor) object that was used to create the gesture.

### `Strokes`

The [InkStrokes](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85)) collection that makes up the gesture.

### `Gestures`

An array of [IInkGesture](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkgesture) objects, in order of confidence. For more information about this member, see the [Gesture](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-gesture) event.

For more information about the VARIANT structure, see [Using the COM Library](https://learn.microsoft.com/windows/desktop/tablet/using-the-com-library).

## See also

[Gesture Event [InkEdit Control]](https://learn.microsoft.com/windows/desktop/tablet/inkedit-gesture)

[IInkGesture Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkgesture)

[InkEdit](https://learn.microsoft.com/windows/desktop/tablet/inkedit-control-reference)

[Using the COM Library](https://learn.microsoft.com/windows/desktop/tablet/using-the-com-library)