# IMathInputControl::Show

## Description

Shows the control.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Shows the Math Input Control if it is not visible. If the control is already visible, puts the control on top of the z-order stack.
If [SetPosition](https://learn.microsoft.com/windows/desktop/api/micaut/nf-micaut-imathinputcontrol-setposition) is not called, **Show** will display the control at the top-left corner of the screen ((0, 0) in screen coordinates).
The control's width and height will be at their minimum.

#### Examples

```

    HRESULT hr = CoInitialize(NULL);
    hr = g_spMIC.CoCreateInstance(CLSID_MathInputControl);
    hr = g_spMIC->EnableExtendedButtons(VARIANT_TRUE);
    hr = g_spMIC->Show();

```

## See also

[Creating a Math Input Control](https://learn.microsoft.com/windows/desktop/tablet/creating-a-math-input-control)

[Customizing the Math Input Control](https://learn.microsoft.com/windows/desktop/tablet/customizing-the-math-input-control)

[Hide](https://learn.microsoft.com/windows/desktop/api/micaut/nf-micaut-imathinputcontrol-hide)

[IMathInputControl](https://learn.microsoft.com/windows/desktop/api/micaut/nn-micaut-imathinputcontrol)