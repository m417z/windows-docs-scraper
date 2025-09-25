# StreamClassRegisterAdapter function

## Description

The **StreamClassRegisterAdapter** routine registers a stream class minidriver.

The name **StreamClassRegisterAdapter** is supported for backward compatibility only.

Instead, Microsoft recommends the use of **StreamClassRegisterMinidriver**, an alias of **StreamClassRegisterAdapter**. The name **StreamClassRegisterMinidriver** more accurately indicates that the routine registers a stream class minidriver. Once registered, a minidriver can drive any number of adapter instances in a system.

The **StreamClassRegisterMinidriver** routine registers a stream minidriver with the stream class driver.

## Parameters

### `Argument1` [in]

Points to the first argument to the minidriver's **DriverEntry** routine.

### `Argument2` [in]

Points to the second argument to the minidriver's **DriverEntry** routine.

### `HwInitializationData` [in]

Points to an [HW_INITIALIZATION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_initialization_data) structure that provides the information the class driver needs to begin initializing the minidriver.

## Return value

Returns STATUS_SUCCESS on success, or the appropriate error code on failure.

## Remarks

A stream minidriver must call **StreamClassRegisterMinidriver** within its **DriverEntry** routine.

The stream minidriver's **DriverEntry** initializes a stream class minidriver. This routine is required.

Argument1 Supplies a context value with which the adapter minidriver should call **StreamClassRegisterMinidriver**. For Windows 2000 and later, this points to a DRIVER_OBJECT.

Argument2 Supplies a second context value with which the adapter minidriver should call **StreamClassRegisterMinidriver**. For Windows 2000 and later, this points to a registry path.

**DriverEntry** returns the value returned by its call to **StreamClassRegisterMinidriver**.

Remarks
**DriverEntry** is the initial entry point for a stream class minidriver.

Since **StreamClassRegisterMinidriver** performs most of the required driver initialization, the primary task of a stream class minidriver's DriverEntry routine is to allocate and fill in a HW_INITIALIZATION_DATA structure with driver-specific constants and entry points. The DriverEntry should then call **StreamClassRegisterMinidriver**.

Most of the information passed in the HW_INITIALIZATION_DATA structure informs the class driver of the minidriver-wide callbacks, and what size buffers to allocate for the minidriver's data structures. The class driver queries the minidriver for additional start-up information through [SRB_INITIALIZE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/stream/srb-initialize-device) and [SRB_GET_STREAM_INFO](https://learn.microsoft.com/windows-hardware/drivers/stream/srb-get-stream-info) requests to the minidriver's [StrMiniReceiveDevicePacket](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/nc-strmini-phw_receive_device_srb) routine (passed as the **HwReceivePacket** member of HW_INITIALIZATION_DATA).

Once registered, a minidriver can drive any number of adapter instances in a system.

## See also

[HW_INITIALIZATION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_initialization_data)

[SRB_GET_STREAM_INFO](https://learn.microsoft.com/windows-hardware/drivers/stream/srb-get-stream-info)

[SRB_INITIALIZE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/stream/srb-initialize-device)

[StrMiniReceiveDevicePacket](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/nc-strmini-phw_receive_device_srb)