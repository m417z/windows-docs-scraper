# IReconcileInitiator::SetAbortCallback

## Description

Sets the object through which the initiator can asynchronously terminate a reconciliation. A briefcase reconciler typically sets this object for reconciliations that are lengthy or involve user interaction.

## Parameters

### `punkForAbort`

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

The address of the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface for the object. The initiator signals a request to terminate the reconciliation by using the [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method to release the object. This parameter may be **NULL** to direct the initiator to remove the previously specified object.

## Return value

Type: **HRESULT**

Returns the S_OK value if successful, or one of the following error values otherwise.

| Return code | Description |
| --- | --- |
| **REC_E_NOCALLBACK** | The initiator does not support termination of reconciliation operations and does not hold the specified object. |
| **E_UNEXPECTED** | Unspecified error. |

## Remarks

The initiator can accept or reject the object. If the initiator accepts the object, the briefcase reconciler must remove the object by calling this method with a **NULL** parameter when the reconciliation is complete. Because the reconciler removes the object after completing reconciliation, there may be times when the initiator releases the object after reconciliation is complete. In such cases, the reconciler ignores the request to terminate.

If the reconciliation is terminated, the [Reconcile](https://learn.microsoft.com/windows/desktop/api/reconcil/nf-reconcil-ireconcilableobject-reconcile) method must return either the REC_E_ABORTED or REC_E_NOTCOMPLETE value.

## See also

[IReconcileInitiator](https://learn.microsoft.com/windows/desktop/lwef/ireconcileinitiator)