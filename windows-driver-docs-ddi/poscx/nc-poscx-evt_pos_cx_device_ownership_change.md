# EVT_POS_CX_DEVICE_OWNERSHIP_CHANGE callback function

## Description

The
EVT_POS_CX_DEVICE_OWNERSHIP_CHANGE callback is called during the API claim ownership transition. The driver is expected to set the device back to a default state in this routine.

## Parameters

### `device` [in]

A handle to a framework device object that represents the device.

### `oldOwnerFileObj` [in, optional]

The file object of the previous claim owner. This may be NULL if no previous owner.

### `newOwnerFileObj` [in, optional]

The file object of the new claim owner. This may be NULL if the device was released without a pending claim request.