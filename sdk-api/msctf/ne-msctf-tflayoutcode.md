# TfLayoutCode enumeration

## Description

Elements of the **TfLayoutCode** enumeration specify the type of layout change in an [ITfTextLayoutSink::OnLayoutChange](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itftextlayoutsink-onlayoutchange) notification.

## Constants

### `TF_LC_CREATE:0`

The view has just been created.

### `TF_LC_CHANGE:1`

The view layout has changed.

### `TF_LC_DESTROY:2`

The view is about to be destroyed.

## Remarks

In TSF, a view is on-screen rendering of document content. These constants are assigned to parameters of methods of the **ITf*** interfaces, but not those of the **IText*** interfaces.

## See also

[ITfTextLayoutSink::OnLayoutChange](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itftextlayoutsink-onlayoutchange)