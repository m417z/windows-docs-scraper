# UcxControllerSetIdStrings function

## Description

Updates the identifier strings
of a controller after the controller has been initialized.

## Parameters

### `Controller`

A handle to the UCX controller that the client driver received in a previous call to the [**UcxControllerCreate**](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/mt188033(v=vs.85)) method.

### `ManufacturerNameString` [in]

A string that contains the name of controller manufacturer.

### `ModelNameString` [in]

A string that contains the name of device model.

### `ModelNumberString` [in]

A string that contains the revision number of the device model.

## Return value

The function returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return one an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) error code.