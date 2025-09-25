# HidP_GetButtons macro

## Description

The **HidP_GetButtons** macro is a mnemonic alias for the [**HidP_GetUsages**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getusages) function.

## Syntax

```cpp
#define HidP_GetButtons(Rty, UPa, LCo, ULi, ULe, Ppd, Rep, RLe) \
        HidP_GetUsages(Rty, UPa, LCo, ULi, ULe, Ppd, Rep, RLe)
```

## Parameters

### `Rty` [in]

Specifies a [**HIDP_REPORT_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ne-hidpi-_hidp_report_type) enumerator value that identifies the report type.

### `UPa` [in]

Specifies the [usage page](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-usages) of the button usages. The routine only returns information about buttons on this usage page.

### `LCo` [in]

Specifies the [link collection](https://learn.microsoft.com/windows-hardware/drivers/hid/link-collections) of the button usages. If *LCo* is nonzero, the routine only returns information about the buttons that this link collection contains; otherwise, if *LCo* is zero, the routine returns information about all the buttons in the [top-level collection](https://learn.microsoft.com/windows-hardware/drivers/hid/top-level-collections) associated with *Ppd*.

### `ULi` [out]

Pointer to a caller-allocated buffer that the routine uses to return the usages of all buttons that are set to ON and belong to the usage page specified by *UPa*.

### `ULe` [in, out]

Specifies, on input, the length, in array elements, of the *ULi* buffer. Specifies, on output, the number of buttons that are set to ON on the specified usage page.

### `Ppd` [in]

Pointer to a top-level collection's [pre-parsed data](https://learn.microsoft.com/windows-hardware/drivers/hid/preparsed-data).

### `Rep` [out]

Pointer to a report.

### `RLe` [in]

Specifies the length, in bytes, of the report located at *Rep*.

## Remarks

See [**HidP_GetUsages**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getusages) for return value details.

## See also

- [**HidP_GetUsages**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getusages)