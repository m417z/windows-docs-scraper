# IBrowserService2::SetAcceleratorMenu

## Description

Deprecated. Implemented by a derived class to define menu accelerators that can be used in a call to [TranslateAcceleratorSB](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellbrowser-translateacceleratorsb).

## Parameters

### `hacc` [in]

Type: **HACCEL**

A handle to an array of [ACCEL](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-accel) structures, each structure describing a keyboard mnemonic.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.