# MCIWndRegisterClass function

## Description

The **MCIWndRegisterClass** function registers the MCI window class MCIWND_WINDOW_CLASS.

#### - hInstance

Handle to the device instance.

## Return value

Returns zero if successful.

## Remarks

After registering the MCI window class, use the **CreateWindow** or **CreateWindowEx** functions to create an MCIWnd window. If your application uses this function, it does not need to use the [MCIWndCreate](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-mciwndcreatea) function.