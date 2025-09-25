# PsDereferenceSiloContext function

## Description

This routine decrements the reference count on the object.

## Parameters

### `SiloContext` [in]

A pointer to the object created by the [PsCreateSiloContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pscreatesilocontext) routine. This parameter is required and it cannot be **NULL**.

## Remarks

If the reference count reaches zero it will call the cleanup callback provided when the [PsCreateSiloContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pscreatesilocontext) routine created the object.