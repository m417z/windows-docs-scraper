# IEC_RECOGNITIONRESULTINFO structure

## Description

Contains information about an [IInkRecognitionResult Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkrecognitionresult) object.

## Members

### `nmhdr`

 The NMHDR structure that contains standard information about the WM_NOTIFY message. The NMHDR structure contains the handle and identifier of the control that is sending the message and the notification code, which in this case is [IECN_RECOGNITIONRESULT](https://learn.microsoft.com/windows/desktop/tablet/inkedit-messages--win32-only-). The format of the NMHDR structure is:

```cpp
typedef struct tagNMHDR {
      HWND hwndFrom;
      UINT idFrom;
      UINT code;
  } NMHDR;
```

### `RecognitionResult`

The [IInkRecognitionResult](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkrecognitionresult) object that contains recognition results.

## See also

[IInkRecognitionResult Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkrecognitionresult)

[InkEdit](https://learn.microsoft.com/windows/desktop/tablet/inkedit-control-reference)

[RecognitionResult Event](https://learn.microsoft.com/windows/desktop/tablet/inkedit-recognitionresult)

[Using the COM Library](https://learn.microsoft.com/windows/desktop/tablet/using-the-com-library)