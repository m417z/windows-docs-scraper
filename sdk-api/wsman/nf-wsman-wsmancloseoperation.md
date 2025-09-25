# WSManCloseOperation function

## Description

Cancels or closes an asynchronous operation. All resources that are associated with the operation are freed.

## Parameters

### `operationHandle` [in, out, optional]

Specifies the operation handle to be closed.

### `flags`

Reserved for future use. Set to zero.

## Return value

This method returns zero on success. Otherwise, this method returns an error code.

## Remarks

The method de-allocates local and remote resources associated with the operation. After the **WSManCloseOperation** method is called, the *operationHandle* parameter cannot be passed to any other call. If the callback associated with the operation is pending and has not completed before **WSManCloseOperation** is called, the operation is marked for deletion and the method returns immediately.