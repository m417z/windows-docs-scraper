# SafeRef function

## Description

[Do not use SafeRef in COM+. This function was used by objects in MTS to obtain a reference to itself. With COM+, this is no longer necessary.]

## Parameters

### `rid` [in]

A reference to the IID of the interface that the current object wants to pass to another object or client.

### `pUnk` [in]

A reference to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface on the current object.

## Return value

If the function succeeds, the return value is a pointer to the specified interface that can be passed outside the current object's context. Otherwise, the return value is **NULL**.

## See also

[COM+ Contexts and Threading Models](https://learn.microsoft.com/windows/desktop/cossdk/com--contexts-and-threading-models)

[IMTxAS::SafeRef](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms679240(v=vs.85))