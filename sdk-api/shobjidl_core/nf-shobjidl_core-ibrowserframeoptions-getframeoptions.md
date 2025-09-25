# IBrowserFrameOptions::GetFrameOptions

## Description

Retrieves the available browser frame view options.

## Parameters

### `dwMask` [in]

Type: **[BROWSERFRAMEOPTIONS](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_browserframeoptions)**

Specifies the options requested as a bitwise combination of one or more of the constants of enumeration type [BROWSERFRAMEOPTIONS](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_browserframeoptions).

### `pdwOptions` [out]

Type: **[BROWSERFRAMEOPTIONS](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_browserframeoptions)***

When this method returns, contains the options that the view can enable (for example, [IShellView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview) ). This value is not optional and is always equal to, or a subset of, the options specified by *dwMask*.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If the method succeeds, the return value is S_OK and *pdwOptions* contains the subset of available view options. If the method fails, *pdwOptions* is set to BFO_NONE.