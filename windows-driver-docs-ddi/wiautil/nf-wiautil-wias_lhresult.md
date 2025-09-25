# WIAS_LHRESULT macro (wiautil.h)

## Description

The WIAS_LHRESULT macro is obsolete. It is recommended that the [WIAS_HRESULT]9/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wias_hresult) macro be used instead. The WIAS_LHRESULT macro translates an HRESULT value into a string and writes the string to the diagnostic log file.

## Parameters

### `x`

### `y`

- **hr** - Specifies the HRESULT value to be translated into a string.

- **pIWiaLog** - Pointer to an [IWiaLog Interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wia_lh/nn-wia_lh-iwialog).

## Remarks

The following is an example of how the macro can be used:

```cpp
hr = wiasFreePropContext(*pContext);
if (hr != S_OK)
   WIAS_LHRESULT(g_pIWiaLog, hr);
```

The WIAS_LHRESULT macro is obsolete. It is recommended that the [WIAS_HRESULT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wias_hresult) macro be used instead.

## See also

[WIAS_HRESULT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wias_hresult)

[WIAS_LERROR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wias_lerror)

[WIAS_LTRACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wias_ltrace)

[WIAS_LWARNING](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wias_lwarning)