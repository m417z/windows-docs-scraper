# IInkCollector::get_Renderer

## Description

Gets or sets the [InkRenderer](https://learn.microsoft.com/windows/desktop/tablet/inkrenderer-class) object that is used to draw ink.

This property is read/write.

## Parameters

## Remarks

When handling certain window messages, changing the [Renderer](https://learn.microsoft.com/windows/desktop/tablet/inkrenderer-class) associated with the [InkCollector](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-class) can cause a reentrant function call, generating unexpected results. For example, changing to a different *Renderer* or modifying its transforms within a message handler can result in a reentrant call. This affects the following messages: **WM_ACTIVATE**, **WM_ACTIVATEAPP**, **WM_NCACTIVATE**, **WM_PAINT**; **WM_SYSCOMMAND** if *wParam* is set to SC_HOTKEY or SC_TASKLIST; and **WM_SYSKEYDOWN** (when processing Alt-Tab or Alt-Esc key combinations). It is an issue with single-threaded apartment model applications.

## See also

[IInkCollector](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkcollector)

[InkCollector Class](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-class)