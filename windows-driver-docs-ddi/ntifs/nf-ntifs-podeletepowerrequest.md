# PoDeletePowerRequest function (ntifs.h)

## Description

The **PoDeletePowerRequest** routine deletes a power request object.

## Parameters

### `PowerRequest` [in, out]

A pointer to a power request object that was created by the [**PoCreatePowerRequest**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-pocreatepowerrequest) routine.

## Remarks

The driver must delete the power request object before it deletes the device object that was used to create the power request object.

## See also

[**PoCreatePowerRequest**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-pocreatepowerrequest)