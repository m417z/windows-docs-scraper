# PanelType enumeration

## Description

Defines the type of input currently available in the [PenInputPanel](https://learn.microsoft.com/windows/desktop/tablet/peninputpanel-class) object.

## Constants

### `PT_Default:0`

The [PenInputPanel](https://learn.microsoft.com/windows/desktop/tablet/peninputpanel-class) object displays the last panel type used for any pen input panel in any application. If all previous references to the pen input panel have been destroyed in all active applications, a new pen input panel will use the handwriting panel type.

### `PT_Inactive`

The [PenInputPanel](https://learn.microsoft.com/windows/desktop/tablet/peninputpanel-class) object does not accept input. This value is returned by the [CurrentPanel](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nf-peninputpanel-ipeninputpanel-get_currentpanel) property when the panel window is owned by another instance of the **PenInputPanel** object. This value is also returned if the panel window has not yet been activated.

### `PT_Handwriting`

The [PenInputPanel](https://learn.microsoft.com/windows/desktop/tablet/peninputpanel-class) object displays the default handwriting panel for the current input language.

### `PT_Keyboard`

The [PenInputPanel](https://learn.microsoft.com/windows/desktop/tablet/peninputpanel-class) object displays the default keyboard panel for the current input language.

## Remarks

The end user can change the handwriting panel between lined and boxed input modes using buttons on the Tablet PC Input Panel user interface (UI). There is no programmatic way to get or set lined or boxed mode. By default, western languages use lined input and East Asian languages use boxed input, but the user is free to change between these modes.

## See also

[CurrentPanel Property](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nf-peninputpanel-ipeninputpanel-get_currentpanel)

[DefaultPanel Property](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nf-peninputpanel-ipeninputpanel-get_defaultpanel)

[PenInputPanel Class](https://learn.microsoft.com/windows/desktop/tablet/peninputpanel-class)