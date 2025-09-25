# IImePadApplet::Notify

## Description

Called from [IImePad](https://learn.microsoft.com/windows/desktop/api/imepad/nn-imepad-iimepad) to pass information with a notify code

## Parameters

### `lpImePad` [in]

Pointer of IUnknown interface. To get the [IImePad](https://learn.microsoft.com/windows/desktop/api/imepad/nn-imepad-iimepad) interface pointer, use [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)).

### `notify` [in]

The [IImePadApplet](https://learn.microsoft.com/windows/desktop/api/imepad/nn-imepad-iimepadapplet) notify code. See Remarks for the possible codes.

### `wParam` [in, out]

Additional information specific to *notify*.

### `lParam` [in, out]

Additional information specific to *notify*.

## Return value

**S_OK** if successful, otherwise **E_FAIL**.

## Remarks

### Possible notify codes (**IMEPN_*** values)

| Code | Description |
| --- | --- |
| **IMEPN_ACTIVATE** | The applet is activated. |
| **IMEPN_INACTIVATE** | The applet is inactivate. |
| **IMEPN_SHOW** | IMEPad and the applet are shown. |
| **IMEPN_HIDE** | IMEPad and the applet are hidden. |
| **IMEPN_SIZECHANGING** | The applet size is changing. |
| **IMEPN_SIZECHANGED** | The applet size has changed. |
| **IMEPN_CONFIG** | The applet setting is selected in IMEPad menu. |
| **IMEPN_HELP** | The applet help is selected in IMEPad menu. |

## See also

[IImePadApplet](https://learn.microsoft.com/windows/desktop/api/imepad/nn-imepad-iimepadapplet)