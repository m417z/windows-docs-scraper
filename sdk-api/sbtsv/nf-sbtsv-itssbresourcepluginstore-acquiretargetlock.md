# ITsSbResourcePluginStore::AcquireTargetLock

## Description

Locks a target.

## Parameters

### `targetName` [in]

The name of the target to lock.

### `dwTimeout` [in]

The timeout for the operation, in milliseconds.

### `ppContext` [out]

Returns a pointer to the context of the lock. To release the lock, supply this pointer to the [ReleaseTargetLock](https://learn.microsoft.com/windows/desktop/api/sbtsv/nf-sbtsv-itssbresourcepluginstore-releasetargetlock) method.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

After the lock is acquired, the calling thread is assumed to have exclusive access to the target object and therefore no other thread (within the same machine) can update it. Therefore the calling thread must call the [ReleaseTargetLock](https://learn.microsoft.com/windows/desktop/api/sbtsv/nf-sbtsv-itssbresourcepluginstore-releasetargetlock) method as soon as it has made the necessary updates to the target object.

**Important** this lock does not completely prevent target objects from being modified externally if more than one Connection Broker exists in the deployment. The calling thread must be prepared to handle a failure gracefully and retry the target update.

## See also

[ITsSbResourcePluginStore](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbresourcepluginstore)