# HidP_SetButtons macro

## Description

The **HidP_SetButtons** macro is a mnemonic alias for the [**HidP_SetUsages**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_setusages) function.

## Syntax

```cpp
#define HidP_SetButtons(Rty, Up, Lco, ULi, ULe, Ppd, Rep, Rle) \
        HidP_SetUsages(Rty, Up, Lco, ULi, ULe, Ppd, Rep, Rle)
```

## Parameters

### `Rty` [in]

Specifies a [**HIDP_REPORT_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ne-hidpi-_hidp_report_type) enumerator value that indicates the type of report located at *Rep*.

### `Up` [in]

Specifies the [usage page](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-usages) for the usages specified by *ULi*.

### `Lco` [in]

Specifies the [link collection](https://learn.microsoft.com/windows-hardware/drivers/hid/link-collections) that contains the usages. If *Lco* is nonzero, the routine only sets the usages, if they exist, in this link collection. If *Lco* is zero, the routine sets the first usage for each specified usage in the [top-level collection](https://learn.microsoft.com/windows-hardware/drivers/hid/top-level-collections) associated with *Ppd*.

### `ULi` [in, out]

Pointer to the array of usages.

### `ULe` [in, out]

Specifies, on input, the number of usages in *ULi*. See the Remarks section for information about the output value.

### `Ppd` [in]

Pointer to the [pre-parsed data](https://learn.microsoft.com/windows-hardware/drivers/hid/preparsed-data) of the top-level collection associated with the report located at *Rep*.

### `Rep` [in]

Pointer to a report.

### `Rle` [in]

Specifies the size, in bytes, of the report located at *Rep*, which must be equal to the report length for the specified report type that [**HidP_GetCaps**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getcaps) returns in a collection's [**HIDP_CAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ns-hidpi-_hidp_caps) structure.

## Remarks

See [**HidP_SetUsages**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_setusages) for return value details.

## See also

- [**HidP_SetUsages**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_setusages)