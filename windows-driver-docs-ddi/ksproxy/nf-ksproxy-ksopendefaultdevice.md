# KsOpenDefaultDevice function

## Description

The **KsOpenDefaultDevice** function opens a handle to the first device that is listed in the specified Plug and Play (PnP) category.

## Parameters

### `Category` [in]

Identifier of the PnP category to enumerate.

### `Access` [in]

An ACCESS_MASK bitmask specifying how to access the default device.

### `DeviceHandle` [out]

Pointer to a variable that receives the handle to the default device that is opened.

## Return value

Returns NOERROR if successful; otherwise, returns an error code.

## Remarks

The **KsOpenDefaultDevice** function passes a pointer to *Category* in a call to the **SetupDiGetClassDevs** function to obtain a handle to the list of PnP devices. For more information about the ACCESS_MASK bitmask and **SetupDiGetClassDevs**, see the Microsoft Windows SDK documentation.