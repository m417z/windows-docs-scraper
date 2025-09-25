# PosCxInit function

## Description

PosCxInit is called to initialize the PosCx library's internal resources. The resources are tied to the device, and are released when the device goes away.

It is recommended to call this method while handling EvtDeviceAdd.

## Parameters

### `device` [in]

A handle to a framework device object that represents the device.

### `posCxAttrPtr` [in]

A pointer to a caller-allocated and initialized [POS_CX_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/poscx/ns-poscx-_pos_cx_attributes) structure. The structure should be initialized with [POS_CX_ATTRIBUTES_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/poscx/nf-poscx-pos_cx_attributes_init).

## Return value

An appropriate NTSTATUS error code that indicates success or failure of the initialization.

## See also

[POS_CX_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/poscx/ns-poscx-_pos_cx_attributes)

[POS_CX_ATTRIBUTES_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/poscx/nf-poscx-pos_cx_attributes_init)