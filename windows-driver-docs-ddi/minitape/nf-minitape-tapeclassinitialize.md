# TapeClassInitialize function

## Description

The **TapeClassInitialize** routine performs much of the driver and device initialization on behalf of a miniclass driver. **TapeClassInitialize** loads the tape class driver entry points for tape I/O requests into the miniclass driver data structure, locates and claims unclaimed tape devices that the miniclass driver supports, and allocates and initializes the operating system resources for the miniclass driver and its devices. **TapeClassInitialize** uses miniclass-driver-specific information supplied in *TapeInitData* and calls back to the tape miniclass driver for driver-specific operations.

## Parameters

### `Argument1` [in]

Pointer to driver context information that was passed to the tape miniclass driver's **DriverEntry** routine. The format of the information is operating system-specific and must not be interpreted by a tape miniclass driver.

### `Argument2` [in]

Pointer to the second driver context structure that was passed to the tape miniclass driver's **DriverEntry** routine. The format of the information is operating system-specific and must not be interpreted by a tape miniclass driver.

### `TapeInitData` [in]

Pointer to a TAPE_INIT_DATA_EX structure containing driver-specific information such as the entry points for the tape miniclass driver's command processing routines.

## Return value

**TapeClassInitialize** returns a value indicating the success or failure of the driver initialization. The tape miniclass driver passes this value, uninterpreted, as the return value from its **DriverEntry** routine.

## Remarks

A tape miniclass driver calls **TapeClassInitialize** from its **DriverEntry** routine and passes driver-specific information in *TapeInitData*. **TapeClassInitialize** performs a large part of the driver initialization on behalf of the miniclass driver and insulates the miniclass driver from operating system-specific details.

**TapeClassInitialize** calls the tape miniclass driver for driver-specific activities required during initialization. For example, **TapeClassInitialize** calls the tape miniclass driver's TapeMiniVerifyInquiry routine to determine whether the driver supports a given tape device. **TapeClassInitialize** also calls the tape miniclass driver's TapeMiniExtensionInit routine to initialize the minitape extension, if the miniclass driver requested one.

A tape miniclass driver allocates a TAPE_INIT_DATA_EX structure on the stack, clears it with **TapeClassZeroMemory**, fills in all the appropriate members, and passes it to **TapeClassInitialize**.

## See also

[DriverEntry of Tape Miniclass Driver](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-tape-miniclass-driver)

[TAPE_INIT_DATA_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/ns-minitape-_tape_init_data_ex)