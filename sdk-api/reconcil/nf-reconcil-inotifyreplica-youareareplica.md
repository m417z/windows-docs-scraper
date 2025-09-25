# INotifyReplica::YouAreAReplica

## Description

Notifies an object that it may be subject to subsequent reconciliation through the [Reconcile](https://learn.microsoft.com/windows/desktop/api/reconcil/nf-reconcil-ireconcilableobject-reconcile) method.

## Parameters

### `ulcOtherReplicas`

Type: **ULONG**

The number of other replicas of the object. This parameter must not be zero.

### `rgpmkOtherReplicas`

Type: **[IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker)****

The address of an array that contains the addresses of the monikers to use to access the other replicas.

## Return value

Type: **HRESULT**

Returns **S_OK** if successful, or **E_UNEXPECTED** otherwise.

## Remarks

An object may be notified that it is a replica more than once. Briefcase reconcilers are not required to implement this interface. Initiators are not required to call this interface if it is implemented. However, an object's implementation of [Reconcile](https://learn.microsoft.com/windows/desktop/api/reconcil/nf-reconcil-ireconcilableobject-reconcile) may fail if that object has not previously been notified through **INotifyReplica::YouAreAReplica** that it may be subject to reconciliation.

The briefcase calls the [INotifyReplica](https://learn.microsoft.com/windows/desktop/api/reconcil/nn-reconcil-inotifyreplica) interface when objects are added to it.