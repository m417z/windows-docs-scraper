# StorPortInitialize function

## Description

The **StorPortInitialize** routine initializes the port driver parameters and extension data. **StorPortInitialize** also saves the adapter information provided from the [miniport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storage-miniport-drivers) **DriverEntry** routine.

## Parameters

### `Argument1` [in]

The first pointer with which the operating system called the miniport's DriverEntry routine.

### `Argument2` [in]

The second pointer with which the operating system called the miniports's DriverEntry routine.

### `HwInitializationData` [in]

Pointer to the initialization and configuration information set by the miniport driver in its DriverEntry routine.

### `HwContext` [in, optional]

Is the address of a context value to be passed to the miniport driver's [**HwStorFindAdapter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_find_adapter) routine. Only legacy miniport drivers that scan the bus for HBAs rather than receiving configuration information from the port driver can use this parameter to store state between calls to **HwStorFindAdapter**.

## Return value

The result of the initialization actions performed by **StorPortInitialize**. The miniport driver will return this value as the return value for its DriverEntry routine.

**StorPortInitialize** returns one of the following status codes:

| Return code | Description |
| ----------- | ----------- |
| **STATUS_INVALID_PARAMETER** | *Argument1* is NULL, or *Argument2* is NULL, OR *HwInitializationData* is NULL. |
| **STATUS_SUCCESS** | The driver extension data and adapter information were initialized successfully. |
| **STATUS_NO_MEMORY** | No memory is available to store an initialization parameter. |
| **STATUS_REVISION_MISMATCH** | The version of the structure pointed to by *HwInitializationData* is invalid for the current operating system. |
| **STATUS_INSUFFICENT_RESOURCES** | The allocation failed for the driver object extension data. |

## Remarks

This routine must be called from the miniport driver's **DriverEntry** routine.

Because Storport miniport drivers must support PnP, the Storport driver does not use the *HwContext* parameter passed to **StorPortInitialize**.

Every miniport driver's DriverEntry routine must call **StorPortInitialize** after the miniport driver has first zeroed and then set the members of [**HW_INITIALIZATION_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_hw_initialization_data-r1).

## See also

[**HW_INITIALIZATION_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_hw_initialization_data-r1)

[**HwStorFindAdapter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_find_adapter)