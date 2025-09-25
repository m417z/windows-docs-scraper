# IDARG_IN_QUERY_HWCURSOR structure

## Description

The **IDARG_IN_QUERY_HWCURSOR** structure is passed to [**IddCxMonitorQueryHardwareCursor**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorqueryhardwarecursor), [**IddCxMonitorQueryHardwareCursor2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorqueryhardwarecursor2), and [**IddCxMonitorQueryHardwareCursor3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorqueryhardwarecursor3)
to provide information about the cursor associated with the monitor.

## Members

### `LastShapeId` [in]

The ID of the last cursor shape the driver received for this monitor. This ID is compared against the latest shape ID that the OS has. The new shape is only copied to the buffer that **pShapeBuffer** points to if the OS version has been updated since the last image driver was received.

### `ShapeBufferSizeInBytes` [in]

Size in bytes of the cursor shape buffer that **pShapeBuffer** points to.

### `pShapeBuffer` [out]

Pointer to a driver-allocated buffer that the OS will copy any new cursor image data into.

## See also

[**IDARG_OUT_QUERY_HWCURSOR2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_out_query_hwcursor2)

[**IDARG_OUT_QUERY_HWCURSOR3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_out_query_hwcursor3)

[**IddCxMonitorQueryHardwareCursor**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorqueryhardwarecursor)

[**IddCxMonitorQueryHardwareCursor2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorqueryhardwarecursor2)

[**IddCxMonitorQueryHardwareCursor3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorqueryhardwarecursor3)