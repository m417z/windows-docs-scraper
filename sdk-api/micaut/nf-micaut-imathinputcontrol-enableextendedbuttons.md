# IMathInputControl::EnableExtendedButtons

## Description

Determines whether the extended set of control buttons is shown.

## Parameters

### `Extended` [in]

**VARIANT_TRUE** to show the extended button set; **VARIANT_FALSE** to show the basic button set.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The basic button set is shown by default.

The basic button set contains the **Clear**, **Erase**, **Insert**, **Select and Correct**, and **Write** buttons. The extended button set contains the basic set plus the **Redo** and **Undo** buttons.

The following image shows the Math Input Control with extended buttons enabled.

![Math input control with extended buttons enabled](https://learn.microsoft.com/windows/win32/api/micaut/images/MIC.png)
The following image shows the Math Input Control with extended buttons disabled.

![Math input control with extended buttons disabled](https://learn.microsoft.com/windows/win32/api/micaut/images/MIC_no_extended.png)

#### Examples

```

    hr = g_spMIC->EnableExtendedButtons(VARIANT_TRUE);

```

## See also

[Customizing the Math Input Control](https://learn.microsoft.com/windows/desktop/tablet/customizing-the-math-input-control)

[IMathInputControl](https://learn.microsoft.com/windows/desktop/api/micaut/nn-micaut-imathinputcontrol)