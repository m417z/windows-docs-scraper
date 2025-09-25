# ITuningSpaceContainer::put_Item

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **put_Item** method saves changes to an existing tuning space in the collection.

## Parameters

### `varIndex` [in]

**VARIANT** that specifies the index of the tuning space.

### `TuningSpace` [in]

Pointer to the [ITuningSpace](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ituningspace) interface of the tuning space.

## Return value

Returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument. |
| **E_POINTER** | NULL pointer argument. |
| **S_OK** | Success. |

If the method fails, error information can be retrieved using the standard COM **IErrorInfo** interface.

## Remarks

An application can retrieve an existing tuning space from the collection, modify its properties by calling [ITuningSpace](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ituningspace) methods, and then call **put_Item** to save the changes. The unique name property on the tuning space must match the tuning space at the specified index in the collection; otherwise, the method returns E_INVALIDARG.

To add a new tuning space, use the [ITuningSpaceContainer::Add](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nf-tuner-ituningspacecontainer-add) method.

## See also

[ITuningSpaceContainer Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ituningspacecontainer)