# KsValidateConnectRequest function

## Description

The **KsValidateConnectRequest** function validates a connection request and returns a pointer to the connection structure associated with the request.

This function can only be called at PASSIVE_LEVEL.

## Parameters

### `Irp` [in]

Pointer to an IRP specifying the connection request.

### `DescriptorsCount` [in]

Specifies the number of pin descriptors passed.

### `Descriptor` [in]

Specifies a pointer to the list of [KSPIN_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kspin_descriptor) structures.

### `Connect` [out]

Specifies a location in which to place a pointer to the [KSPIN_CONNECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kspin_connect) pointer passed to the create request. If **KsValidateConnectRequest** returns success, then Connect+1 will contain a pointer to the KSDATAFORMAT with which the pin was opened.

## Return value

The **KsValidateConnectRequest** function returns STATUS_SUCCESS if successful, or it returns an error.

## Remarks

The **KsValidateConnectRequest** function handles basic connection structure access exceptions and validates the communication requirements, medium, protocol, and basic data format. The validation performed on the data format passed is based on the data range list for the specified pin against which a pin instance is to be created. Validation is successful in three instances: if a range major format is a wildcard, the range major format matches and the range subformat is a wildcard, or the range major format, range subformat, and the range specifier all match.

The buffer is passed a copy of the original input buffer, if the originator was not in kernel mode, and is therefore safe to access.