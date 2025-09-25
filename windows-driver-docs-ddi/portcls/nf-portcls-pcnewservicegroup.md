# PcNewServiceGroup function

## Description

The **PcNewServiceGroup** function creates and initializes a service group.

## Parameters

### `OutServiceGroup` [out]

Pointer to the service-group object created by this function. This parameter points to the caller-allocated pointer variable into which the function outputs the pointer to the [IServiceGroup](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iservicegroup) object. Specify a valid, non-**NULL** pointer value for this parameter.

### `OuterUnknown` [in, optional]

Pointer to the [IUnknown](https://learn.microsoft.com/windows/win32/api/unknwn/nn-unknwn-iunknown) interface of an object that needs to aggregate the object. Unless aggregation is required, set this parameter to **NULL**.

## Return value

**PcNewServiceGroup** returns STATUS_SUCCESS if the call was successful. Otherwise, it returns an appropriate error code.

## Remarks

The *OutServiceGroup* and *OuterUnknown* parameters follow the [reference-counting conventions for COM objects](https://learn.microsoft.com/windows-hardware/drivers/audio/reference-counting-conventions-for-com-objects).

## See also

[IServiceGroup](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iservicegroup)