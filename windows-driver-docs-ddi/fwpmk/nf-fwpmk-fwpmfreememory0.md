## Description

The **FwpmFreeMemory0** function is used to release memory resources allocated by the Windows Filtering Platform (WFP) functions.

## Parameters

### `p` [in, out]

Address of the pointer to be freed.

## Remarks

**FwpmFreeMemory0** is used to free memory returned by the various Fwpm* functions, such as **[FwpmFilterGetByKey0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmfiltergetbykey0)**.

Fwpm* functions that return a **HANDLE**, such as **[FwpmCalloutCreateEnumHandle0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmcalloutcreateenumhandle0)**, have specific functions to release memory.

If the caller passes a pointer that is not valid, the behavior is undefined.

**FwpmFreeMemory0** is a specific implementation of **FwpmFreeMemory**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

- **[FwpmFilterGetByKey0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmfiltergetbykey0)**
- **[FwpmCalloutCreateEnumHandle0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmcalloutcreateenumhandle0)**
- [WFP Functions](https://learn.microsoft.com/windows/desktop/FWP/fwp-functions)
- [Windows Filtering Platform API Reference](https://learn.microsoft.com/windows/desktop/FWP/fwp-reference)
- [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows)