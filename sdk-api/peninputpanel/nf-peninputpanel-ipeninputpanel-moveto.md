# IPenInputPanel::MoveTo

## Description

Deprecated. The [PenInputPanel](https://learn.microsoft.com/windows/desktop/tablet/peninputpanel-class) has been replaced by the [Text Input Panel (TIP)](https://learn.microsoft.com/windows/desktop/tablet/text-input-panel-reference).

Sets the position of the [PenInputPanel](https://learn.microsoft.com/windows/desktop/tablet/peninputpanel-class) object to a static screen position.

## Parameters

### `Left` [in]

 The new horizontal position in screen coordinates.

### `Top` [in]

The new vertical position in screen coordinates.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_UNEXPECTED** | Unexpected parameter or property type. |
| **E_FAIL** | An unspecified error occurred. |

## Remarks

The **MoveTo** method causes an error if the control to which the [PenInputPanel](https://learn.microsoft.com/windows/desktop/tablet/peninputpanel-class) is attached does not have focus. This method can be safely called if the pen input panel is not visible, as long as the attached control has focus.

If the new position causes the panel to appear outside the boundary of the screen working area, the panel is shifted toward the center of the working area so that the edges of the panel are adjacent to the nearest edges of the screen.

To explicitly override the automatic positioning behavior of the [PenInputPanel](https://learn.microsoft.com/windows/desktop/tablet/peninputpanel-class) object, use the [Left](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nf-peninputpanel-ipeninputpanel-get_left) and [Top](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nf-peninputpanel-ipeninputpanel-get_top) properties of the **PenInputPanel** object to determine its current position. If the **PenInputPanel** is located on a section of the screen that should be visible, use the **MoveTo** method to relocate the **PenInputPanel**.

You can also override the automatic positioning behavior of the [PenInputPanel](https://learn.microsoft.com/windows/desktop/tablet/peninputpanel-class) object by monitoring to the [Left](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nf-peninputpanel-ipeninputpanel-get_left) and [Top](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nf-peninputpanel-ipeninputpanel-get_top) parameters passed to a [PanelMoving](https://learn.microsoft.com/windows/desktop/tablet/peninputpanel-panelmoving) event handler. If the **PenInputPanel** is located on a section of the screen that should be visible, use the **MoveTo** method to relocate the **PenInputPanel**.

## See also

[IPenInputPanel](https://learn.microsoft.com/windows/win32/api/peninputpanel/nn-peninputpanel-ipeninputpanel)

[PenInputPanel](https://learn.microsoft.com/windows/desktop/tablet/peninputpanel-class)