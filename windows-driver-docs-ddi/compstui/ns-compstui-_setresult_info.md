## Description

The **SETRESULT_INFO** structure is used as an input parameter to an application's [PFNPROPSHEETUI](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/nc-compstui-pfnpropsheetui)-typed callback function.

## Members

### `cbSize`

CPSUI-supplied size, in bytes, of the **SETRESULT_INFO** structure.

### `wReserved`

Reserved.

### `hSetResult`

CPSUI-supplied handle to an added property sheet page, obtained from the application. For more information, see the **Remarks** section below.

### `Result`

CPSUI-supplied handle to an added property sheet page, obtained from the application. For more information, see the **Remarks** section below.

## Remarks

When an application calls CPSUI's [ComPropSheet](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/nc-compstui-pfncompropsheet) function, specifying a function code of [CPSFUNC_SET_RESULT](https://learn.microsoft.com/previous-versions/ff547087(v=vs.85)), CPSUI calls all registered [PFNPROPSHEETUI](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/nc-compstui-pfnpropsheetui)-typed functions, specifying a reason of PROPSHEETUI_REASON_SET_RESULT. When specifying this reason, CPSUI also supplies a **SETRESULT_INFO** structure.

The values contained in the structure's **hSetResult** and **Result** members are the *lParam1* and *lParam2* values, respectively, that were supplied to CPSUI's **ComPropSheet** function.

Each of the application's PFNPROPSHEETUI-typed functions is called in order, from the one most recently declared to the first one declared, until one of these functions provides a return value of less than one. At that point, CPSUI returns from its **ComPropSheet** function, providing a count of the number of PFNPROPSHEETUI-typed functions that were called.

Typically, an application's PFNPROPSHEETUI-typed function sets the **Result** member of its PROPSHEETUI_INFO structure to the value received in the **SETRESULT_INFO** structure's **Result** member. Then the function returns a value of 1 (or greater), so the next PFNPROPSHEETUI-typed function can also receive it. Each subsequently called function is associated with a page that is the parent of the page associated with the last-called function. A function can modify the contents of **SETRESULT_INFO** structure's **Result** member, causing the functions associated with parent pages to receive the new value.