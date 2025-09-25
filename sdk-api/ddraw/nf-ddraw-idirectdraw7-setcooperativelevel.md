# IDirectDraw7::SetCooperativeLevel

## Description

Determines the top-level behavior of the application.

## Parameters

### `unnamedParam1` [in]

Window handle used for the application. Set to the calling application's top-level window handle (not a handle for any child windows created by the top-level window). This parameter can be NULL when the DDSCL_NORMAL flag is specified in the *dwFlags* parameter.

### `unnamedParam2` [in]

This value consists of one or more of the following flags:

#### DDSCL_ALLOWMODEX

Allows the use of Mode X display modes. This flag can be used only if the DDSCL_EXCLUSIVE and DDSCL_FULLSCREEN flags are present.

#### DDSCL_ALLOWREBOOT

Allows CTRL+ALT+DEL to function while in exclusive (full-screen) mode.

#### DDSCL_CREATEDEVICEWINDOW

This flag is supported in Windows 98 and Windows 2000 only. Indicates that DirectDraw will create and manage a default device window for this DirectDraw object.

#### DDSCL_EXCLUSIVE

Requests the exclusive level. This flag must be used with the DDSCL_FULLSCREEN flag.

#### DDSCL_FPUPRESERVE

The calling application cares about the FPU state and does not want Direct3D to modify it in ways visible to the application. In this mode, Direct3D saves and restores the FPU state every time that it needs to modify the FPU state.

#### DDSCL_FPUSETUP

The calling application is likely to keep the FPU set up for optimal Direct3D performance (single precision and exceptions disabled), so Direct3D does not need to explicitly set the FPU each time. This is the default state.

#### DDSCL_FULLSCREEN

The exclusive-mode owner is responsible for the entire primary surface. The GDI can be ignored. This flag must be used with the DDSCL_EXCLUSIVE flag.

#### DDSCL_MULTITHREADED

Requests multithread-safe DirectDraw behavior. This causes Direct3D to take the global critical section more frequently.

#### DDSCL_NORMAL

The application functions as a typical Windows application. This flag cannot be used with the DDSCL_ALLOWMODEX, DDSCL_EXCLUSIVE, or DDSCL_FULLSCREEN flags.

#### DDSCL_NOWINDOWCHANGES

DirectDraw is not allowed to minimize or restore the application window on activation.

#### DDSCL_SETDEVICEWINDOW

This flag is supported in Windows 98 and Windows 2000 only. Indicates that the *hWnd* parameter is the window handle of the device window for this DirectDraw object. This flag cannot be used with the DDSCL_SETFOCUSWINDOW flag.

#### DDSCL_SETFOCUSWINDOW

This flag is supported in Windows 98 and Windows 2000 only. Indicates that the *hWnd* parameter is the window handle of the focus window for this DirectDraw object. This flag cannot be used with the DDSCL_SETDEVICEWINDOW flag.

## Return value

If the method succeeds, the return value is DD_OK.

If it fails, the method can return one of the following error values:

* DDERR_EXCLUSIVEMODEALREADYSET
* DDERR_HWNDALREADYSET
* DDERR_HWNDSUBCLASSED
* DDERR_INVALIDOBJECT
* DDERR_INVALIDPARAMS
* DDERR_OUTOFMEMORY

## Remarks

This method must be called by the same thread that created the application window.

An application must set either the DDSCL_EXCLUSIVE or the DDSCL_NORMAL flag.

The DDSCL_EXCLUSIVE flag must be set to call functions that can adversely affect performance of other applications.

Interaction between this method and the [IDirectDraw7::SetDisplayMode](https://learn.microsoft.com/windows/desktop/api/ddraw/nf-ddraw-idirectdraw7-setdisplaymode) method differs from their IDirectDraw counterparts.

If you use Microsoft Foundation Classes (MFC), the window handle passed to this method must identify the application's top-level window, not a derived child window. To retrieve your MFC application's top-level window handle, you could use the following code:

```

HWND hwndTop = AfxGetMainWnd()->GetSafeHwnd();

```

## See also

[IDirectDraw7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdraw7)