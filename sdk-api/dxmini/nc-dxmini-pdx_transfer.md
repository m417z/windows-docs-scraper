## Description

The *DxTransfer* callback function informs the driver to bus master data from a surface to the buffer specified in the memory descriptor list (MDL).

## Parameters

### `unnamedParam1`
Points to the miniport driver's device extension.

### `unnamedParam2`
Points to a [DDTRANSFERININFO](https://learn.microsoft.com/windows/desktop/api/dxmini/ns-dxmini-ddtransferininfo) structure that contains the transfer information for the surface.

### `unnamedParam3`
Points to a [DDTRANSFEROUTINFO](https://learn.microsoft.com/windows/desktop/api/dxmini/ns-dxmini-ddtransferoutinfo) structure that contains the polarity of the field being captured.

## Return value

*DxTransfer* returns DX_OK if it succeeds; otherwise, it returns one of the following error values:

## Remarks

The MDL is defined in [WDM](https://learn.microsoft.com/windows-hardware/drivers/) documentation.

As shown in the following code sample, the video miniport driver can use the pointer to the MDL in the **lpDestMDL** member of the DDTRANSFERININFO structure at the *TransferInInfo* parameter to bus master data to the physical memory pages that make up a scattered buffer:

```cpp
DWORD
DxTransfer(
    DEVICE_EXT *pDeviceExt,
    PDDTRANSFERININFO pTransferInInfo,
    PDDTRANSFEROUTINFO pTransferOutInfo
    )
{
    PMDL pMdl;
    UINT uiNbPages;
    PPFN_NUMBER pPages;
    PVOID MappedSystemVa;
    ULONG ByteCount;

    pMdl = pTransferInInfo->lpDestMDL;
    MappedSystemVa = MmGetMdlVirtualAddress(pMdl);
    ByteCount = MmGetMdlByteCount(pMdl);
    uiNbPages = ADDRESS_AND_SIZE_TO_SPAN_PAGES(MappedSystemVa,
                                               ByteCount);
    pPages = MmGetMdlPfnArray(pMdl)
    for (i=0; i<uiNbPages; i++) {
        //
        // Transfer to page[i]
        //
        pPages[i];
    }
}
```

See the [ADDRESS_AND_SIZE_TO_SPAN_PAGES](https://learn.microsoft.com/windows-hardware/drivers/kernel/mm-bad-pointer), [MmGetMdlByteCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wdm/nf-wdm-mmgetmdlbytecount), [MmGetMdlPfnArray](https://learn.microsoft.com/windows-hardware/drivers/kernel/mm-bad-pointer), and [MmGetMdlVirtualAddress](https://learn.microsoft.com/windows-hardware/drivers/kernel/mm-bad-pointer) kernel-mode macros for more information.

*DxTransfer* is called at hardware interrupt time. This means the driver cannot wait for a previous bus master to complete and it cannot call any functions that are not safe to call at interrupt time (that is, most of them).

In addition, the driver should not fail the call just because the hardware is currently busy. Instead, the driver should maintain an internal queue.

## See also

[ADDRESS_AND_SIZE_TO_SPAN_PAGES](https://learn.microsoft.com/windows-hardware/drivers/kernel/mm-bad-pointer)

[DDTRANSFERININFO](https://learn.microsoft.com/windows/desktop/api/dxmini/ns-dxmini-ddtransferininfo)

[DDTRANSFEROUTINFO](https://learn.microsoft.com/windows/desktop/api/dxmini/ns-dxmini-ddtransferoutinfo)

[MmGetMdlByteCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wdm/nf-wdm-mmgetmdlbytecount)

[MmGetMdlPfnArray](https://learn.microsoft.com/windows-hardware/drivers/kernel/mm-bad-pointer)

[MmGetMdlVirtualAddress](https://learn.microsoft.com/windows-hardware/drivers/kernel/mm-bad-pointer)