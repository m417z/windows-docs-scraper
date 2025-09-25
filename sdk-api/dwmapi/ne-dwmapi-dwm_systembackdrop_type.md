## Description

Flags for specifying the system-drawn backdrop material of a window, including behind the non-client area.

## Constants

### `DWMSBT_AUTO`

The default. Let the Desktop Window Manager (DWM) automatically decide the system-drawn backdrop material for this window. This applies the backdrop material just behind the default Win32 title bar. This behavior attempts to preserve maximum backwards compatibility. For this reason, the DWM might also decide to draw no backdrop material at all based on internal heuristics.

If drawing the backdrop material behind the entire window is required, choose one of the other more specific values of this enum as appropriate.

### `DWMSBT_NONE`

Don't draw any system backdrop.

### `DWMSBT_MAINWINDOW`

Draw the backdrop material effect corresponding to a long-lived window behind the entire window bounds.

For Windows 11, this corresponds to Mica in its default variant. The material effect might change with future Windows releases. For more info about Mica, see [Mica](https://learn.microsoft.com/windows/apps/design/style/mica).

### `DWMSBT_TRANSIENTWINDOW`

Draw the backdrop material effect corresponding to a transient window behind the entire window bounds.

For Windows 11, this corresponds to Desktop Acrylic, also known as Background Acrylic, in its brightest variant. The material effect might change with future Windows releases. For more info about Desktop Acrylic, see [Acrylic](https://learn.microsoft.com/windows/apps/design/style/acrylic).

### `DWMSBT_TABBEDWINDOW`

Draw the backdrop material effect corresponding to a window with a tabbed title bar behind the entire window bounds.

For Windows 11, this corresponds to Mica in its alternate variant (Mica Alt). The material might change with future releases of Windows. For more info about Mica Alt, see [Layering with Mica Alt](https://learn.microsoft.com/windows/apps/design/style/mica#app-layering-with-mica-alt).

## Remarks

## See also