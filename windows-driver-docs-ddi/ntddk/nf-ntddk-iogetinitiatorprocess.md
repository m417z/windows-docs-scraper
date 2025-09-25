# IoGetInitiatorProcess function

## Description

The IoGetInitiatorProcess routine retrieves the process which initiated the creation of a file object if different than the process which is issuing the create.

## Parameters

### `FileObject` [in]

The file object from which to retrieve the initiator process.

## Return value

NULL if there is no initiator process. Otherwise, a pointer to which process initiated the creation of the file object.

## Remarks

A driver normally uses IoGetInitiatorProcess to determine which process has issued a request. However, there are situations where a system component may issue a create on behalf of another process (after a successful create the component will duplicate the handle to the process). This routine can be used if the driver must know which process the create operation is ultimately intended for.