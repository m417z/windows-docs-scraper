# MmAdvanceMdl function

## Description

The **MmAdvanceMdl** routine advances the beginning of an MDL's virtual memory range by the specified number of bytes.

## Parameters

### `Mdl` [in, out]

Specifies the MDL to advance.

### `NumberOfBytes` [in]

Specifies the number of bytes to advance the beginning of the MDL.

## Return value

**MmAdvanceMdl** returns an NTSTATUS code. The possible return values include:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The routine successfully advanced the beginning of the MDL. |
| **STATUS_INVALID_PARAMETER_2** | The caller attempted to advance the beginning of the MDL past the end. |

## Remarks

**MmAdvanceMdl** advances only the beginning of the virtual memory address range. The ending address remains the same, and the length of the range is shrunk accordingly.

A higher-level driver can use **MmAdvanceMdl** under low-memory conditions when a lower-level driver can only partially complete a read/write request. The higher-level driver can use **MmAdvanceMdl** to advance past the part of the buffer that has already been read or written, and then reissue the IRP to complete the request. (The driver can, of course, repeat this process as many times as necessary.)

If **MmAdvanceMdl** advances past the initial page, any pages that **MmAdvanceMdl** passed are immediately unlocked, and the system virtual address that maps the MDL and the user address are also adjusted.

Use of **MmAdvanceMdl** can slow system performance. It must be used only when all of the following conditions hold:

* The higher-level driver, in its own I/O handling, can only complete certain I/O requests after transferring a fixed amount of data, but the lower-level driver only transfers data in smaller amounts. (An example is a network transport driver for the SPX or NBT protocols. Each protocol supports reliable message passing for messages that are bigger than one Ethernet frame. The transport driver can only complete a read request for such a message once it has reassembled the message from multiple Ethernet frames.)
* The higher-level driver already tried and failed to allocate a new MDL to transfer a data fragment from an incomplete I/O request. (If the driver succeeds in allocating a new MDL, it must use that MDL and [IoBuildPartialMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iobuildpartialmdl) to perform the I/O request instead of **MmAdvanceMdl**.)
* The higher-level driver must continue to make progress, even under low-memory conditions.

Drivers that do not satisfy these conditions must instead use the **IoBuildPartialMdl** routine to complete any partially-successful I/O operations.

## See also

[IoBuildPartialMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iobuildpartialmdl)