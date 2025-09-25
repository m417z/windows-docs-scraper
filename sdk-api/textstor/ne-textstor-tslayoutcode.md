# TsLayoutCode enumeration

## Description

Elements of the **TsLayoutCode** enumeration are used to specify the type of layout change in an [ITextStoreACPSink::OnLayoutChange](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreacpsink-onlayoutchange) or [ITextStoreAnchorSink::OnLayoutChange](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreanchorsink-onlayoutchange) notification.

## Constants

### `TS_LC_CREATE:0`

The view has just been created.

### `TS_LC_CHANGE:1`

The view layout has changed.

### `TS_LC_DESTROY:2`

The view is about to be destroyed.

## See also

[ITextStoreACPSink::OnLayoutChange](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreacpsink-onlayoutchange)

[ITextStoreAnchorSink::OnLayoutChange](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreanchorsink-onlayoutchange)