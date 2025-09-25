# HidP_GetButtonsEx macro

## Description

The **HidP_GetButtonsEx** macro is a mnemonic alias for the [**HidP_GetUsagesEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getusagesex) function.

## Syntax

```cpp
#define HidP_GetButtonsEx(Rty, LCo, BLi, ULe, Ppd, Rep, RLe) \
         HidP_GetUsagesEx(Rty, LCo, BLi, ULe, Ppd, Rep, RLe)
```

## Parameters

### `Rty` [in]

Specifies a [**HIDP_REPORT_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ne-hidpi-_hidp_report_type) enumerator value that identifies the report type.

### `LCo` [in]

Specifies the [link collection](https://learn.microsoft.com/windows-hardware/drivers/hid/link-collections) of the button usages. If *LCo* is nonzero, the routine only returns information about the buttons that this link collection contains; otherwise, if *LCo* is zero, the routine returns information about all the buttons in the [top-level collection](https://learn.microsoft.com/windows-hardware/drivers/hid/top-level-collections) associated with *Ppd*.

### `BLi` [in, out]

Pointer to a caller-allocated buffer that routine uses to return the usage and [usage page](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-usages) identifiers for each button that is set to ON (1).

### `ULe` [in, out]

Specifies, on input, the length, in array elements, of the *BLi* buffer. Specifies, on output, the number usages that are currently set to ON in the specified report.

### `Ppd` [in]

Pointer to a top-level collection's [pre-parsed data](https://learn.microsoft.com/windows-hardware/drivers/hid/preparsed-data).

### `Rep` [in]

Pointer to a report that contains button data.

### `RLe` [in]

Specifies the length, in bytes, of the report located at *Rep*.

## Remarks

See [**HidP_GetUsagesEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getusagesex) for return value details.

## See also

- [**HidP_GetUsagesEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getusagesex)