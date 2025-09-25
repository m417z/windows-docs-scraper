# IReconcilableObject::Reconcile

## Description

Reconciles the state of an object with one or more other objects. The reconciliation updates the internal state of the object by merging the states of all objects to form a combined state.

## Parameters

### `pInitiator`

Type: **[IReconcileInitiator](https://learn.microsoft.com/windows/desktop/lwef/ireconcileinitiator)***

The address of the [IReconcileInitiator](https://learn.microsoft.com/windows/desktop/lwef/ireconcileinitiator) interface for the initiator of the reconciliation process. This parameter must not be **NULL**.

### `dwFlags`

Type: **DWORD**

The control flags for the reconciliation. This parameter may be zero or a combination of these values:

#### RECONCILEF_FEEDBACKWINDOWVALID

The *hwndProgressFeedback* parameter is valid.

#### RECONCILEF_MAYBOTHERUSER

The briefcase reconciler can prompt for user interaction if it is needed. Without this value, user interaction is not permitted. The *hwndOwner* parameter is valid.

#### RECONCILEF_NORESIDUESOK

The briefcase reconciler can ignore requests for residues and carry out reconciliation. Reconcilers that do not support residues should check for this value whenever an initiator requests residues. Without this value, a reconciler that does not support residues must immediately return REC_E_NORESIDUES.

#### RECONCILEF_OMITSELFRESIDUE

The briefcase reconciler can discard any residue associated with this object. Initiators typically use this value for reconciliations that loop from generation to generation.

#### RECONCILEF_ONLYYOUWERECHANGED

The **Reconcile** method is being called to propagate changes in the changed object to other unchanged objects. This value will only be set if the following key exists in the registry.

```
HKEY_CLASSES_ROOT
   CLSID
      {CLSID of reconciler}
         SingleChangeHook
```

If this key is not present in the registry, the initiator carries out reconciliation by making the other unchanged objects binary identical copies of the changed object. The
*rgpmkOtherInput* monikers identify the other objects. This value will only be set in
*dwFlags* if RECONCILEF_YOUMAYDOTHEUPDATES is also set. If the briefcase reconciler completes the updates itself successfully, REC_S_IDIDTHEUPDATES should be returned and the variable pointed to by the
*plOutIndex* parameter should be set to -1L. Note that S_OK should not be returned on success if this value is set in
*dwFlags*. The initiator will not save the source object's storage if **Reconcile** returns REC_S_IDIDTHEUPDATES. If the reconciler wishes to fall back to the initiator's bit copy implementation, it may return S_FALSE.

#### RECONCILEF_RESUMEDRECONCILIATION

The briefcase reconciler should resume reconciliation, using the partial residues provided. Without this value, the reconciler should ignore any "considered but rejected" information in any of the input versions.

#### RECONCILEF_YOUMAYDOTHEUPDATES

The briefcase reconciler can perform the updates. Without this value, the reconciler cannot perform the updates. If reconciliation is completed successfully, the reconciler should return REC_S_IDIDTHEUPDATES if it performed the updates or S_OK if it did not perform the updates.

### `hwndOwner`

Type: **HWND**

A handle to the window to be used as the parent for any child windows that the briefcase reconciler creates. This parameter is valid only if RECONCILEF_MAYBOTHERUSER is specified in
*dwFlags*.

### `hwndProgressFeedback`

Type: **HWND**

A handle to the progress feedback window to be displayed by the initiator. This parameter is valid only if RECONCILEF_FEEDBACKWINDOWVALID is specified in
*dwFlags*. The briefcase reconciler may call the
**SetWindowText** function using this window handle to display additional reconciliation status information to the user.

### `ulcInput`

Type: **ULONG**

The number of versions or partial residues specified in
*dwFlags*. This parameter must not be zero.

### `rgpmkOtherInput`

Type: **[IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker)****

The address of an array that contains the addresses of the monikers to use to access the versions or partial residues to be reconciled.

### `plOutIndex`

Type: **LONG***

The address of the variable that receives an index value indicating whether the result of the reconciliation is identical to one of the initial versions. The variable is set to -1L if the reconciliation result is a combination of two or more versions. Otherwise, it is a zero-based index, with 0 indicating this object, 1 indicating the first version, 2 indicating the second version, and so on.

### `pstgNewResidues`

Type: **[IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage)***

The address of the
**IStorage** interface used to store the new residues. This parameter can be **NULL** to indicate that residues should not be saved.

### `pvReserved`

Type: **void***

Reserved; must be **NULL**.

## Return value

Type: **HRESULT**

Returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | Reconciliation completed successfully, and the changes must be propagated to the other objects. |
| **S_FALSE** | No reconciliation actions were performed. The briefcase reconciler wishes to fall back to the initiator's bit copy implementation. This value may only be returned if RECONCILEF_ONLYYOUWERECHANGED is set in *dwFlags*. |
| **REC_S_IDIDTHEUPDATES** | Reconciliation was completed successfully, and all the objects involved (the object implementing the [Reconcile](https://learn.microsoft.com/windows/desktop/api/reconcil/nf-reconcil-ireconcilableobject-reconcile) method and all the other objects described by *rgpmkOtherInput*) have been updated appropriately. The initiator does not need, therefore, to do anything further to propagate the changes. The variable pointed to by *plOutIndex* should be set to -1L if **Reconcile** returns this value. The initiator will not save the source object's storage if **Reconcile** returns this value. This value may only be returned if RECONCILEF_YOUMAYDOTHEUPDATES was set in *dwFlags*. |
| **REC_S_NOTCOMPLETE** | The briefcase reconciler completed some, but not all, of the reconciliation. It may need user interaction. The changes will not be propagated to other objects. |
| **REC_S_NOTCOMPLETEBUTPROPAGATE** | The briefcase reconciler completed some, but not all, of the reconciliation. It may need user interaction. The changes will be propagated to the other objects. |
| **REC_E_NORESIDUES** | The briefcase reconciler does not support the generation of residues, so the request for residues is denied. The state of the object is unchanged. |
| **REC_E_ABORTED** | The briefcase reconciler stopped reconciliation in response to a termination request from the initiator (see [SetAbortCallback](https://learn.microsoft.com/previous-versions/bb761345(v=vs.85)) for more information). The state of the object is unspecified. |
| **REC_E_TOODIFFERENT** | Reconciliation cannot be carried out because the provided document versions are too dissimilar. |
| **REC_E_INEEDTODOTHEUPDATES** | The RECONCILEF_YOUMAYDOTHEUPDATES flag was not set when the object's [Reconcile](https://learn.microsoft.com/windows/desktop/api/reconcil/nf-reconcil-ireconcilableobject-reconcile) implementation was called; this implementation requires that this value be set in the *dwFlags* parameter. |
| **OLE_E_NOTRUNNING** | The object is an OLE embedded object that must be run before this operation can be carried out. The state of the object is unchanged. |
| **E_UNEXPECTED** | Unspecified error. |

## See also

[IReconcilableObject](https://learn.microsoft.com/windows/desktop/api/reconcil/nn-reconcil-ireconcilableobject)