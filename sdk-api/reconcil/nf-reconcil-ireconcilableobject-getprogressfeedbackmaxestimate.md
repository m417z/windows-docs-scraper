# IReconcilableObject::GetProgressFeedbackMaxEstimate

## Description

Retrieves an estimated measurement of the amount of work required to complete a reconciliation. Reconcilers typically use this method to estimate the work needed to reconcile an embedded document. This value corresponds to a similar value that is passed with the [SetProgressFeedback](https://learn.microsoft.com/previous-versions/bb761347(v=vs.85)) method during reconciliation.

## Parameters

### `pulProgressMax`

Type: **ULONG***

The address of the variable to receive the work estimate value.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or one of the following error values otherwise.

| Return code | Description |
| --- | --- |
| **OLE_E_NOTRUNNING** | The object is an OLE embedded document that must be run before this operation can be carried out. The object state is unchanged as a result of the call. |
| **E_UNEXPECTED** | Unspecified error. |

## See also

[IReconcilableObject](https://learn.microsoft.com/windows/desktop/api/reconcil/nn-reconcil-ireconcilableobject)