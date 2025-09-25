# IOleUILinkContainerA::UpdateLink

## Description

Forces selected links to connect to their source and retrieve current information.

## Parameters

### `dwLink` [in]

Container-defined unique identifier for a single link. Containers can use the pointer to the link's container site for this value.

### `fErrorMessage` [in]

Determines whether the caller (implementer of [IOleUILinkContainer](https://learn.microsoft.com/windows/desktop/api/oledlg/nn-oledlg-ioleuilinkcontainera)) should show an error message upon failure to update a link. The **Update Links** dialog box sets this to **FALSE**. The **Object Properties** and **Links** dialog boxes set it to **TRUE**.

### `fReserved` [in]

This parameter is reserved and must be set to **FALSE**.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | Insufficient access permissions. |
| **E_FAIL** | The operation failed. |
| **E_INVALIDARG** | The specified identifier is invalid. |
| **E_OUTOFMEMORY** | There is insufficient memory available for this operation. |

## Remarks

### Notes to Callers

Call this method with *fErrorMessage* set to **TRUE** in cases where the user expressly presses a button to have a link updated, that is, presses the links' **Update Now** button. Call it with **FALSE** in cases where the container should never display an error message, that is, where a large set of operations are being performed and the error should be propagated back to the user later, as might occur with the **Update links** progress meter. Rather than providing one message for each failure, assuming there are failures, provide a single message for all failures at the end of the operation.

### Notes to Implementers

For OLE links, call [IOleObject::Update](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-update).

## See also

[IOleObject::Update](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-update)

[IOleUILinkContainer](https://learn.microsoft.com/windows/desktop/api/oledlg/nn-oledlg-ioleuilinkcontainera)