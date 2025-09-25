# DRVFN structure

## Description

The DRVFN structure is used by graphics drivers to provide GDI with pointers to the graphics DDI functions defined by the driver.

## Members

### `iFunc`

Is the function index that identifies a graphics DDI function implemented by the driver. The index name reflects the name of the related graphics DDI function; for example, an index value of INDEX_DrvEnablePDEV specifies the [DrvEnablePDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenablepdev) function. See the header file, *winddi.h*, for a complete list of index values.

### `pfn`

Specifies the address of the driver-defined graphics DDI function associated with the index supplied for **iFunc**. This function has the following prototype:

```
LONG_PTR  (APIENTRY * PFN) ();
```

## Remarks

A graphics driver must allocate an array of DRVFN structures, with an array element for each graphics DDI function implemented in the driver. The driver returns the array's address to GDI in the [DRVENABLEDATA](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-drvenabledata) structure whose pointer is passed to the driver's [DrvEnableDriver](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenabledriver) function during driver initialization.

Graphics DDI function addresses can be placed in the DRVFN array in any order.

## See also

[DrvEnableDriver](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenabledriver)