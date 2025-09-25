# KsValidateTopologyNodeCreateRequest function

## Description

The **KsValidateTopologyNodeCreateRequest** function validates a topology node creation request and returns the create structure associated with the request. The function can only be called at PASSIVE_LEVEL.

## Parameters

### `Irp` [in]

Specifies the IRP with the node create request being handled.

### `Topology` [in]

Specifies the topology structure associated with the parent object. This is used to validate the create request.

### `NodeCreate` [out]

Location for the node create structure pointer passed to the create request.

## Return value

The **KsValidateTopologyNodeCreateRequest** function returns a STATUS_SUCCESS if successful, or else an error if unsuccessful.